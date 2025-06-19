#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

float calculadoraCoeficientes(const list<float>& coeficientes, const list<float>& valores_anteriores, int posicionIncognita);

int main(){

list<list<float>> ecuacionesConCoeficientes;

int rtaSist,rtaMetodo;

cout << "Elegir tipo de sistema (numero entero teniendo en cuenta el formato nxn):\n"; 
cin >> rtaSist;

cout << "Elegir metodo de resolucion:\n 1_Jacobi\n 2_Gauss-Seidel\n";
cin >> rtaMetodo;

cout << "Teniendo en cuenta el formato ax + bx + cx ... +zx = k" << endl;

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

if(rtaMetodo == 1){

int iteracion = 0;

list <float> incognitasAnteriores(rtaSist,0);
list<float> incognitasActuales;

while (iteracion != -1){
int t = 0;
for (const list<float>& ecuacion : ecuacionesConCoeficientes) {
        float incognita = calculadoraCoeficientes(ecuacion,incognitasAnteriores,t);
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

float calculadoraCoeficientes(const list<float>& coeficientes, const list<float>& valores_anteriores, int posicionIncognita) {
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

/* 

ax + by = c
dx + ey = f

if(respuesta1 == 1){//Jacobi

    while(iteracion != -1){

        num_iteracion ++;

        x_anterior = x;
        y_anterior = y;

        x = (c - b*y_anterior)/a;
        y = (f - d*x_anterior)/e;

        printf("Iteracion %d: (%f;%f)\n",num_iteracion,x,y);

        printf("Responder 1 para seguir o -1 para parar\n");
        scanf("%d",&iteracion);

    }
*/

/*
int iteracion = 0;

list<float> valor_incognitas_anteriores(coeficientes.size()-1, 0);
list <float> valor_incognitas_actual(coeficientes.size()-1,0);
if(rtaMetodo == 1){

while(iteracion != -1){

// coeficientes --> [1,2,3,4,5,6]
// valor_incognitas_anteriores --> [0,0,0,0,0]
// valor_incognitas_actual --> [0,0,0,0,0]
// valor_incognitas_actual[6 - (2*0 + 3*0 + 4*0 + 5*0),..,..,..,..]

for(int j = 0; j < valor_incognitas_actual.size(); j++){ // [1,2,3,4,5,6] <-- coeficientes [0,0,0,0,0] <-- incognitas

    auto it = valor_incognitas_actual.begin();
    advance(it, j);
    
    *it = calculadoraCoeficientes(coeficientes,valor_incognitas_anteriores,j);

}
int k = 0;
for(int valorActual : valor_incognitas_actual){
    if(k==0){
    printf("Iteracion %d: (%f",valorActual);
    }else if (k == valor_incognitas_actual.size() - 1){
    printf("%f)\n",valorActual);
    }else{
        printf(";%f",valorActual);
    }
       k++; 
    }
    printf("Responder 1 para seguir o -1 para parar\n");
        scanf("%d",&iteracion);
}

}

/* 
while(iteracion != -1){

        num_iteracion ++;

        x_anterior = x;
        y_anterior = y;

        x = (c - b*y_anterior)/a;
        y = (f - d*x_anterior)/e;

        printf("Iteracion %d: (%f;%f)\n",num_iteracion,x,y);

        printf("Responder 1 para seguir o -1 para parar\n");
        scanf("%d",&iteracion);

    }





switch(rtaSist){
    case 1:{
    float a,b,c,d,e,f;

    cout << "Teniendo en cuenta el formato ax + by = c" << endl;

    cout << "Coeficientes de la primer ecuacion (donde c es el termino independiente): " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << "Teniendo en cuenta el formato dx + ey = f" << endl;

    cout << "Coeficientes de la segunda ecuacion (donde f es el termino independiente): " << endl;
    cin >> d;
    cin >> e;
    cin >> f;
        
    float x = 0;
    float y = 0;

    float x_anterior = 0;
    float y_anterior = 0;

    int num_iteracion = 0;

    printf("Iteracion %d: (%f;%f)\n",num_iteracion,x,y);

    if(respuesta1 == 1){//Jacobi

    while(iteracion != -1){

        num_iteracion ++;

        x_anterior = x;
        y_anterior = y;

        x = (c - b*y_anterior)/a;
        y = (f - d*x_anterior)/e;

        printf("Iteracion %d: (%f;%f)\n",num_iteracion,x,y);

        printf("Responder 1 para seguir o -1 para parar\n");
        scanf("%d",&iteracion);

    }
    }
    else{
        while(iteracion != -1){//Gauss-Seidel

            num_iteracion ++;
    
            x = (c - b*y)/a;
            y = (f - d*x)/e;
    
            printf("Iteracion %d: (%f;%f)\n",num_iteracion,x,y);
    
            printf("Responder 1 para seguir o -1 para parar\n");
            scanf("%d",&iteracion);
    
        }  
    }
    break;
}
    case 2:{

        float a,b,c,d,e,f,g,h,i,j,k,l;

    cout << "Teniendo en cuenta el formato ax + by + cz= d" << endl;

    cout << "Coeficientes de la primer ecuacion (donde c es el termino independiente): " << endl;
    cin >> a >> b >> c >> d;

    cout << "Teniendo en cuenta el formato ex + fy + gz = h" << endl;

    cout << "Coeficientes de la segunda ecuacion (donde f es el termino independiente): " << endl;
    cin >> e >> f >> g >> h;

    cout << "Teniendo en cuenta el formato ix + jy + kz = l" << endl;

    cout << "Coeficientes de la segunda ecuacion (donde f es el termino independiente): " << endl;
    cin >> i >> j >> k >> l;

    float x = 0;
    float y = 0;
    float z = 0;

    float x_anterior = 0;
    float y_anterior = 0;
    float z_anterior = 0;

    int num_iteracion = 0;

    printf("Iteracion %d: (%f;%f;%f)\n",num_iteracion,x,y,z);

    if(respuesta1 == 1){ //Jacobi

    while(iteracion != -1){

        num_iteracion ++;

        x_anterior = x;
        y_anterior = y;
        z_anterior = z;

        x = (d - b*y_anterior - c*z_anterior)/a;
        y = (h - e*x_anterior - g*z_anterior)/f;
        z = (l - i*x_anterior - j*y_anterior)/k;

        printf("Iteracion %d: (%f;%f;%f)\n",num_iteracion,x,y,z);

        printf("Responder 1 para seguir o -1 para parar\n");
        scanf("%d",&iteracion);

    }

    }else{//Gauss-Seidel
        while(iteracion != -1){

            num_iteracion ++;
    
            x_anterior = x;
            y_anterior = y;
            z_anterior = z;
    
            x = (d - b*y_anterior - c*z_anterior)/a;
            y = (h - e*x - g*z_anterior)/f;
            z = (l - i*x - j*y)/k;
    
            printf("Iteracion %d: (%f;%f;%f)\n",num_iteracion,x,y,z);
    
            printf("Responder 1 para seguir o -1 para parar\n");
            scanf("%d",&iteracion);
    }
        break;
    }
}
}
*/