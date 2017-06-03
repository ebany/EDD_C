#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    char operador;
    struct nodo* izquierda;
    struct nodo* derecha;
} NODO;

/* ABB*/
NODO* raizABB = NULL;
int agregarABB(int valor,NODO** raiz);
//int eliminarABB(int valor, NODO** actual, NODO** padre);
//void recorrerABB();
//void auxRecorrerABB(nodo** actual, FILE** archivo);
void preOrdenABB(NODO** actual, FILE** archivo);
void inOrdenABB(NODO** actual, FILE** archivo);
void posOrdenABB(NODO** actual, FILE** archivo);

/* ABB OPERACION */

/* AVL */

NODO* raizAVL = NULL;

/* Genericos */
int valor = 0;
int opcion = 0;
int respuesta = 0;
FILE *archivo2;
int extra = 1025;
NODO* vacio = NULL;

int main()
{
    while(opcion!=15){
        printf("\nOpciones:\n");
        printf("1. Ingresar numero al ABB\n");
        printf("2. Graficar ABB\n");
        printf("3. eliminar dato en ABB\n");
        printf("-----------------------------\n");
        printf("4. recorrido pre-orden ABB\n");
        printf("5. recorrido in-orden ABB\n");
        printf("6. recorrido pos-orden ABB\n");
        printf("-----------------------------\n");
        printf("7. Ingresar numero al AVL\n");
        printf("8. Graficar AVL\n");
        printf("9. eliminar dato en AVL\n");
        printf("-----------------------------\n");
        printf("15. salir\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                printf("ingrese un numero entero: ");
                scanf("%d",&valor);
                respuesta = agregarABB(valor, &raizABB);
                if(respuesta){
                    printf("el dato se agrego %d\n",valor);
                }else{
                    printf("el dato ya existe");
                }
                break;
            case 2:
                recorrerABB(&raizABB);
                system("dot -Tpng ~/Documentos/\"Codigo c\"/ABByAVL/grafoABB.txt -o ~/Documentos/\"Codigo c\"/ABByAVL/bb.png");
                system("nohup display ~/Documentos/\"Codigo c\"/ABByAVL/bb.png &" );
                break;
            case 3:
                printf("ingrese el numero entero que desea eliminar: ");
                scanf("%d",&valor);
                respuesta = eliminarABB(valor, &raizABB);
                if(respuesta){
                    printf("el dato se elimino %d\n",valor);
                }else{
                    printf("el dato no existe");
                }
                break;
            case 4:
                archivo2 = fopen("\grafoABBpreOrden.txt","w");
                fprintf(archivo2,"digraph G {\n");
                fprintf(archivo2,"node [shape=record];\n struct1[shape=record,label=\"");
                preOrdenABB(&raizABB,&archivo2);
                fprintf(archivo2,"\"];}");
                fclose(archivo2);
                system("dot -Tpng ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBpreOrden.txt -o ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBpreOrden.png");
                system("nohup display ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBpreOrden.png &" );
                break;
            case 5:
                archivo2 = fopen("\grafoABBinOrden.txt","w");
                fprintf(archivo2,"digraph G {\n");
                fprintf(archivo2,"node [shape=record];\n struct1[shape=record,label=\"");
                inOrdenABB(&raizABB,&archivo2);
                fprintf(archivo2,"\"];}");
                fclose(archivo2);
                system("dot -Tpng ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBinOrden.txt -o ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBinOrden.png");
                system("nohup display ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBinOrden.png &" );
                break;
            case 6:
                archivo2 = fopen("\grafoABBposOrden.txt","w");
                fprintf(archivo2,"digraph G {\n");
                fprintf(archivo2,"node [shape=record];\n struct1[shape=record,label=\"");
                posOrdenABB(&raizABB,&archivo2);
                fprintf(archivo2,"\"];}");
                fclose(archivo2);
                system("dot -Tpng ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBposOrden.txt -o ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBposOrden.png");
                system("nohup display ~/Documentos/\"Codigo c\"/ABByAVL/grafoABBposOrden.png &" );
                break;
            case 7:
                printf("ingrese un numero entero: ");
                scanf("%d",&valor);
                respuesta = agregarABB(valor, &raizAVL);

                // verificar si esta equilibrado
                extra = 1025;
                while(extra>1024){
                    extra = verificarEquilibrio(&raizAVL,&vacio);
                }

                if(respuesta){
                    printf("el dato se agrego %d\n",valor);
                }else{
                    printf("el dato ya existe");
                }
                break;
            case 8:
                recorrerABB(&raizAVL);
                system("dot -Tpng ~/Documentos/\"Codigo c\"/ABByAVL/grafoABB.txt -o ~/Documentos/\"Codigo c\"/ABByAVL/bb.png");
                system("nohup display ~/Documentos/\"Codigo c\"/ABByAVL/bb.png &" );
                break;
            case 9:
                printf("ingrese el numero entero que desea eliminar: ");
                scanf("%d",&valor);
                respuesta = eliminarAVL(valor, &raizAVL, &vacio);

                extra = 1025;
                while(extra>1024){
                    extra = verificarEquilibrio(&raizAVL,&vacio);
                }

                if(respuesta){
                    printf("el dato se elimino %d\n",valor);
                }else{
                    printf("el dato no existe");
                }
                break;
        }
    }
    free(raizABB);
    return 0;
}

