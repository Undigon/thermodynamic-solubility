/*Este algoritmo emplea el método*
 *de la fuerza ionica media y    *
 *está específicamente diseñado  *
 *para sales 1+1 sin ion común   */

#include <stdio.h>
#include <math.h>
#define PRECISION 1e-6 //0.000001 one millionth

long double conc = 1e-2;
long double kPS = 0e+1;
long double s_i_ans = 1e-1; //Can be any positive value I think

//noionc recourses until the relative change of s_i
//becomes lower than what PRECISION dictates.
void noionc (long double a, long double b, long double c){
	if ( 1 - (b / pow(10, -0.51*sqrt(c + a)))/c < PRECISION){
		if (1 - (b / pow(10, -0.51*sqrt(c + a)))/c > -PRECISION) {
			printf("La solubilidad es de %Le M\n", c);		
			return;
		}
		else {
			noionc(a, b, b / pow(10, -0.51*sqrt(c + a)));
		}
	}
	else {
		noionc(a, b, b / pow(10, -0.51*sqrt(c + a)));
	}
}

int main (){
//	double s_i;
	printf ("Se requiere de dos valores: La concentración actual\nde la solución y ");
	printf ("la constante de solubilidad termodinámica del soluto.\n");
	scanf ("%Le", &conc);
	scanf ("%Le", &kPS);
	kPS = sqrt(kPS);
	noionc(conc, kPS, s_i_ans);
	return 0;
}
