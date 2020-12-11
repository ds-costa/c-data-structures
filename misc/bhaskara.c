#include <stdio.h>
#include <math.h>

double delta(int a, int b, int c) {
  return (b * b) - 4 * a * c;
}

void baskhara(int a, int b, int c, double *x1, double *x2) {

	double dt = delta(a, b, c);
	double sqrtDelta = sqrt(dt);

  if(dt < 0) {
	printf("Error\n");
	*x1 = *x2 = NAN;
	return;
  }
  else if(dt == 0) {
	*x1 = *x2 = (-b) / (2 * a);
	return;
  }

	*x1 = (-b + sqrtDelta) / (2 * a);
	*x2 = (-b - sqrtDelta) / (2 * a);
}

void printEquation(int a, int b, int c, double x1, double x2) {
	printf("%dx²+%dbx+(%d) = 0\n\nx1: %lf\nx2: %lf\n", a, b, c, x1, x2);
}
