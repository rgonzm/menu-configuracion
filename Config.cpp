#include <stdio.h>
#include <fstream>
#include <stdlib.h>
//#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
//using std::ofstream;
//using namespace std;
int Cantidad_Fases();
void Etapas_Fases(int numero_fases);
void Tiempos_Etapas(int numero_fases);
int seleccionador_etapas(char *c_etapas);



int main(){




char nombre[5];
char opcion_elegida[2];
int numero_fases=0;
string number;
printf("\n\n\nBienvenido a la interfaz de configuracion de tiempos y fases\n\n\n");
printf("¿Que desea configurar?\n\n\n");


	do{
	opcion_elegida[0]=0;
	printf("1.Cantidad de fases\n");
	printf("2.Etapas encendidas por fase\n");
	printf("3.Tiempos de las etapas\n");
	printf("\nPara salir presione s\n");
	scanf("%2s",opcion_elegida);
		printf("La opcion elegida es :%s\n",opcion_elegida);
		if(opcion_elegida[0]== 115){
		printf("\nHa salido de la configuracion, have a good day\n");
		break;
		}

		if((opcion_elegida[0] <= 48) | (opcion_elegida[0]> 51)){
		opcion_elegida[0]=0;
		printf("Opcion ingresada incorrecta,intente nuevamente\n");
		}

		if( opcion_elegida[0] == 49 ){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nA elegido Cantidad de fases\n");
		numero_fases=Cantidad_Fases();
		opcion_elegida[0]=0;
		}
		if(opcion_elegida[0] == 50){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nA elegido etapas encendidas por fase\n");
		Etapas_Fases(numero_fases);
                opcion_elegida[0]=0;

		}
		if(opcion_elegida[0] == 51){
		printf("A elegido tiempos de las etapas\n");
		Tiempos_Etapas(numero_fases);
                opcion_elegida[0]=0;

		}

	}while(opcion_elegida[0]==0);


scanf("%4s",nombre);
ofstream archivo;
archivo.open("Nombre.txt");
archivo << nombre;
//open archivo;
//archivo.open("nombre.txt");
printf("El nombre que ingreso es: %s\n",nombre);
archivo.close();
//cin.get(nombre);
return 0;

}


int Cantidad_Fases(){
 char c_fases[5];
 char salida_conf=0;
 int prueba;
// int fases;
	do{
	printf("\nIngrese la cantidad de fases del cruce de, 1-5 fases\n");
 	scanf("%s",c_fases);
	prueba=atoi(c_fases);
		if((prueba >=1) & (prueba <= 5)){
 		printf("\n\n\nUsted a ingresado %d, cantidad de fases\n\n\n\n",prueba);
		printf("\nSi es correcto presione s, para salir de este menu\n");
		printf("Si es incorrecto presione n, para configurar nuevamente\n");
		scanf("%s",&salida_conf);
		}
		if(((prueba < 1) | (prueba >5) | (prueba==0)) & (salida_conf !=115)){
		printf("\nValor de fases ingresado incorrecto\n");
		}
	}while(salida_conf != 115);
// fases=c_fases[0];
 return prueba;
}

void Etapas_Fases(int numero_fases){
 char c_etapas[15];
 char control_salida=0;
 int fases_ingresadas=numero_fases;
 int error=0;
	do{
		if(numero_fases !=0){
			do{
			printf("\nIngrese las etapas activas de la etapa %d\n",numero_fases);
			printf("\n\nTenga en consideracion de ingresar las etapas de la siguiente manera:A-B-C-D-E-F-G-H\n");
			scanf("%s",c_etapas);
			printf("Usted a ingresado %s\n",c_etapas);
			error=seleccionador_etapas(c_etapas);
			}while(error==1);
		}
		numero_fases--;

		if(numero_fases ==-1){
		printf("\nNo se han ingresado fases, presione s para salir\n");
		scanf("%s",&control_salida);
		}
		if(numero_fases ==0){
		printf("\nSe han configurado correctamente las etapas activas por fase\n");
		printf("\nPresione s para salir o n para configurar nuevamente\n");
		scanf("%s",&control_salida);
		numero_fases=fases_ingresadas;
		}
	}while(control_salida!=115);
}

