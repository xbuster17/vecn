#include "alg_lin.h"

int main (void){

//some tests:
    vecn_NEW(a, 3);
    vecn_NEW(b, 3);
    vecn_NEW(c, 3);

    vecn_SET(a, .6, .7, .8);
    vecn_SET(b, .1, .2, .3);
    vecn_SET(c, .1, .1, .1);

    vecn_NEW(x, 3);

    vecn_add(a,b,x);
    vecn_add(c,x,x);

    vecn_echo(x, "x");
    printf("%s%g\n", "ang(a,b)=", rad_to_deg(vecn_angle(a,b)));

    vecn_NEW(a1, 6);
    vecn_set(a1, 2.1111);
    vecn_echo(a1, "a1");
    double a1_v[6] = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
    a1.v = a1_v;
    vecn_echo(a1, "a1");

    vecn_cross(a,b,x);
    vecn_echo(x, "a x b");

    return 0;
}
