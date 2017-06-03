#include <stdio.h>
#include <stdlib.h>

/* lista simple */
typedef struct nodo{
    int dato;
    struct nodo* siguiente;
} NODO;

NODO* primero = NULL;
NODO* ultimo = NULL;

void agregar(int valor);
void recorrer();
int eliminar(int valor);

/* Lista simple circular */
NODO* primeroSc = NULL;
NODO* ultimoSc = NULL;

void agregarSimpleCircular(int valor);
void recorrerSimpleCircular();
int eliminarSimpleCircular(int valor);

/* lista doble */
typedef struct nodoD{
    int dato;
    struct nodoD* siguiente;
    struct nodoD* anterior;
} NODOD;

NODOD* primeroD = NULL;
NODOD* ultimoD = NULL;

void agregarDoble(int valor1);
void recorrerDoble();
int eliminarDoble(int valor1);

/* pila */
NODO* primeroP = NULL;
NODO* ultimoP = NULL;

void agregarPila(int valor);
void recorrerPila();
int eliminarPila();

/* cola */
NODO* primeroC = NULL;
NODO* ultimoC = NULL;

void agregarCola(int valor);
void recorrerCola();
int eliminarCola();

/* lista doble circular */
NODOD* primeroDc = NULL;
NODOD* ultimoDc = NULL;

void agregarDobleCircular(int valor);
void recorrerDobleCircular();
int eliminarDobleCircular(int valor);

/* Genericos */
int opcion = 0;
int valor = 0;
int resultado = 0;


