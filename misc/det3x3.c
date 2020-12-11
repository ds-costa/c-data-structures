#include <stdio.h>

typedef double mat3x3[3][3];

double det3x3(mat3x3 mat) {

	printf("%.2f %.2f %.2f| %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2], mat[0][0], mat[0][1]);
	printf("%.2f %.2f %.2f| %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2], mat[1][0], mat[1][1]);
	printf("%.2f %.2f %.2f| %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2], mat[2][0], mat[2][1]);

    printf("---\n");

    printf("\n(%.2f * %.2f * %.2f) + (%.2f * %.2f * %.2f) + (%.2f * %.2f * %.2f) - (%.2f * %.2f * %.2f) - (%.2f * %.2f * %.2f) - (%.2f * %.2f * %.2f)\n", mat[0][2], mat[1][1],mat[2][0],mat[0][0],mat[1][2],mat[2][1],mat[0][1],mat[1][0],mat[2][2],mat[0][0],mat[1][1],mat[2][2],mat[0][1],mat[1][2],mat[2][0],mat[0][2],mat[1][0],mat[2][1]);
	printf("(%.2f) + (%.2f) + (%.2f) - (%.2f) - (%.2f) - (%.2f)\n", (mat[0][2] * mat[1][1] * mat[2][0]), (mat[0][0] * mat[1][2] * mat[2][1]), (mat[0][1]*mat[1][0]*mat[2][2]),(mat[0][0]*mat[1][1]*mat[2][2]),(mat[0][1]*mat[1][2]*mat[2][0]),(mat[0][2]*mat[1][0]*mat[2][1]));

    return (
        mat[0][0]*mat[1][1]*mat[2][2] +
        mat[0][1]*mat[1][2]*mat[2][0] +
        mat[0][2]*mat[1][0]*mat[2][1] -
        mat[0][0]*mat[1][2]*mat[2][1] -
        mat[0][1]*mat[1][0]*mat[2][2] -
        mat[0][2]*mat[1][1]*mat[2][0]
    ); 
}