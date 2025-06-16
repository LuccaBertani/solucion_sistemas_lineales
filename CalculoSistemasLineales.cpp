#include <iostream>
#include <cstdio>

using namespace std;

int main(){

int iteracion = 0;

int respuesta,respuesta1;

cout << "Elegir tipo de sistema" << endl << "1_2X2" << endl << "2_3X3" << endl;
cin >> respuesta;

cout << "Elegir metodo de resolucion" << endl << "1_Jacobi" << endl << "2_Gauss-Seidel" << endl;
cin >> respuesta1;

switch(respuesta){
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
}