int main()
{
    while(opcion!=20)
    {
        printf("\nOpciones:\n");
        //printf("1. Cargar datos de archivo.\n");
        printf("2. Ingresar numero a la LISTA SIMPLE\n");
        printf("3. Graficar LISTA SIMPLE\n");
        printf("4. eliminar dato en LISTA SIMPLE\n");
        printf("-------------------------------------------\n");
        printf("5. Ingresar numero a la LISTA DOBLE\n");
        printf("6. Graficar LISTA DOBLE\n");
        printf("7. eliminar dato en LISTA DOBLE\n");
        printf("--------------------------------------------\n");
        printf("8. Ingresar numero a la LISTA SIMPLE CIRCULAR\n");
        printf("9. Graficar LISTA SIMPLE CIRCULAR\n");
        printf("10. eliminar dato en LISTA SIMPLE CIRCULAR\n");
        printf("--------------------------------------------\n");
        printf("11. Ingresar numero a la LISTA DOBLE CIRCULAR\n");
        printf("12. Graficar LISTA DOBLE CIRCULAR\n");
        printf("13. eliminar dato en LISTA DOBLE CIRCULAR\n");
        printf("--------------------------------------------\n");
        printf("14. Ingresar numero a la PILA\n");
        printf("15. Graficar PILA\n");
        printf("16. eliminar dato en PILA\n");
        printf("--------------------------------------------\n");
        printf("17. Ingresar numero a la COLA\n");
        printf("18. Graficar COLA\n");
        printf("19. eliminar dato en COLA\n");
        printf("--------------------------------------------\n");
        printf("20. salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("hola mundo");
                break;
            case 2:
                printf("\nIngrese un entero: ");
                scanf("%d",&valor);
                agregar(valor);
                printf("valor agregado");
                break;
            case 3:
                recorrer();
                system("dot -Tpng ~/Documentos/\"Codigo c\"/\"Lista Simple\"/lista.txt -o ~/Documentos/\"Codigo c\"/\"Lista Simple\"/lista.png");
                system("nohup display ~/Documentos/\"Codigo c\"/\"Lista Simple\"/lista.png &" );
                break;
            case 4:
                printf("\nIngrese el numero que desea eliminar: ");
                scanf("%d",&valor);
                resultado = eliminar(valor);
                if(resultado==0){
                    printf("dato no encontrado");
                }else{
                    printf("dato eliminado");
                }
                break;
            case 5:
                printf("\nIngrese un entero: ");
                scanf("%d",&valor);
                agregarDoble(valor);
                printf("valor agregado");
                break;
            case 6:
                recorrerDoble();
                system("dot -Tpng ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaDoble.txt -o ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaDoble.png");
                system("nohup display ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaDoble.png &" );
                break;
            case 7:
                printf("\nIngrese el numero que desea eliminar: ");
                scanf("%d",&valor);
                resultado = eliminarDoble(valor);
                if(resultado==0){
                    printf("dato no encontrado\n");
                }else{
                    printf("dato eliminado\n");
                }
                break;
            case 8:
                printf("\nIngrese un entero: ");
                scanf("%d",&valor);
                agregarSimpleCircular(valor);
                printf("valor agregado");
                break;
            case 9:
                recorrerSimpleCircular();
                system("dot -Tpng ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaSimpleCircular.txt -o ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaSimpleCircular.png");
                system("nohup display ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaSimpleCircular.png &" );
                break;
            case 10:
                printf("\nIngrese el numero que desea eliminar: ");
                scanf("%d",&valor);
                resultado = eliminarSimpleCircular(valor);
                if(resultado==0){
                    printf("dato no encontrado\n");
                }else{
                    printf("dato eliminado\n");
                }
                break;
            case 11:
                printf("\nIngrese un entero: ");
                scanf("%d",&valor);
                agregarDobleCircular(valor);
                printf("valor agregado");
                break;
            case 12:
                recorrerDobleCircular();
                system("dot -Tpng ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaDobleCircular.txt -o ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaDobleCircular.png");
                system("nohup display ~/Documentos/\"Codigo c\"/\"Lista Simple\"/listaDobleCircular.png &" );
                break;
            case 13:
                printf("\nIngrese el numero que desea eliminar: ");
                scanf("%d",&valor);
                resultado = eliminarDobleCircular(valor);
                if(resultado==0){
                    printf("dato no encontrado\n");
                }else{
                    printf("dato eliminado\n");
                }
                break;
            case 14:
                printf("\nIngrese un entero: ");
                scanf("%d",&valor);
                agregarPila(valor);
                printf("valor agregado");
                break;
            case 15:
                recorrerPila();
                system("dot -Tpng ~/Documentos/\"Codigo c\"/\"Lista Simple\"/pila.txt -o ~/Documentos/\"Codigo c\"/\"Lista Simple\"/pila.png");
                system("nohup display ~/Documentos/\"Codigo c\"/\"Lista Simple\"/pila.png &" );
                break;
            case 16:
                resultado = eliminarPila();
                if(resultado==0){
                    printf("dato no encontrado\n");
                }else{
                    printf("dato eliminado\n");
                }
                break;
            case 17:
                printf("\nIngrese un entero: ");
                scanf("%d",&valor);
                agregarCola(valor);
                printf("valor agregado");
                break;
            case 18:
                recorrerCola();
                system("dot -Tpng ~/Documentos/\"Codigo c\"/\"Lista Simple\"/cola.txt -o ~/Documentos/\"Codigo c\"/\"Lista Simple\"/cola.png");
                system("nohup display ~/Documentos/\"Codigo c\"/\"Lista Simple\"/cola.png &" );
                break;
            case 19:
                resultado = eliminarCola();
                if(resultado==0){
                    printf("dato no encontrado\n");
                }else{
                    printf("dato eliminado\n");
                }
                break;
        }
    }

    return 0;
}

/*-----------------------------------------------------------LISTA SIMPLE----------------------------------------------------------------*/

void agregar(int valor)
{
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if(nuevo != NULL)
    {
        if(primero!=NULL)
        {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
        else
        {
            primero = ultimo = nuevo;
        }
    }
}

void recorrer()
{
    FILE *archivo = fopen("\lista.txt","w");
    fprintf(archivo,"digraph G {");
    NODO* temporal = primero;
    while(temporal!=NULL)
    {
        if(temporal->siguiente!=NULL){
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo," -> ");
            fprintf(archivo,"%d",temporal->siguiente->dato);
            fprintf(archivo,";\n");
        }else{
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo,";\n");
        }

        printf("%d ,",temporal->dato);
        temporal = temporal->siguiente;
    }
    fprintf(archivo,"}");
    fclose(archivo);
}

