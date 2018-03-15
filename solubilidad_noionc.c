/*Este algoritmo emplea el método*
 *de la actividad media y está   *
 *específicamente diseñado para  *
 *   sales 1+1 sin ion común     */

#include <stdio.h>
#include <math.h>

int main (){
//	double s_i;
	long double conc = 0.01;
	long double kPS = 0.0;
	long double s_i_ans = 0.1; //set to 1,76e-4 if all else fails
	printf ("Se requiere de dos valores: La concentración actual\n
		de la solución y la constante de solubilidad termodinámica del soluto.\n");
	scanf ("%Le", &conc);
	//printf ("%Le\n", conc); //Just debug things
	scanf ("%Le", &kPS);
	//printf ("%Le\n", kPS); //Just debug things
	kPS = sqrt(kPS);
	for (int i = 0; i < 5; i++){
		s_i_ans = kPS / pow(10, -0.51*sqrt(s_i_ans + conc));
	}
	printf("La solubilidad es de %Le\n", s_i_ans);
	return 0;
}
