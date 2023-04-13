# Manual de manejo del programa :tw-1f4e2: :tw-1f4e2:

Este proyecto fue solcitido por un integrante de Camaras Hiperbaricas Buin con la finalidad de optimizar el conteo de pacientes y los pagos recibidos por ellos.

###1) PASO 1
Vamos a abrir el archivo CAMARAHIPERBARICABUIN.exe
![](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExMGE2ZDEwNWY3ZjhlMGFmZjk2ZTNhNDEyNjUxNTQ1MTMxZmE4ZTJmMSZjdD1n/aVQbUYaFdQMnwhmUke/giphy.gif)

###2)PASO 2
Ya abierto nuestro programa, elegiremos entre las 3 opciones que contiene:
1. Agregar pacientes a un archivo creado o crear el archivo y agregar los pacientes
2. Encontrar los datos del paciente a travez del rut
3. Salir del programa

![](https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExNGNlMTk1OTAyNThhZGE3MzhlYjRjZTY1MTlkNjcyMDRmNTVhY2ZiZCZjdD1n/O1AB53mYHq6WhDl5jd/giphy.gif)
####2.1) OPCION 1
Esta opcion le solicitara al usuario el nombre de un archivo de preferencia .txt dentro de la carpeta donde esta situado el programa o el nombre del archivo que desea crear con ese nombre. El nombre del archivo se debe ingresar con el siguiente formato para que sea efectiva la apertura del archivo, si no, no se abrira este.

    "(Nombre del archivo).txt"

Despues se le solicitara al usuario que ingrese la cantidad de pacientes que desea ingresar al archivo. Finalizado esto se le pedira que ingrese los datos del paciente como:
- NombreApellido
- Rut sin puntos y con guion
- Dia (numerico)
- Mes (numerico)
- Año (numerico)
- Plan de sesiones que escojio el paciente (numerico)
- El valor del plan de las sesiones (numerico)

Por lo tanto en la aplicacion se debe ingresar en el siguiente formato:
```c
"NombreApellido xxxxxxxx-x dia mes año sesiones valor"
```

##### EJEMPLO
Deseo ingresar al paciente Benito Aralla el cual tiene como datos:
- BenitoAralla
- 12345678-9
- 10
- 11
- 2023
- 10
- 250000

Ya que se escogio la opcion 1 y se escogio el nombre del archivo ingresaremos lo datos del paciente de la siguiente manera:

```c
"BenitoArralla 12345678-9 10 11 2023 10 250000"
```
Si los datos fueron ingresados correctamente el paciente ya se encontrara en el archivo.

####2.2)OPCION 2
Esta opcion se le solicitara al usuario el nombre del archivo .txt que deseara abrir para encontrar los datos del paciente. Por otra parte se le solicitara al usuario que ingrese el rut del paciente que desea buscar, se debera ingresar de la siguiente manera:

```c
" xxxxxxxx-x "
```
Sin puntos y con el guion. Ya ingresado el rut del paciente se mostrara por pantalla los siguiente:

```c
" Nombre: NombreApellido Fecha: dia mes año Plan: sesiones Valor: $valor "
```

Se mostrara cuantas veces este registrado por rut el paciente en nuestro archivo.

####2.3)OPCION 3
Esta opcion no tiene como otra finalidad de cerrar el programa