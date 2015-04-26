#include "alg_lin.h"

double rad_to_deg(double rad){
    return rad * 180.f / PI;
}
double deg_to_rad(double deg){
    return deg * PI / 180.f;
}

void vecn_set(vecn v, double k){
    unsigned int i = 0;
    for(; i<v.n; i++)
        v.v[i] = k;
}

void vecn_add(vecn a, vecn b, vecn x){
    if((a.n & b.n) != x.n) /*blow up!*/ return;

    unsigned int i = 0;
    for(;i<a.n; i++)
        x.v[i] = a.v[i] + b.v[i];
}

void vecn_sub(vecn a, vecn b, vecn x){
    if((a.n & b.n) != x.n) /*blow up!*/ return;

    unsigned int i = 0;
    for(;i<a.n; i++)
        x.v[i] = a.v[i] - b.v[i];
}

void vecn_scale(vecn a, double k){
    unsigned int i = 0;
    for(;i<a.n; i++)
        a.v[i] *= k;
}

double vecn_dot(vecn a, vecn b){
    if(a.n != b.n) {
        printf("###\n###ERROR: n mismatch vecn_dot(a.n = %d, b.n = %d);\n###", a.n, b.n);
        return 0;
    };
    unsigned int i = 0;
    double res = 0;
    for(;i<a.n; i++)
        res += a.v[i] * b.v[i];
    return res;
}

double vecn_norm(vecn v){
    return sqrt(vecn_dot(v, v));
}

double vecn_angle(vecn a, vecn b){
    return acos(
        vecn_dot(a, b) /
        ( vecn_norm(a) * vecn_norm(b) )
    );
}

//a,b,x € R³
void vecn_cross(vecn a, vecn b, vecn x){
    if(((a.n & b.n) & x.n) != 3u) /*blow up!*/ return;
    x.v[0] = (a.v[1] * b.v[2]) - (a.v[2] * b.v[1]);
    x.v[1] = (a.v[2] * b.v[0]) - (a.v[0] * b.v[2]);
    x.v[2] = (a.v[0] * b.v[1]) - (a.v[1] * b.v[0]);
}

//print / echo
void vecn_print(vecn v){
    unsigned int i = 0;
    printf("{ ");
    for (;i < v.n; i++){
        if(i == v.n-1)
            printf("%g", v.v[i]);
        else
            printf("%g, ", v.v[i]);
    }
    printf(" }");
}
void vecn_echo(vecn v, char* name){
    unsigned int i = 0;
    printf("%s={", name);
    for (;i < v.n; i++)
        if(i == v.n-1)
            printf("%g", v.v[i]);
        else
            printf("%g, ", v.v[i]);
    printf("}\n");
}
