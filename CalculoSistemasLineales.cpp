#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

float calculadoraCoeficientesJacobi(const list<float>& coeficientes, const list<float>& valores_anteriores, int posicionIncognita);
float calculadoraCoeficientesGauss_Seidel(const list<float>& coeficientes, const list<float>& valores_anteriores, int posicionIncognita, const list<float>& valores_actuales);

int main(){

list<list<float>> ecuacionesConCoeficientes;

int rtaSist,rtaMetodo;

cout << "Elegir tipo de sistema (numero entero teniendo en cuenta el formato nxn):\n"; 
cin >> rtaSist;

cout << "Elegir metodo de resolucion:\n 1_Jacobi\n 2_Gauss-Seidel\n";
cin >> rtaMetodo;

cout << "Teniendo en cuenta el formato ax + by + cz ... +zr = k" << endl;

for(int j = 0; j< rtaSist ; j++){

printf("Ecuacion num %d°\n",j+1);

list <float> coeficientes;

for(int i = 0; i< rtaSist + 1 ; i++){
float valor;
if(i == rtaSist){
    printf("Ingrese la constante\n");
    scanf("%f",&valor);

coeficientes.push_back(valor);
}
else{
printf("Ingrese el coeficiente num %d°\n",i+1);
scanf("%f",&valor);

coeficientes.push_back(valor);
}
}
ecuacionesConCoeficientes.push_back(coeficientes);
}

int iteracion = 0;

if(rtaMetodo == 1){

list <float> incognitasAnteriores(rtaSist,0);
list<float> incognitasActuales;

while (iteracion != -1){
int t = 0;
for (const list<float>& ecuacion : ecuacionesConCoeficientes) {
        float incognita = calculadoraCoeficientesJacobi(ecuacion,incognitasAnteriores,t);
        incognitasActuales.push_back(incognita);
        t++;
    }
    incognitasAnteriores = incognitasActuales;
    

    printf("Solucion: (");
    for (auto it = incognitasActuales.begin(); it != incognitasActuales.end(); ++it) {
        printf("%.2f", *it);
        if (next(it) != incognitasActuales.end()) {
            printf(";");
        }
    }
    printf(")\n");
    incognitasActuales.clear();
    printf("Siguiente iteracion? Si = 1, No = -1.\n");
    scanf("%d",&iteracion);
}

} else if(rtaMetodo == 2){

list <float> incognitasAnteriores(rtaSist,0);
list<float> incognitasActuales;

while (iteracion != -1){
int t = 0;

for (const list<float>& ecuacion : ecuacionesConCoeficientes) {
        float incognita = calculadoraCoeficientesGauss_Seidel(ecuacion,incognitasAnteriores,t,incognitasActuales);
        incognitasActuales.push_back(incognita);
        t++;
    }
    incognitasAnteriores = incognitasActuales;
    

    printf("Solucion: (");
    for (auto it = incognitasActuales.begin(); it != incognitasActuales.end(); ++it) {
        printf("%.2f", *it);
        if (next(it) != incognitasActuales.end()) {
            printf(";");
        }
    }
    printf(")\n");
    incognitasActuales.clear();
    printf("Siguiente iteracion? Si = 1, No = -1.\n");
    scanf("%d",&iteracion);
}

    
}

}

float calculadoraCoeficientesJacobi(const list<float>& coeficientes, const list<float>& valores_anteriores, int posicionIncognita) {
    auto itCoef = coeficientes.begin();
    auto itVal = valores_anteriores.begin();

    float sumatoria = 0.0;
    int j = 0;

    int n = valores_anteriores.size();

    // Recorrer coeficientes hasta la penúltima posición (coeficientes de variables)
    for (; j < n; ++j, ++itCoef, ++itVal) {
        if (j != posicionIncognita) {
            sumatoria += (*itCoef) * (*itVal);
        }
    }

    // Ahora itCoef apunta al coef independiente (último de la fila)
    float terminoIndependiente = *itCoef;

    // Obtener coeficiente de la incógnita actual (volver a empezar y avanzar hasta posicionIncognita)
    itCoef = coeficientes.begin();
    advance(itCoef, posicionIncognita);
    float coefIncognita = *itCoef;

    return (terminoIndependiente - sumatoria) / coefIncognita;
}

float calculadoraCoeficientesGauss_Seidel(const list<float>& coeficientes, const list<float>& valores_anteriores, int posicionIncognita, const list<float>& valores_actuales) {
    auto itCoef = coeficientes.begin();
    auto itVal_anteriores = valores_anteriores.begin();
    auto itVal_actuales = valores_actuales.begin();

    float sumatoria_anteriores = 0.0, sumatoria_actuales = 0.0;
    int j = 0;

    int n = valores_anteriores.size();

    // valores_actuales = [1,2]
    // valores_anteriores = [2,4,5,6]

    // Recorrer coeficientes hasta la penúltima posición (coeficientes de variables)
    for (; j < n; ++j, ++itCoef, ++itVal_anteriores) {
        if (j != posicionIncognita) {

            if(valores_actuales.size() > j){
            sumatoria_actuales += (*itCoef) * (*itVal_actuales);
            } else {
            sumatoria_anteriores += (*itCoef) * (*itVal_anteriores);
            }
        }
    }

    // Ahora itCoef apunta al coef independiente (último de la fila)
    float terminoIndependiente = *itCoef;

    // Obtener coeficiente de la incógnita actual (volver a empezar y avanzar hasta posicionIncognita)
    itCoef = coeficientes.begin();
    advance(itCoef, posicionIncognita);
    float coefIncognita = *itCoef;

    return (terminoIndependiente - sumatoria_anteriores - sumatoria_actuales) / coefIncognita;
}