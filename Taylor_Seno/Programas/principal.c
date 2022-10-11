#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float factimpC(int N);
float powerimpC(int x,int N);
extern float factimpASM(int N);
extern float powerimpASM(int x,int N);

int main(){
	struct timespec ti, tf;
    double elapsed1,elapsed2;

    
	float *factorialImpC,*factorialImpASM, *npowImpC, *npowImpASM;

    int i,j,k,l;
	float sum1=0,sum2=0;
    int n=16;
    int X=5;
	float seno,e_M;

	factorialImpC=(float *)malloc(n * sizeof(float));
	factorialImpASM=(float *)malloc(n * sizeof(float));
	npowImpC=(float *)malloc(n * sizeof(float));
	npowImpASM=(float *)malloc(n * sizeof(float));

// OPCION 1: Usando las funciones factimpC y powerimpC

	clock_gettime(CLOCK_REALTIME, &ti);
	for(i=0;i<n+1;i++){
		factorialImpC[i]=factimpC(i);
		npowImpC[i]=powerimpC(X,i);
		sum1+=npowImpC[i]/factorialImpC[i];
	}
	clock_gettime(CLOCK_REALTIME, &tf);
    elapsed1 =  (tf.tv_nsec - ti.tv_nsec);

// OPCION 2: Usando las funciones factimpASM y powerimpASM
	clock_gettime(CLOCK_REALTIME, &ti);
	for(l=0;l<n+1;l++){
		factorialImpASM[l]=factimpASM(l);
		npowImpASM[l]=powerimpASM(X,l);
		sum2+=npowImpASM[l]/factorialImpASM[l];
	}
	clock_gettime(CLOCK_REALTIME, &tf);
    elapsed2 =  (tf.tv_nsec - ti.tv_nsec);


	printf("La opción 1 da como resultado %.10f y su tiempo de ejecución fue de %.2f nanosegundos\n",sum1, elapsed1);
	printf("La opción 2 da como resultado %.10f y su tiempo de ejecución fue de %.2f nanosegundos\n",sum2, elapsed2);


	seno=sin(5);
	e_M=100*fabs((seno-sum1)/seno);
	printf("El valor relativo de la opcion 1 es %f\n",e_M);
	e_M=100*fabs((seno-sum2)/seno);
	printf("El valor relativo de la opcion 2 es %f\n",e_M);

	return 0;
}

float factimpC(int N){

    float result=1;
    for(int i=1;i<N*2+1;i++){

        result*=(i+1);

    }

    return result;

}

float powerimpC(int x,int N){
    float result=1;

    for(int i=0;i<N*2+1;i++){
        result*=x;

    }

    if(N%2!=0){
        result*=-1;
    }

    return result;
}