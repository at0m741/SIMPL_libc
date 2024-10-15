#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define NDIM 3
double determinant2x2(double mat[2][2]);
double determinant3x3(double mat[3][3]);
double determinant4x4(double mat[NDIM][NDIM]);
#endif /* MATRIX_H */
