#include "Archivos.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    int val, n, d, suma;
    FILE *p, *q, *r;
    Pas *arrpacien;
    do
    {   /*Menu principal*/
        printf("##########################################\n");
        printf("######## CAMARA HIPERBARICA BUIN #########\n");
        printf("##########################################\n");
        printf("1) Ordenar archivos de pacientes\n");
        printf("2) Agregar pacientes a un archivo creado\n");
        printf("3) Encontrar datos del paciente\n");
        /*Obtencion del numero, para elegir la opcion correspondiente*/
        printf("Elija una opcion: ");
        scanf("%d", &val);

        switch (val)
        {
        /*Caso en que se ordenaran los datos del archivo por Nombre, Rut, Fecha, Plan y valor*/
        case 1:
            /*Apertura y creacion de archivos*/
            p = abrirarchivoleer();
            q = abrirarchivoescrib();
            /*Obtencion del primer dato del archivo p que corresponde a la cantidad de pacientes*/
            fscanf(p,"%d", &n);
            /*Asignacion de memoria*/
            asignarmemoria(n);
            /*Asignacion de memoria de tipo Pas al arreglo de tipo Pas el cual contendra toda la informacion de los pacientes en forma de matriz*/
            arrpacien = (Pas*)malloc(sizeof(Pas)*n);
            /*Funcion que ordena los datos y crea el archivo donde estan categorizados*/
            ordenar_datos(p, q, n, arrpacien);
            /*Se cierran los archivos despues de su uso*/
            fclose(p);
            fclose(q);
            system("pause");
            break;
        
        /**/
        case 2:
            //obtener los datos de r y escribirlos en los de q pero con los nuevos datos
            r = abrirarchivoescrib();
            printf("Cuantos pacientes a%cadira:", 164);
            scanf("%d", &n);
            
            asignarmemoria(n);
            arrpacien = (Pas*)malloc(sizeof(Pas)*(n));

            escribirenelarchivo(r, n, arrpacien);
            fclose(r);
            system("pause");
            break;

        case 3:
        /**/
            p = abrirarchivoleer();
            fscanf(p,"%d", &n);
            asignarmemoria(n);
            arrpacien = (Pas*)malloc(sizeof(Pas)*n);
            encontrarpersona(p, n, arrpacien);
            fclose(p);
            system("pause");
            break;

        }system("cls");
    } while (val <= 3);
}


/*Nombre:
Rut:
Fecha:
Plan:
Valor:

Palan de 10 sesiones*/