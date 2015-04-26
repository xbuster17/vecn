#ifndef LIN_ALG_H
#define LIN_ALG_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.14159265359

typedef struct vecn {
    unsigned
        int n;
    double * v;
} vecn;

#define vecn_NEW(x,nl) double x ## __V[nl] = {0};\
    vecn x = {.n = nl, .v = x ## __V}

void vecn_print(vecn vec);
void vecn_echo(vecn v, char* name);

#define \
    vecn_SET(x, ...) \
        memcpy(x.v, (double[]) { __VA_ARGS__ }, \
        x.n * sizeof(double))

void vecn_set(vecn v, double k);

void vecn_sub(vecn a, vecn b, vecn x);
void vecn_add(vecn a, vecn b, vecn x);

void vecn_scale(vecn a, double k);
double vecn_dot(vecn a, vecn b);

double vecn_norm(vecn v);
double vecn_angle(vecn a, vecn b);

double rad_to_deg(double rad);
double deg_to_rad(double deg);

//a,b,x € R³
void vecn_cross(vecn a, vecn b, vecn x);

#endif