int eliminar(int valor)
{
    NODO* actual = primero;
    NODO* anterior = NULL;

    while(actual!=NULL)
    {
        if(anterior==NULL && actual->dato==valor){
            if(actual->siguiente==NULL){
                primero = ultimo = NULL;
            }else{
                primero = primero->siguiente;
                free(actual);
            }
            return 1;
        }else if(actual->siguiente==NULL && actual->dato==valor){
            anterior->siguiente=NULL;
            ultimo = anterior;
            free(actual);
            return 1;
        }else if(actual->dato==valor){
            anterior->siguiente=actual->siguiente;
            free(actual);
            return 1;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("no hay datos en la lista\n");
    return 0;
}

/*----------------------------------------------------LISTA SIMPLE CIRCULAR-------------------------------------------------------------*/

void agregarSimpleCircular(int valor){
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));

    if(nuevo!=NULL){
        nuevo->dato = valor;
        nuevo->siguiente=NULL;
        if(primeroSc==NULL){
            primeroSc = ultimoSc = nuevo;
            nuevo->siguiente = nuevo;
        }else if(primeroSc==ultimoSc){
            ultimoSc = nuevo;
            primeroSc->siguiente = ultimoSc;
            ultimoSc->siguiente = primeroSc;
        }else{
            ultimoSc->siguiente = nuevo;
            nuevo->siguiente = primeroSc;
            ultimoSc = nuevo;
        }
    }
}

void recorrerSimpleCircular(){
    FILE *archivo = fopen("\listaSimpleCircular.txt","w");
    fprintf(archivo,"digraph H {\n");

    NODO* temporal = primeroSc;
    if(primeroSc!=NULL){
        do{
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo," -> ");
            fprintf(archivo,"%d",temporal->siguiente->dato);
            fprintf(archivo,";\n");
            temporal = temporal->siguiente;
        }while(temporal!=primeroSc);
    }

    fprintf(archivo,"}");
    fclose(archivo);
}

int eliminarSimpleCircular(int valor){
    NODO* temporal = primeroSc;
    NODO* eliminar = NULL;
    if(primeroSc!=NULL){
        do{
            if(temporal==primeroSc && temporal->dato==valor){
                if(temporal->siguiente==primeroSc){
                    ultimoSc = primeroSc = NULL;
                    free(temporal);
                    return 1;
                }else{
                    primeroSc = primeroSc->siguiente;
                    ultimoSc->siguiente = primeroSc;
                    free(temporal);
                    return 1;
                }
            }else if(temporal->siguiente->dato== valor){
                if(temporal->siguiente==ultimoSc){
                    eliminar = temporal->siguiente;
                    ultimoSc = temporal;
                    ultimoSc->siguiente = primeroSc;
                    free(eliminar);
                    return 1;
                }else{
                    eliminar = temporal->siguiente;
                    temporal->siguiente = temporal->siguiente->siguiente;
                    free(eliminar);
                    return 1;
                }
            }
            temporal = temporal->siguiente;
        }while(temporal!=primeroSc);
    }

    return 0;
}

/*-----------------------------------------------------------LISTA DOBLE----------------------------------------------------------------*/

void agregarDoble(int valor1)
{
    NODOD* nuevo = (NODOD*)malloc(sizeof(NODOD));

    if(nuevo != NULL)
    {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;

        if(primeroD!=NULL)
        {
            ultimoD->siguiente = nuevo;
            nuevo->anterior = ultimoD;
            ultimoD = nuevo;
        }
        else
        {
            primeroD = ultimoD = nuevo;
            primeroD->siguiente = ultimoD;
            ultimoD->anterior = primeroD;
        }
    }
}

