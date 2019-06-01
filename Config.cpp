#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;

//using std::ofstream;
//using namespace std;
int Cantidad_Fases();

void Etapas_Fases(int numero_fases);

void Tiempos_Etapas(int numero_fases);

int seleccionador_etapas(char *c_etapas);

int main() {

//    char nombre[5];
    char opcion_elegida[2];
    int numero_fases = 0;
    string number;
    printf("\n\n\nBienvenido a la interfaz de configuracion de tiempos y fases\n\n\n");
    printf("¿Que desea configurar?\n\n\n");

    do {
        opcion_elegida[0] = 0;
        printf("1.Cantidad de fases\n");
        printf("2.Etapas encendidas por fase\n");
        printf("3.Tiempos de las etapas\n");
        printf("\nPara salir presione s\n");
        scanf("%2s", opcion_elegida);
        printf("La opcion elegida es :%s\n", opcion_elegida);
        if (opcion_elegida[0] == 115) {
            printf("\nHa salido de la configuracion, have a good day\n");
            break;
        }

        if ((opcion_elegida[0] <= 48) | (opcion_elegida[0] > 51)) {
            opcion_elegida[0] = 0;
            printf("Opcion ingresada incorrecta,intente nuevamente\n");
        }

        if (opcion_elegida[0] == 49) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nA elegido Cantidad de fases\n");
            numero_fases = Cantidad_Fases();
            opcion_elegida[0] = 0;
        }
        if (opcion_elegida[0] == 50) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nA elegido etapas encendidas por fase\n");
            Etapas_Fases(numero_fases);
            opcion_elegida[0] = 0;
        }
        if (opcion_elegida[0] == 51) {
            printf("A elegido tiempos de las etapas\n");
            Tiempos_Etapas(numero_fases);
            opcion_elegida[0] = 0;
        }

    } while (opcion_elegida[0] == 0);

//	scanf("%4s", nombre);
//	ofstream archivo;
//	archivo.open("Nombre.txt");
//	archivo << nombre;
//	//open archivo;
//	//archivo.open("nombre.txt");
//	printf("El nombre que ingreso es: %s\n", nombre);
//	archivo.close();
    //cin.get(nombre);
    return 0;
}

int Cantidad_Fases() {
    char c_fases[5];
    char salida_conf = 0;
    int prueba;
    // int fases;
    do {
        printf("\nIngrese la cantidad de fases del cruce de, 1-8 fases\n");
        scanf("%s", c_fases);
        prueba = atoi(c_fases);
        if ((prueba >= 1) & (prueba <= 8)) {
            printf("\n\n\nUsted a ingresado %d, cantidad de fases\n\n\n\n", prueba);
            printf("\nSi es correcto presione s, para salir de este menu\n");
            printf("Si es incorrecto presione n, para configurar nuevamente\n");
            scanf("%s", &salida_conf);
        }
        if (((prueba < 1) | (prueba > 8) | (prueba == 0)) & (salida_conf != 115)) {
            printf("\nValor de fases ingresado incorrecto\n");
        }
    } while (salida_conf != 115);
    // fases=c_fases[0];
    return prueba;
}

void Etapas_Fases(int numero_fases) {
    char c_etapas[20];
    char control_salida = 0;
    int fases_ingresadas = numero_fases;
    int error = 0;
    do {
        if (numero_fases != 0) {
            do {
                printf("\nIngrese las etapas activas de la fase %d\n", numero_fases);
                printf("\n\nTenga en consideracion de ingresar las etapas de la siguiente manera:A-B-C-D-E-F-G-H\n");
                scanf("%s", c_etapas);
                printf("Usted a ingresado %s\n", c_etapas);
                error = seleccionador_etapas(c_etapas);
            } while (error == 1);
        }
        numero_fases--;

        if (numero_fases == -1) {
            printf("\nNo se han ingresado fases, presione s para salir\n");
            scanf("%s", &control_salida);
        }
        if (numero_fases == 0) {
            printf("\nSe han configurado correctamente las etapas activas por fase\n");
            printf("\nPresione s para salir o n para configurar nuevamente\n");
            scanf("%s", &control_salida);
            numero_fases = fases_ingresadas;
        }
    } while (control_salida != 115);
}

