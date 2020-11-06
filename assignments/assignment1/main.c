
/****************************************
*	TITLE: Projeto 01 - Manipulação de arquivos
*	AUTHOR: David S. Costa		
*	DESCRIPTTION: Projeto 01 da disciplina ATP2, 
*	Leitura de um arquivo seno e aproximação dos valores cosseno e radiano correspondentes.
*****************************************/

#include <stdio.h>
#include <stdlib.h>

/* Declaração de constantes */
#define PI 3.141592653589793
#define FILE_STREAM_DEGREES_QUANTITY 91

/* Protótipos de funções */

// Converte graus para radianos
double degreesToRadians(double degree);

// Faz a leitura da tabela trigonométrica (grau, seno, cosseno) para angulos de 0º a 90º
void readTable(FILE* stream, int *tableDegrees, double *tableSin, double *tableCos);


int main() {

	// Streams de arquivos 
	FILE* inputStream = fopen("seno.txt", "r");
	FILE* trigoStream = fopen("trigo.txt", "r"); 
	FILE* outputStream = fopen("senocosseno.txt", "w");

	// Estruturas para armazenamento de valores da tabela trigo.txt
	int tableDegrees[FILE_STREAM_DEGREES_QUANTITY];
	double tableSin[FILE_STREAM_DEGREES_QUANTITY];
	double tableCos[FILE_STREAM_DEGREES_QUANTITY];

	// Leitura da tabela trigo.txt
	readTable(trigoStream, tableDegrees, tableSin, tableCos);
	fclose(trigoStream);

	while(!feof(inputStream)) {
		//Leitura de um seno da tabela
		double streamSin;
		fscanf(inputStream, "%lf\n", &streamSin);
	
		int i;
		double radApproximation;

		for(i = 0; i < FILE_STREAM_DEGREES_QUANTITY; i++) {
			if(streamSin == tableSin[i]) {
				radApproximation = degreesToRadians(tableDegrees[i]);

				fprintf(outputStream, "%.5lf %.5lf %.5lf\n", radApproximation, streamSin, tableCos[i]);
				break;
			}
			else if(streamSin < tableSin[i]) { // Aproximação de radiano
				
				double sinDifference = tableSin[i] - tableSin[i - 1];
				double cosDifference = tableCos[i] - tableCos[i - 1];

				double base = (tableSin[i] - streamSin) / sinDifference;
				double cosApproximation = tableCos[i] - (cosDifference * base);

				radApproximation = degreesToRadians((double) i - base);

				fprintf(outputStream, "%.5lf %.5lf %.5lf\n", radApproximation, streamSin, cosApproximation);
				break;
			}
		}
	}
	
	fclose(inputStream);
	fclose(outputStream);

    return 0;
}

double degreesToRadians(double degree) {
	return degree * (PI / 180);
}

void readTable(FILE* stream, int *tableDegrees, double *tableSin, double *tableCos) {
	int i;
	for(i = 0; i < FILE_STREAM_DEGREES_QUANTITY; i++) {
		fscanf(stream, "%i\n%lf\n%lf\n", &tableDegrees[i], &tableSin[i], &tableCos[i]);
	}
}