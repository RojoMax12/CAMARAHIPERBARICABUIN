#include "Archivos.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    int val, n, d, suma;
    FILE *p, *r;
    Pas *arrpacien;
    do
    {   /*Menu principal*/
        printf("##########################################\n");
        printf("######## CAMARA HIPERBARICA BUIN #########\n");
        printf("##########################################\n");
        printf("1) Agregar pacientes a un archivo creado\n");
        printf("2) Encontrar datos del paciente\n");
        /*Obtencion del numero, para elegir la opcion correspondiente*/
        printf("Elija una opcion: ");
        scanf("%d", &val);

        switch (val)
        {        
        case 1:
            //obtener los datos de r y escribirlos en los de q pero con los nuevos datos
            r = abrirarchivosobrescribir();
            printf("Cuantos pacientes a%cadira:", 164);
            scanf("%d", &n);

            //Asigna memeria de acuerdo a la cantidad de pacientes que se agregaran al archivo
            asignarmemoria(n);
            arrpacien = (Pas*)malloc(sizeof(Pas)*(n));

            escribirenelarchivo(r, n, arrpacien);
            fclose(r);
            system("pause");
            break;

        case 2:
            //Encuentra los datos registrados del paciente en el archivo creado
            p = abrirarchivoleer();
            encontrarpersona(p, n, arrpacien);
            fclose(p);
            system("pause");
            break;

        }system("cls");
    } while (val <= 2);
}


/*Nombre:
Rut:
Fecha:
Plan:
Valor:

Palan de 10 sesiones*/