/*------------------------------------------------ABB---------------------------------------------*/

int agregarABB(int valor, NODO** raiz){         //  <------------------------ para AVL Y ABB

    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    if(nuevo!=NULL){
        nuevo->dato = valor;
        nuevo->izquierda = NULL;
        nuevo->derecha = NULL;

        if(*raiz==NULL){
            *raiz = nuevo;
            return 1;
        }else if((*raiz)->dato < valor){
            if((*raiz)->derecha!=NULL){
                return agregarABB(valor,&(*raiz)->derecha);
            }else{
                (*raiz)->derecha = nuevo;
                return 1;
            }
        }else if((*raiz)->dato > valor){
            if((*raiz)->izquierda!=NULL){
                return agregarABB(valor, &(*raiz)->izquierda);
            }else{
                (*raiz)->izquierda = nuevo;
                return 1;
            }
        }
    }
    return 0;
}

int eliminarABB(int valor,NODO** actual, NODO** padre){
    if(*actual!=NULL){
        if((*actual)->dato==valor){
            if((*actual)->izquierda==NULL && (*actual)->derecha==NULL){
                if(*padre==NULL){
                    raizABB = NULL;
                }else if((*padre)->izquierda==*actual){
                    (*padre)->izquierda = NULL;
                }else{
                    (*padre)->derecha = NULL;
                }
            }else if((*actual)->derecha==NULL && (*actual)->izquierda!=NULL){
                if(*padre!=NULL){
                    if((*padre)->izquierda==*actual){
                        (*padre)->izquierda=(*actual)->izquierda;
                    }else{
                        (*padre)->derecha=(*actual)->izquierda;
                    }
                }else{
                    raizABB = (*actual)->izquierda;
                }

            }else if((*actual)->izquierda==NULL && (*actual)->derecha!=NULL){
                if(*padre!=NULL){
                    if((*padre)->izquierda==*actual){
                        (*padre)->izquierda=(*actual)->derecha;
                    }else{
                        (*padre)->derecha=(*actual)->derecha;
                    }
                }else{
                    raizABB = (*actual)->derecha;
                }

            }else{
                NODO* temporal = (*actual)->derecha;
                while(temporal->izquierda!=NULL){
                    temporal = temporal->izquierda;
                }
                temporal->izquierda = (*actual)->izquierda;
                if(*padre!=NULL){
                    if((*padre)->izquierda==*actual){
                        (*padre)->izquierda=(*actual)->derecha;
                    }else{
                        (*padre)->derecha=(*actual)->derecha;
                    }
                }else{
                    raizABB = (*actual)->derecha;
                }
                //free(*actual);
            }
            return 1;
        }else if(valor < (*actual)->dato){
            return eliminarABB(valor, &(*actual)->izquierda,&(*actual));
        }else if(valor > (*actual)->dato){
            return eliminarABB(valor, &(*actual)->derecha,&(*actual));
        }
    }
    return 0;
}


/*-----------------------------------------------Grafo ABB--------------------------------------------*/
void recorrerABB(NODO** raizArbol){
    FILE *archivo = fopen("\grafoABB.txt","w");
    fprintf(archivo,"digraph G {");
    auxRecorrerABB(&(*raizArbol),&archivo);
    fprintf(archivo,"}");
    fclose(archivo);
}

void auxRecorrerABB(NODO** actual, FILE** archivo){
    if(*actual!=NULL){
        if((*actual)->izquierda==NULL && (*actual)->derecha==NULL){
            fprintf(*archivo, "%d",(*actual)->dato);
            fprintf(*archivo,";\n");
        }else{
            if((*actual)->izquierda!=NULL){
                fprintf(*archivo, "%d",(*actual)->dato);
                fprintf(*archivo," -> ");
                fprintf(*archivo, "%d",(*actual)->izquierda->dato);
                fprintf(*archivo,";\n");
                auxRecorrerABB(&(*actual)->izquierda,&(*archivo));
            }
            if((*actual)->derecha!=NULL){
                fprintf(*archivo, "%d",(*actual)->dato);
                fprintf(*archivo," -> ");
                fprintf(*archivo, "%d",(*actual)->derecha->dato);
                fprintf(*archivo,"[color=red];\n");
                auxRecorrerABB(&(*actual)->derecha,&(*archivo));
            }
        }
    }
}

