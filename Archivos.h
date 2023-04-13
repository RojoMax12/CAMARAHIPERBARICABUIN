#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>



typedef struct Paciente
{   char nombres[30], rut[12];
    int plan, valor,dia, mes, ano;
}Pas;


FILE *abrirarchivoleer();
FILE *abrirarchivoescrib();
FILE *abrirarchivosobrescribir();

Pas *asignarmemoria(int n);;

void ordenar_datos(FILE *p, FILE *q, int n, Pas *arrpas);
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

FILE *abrirarchivoescrib(){
  FILE *p;
  char nombre[30];
  printf("Ingrese el nombre del archivo de salida: ");
  scanf("%s", nombre);
  p = fopen(nombre, "w+");
  if(p != NULL){
    printf("El archivo a sido correctamente creado\n");
  }
  else{
    printf("Error al crear el archivo el archivo\n");
  }
  return p;
}

FILE *abrirarchivosobrescribir(){
  FILE *p;
  char nombre[30];
  printf("Ingrese el nombre del archivo: ");
  scanf("%s", nombre);
  p = fopen(nombre, "a+");
  if(p != NULL){
    printf("El archivo a sido correctamente abierto para escribir\n");
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


void ordenar_datos(FILE *p, FILE *q, int n, Pas *arrpas){
    int i = 0;
    while(fscanf(p,"%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor)!=EOF)
    {
      fprintf(q,"\nNombre: %s Rut: %s Fecha: %d/%d/%d Plan: %d sesiones Valor:$ %d",arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, arrpas[i].mes, arrpas[i].ano, arrpas[i].plan, arrpas[i].valor);
      i++;
    }
}

void escribirenelarchivo(FILE *p, int n, Pas *arrpas){
  int i = 0, count = 0;
  while (fscanf(p,"%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor)!= EOF)
  { i++;
    count++;
  }
  fprintf(p, "%d", count + n);
  /*
  for (int i = 0; i <= n - 1; i++)
  {
  fscanf(p,"%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor);
  fprintf(p,"\n %s %s %d %d %d %d %d",arrpas[i].nombres, arrpas[i].rut, arrpas[i].dia, arrpas[i].mes, arrpas[i].ano, arrpas[i].plan, arrpas[i].valor);
  
  printf("Ingrese los datos del paciente de la siguiente manera (NombreApellido RutSinPutosYconGuion Dia Mes Año PlanElCualEligio ValorDelPlan) ");
  scanf("%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor);
  fprintf(p,"\n %s %s %d %d %d %d %d",arrpas[i].nombres, arrpas[i].rut, arrpas[i].dia, arrpas[i].mes, arrpas[i].ano, arrpas[i].plan, arrpas[i].valor);
  }*/
}

void encontrarpersona(FILE *p, int n, Pas *arrpas){
    char rut[12];
    int cont = 0;
    printf("Ingrese el rut del paciente que desea buscar: ");
    scanf("%s", rut);
    for(int i = 0; i <= n - 1; i++)
    {
      fscanf(p,"%s %s %d %d %d %d %d", arrpas[i].nombres, arrpas[i].rut, &arrpas[i].dia, &arrpas[i].mes, &arrpas[i].ano, &arrpas[i].plan, &arrpas[i].valor);
      if(strcmp(rut, arrpas[i].rut) == 0)
      {
        printf("Nombre: %s Fecha: %d/%d/%d Plan: %d sesiones Valor:$%d\n",arrpas[i].nombres, arrpas[i].dia, arrpas[i].mes, arrpas[i].ano, arrpas[i].plan, arrpas[i].valor);
        cont = 1;
      }
      
    }
    
}