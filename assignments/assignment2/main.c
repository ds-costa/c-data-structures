
/****************************************
*	TITLE: Projeto 02 - Uso simples de funções
*	AUTHOR: David S. Costa		
*	DESCRIPTTION: Projeto 02 da disciplina ATP2, 
*	Leitura de um arquivo de pontos e obtenção do ponto mais próximo do centro de massa do sistema.
*****************************************/

#include <stdio.h>
#include <math.h>

//Estrutura que define o dado abstrato "Ponto"
typedef struct point {
	double x, y;
} Point;

//Macro Distancia entre dois pontos
#define euclidianDistance(p1, p2) sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
//Centro de massa de um conjunto de pontos
Point centerOfMass(Point *points, int pointsQuantity);

int main(void) {

	FILE *inputStream = fopen("input.txt", "r");
	int pointsQuantity, i;
 
	fscanf(inputStream, "%d", &pointsQuantity);

	Point points[pointsQuantity];
	
	// Leitura do arquivo de input e gravação de valores em vetor de pontos
	for(i = 0; i < pointsQuantity; i++) {
		fscanf(inputStream, "%lf %lf", &points[i].x, &points[i].y);
	}
	fclose(inputStream);

	//Cálculo do centro de massa do conjunto de pontos
	Point c_of_mass = centerOfMass(points, pointsQuantity);
	
	// Calcula a distancia do centro de massa até o primeiro ponto do vetor
	double distance = euclidianDistance(points[0], c_of_mass);
	//Auxiliar para comparar a distancia do centro de massa de dois pontos
	double auxDistance = 0.0;
	//centerPoint inicialmente Assume que points[0] é o ponto mais próximo do centro de massa
	Point centerPoint = points[0];
	
	// Loop que define o ponto central
	for(i = 1; i < pointsQuantity; i++) {
		auxDistance = euclidianDistance(points[i], c_of_mass);
		if(auxDistance < distance) {
			distance = auxDistance;
			centerPoint = points[i];
		}
	}

	printf("Ponto (%.1lf, %.1lf)\n", centerPoint.x, centerPoint.y);

	return 0;
}

Point centerOfMass(Point *points, int pointsQuantity) {
	Point p = {0.0, 0.0};
	int i;
	for(i = 0; i < pointsQuantity; i++) {
		p.x += points[i].x;
		p.y += points[i].y;
	}
	p.x /= pointsQuantity;
	p.y /= pointsQuantity;
	return p;
}
