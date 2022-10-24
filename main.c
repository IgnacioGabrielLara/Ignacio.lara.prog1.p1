#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

float aplicarAumento(float numeroIngresado);

int reemplazarCaracter(char cadena [], char caracter, char caracterDos);


typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;


int ordenarVacuna(eVacuna list[], int tam);

int main()
{
    //---------------------------------------------------

    eVacuna vacuna[TAM];

    int id[4]={10, 11, 12, 13};
    char nombre[4][20]={"SPUTVNIK", "ASTRASENECA", "MODERNA","PFIZER"};
    char tipoChar[4] = {'a','b','s','a'};
    float efectiva [4]= {90.8, 80.5, 60.4, 75.4};

    for(int i=0; i<TAM; i++)
    {
        vacuna[i].id= id[i];
        strcpy(vacuna[i].nombre, nombre[i]);
        vacuna[i].tipo=tipoChar[i];
        vacuna[i].efectividad= efectiva[i];
    }

    ordenarVacuna(vacuna, TAM);

    for(int i=0; i<TAM; i++)
    {
        printf("%d %s %c %.2f\n ", vacuna[i].id, vacuna[i].nombre, vacuna[i].tipo, vacuna[i].efectividad);
    }
    return 0;


    //----------------------------------------

    float numero = 20;

    float numeroConAumento = aplicarAumento(numero);

    printf("%.2f", numeroConAumento);

    //-------------------------------------


}


float aplicarAumento(float numeroIngresado)
{

    float aumento = 0;
    float resultado = 0;

    if(numeroIngresado>0)
    {

        aumento=(numeroIngresado * 5)/100;
        resultado = numeroIngresado + aumento;
    }
    return resultado;
}

int reemplazarCaracter(char cadena [], char caracter, char caracterDos)
{
    int contador=0;
    char aux;

    if(cadena!= NULL)
    {
        for(int i=0; i<strlen(cadena); i++)
        {
            if(cadena[i]==caracter)
            {
                aux = caracter;

                if(cadena[i] == caracterDos)
                {
                    caracterDos = aux;
                    contador++;
                }
            }
        }
    }

    return contador;
}

int ordenarVacuna(eVacuna list[], int tam)
{
    if(list!= NULL && tam>0)
    {
       eVacuna aux;

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

                if(strcmp(list[i].tipo, list[j].tipo) > 0)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                else if(strcmp(list[i].tipo, list[j].tipo) == 0 && strcmp(list[i].efectividad, list[j].efectividad) < 0){
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }
        }
    }
}