void Tiempos_Etapas(int numero_fases){
 char control_salida=0;
 char Tiempos_delay[30];
 char Tiempos_amarillo[30];
 char Tiempos_rr[30];
 int fases_activas=numero_fases;
 char nombre_1[5];
 char nombre_2[6];
 char nombre_3[6];
 int contador_aux=0;
 nombre_1[0]='D';
 nombre_1[1]='E';
 nombre_1[2]='L';
 nombre_1[3]='A';
 nombre_1[4]='Y';

 nombre_2[0]='A';
 nombre_2[1]='M';
 nombre_2[2]='A';
 nombre_2[3]='R';
 nombre_2[4]='I';

 nombre_3[0]='R';
 nombre_3[1]='O';
 nombre_3[2]='J';
 nombre_3[3]='O';
 nombre_3[4]='R';

	for(int i=0;i<30;i++){
	Tiempos_delay[i]=0;
	Tiempos_amarillo[i]=0;
	Tiempos_rr[i]=0;
	}
	do{
	printf("\n\n\n\n\nBienvenido al programador del tiempo \n");
	printf("\nEn esta seccion se podra seleccionar el tiempo de cambio de fase\n");
	printf("Es importante destacar que la matriz se llena de izquierda a derecha y de arriba hacia abajo\n");
//	usleep(10000);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("       ");
	for(int i=0;i<5;i++){
	printf(" %c ",nombre_1[i]);
	}
	printf(" ");
        for(int i=0;i<5;i++){
        printf(" %c ",nombre_2[i]);
        }
        printf(" ");
        for(int i=0;i<5;i++){
        printf(" %c ",nombre_3[i]);
        }
	printf("\n");
        printf("       ");
	for(int j=0;j<3;j++){
		for(int i=0;i<fases_activas;i++){
		printf(" %d ",numero_fases);
		numero_fases--;
		}
	printf(" ");
	numero_fases=fases_activas;
	}
        printf("\n");
        printf("       ");
	for(int j=0;j<3;j++){
		for(int i=0;i<fases_activas;i++){
		printf(" %d ",Tiempos_delay[i]);
		contador_aux++;
		}

	}

	printf("\n\n\n\n\nPara salir presione s\n");
	scanf("%s",&control_salida);
	}while(control_salida ==115);
}


int seleccionador_etapas(char *c_etapas){
int largo=0;
char etapas_activas[1];
etapas_activas[0]=0;
etapas_activas[1]=0;
int fallo_etapas=0;


	for(int i=0;c_etapas[i] != '\0';i++){
	largo++;
	}

	for(int i=0;i<largo;i=i+2){
//		if(c_etapas[i] == 'A'){
//		etapas_activas[0]=etapas_activas[0] | 0x01;
//		}
		switch(c_etapas[i]){
		case 'A':
                etapas_activas[0]=etapas_activas[0] | 0x01;
                fallo_etapas=2;
		break;
		case 'B':
                etapas_activas[0]=etapas_activas[0] | 0x02;
                fallo_etapas=2;
		break;
                case 'C':
                etapas_activas[0]=etapas_activas[0] | 0x04;
                fallo_etapas=2;
                break;
                case 'D':
                etapas_activas[0]=etapas_activas[0] | 0x08;
                fallo_etapas=2;
                break;
                case 'E':
                etapas_activas[0]=etapas_activas[0] | 0x10;
                fallo_etapas=2;
                break;
                case 'F':
                etapas_activas[0]=etapas_activas[0] | 0x20;
                fallo_etapas=2;
                break;
                case 'G':
                etapas_activas[0]=etapas_activas[0] | 0x40;
                fallo_etapas=2;
                break;
                case 'H':
                etapas_activas[0]=etapas_activas[0] | 0x80;
                fallo_etapas=2;
                break;

		default:
		printf("Error en indentificar  las etapas\n");
		fallo_etapas=1;
		break;




		}

	}

printf("En la funcion esta %x y largo %d finalmente las etapas activas son:%x\n",c_etapas[0],largo,etapas_activas[0]);
return fallo_etapas;

}
