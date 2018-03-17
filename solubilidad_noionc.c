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

//These functions recourse until the relative change of s_i
//becomes lower than what PRECISION dictates.
void noionc (long double a, long double b, long double c){
	if ( 1 - (b / pow(10, -0.51*sqrt(c + a)))/c < PRECISION){
		if (1 - (b / pow(10, -0.51*sqrt(c + a)))/c > -PRECISION) {
			printf("La solubilidad es de %Le M\n", (b / pow(10, -0.51*sqrt(c + a))));
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

void ionc (long double a, long double b, long double c){
	if (1 - (-a+sqrt(a*a+4*b/pow(10, -1.02*sqrt(c+a))))/(2*c) < PRECISION*100){
		if (1 - (-a+sqrt(a*a+4*b/pow(10, -1.02*sqrt(c+a))))/(2*c) > -PRECISION*100){
			printf("La solubilidad es de %Le M\n", ((-a+sqrt(a*a+4*b/pow(10, -1.02*sqrt(c+a))))/2));
			return;
		}
		else {
			ionc (a, b, ((-a+sqrt(a*a+4*b/pow(10, -1.02*sqrt(c+a))))/2));
		}
	}
	else {
		ionc (a, b, ((-a+sqrt(a*a+4*b/pow(10, -1.02*sqrt(c+a))))/2));
	}
}

int main (){
	char situation;
	printf ("Se requiere de dos valores: La concentración actual\nde la solución y ");
	printf ("la constante de solubilidad termodinámica del soluto.\n");
	scanf ("%Le", &conc);
	scanf ("%Le", &kPS);
	printf("¿Presenta efecto del ion común?: (s)i/(n)o\n");
	getchar();
	situation = getchar();
	if ('n' == situation) {
		kPS = sqrt(kPS);
		noionc(conc, kPS, s_i_ans);
	}
	else if ('s' == situation) {
		ionc(conc, kPS, s_i_ans);
		
	}
	else {printf ("Caso no reconocido\n");}
	return 0;
}