/*---------------------------------------------- Recorridos ABB------------------------------------*/

void preOrdenABB(NODO** actual, FILE** archivo){

    if(*actual!=NULL){
        fprintf(*archivo, "<f0>%d|",(*actual)->dato);
    }
    if((*actual)->izquierda!=NULL){
        preOrdenABB(&(*actual)->izquierda,&(*archivo));
    }
    if((*actual)->derecha!=NULL){
        preOrdenABB(&(*actual)->derecha,&(*archivo));
    }
}

void inOrdenABB(NODO** actual, FILE** archivo){
    if((*actual)->izquierda!=NULL){
        inOrdenABB(&(*actual)->izquierda,&(*archivo));
    }
    if(*actual!=NULL){
        fprintf(*archivo, "<f0>%d|",(*actual)->dato);
    }
    if((*actual)->derecha!=NULL){
        inOrdenABB(&(*actual)->derecha,&(*archivo));
    }
}

void posOrdenABB(NODO** actual, FILE** archivo){
    if((*actual)->izquierda!=NULL){
        posOrdenABB(&(*actual)->izquierda,&(*archivo));
    }
    if((*actual)->derecha!=NULL){
        posOrdenABB(&(*actual)->derecha,&(*archivo));
    }
    if(*actual!=NULL){
        fprintf(*archivo, "<f0>%d|",(*actual)->dato);
    }
}

/*---------------------------------------------------------AVL-------------------------------------------------------------*/

int verificarEquilibrio(NODO** raiz, NODO** padre){
    int izquierda = 0;
    int derecha = 0;
    int factorEquilibrio = 0;
    NODO* nodo1 = *raiz;
    NODO* nodo2 = *raiz;

    if(*raiz!=NULL){
        if((*raiz)->izquierda==NULL && (*raiz)->derecha==NULL){
            return 1;
        }else{
            if((*raiz)->izquierda!=NULL){
                izquierda = verificarEquilibrio(&(*raiz)->izquierda,&(*raiz));
            }
            if((*raiz)->derecha!=NULL){
                derecha = verificarEquilibrio(&(*raiz)->derecha,&(*raiz));
            }

            factorEquilibrio = derecha - izquierda;
            printf("%d\n",factorEquilibrio);
            if(factorEquilibrio == 2 || factorEquilibrio == -2){

                // mandar el nodo** padre si no es nulo, si es nulo enviar raiz

                if((*raiz)->derecha==NULL && (*raiz)->izquierda->derecha==NULL){
                    // rotacion izquierda izquierda
                    nodo1 = (*raiz)->izquierda; // <-------- n1
                    (*raiz)->izquierda = nodo1->derecha;
                    nodo1->derecha = *raiz;
                    if(*padre==NULL){
                        raizAVL = nodo1;
                    }else if((*padre)->derecha==(*raiz)){
                        (*padre)->derecha = nodo1;
                    }else{
                        (*padre)->izquierda = nodo1;
                    }
                }else if((*raiz)->izquierda==NULL && (*raiz)->derecha->izquierda==NULL){
                    // rotacion derecha derecha
                    nodo1 = (*raiz)->derecha; // <-------- n1
                    (*raiz)->derecha = nodo1->izquierda;
                    nodo1->izquierda = *raiz;
                    if(*padre==NULL){
                        raizAVL = nodo1;
                    }else if((*padre)->derecha==(*raiz)){
                        (*padre)->derecha = nodo1;
                    }else{
                        (*padre)->izquierda = nodo1;
                    }
                }else if((*raiz)->derecha==NULL && (*raiz)->izquierda->izquierda==NULL){
                   // rotacion izquierda derecha
                    nodo1 = (*raiz)->izquierda;
                    nodo2 = (*raiz)->izquierda->derecha;
                    nodo1->derecha = nodo2->izquierda;
                    nodo2->izquierda = nodo1;
                    (*raiz)->izquierda = nodo2->derecha;
                    nodo2->derecha = *raiz;
                    if(*padre==NULL){
                        raizAVL = nodo2;
                    }else if((*padre)->derecha==(*raiz)){
                        (*padre)->derecha = nodo2;
                    }else{
                        (*padre)->izquierda = nodo2;
                    }

                }else if((*raiz)->izquierda==NULL && (*raiz)->derecha->derecha==NULL){
                    // rotacion derecha izquierda
                    nodo1 = (*raiz)->derecha;
                    nodo2 = (*raiz)->derecha->izquierda;
                    nodo1->izquierda = nodo2->derecha;
                    nodo2->derecha = nodo1;
                    (*raiz)->derecha = nodo2->izquierda;
                    nodo2->izquierda = *raiz;
                    if(*padre==NULL){
                        raizAVL = nodo2;
                    }else if((*padre)->derecha==(*raiz)){
                        (*padre)->derecha = nodo2;
                    }else{
                        (*padre)->izquierda = nodo2;
                    }
                }else if(factorEquilibrio==2){

                    if(*padre==NULL){
                        // rotacion derecha derecha
                        nodo1 = (*raiz)->derecha; // <-------- n1
                        (*raiz)->derecha = nodo1->izquierda;
                        nodo1->izquierda = *raiz;
                        raizAVL = nodo1;
                    }else if((*padre)->derecha==(*raiz)){
                        // rotacion derecha izquierda
                        nodo1 = (*raiz)->derecha;
                        nodo2 = (*raiz)->derecha->izquierda;
                        nodo1->izquierda = nodo2->derecha;
                        nodo2->derecha = nodo1;
                        (*raiz)->derecha = nodo2->izquierda;
                        nodo2->izquierda = *raiz;
                        (*padre)->derecha = nodo2;
                    }else{
                        // rotacion derecha izquierda
                        nodo1 = (*raiz)->derecha;
                        nodo2 = (*raiz)->derecha->izquierda;
                        nodo1->izquierda = nodo2->derecha;
                        nodo2->derecha = nodo1;
                        (*raiz)->derecha = nodo2->izquierda;
                        nodo2->izquierda = *raiz;
                        (*padre)->izquierda = nodo2;
                    }
                }else{
                    if(*padre==NULL){
                        // rotacion izquierda izquierda
                        nodo1 = (*raiz)->izquierda; // <-------- n1
                        (*raiz)->izquierda = nodo1->derecha;
                        nodo1->derecha = *raiz;
                        raizAVL = nodo1;
                    }else if((*padre)->derecha==(*raiz)){
                        // rotacion izquierda derecha
                        nodo1 = (*raiz)->izquierda;
                        nodo2 = (*raiz)->izquierda->derecha;
                        nodo1->derecha = nodo2->izquierda;
                        nodo2->izquierda = nodo1;
                        (*raiz)->izquierda = nodo2->derecha;
                        nodo2->derecha = *raiz;
                        (*padre)->derecha = nodo2;
                    }else{
                        // rotacion izquierda derecha
                        nodo1 = (*raiz)->izquierda;
                        nodo2 = (*raiz)->izquierda->derecha;
                        nodo1->derecha = nodo2->izquierda;
                        nodo2->izquierda = nodo1;
                        (*raiz)->izquierda = nodo2->derecha;
                        nodo2->derecha = *raiz;
                        (*padre)->izquierda = nodo2;
                    }
                }
                return 1025;
            }else{
                // retorno el mayor para obtener altura en el anterior
                if(izquierda > derecha){
                    return izquierda+1;
                }else{
                    return derecha+1;
                }
            }


        }
    }

    return 1025;
}

