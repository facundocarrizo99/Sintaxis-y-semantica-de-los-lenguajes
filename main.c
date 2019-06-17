#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    int dato;
    struct Nodo* sig;
}Nodo;

Nodo* primero = NULL;

void push (int valor){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
	nuevo->dato=valor;
	nuevo->sig = primero;
	primero = nuevo;
}
void desplegarPila(){
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	if(primero != NULL){
		while(actual != NULL){
			printf("\n %d", actual -> dato);
			actual = actual -> sig;
		}
	}else{
		printf("\n La pila se encuentra Vacia\n\n");
	}
}
int pop(){
    int valor = primero->dato;
	Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
	actual = primero;
	if(primero != NULL){
        primero = primero -> sig;
    }else{
		printf("Pila vacia");
	}
	actual = actual -> sig;

	return valor;
}


int evaluarCaracter (char a){
   int columna = 0 ;

    switch (a) {

        case '0' ... '9':
            columna = 0;
            break;
        case '+':
            columna = 1;
            break;
        case '*':
            columna = 2;
            break;
        case '(':
            columna = 3;
            break;
    }
    return columna;
}
int obtenerFila (int vec[],int a){

    int filaPrima;

    if (vec[1]!= 0){
    filaPrima= vec[0];
    push (vec[1]);
    }
    else
    {
        filaPrima=vec[0];
    }

    ///Aca saque el if (filaPrima==9), xq lo analizo en el while, cuando sale del while hace el pop

return filaPrima;
}


int main()
{

    //pop otro numero corte -1 y trabajarlo aparte, no devuelve una columna
    int matrizTransicion[10][5][2]={{{2,1},{8,0},{8,0},{2,1},{8,0}},
                                   {{8,0},{2,1},{8,0},{8,0},{9,0}},
                                   {{4,3},{8,0},{8,0},{4,3},{8,0}},
                                   {{8,0},{9,0},{4,3},{8,0},{9,0}},
                                   {{5,0},{8,0},{8,0},{0,0},{8,0}},
                                   {{7,6},{8,0},{8,0},{8,0},{8,0}},
                                   {{5,0},{9,0},{9,0},{8,0},{9,0}},
                                   {{9,0},{5,0},{5,0},{5,0},{5,0}},
                                   {{8,0},{8,0},{8,0},{8,0},{8,0}},
                                   {{9,0},{9,0},{9,0},{9,0},{9,0}}
                                   };
printf ("%d",matrizTransicion[8][3][0]);

int estadoActual = 0;
int i=0;
int recorrer,columna;
char a,aux;
char* operacion;
operacion= (char *) malloc(128 * sizeof(char));


printf("%s", "Introduce la operacion: ");
fgets (operacion,128,stdin);

//printf("Hasta aca llegue %s", operacion);
a=operacion[i];
aux=a;
    while (a!= '\n'){

            if (a == ' '){
                i++;
            }

        //while para que no se conserve la fila y modifique la columna cuando lee el carater (1+1 lee bien el 1 pero deja la fila del numero y modifica la columna con el +)
        columna = evaluarCaracter(aux);
        //printf("%d \n", columna);
        recorrer = obtenerFila (matrizTransicion[estadoActual][columna], a);

        ///Aca meti el while, y todo lo que esta adentro lo tiene que cumplir para que pueda seguir
        while (recorrer != 9){
            recorrer = obtenerFila (matrizTransicion[estadoActual][columna], a);
            estadoActual= recorrer;
            if (estadoActual == 8){
                printf("%s", "Syntax Error");
                return 1; //Aca no iba un Break va un return para que termine la opercion
            }

        }
        ///Esto es lo de else if que no sirve que este adentros
        if (a=='+' || a=='*' || estadoActual==9){
             //Cuando desapilas en digito UNICAMENTE EN DIGITO el puntero pasa a ser el siguiente
                i++;
                a=operacion[i];
                if ( a=='(' || a==')' || estadoActual==9){
             //Cuando desapilas en digito UNICAMENTE EN DIGITO el puntero pasa a ser el siguiente
                i++;
                a=operacion[i];

                }
                /// aca no se como decirle lo del pop, siento que no lo hace completamente
                estadoActual=pop();
            }

        i++;
        a=operacion[i];
        aux=a;
    }

    printf("%s", "La Ecuacion ingresada es Correcta");
    return 0;
}
