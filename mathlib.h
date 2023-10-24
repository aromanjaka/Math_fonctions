#ifndef MATHLIB
#define MATHLIB

#define eps 1e-9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void css(char* chemin);
double f(double n);
double derive(double a);
int tangente(double a, double b);
int secante(double a, double b);
int dicho(double a, double b);
double inteTrap(double a, double b);

#endif
