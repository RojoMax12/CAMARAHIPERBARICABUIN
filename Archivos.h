#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

/*Estructura para clasificar a los pacientes tomando su nombre, rut, dia/mes/año, el plan que tomo y el valor de este*/
typedef struct Paciente
{   char nombres[30], rut[12];
    int plan, valor,dia, mes, ano;
}Pas;

/*Funciones creadas para los archivos*/
FILE *abrirarchivoleer();
FILE *abrirarchivosobrescribir();

/*Funciones para asignar memoria a la estructura Tipo paciente*/
Pas *asignarmemoria(int n);;

/*Funciones que se utilizaran para las diferentes opciones del pograma*/
void escribirenelarchivo(FILE *p, int n, Pas *arrpas);
void encontrarpersona();


FILE *abrirarchivoleer(){
  FILE *p;
  char nombre[30];
  printf("Ingrese el nombre del archivo que desea abrir: ");
  scanf("%s", nombre);
  p = fopen(nombre, "r");
  if(p != NULL){
    printf("El archivo a sido correctamente abierto\n");
  }
  else{
    printf("Error al abrir el archivo\n");
  }
  return p;
}

FILE *abrirarchivosobrescribir(){
  FILE *p;
  char nombre[30];
  printf("Ingrese el nombre del archivo que desea crear o desea abrir para a%cadir pacientes: ",164);
  scanf("%s", nombre);
  p = fopen(nombre, "a");
  if(p != NULL){
    printf("El archivo a sido correctamente abierto para a%cadir\n", 164);
  }
  else{
    printf("Error al abrir el archivo el archivo\n");
  }
  return p;
}

Pas *asignarmemoria(int n){
    Pas *a;
    a = (Pas*)malloc(sizeof(Pas)*n);
    for (int i = 0; i <= n - 1; i++)
    {
    a->nombres[i] = 0;
    a->rut[i] = 0;
    }
    a->plan = 0;
    a->valor = 0;
    a->ano = 0;
    a->dia = 0;
    a->mes = 0;
    return a;    
}

/*Funcion que escribe los datos del paciente en la linea final del archivo*/
void escribirenelarchivo(FILE *p, int n, Pas *arrpas){
  for (int i = 0; i <= n - 1; i++)
    { 
    printf("Ingrese los datos del paciente de la siguiente manera (NombreApellido RutSinPutosYconGuion Dia Mes A%co PlanElCualEligio ValorDelPlan):  ", 164);
    scanf("%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor);
    fprintf(p,"\n%s %s %d %d %d %d %d",arrpas[i].nombres, arrpas[i].rut, arrpas[i].dia, arrpas[i].mes, arrpas[i].ano, arrpas[i].plan, arrpas[i].valor);
    printf("Datos del paciente ingresados correctamente\n");
    }
}

/*Funcion que busca en el archivo al paciente por su rut e imprime sus datos por pantalla*/
void encontrarpersona(FILE *p, int n, Pas *arrpas){
    char rut[12], ca[50];
    int cont = 0, con2 = 0;
    while (!feof(p))
    {
    fgets(ca, 50, p);
    con2++;
    }

    rewind(p);
    asignarmemoria(con2);
    arrpas = (Pas*)malloc(sizeof(Pas)*con2);

    printf("Ingrese el rut del paciente que desea buscar: ");
    scanf("%s", rut);
    for(int i = 0; i <= con2 - 1; i++)
    {
      fscanf(p,"%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor);
      if(strcmp(rut, arrpas[i].rut) == 0)
      {
        printf("Nombre: %s Fecha: %d/%d/%d Plan: %d sesiones Valor:$%d\n",arrpas[i].nombres, arrpas[i].dia, arrpas[i].mes, arrpas[i].ano, arrpas[i].plan, arrpas[i].valor);
        cont = 1;
      }
      
    }
    if (cont == 0)
    {
      printf("No existe el paciente\n");
    }  
}