int eliminarAVL(int valor,NODO** actual, NODO** padre){
    if(*actual!=NULL){
        if((*actual)->dato==valor){
            if((*actual)->izquierda==NULL && (*actual)->derecha==NULL){
                if(*padre==NULL){
                    raizAVL = NULL;
                }else if((*padre)->izquierda==*actual){
                    (*padre)->izquierda = NULL;
                }else{
                    (*padre)->derecha = NULL;
                }
            }else if((*actual)->derecha==NULL && (*actual)->izquierda!=NULL){
                if(*padre!=NULL){
                    if((*padre)->izquierda==*actual){
                        (*padre)->izquierda=(*actual)->izquierda;
                    }else{
                        (*padre)->derecha=(*actual)->izquierda;
                    }
                }else{
                    raizAVL = (*actual)->izquierda;
                }

            }else if((*actual)->izquierda==NULL && (*actual)->derecha!=NULL){
                if(*padre!=NULL){
                    if((*padre)->izquierda==*actual){
                        (*padre)->izquierda=(*actual)->derecha;
                    }else{
                        (*padre)->derecha=(*actual)->derecha;
                    }
                }else{
                    raizAVL = (*actual)->derecha;
                }

            }else{
                NODO* temporal = (*actual)->derecha;
                while(temporal->izquierda!=NULL){
                    temporal = temporal->izquierda;
                }
                temporal->izquierda = (*actual)->izquierda;
                if(*padre!=NULL){
                    if((*padre)->izquierda==*actual){
                        (*padre)->izquierda=(*actual)->derecha;
                    }else{
                        (*padre)->derecha=(*actual)->derecha;
                    }
                }else{
                    raizAVL = (*actual)->derecha;
                }
                //free(*actual);
            }
            return 1;
        }else if(valor < (*actual)->dato){
            return eliminarABB(valor, &(*actual)->izquierda,&(*actual));
        }else if(valor > (*actual)->dato){
            return eliminarABB(valor, &(*actual)->derecha,&(*actual));
        }
    }
    return 0;
}