void recorrerDoble()
{
    FILE *archivo = fopen("\listaDoble.txt","w");
    fprintf(archivo,"digraph H {\n");

    NODOD* temporal = primeroD;
    while(temporal!=NULL)
    {
        if(temporal->siguiente!=NULL){
            if(ultimoD==primeroD){
                fprintf(archivo,"%d",temporal->dato);
                fprintf(archivo," -> ");
                fprintf(archivo,"%d",temporal->dato);
                fprintf(archivo,";\n");
                fprintf(archivo,"%d",temporal->dato);
                fprintf(archivo," -> ");
                fprintf(archivo,"%d",temporal->dato);
                fprintf(archivo," [color = red];\n");
                break;
            }else{
                fprintf(archivo,"%d",temporal->dato);
                fprintf(archivo," -> ");
                fprintf(archivo,"%d",temporal->siguiente->dato);
                fprintf(archivo,";\n");
                fprintf(archivo,"%d",temporal->siguiente->dato);
                fprintf(archivo," -> ");
                fprintf(archivo,"%d",temporal->siguiente->anterior->dato);
                fprintf(archivo," [color = red];\n");
            }
        }
        temporal = temporal->siguiente;
    }
    fprintf(archivo,"}");
    fclose(archivo);
}

int eliminarDoble(int valor1)
{
    NODOD* actual = primeroD;
    while(actual!=NULL)
    {
        if(actual==primeroD && actual->siguiente==NULL && actual->dato==valor){
            primeroD = NULL;
            ultimoD = NULL;
            free(actual);
            return 1;
        }else if(actual==primeroD && actual->dato==valor){
            actual->siguiente->anterior = NULL;
            primeroD = actual->siguiente;
            free(actual);
            return 1;
        }else if(actual->siguiente==NULL && actual->dato==valor){
            actual->anterior->siguiente = actual->siguiente;
            ultimoD = actual->anterior;
            free(actual);
            return 1;
        }else if(actual->dato==valor){
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
            free(actual);
            return 1;
        }
        actual = actual->siguiente;
    }
    printf("no hay datos en la lista\n");
    return 0;
}

/*-----------------------------------------------------LISTA DOBLE CIRCULAR--------------------------------------------------------------*/

void agregarDobleCircular(int valor){
    NODOD* nuevo = (NODOD*)malloc(sizeof(NODOD));
    if(nuevo!=NULL){
        nuevo->dato = valor;
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;
        if(primeroDc==NULL){
            primeroDc = ultimoDc = nuevo;
            ultimoDc->siguiente = primeroDc;
            ultimoDc->anterior = primeroDc;
            primeroDc->siguiente = ultimoDc;
            primeroDc->anterior = ultimoDc;
        }else if(primeroDc==ultimoDc){
            primeroDc->siguiente = nuevo;
            primeroDc->anterior = nuevo;
            nuevo->siguiente = primeroDc;
            nuevo->anterior = primeroDc;
            ultimoDc = nuevo;
        }else{
            nuevo->siguiente = primeroDc;
            nuevo->anterior = ultimoDc;
            ultimoDc->siguiente = nuevo;
            primeroDc->anterior = nuevo;
            ultimoDc = nuevo;
        }
    }
}

void recorrerDobleCircular(){
    FILE *archivo = fopen("\listaDobleCircular.txt","w");
    fprintf(archivo,"digraph H {\n");

    NODOD* temporal = primeroDc;
    if(temporal!=NULL){
        do{
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo," -> ");
            fprintf(archivo,"%d",temporal->siguiente->dato);
            fprintf(archivo,";\n");
            fprintf(archivo,"%d",temporal->siguiente->dato);
            fprintf(archivo," -> ");
            fprintf(archivo,"%d",temporal->siguiente->anterior->dato);
            fprintf(archivo," [color = red];\n");
            temporal = temporal->siguiente;
        }while(temporal!=primeroDc);
    }
    fprintf(archivo,"}");
    fclose(archivo);
}

