#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;

}eVacuna;

/*1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto
y devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main.*/
float aplicarAumento(float precio);

/*2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres
como primer parámetro, un carácter como segundo y otro carácter  como tercero, la misma deberá
reemplazar cada ocurrencia del segundo parámetro por el tercero y devolver la cantidad de veces
que se reemplazo ese carácter  en la cadena*/
int reemplazarCaracteres(char cadena[], char caracter1, char caracter2);

/*3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura
por tipo. Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main.*/
int ordenarArray(eVacuna aVacuna[], int tam);

int main()
{
   float precio = 200.45;
   float aumentoAplicado;

   eVacuna aVacuna[TAM] =
   {
       {100,"Sputnik",'v',18},
       {101,"Astracenica",'a',19},
       {102,"Sputinik",'v',14},
       {103,"Gripe",'x',10}
   };

   aumentoAplicado = aplicarAumento(precio);
   printf("El precio del producto %.2f se le aplico un aumento del 5%% es: %.2f\n",precio,aumentoAplicado);

    for(int i=0; i<TAM; i++)
    {
        printf(" %2d |   %10s    |  %c   | %3.2f |\n",aVacuna[i].id,aVacuna[i].nombre,aVacuna[i].tipo,aVacuna[i].efectividad);
    }
    printf("\n");

    ordenarArray(aVacuna,TAM);

    for(int i=0; i<TAM; i++)
    {
        printf(" %2d |   %10s    |  %c   | %3.2f |\n",aVacuna[i].id,aVacuna[i].nombre,aVacuna[i].tipo,aVacuna[i].efectividad);
    }
    printf("\n");
   return 0;
}

float aplicarAumento(float precio)
{
    float aumento = -1;

    if(precio > 0)
    {
        aumento = precio + ((precio*5)/100);
    }

    return aumento;
}

int ordenarArray(eVacuna aVacuna[], int tam)
{
    int todoBien = 0;

    eVacuna auxVacuna;

    if(aVacuna != NULL && tam > 0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

                if(aVacuna[i].tipo > aVacuna[j].tipo || ( aVacuna[i].tipo == aVacuna[j].tipo && aVacuna[i].efectividad > aVacuna[j].efectividad))
                {
                    auxVacuna = aVacuna[i];
                    aVacuna[i] = aVacuna[j];
                    aVacuna[j] = auxVacuna;
                }
            }
        }
        todoBien = 1;
    }

    return todoBien;
}
