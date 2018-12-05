
#ifndef INTEGRAL_H
#define INTEGRAL_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define GRMAX 10
#define N 2000
    
    typedef double real;
    typedef struct{
        real limf, lims;
    }LIMITES;
    
int Validarint(char buffer[]);
int Validarnum(char buffer[]);
void Grau(int *ptr);
void ReservarMemoria(real **ptr, int n);
void LerCoeficiente(real *a, int n);
void Limites(LIMITES *L);
real RegraS(real *a, int n, LIMITES *L);


#ifdef __cplusplus
}
#endif

#endif /* INTEGRAL_H */