void Tiempos_Etapas(int numero_fases) {
    char control_salida = 0;
    int fases_activas = numero_fases;
    int matriz[18][18];
    char aux_numero[1];
    char tiempo_luz_a[1];
//    int aux_salida=0;
    int error_ingreso=0;
    char error[2];
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            matriz[i][j] = '0';
        }
    }

    matriz[0][2] = 'D';
    matriz[0][3] = 'E';
    matriz[0][4] = 'L';
    matriz[0][5] = 'A';
    matriz[0][6] = 'Y';
    matriz[0][7] = 'D';
    matriz[0][8] = 'E';
    matriz[0][9] = 'C';
    matriz[0][10] = 'R';
    matriz[0][11] = 'O';
    matriz[0][12] = 'J';
    matriz[0][13] = 'O';
    matriz[0][14] = 'R';
    matriz[0][15] = 'O';
    matriz[0][16] = 'J';
    matriz[0][17] = 'O';


    matriz[2][0] = 'D';
    matriz[3][0] = 'E';
    matriz[4][0] = 'L';
    matriz[5][0] = 'A';
    matriz[6][0] = 'Y';
    matriz[7][0] = 'D';
    matriz[8][0] = 'E';
    matriz[9][0] = 'C';
    matriz[10][0] = 'R';
    matriz[11][0] = 'O';
    matriz[12][0] = 'J';
    matriz[13][0] = 'O';
    matriz[14][0] = 'R';
    matriz[15][0] = 'O';
    matriz[16][0] = 'J';
    matriz[17][0] = 'O';


    int aux = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 1 + aux; j <= 8 + aux; j++) {
            if (j - aux <= fases_activas) {
                char result = (j - aux);
                matriz[1][j+1] = result+48;
            }else {
		for(int k = 1;k<18;k++){
                matriz[k][j+1] = '-';
		}
            }


            if (j - aux <= fases_activas) {
                char result = (j - aux);
                matriz[j+1][1] = result+48;
            }else {
                for(int k = 1;k<18;k++){
                matriz[j+1][k] = '-';
		}
            }




        }
        aux = aux + 8;
    }






	printf("Ingrese el valor de tiempo de la luz amarilla\n");
        scanf("%s",tiempo_luz_a);
	printf("el tiempo que ingreso vale: %d",tiempo_luz_a[0]);

	int auxiliar=0;

	for(int j=0;j<2;j++){
			for (int i = 2; i < 18; i++) {
			matriz[i+auxiliar][i] = '-';
			}
	auxiliar=auxiliar+8;
	}

	for(int i=2;i<10;i++){
	matriz[i][i+8]='-';
	}




    do {
        printf("\n\n\n\n\nBienvenido al programador del tiempo \n");
        printf("\nEn esta seccion se podra seleccionar el tiempo de cambio de fase\n");
        printf("Es importante destacar que la matriz se llena de izquierda a derecha y de arriba hacia abajo\n");

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("El valor en tiempo de encendido de la luz amarilla es de:%d segundos\n\n\n",tiempo_luz_a[0]-48);
        for (int fila = 0; fila < 18; fila++) {
            for (int columna = 0; columna < 18; columna++) {
//		  sprintf(buffer,"%d",matriz[fila][columna]);
//		  printf("|");

                  printf(" %c ", matriz[columna][fila]);
//		  printf(" %c ",buffer[fila]);
            }
            printf("\n\n");
        }

	if(error_ingreso >= 1){
	printf("Los tiempos ingresados son correctos Y/N\n");
	scanf("%1s",error);
	printf("lo ingresado es: %d\n",error[0]);
		if(error[0]==78){
                printf("Ingrese los valores nuevamente\n");

		error_ingreso--;
			for(int fila=2+error_ingreso;fila< 3+error_ingreso;fila++){
				for(int columna = 2;columna < 18;columna++){
					if(matriz[columna][fila] != '-'){
					 matriz[columna][fila]='0';
					}
				}
			}

		printf("error de ingreso es: %d\n",error_ingreso);
		}else{
		printf("Seleccione los valores para la siguiente fila\n");
		}
	}
//	do{

        for (int fila=2+error_ingreso; fila < 3+error_ingreso; fila++) {
            for (int columna = 2; columna < 18; columna++) {
			if(matriz[columna][fila]=='0'){
				do{
					if(columna <= 9){
				printf("Ingrese el valor del tiempo del  delay en segundos que va desde la fase,%d hacia la fase,%d\n",fila-1,columna);
				scanf("%s",aux_numero);
				matriz[columna][fila]=aux_numero[0];
					}
                                        if(columna > 9){
                                printf("Ingrese el valor del tiempo del rojo-rojo que va desde la fase,%d hacia la fase,%d en segundos\n",fila-1,columna);
                                scanf("%s",aux_numero);
                                matriz[columna][fila]=aux_numero[0];
                                        }

				if((aux_numero[0]<48) | (aux_numero[0]>57)){

                                printf("Ingrese un numero porfavor\n");

				}

				}while((aux_numero[0] <= 48) | (aux_numero[0] >= 57));
//				printf("sali\n");
			}
            }
            printf("\n\n");
        }






	error_ingreso++;
//	}while(aux_salida != 10);

//	if(aux_salida == 17){
        printf("\n\n\n\n\nPara salir presione s, para seguir configurando presione n\n");
        scanf("%s", &control_salida);
//	}
    } while (control_salida != 115);
}

int seleccionador_etapas(char *c_etapas) {
    int largo = 0;
    char etapas_activas[1];
    etapas_activas[0] = 0;
    etapas_activas[1] = 0;
    int fallo_etapas = 0;

    for (int i = 0; c_etapas[i] != '\0'; i++) {
        largo++;
    }
    c_etapas[largo]='-';
    for (int i = 0; i < largo; i = i + 2) {
        //		if(c_etapas[i] == 'A'){
        //		etapas_activas[0]=etapas_activas[0] | 0x01;
        //		}
        switch (c_etapas[i]) {
            case 'A':
		if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x01;
                fallo_etapas = 2;
		}else{
		printf("Fallo en el ingreso de etapas activas\n");
		fallo_etapas =1;
		}
                break;
            case 'B':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x02;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;
            case 'C':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x04;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;
            case 'D':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x08;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;
            case 'E':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x10;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;
            case 'F':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x20;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;
            case 'G':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x40;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;
            case 'H':
                if(c_etapas[i+1]=='-'){
                etapas_activas[0] = etapas_activas[0] | 0x80;
                fallo_etapas = 2;
                }else{
                printf("Fallo en el ingreso de etapas activas\n");
                fallo_etapas =1;
                }
                break;

            default:
                printf("Error en indentificar  las etapas\n");
                fallo_etapas = 1;
                break;
        }
    }

    printf("En la funcion esta %x y largo %d finalmente las etapas activas son:%x\n", c_etapas[0], largo,
           etapas_activas[0]);
    return fallo_etapas;
}