int eliminarDobleCircular(int valor){

    NODOD* temporal = primeroDc;
    if(temporal!= NULL){
        do{
            if(temporal==primeroDc && temporal->dato==valor){
                if(temporal->siguiente==primeroDc){
                    ultimoDc = primeroDc = NULL;
                    free(temporal);
                    return 1;
                }else if(temporal->siguiente==ultimoDc){
                    primeroDc = primeroDc->siguiente;
                    ultimoDc->siguiente = primeroDc;
                    ultimoDc->anterior = primeroDc;
                    free(temporal);
                    return 1;
                }else{
                    primeroDc->siguiente->anterior = ultimoDc;
                    ultimoDc->siguiente = primeroDc->siguiente;
                    primeroDc = temporal->siguiente;
                    free(temporal);
                    return 1;
                }
            }else if(temporal->dato==valor){
                if(temporal==ultimoDc){
                    temporal->anterior->siguiente = primeroDc;
                    primeroDc->anterior = temporal->anterior;
                    ultimoDc = temporal->anterior;
                    free(temporal);
                    return 1;
                }else{
                    temporal->anterior->siguiente = temporal->siguiente;
                    temporal->siguiente->anterior = temporal->anterior;
                    free(temporal);
                    return 1;
                }
            }
            temporal = temporal->siguiente;
        }while(temporal!=primeroDc);
    }

    return 0;
}

/*---------------------------------------------------------------PILA--------------------------------------------------------------------*/

void agregarPila(int valor){
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    if(nuevo != NULL)
    {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        if(primeroP!=NULL)
        {
            ultimoP->siguiente = nuevo;
            ultimoP = nuevo;
        }
        else
        {
            primeroP = ultimoP = nuevo;
        }
    }
}

void recorrerPila(){
    FILE *archivo = fopen("\pila.txt","w");
    fprintf(archivo,"digraph G {");
    NODO* temporal = primeroP;
    while(temporal!=NULL)
    {
        if(temporal->siguiente!=NULL){
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo," -> ");
            fprintf(archivo,"%d",temporal->siguiente->dato);
            fprintf(archivo,";\n");
        }else{
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo,";\n");
        }

        printf("%d ,",temporal->dato);
        temporal = temporal->siguiente;
    }
    if(primeroP!=NULL){
        fprintf(archivo,"%d",primeroP->dato);
        fprintf(archivo,"[shape=diamond];\n");
    }
    fprintf(archivo,"}");
    fclose(archivo);
}

int eliminarPila(){
    NODO* temporal = primeroP;
    if(temporal!=NULL){
        if(primeroP==ultimoP){
            primeroP = ultimoP = NULL;
            return 1;
        }else{
            while(temporal->siguiente!=ultimoP){
                temporal = temporal->siguiente;
            }
            ultimoP = temporal;
            free(temporal->siguiente);
            temporal->siguiente = NULL;
            return 1;
        }
    }
    return 0;
}
/*---------------------------------------------------------------COLA--------------------------------------------------------------------*/

void agregarCola(int valor){
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    if(nuevo != NULL)
    {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        if(primeroC!=NULL)
        {
            ultimoC->siguiente = nuevo;
            ultimoC = nuevo;
        }
        else
        {
            primeroC = ultimoC = nuevo;
        }
    }
}

void recorrerCola(){
    FILE *archivo = fopen("\cola.txt","w");
    fprintf(archivo,"digraph G {");
    NODO* temporal = primeroC;
    while(temporal!=NULL)
    {
        if(temporal->siguiente!=NULL){
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo," -> ");
            fprintf(archivo,"%d",temporal->siguiente->dato);
            fprintf(archivo,";\n");
        }else{
            fprintf(archivo,"%d",temporal->dato);
            fprintf(archivo,";\n");
        }

        printf("%d ,",temporal->dato);
        temporal = temporal->siguiente;
    }
    if(primeroC!=NULL){
        fprintf(archivo,"%d",primeroC->dato);
        fprintf(archivo,"[shape=diamond];\n");
    }
    fprintf(archivo,"}");
    fclose(archivo);
}

int eliminarCola(){

    if(primeroC!=NULL){
        if(primeroC==ultimoC){
            primeroC = ultimoC = NULL;
            return 1;
        }else{
            primeroC = primeroC->siguiente;
            return 1;
        }
    }
    return 0;
}

