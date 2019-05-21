#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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



int obtenerFila (int vec[],int a){

    int filaPrima;

    if (vec[1]!= '/0'){
    filaPrima= vec[0];
    push (vec[1]);
    }
    else
    {
        filaPrima=vec[0];
    }

    if (filaPrima==9){
        filaPrima=pop();
    }
    a++;
    desplegarPila();

return filaPrima, a;
}

int main()
{

char* operacion [sizeof(char*)];


printf("%s", "Introduce la operacion: ");
scanf( "%s" ,operacion);
printf("Hasta aca llegue %s", operacion);


/*
    Diccionario
    E1=0
    E2=1
    T1=2
    T2=3
    F1=4
    N1=5
    N2=6
    DIG=7
    Error=8
    Pop=9
*/

int matrizTransicion[8][4];

    //Fila 0 de la matriz
        matrizTransicion[0][0] = 2,1;       //Es al revez pero con fines didacticos y funcionales lo haceos al revez, en realidad se aplila en 2,1 no en 1,2 =)
        matrizTransicion[0][1] = 8;
        matrizTransicion[0][2] = 8;
        matrizTransicion[0][3] = 2,1;
        matrizTransicion[0][4] = 8;


        //Fila 1 de la matriz
        matrizTransicion[1][0] = 8;
        matrizTransicion[1][1] = 2,1;
        matrizTransicion[1][2] = 8;
        matrizTransicion[1][3] = 8;
        matrizTransicion[1][4] = 9;


        //Fila2 de la matriz
        matrizTransicion[2][0] = 4,3;
        matrizTransicion[2][1] = 8;
        matrizTransicion[2][2] = 8;
        matrizTransicion[2][3] = 4,3;
        matrizTransicion[2][4] = 8;

        //Fila 3 de la matriz
        matrizTransicion[3][0] = 8;
        matrizTransicion[3][1] = 9;
        matrizTransicion[3][2] = 4,3;
        matrizTransicion[3][3] = 8;
        matrizTransicion[3][4] = 9;

        //Fila 4 de la matriz
        matrizTransicion[4][0] = 5;
        matrizTransicion[4][1] = 8;
        matrizTransicion[4][2] = 8;
        matrizTransicion[4][3] = 0;
        matrizTransicion[4][4] = 8;

        //Fila 5 de la matriz
        matrizTransicion[5][0] = 7,6;
        matrizTransicion[5][1] = 8;
        matrizTransicion[5][2] = 8;
        matrizTransicion[5][3] = 8;
        matrizTransicion[5][4] = 8;

        //Fila 6 de la amtriz

        matrizTransicion[6][0] = 5;
        matrizTransicion[6][1] = 9;
        matrizTransicion[6][2] = 9;
        matrizTransicion[6][3] = 8;
        matrizTransicion[6][4] = 9;


        //Fila 7 de la matriz
        matrizTransicion[7][0] = 9;
        matrizTransicion[7][1] = 5;
        matrizTransicion[7][2] = 5;
        matrizTransicion[7][3] = 5;
        matrizTransicion[7][4] = 5;

        //Fila 8 de la matriz
        matrizTransicion[8][0] = 8;
        matrizTransicion[8][1] = 8;
        matrizTransicion[8][2] = 8;
        matrizTransicion[8][3] = 8;
        matrizTransicion[8][4] = 8;

        //Fila 9 de la matriz
        matrizTransicion[9][0] = 9;
        matrizTransicion[9][1] = 9;
        matrizTransicion[9][2] = 9;
        matrizTransicion[9][3] = 9;
        matrizTransicion[9][4] = 9;


// Ejemplo 3123+428*(314*48+512)

int estadoActual = 0;
int i=0;
int recorrer;

char* vecNumero [sizeof(char*)];
char a;
a = operacion[i];
char aux = a;

printf("Llegue dos veces =D %s", operacion);

while(a != '/0') {
    printf(" Llegue x3 %c", operacion[i]);

/*    int columna = evaluarCaracter(aux);
    recorrer = obtenerFila (matrizTransicion[estadoActual][columna], a);
    estadoActual= recorrer;
    printf("%s", "Estado: ", "%estadoActual");
*/


    //Si recibe algo que no esta contemplado
    if (estadoActual == 8){
        printf("%s", "Syntax Error");
        break;
    }

    //Aumenta el puntero en los casos necesarios
    if (a=='+' || a=='*' || a=='(' || estadoActual==9){
         ///Cuando desapilas en digito UNICAMENTE EN DIGITO el puntero pasa a ser el siguiente

            a=operacion[i+1];}

     i++;

    a=operacion[i];
     }



printf("%s", "bye");






	///int atoi(const char *str)
    ///Converts the string pointed to, by the argument str to an integer (type int).

   // push(1);
    //desplegarPila();
    return 0;
}
