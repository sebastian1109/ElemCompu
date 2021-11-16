#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "tools.h"



/* Método Euler Explícito */

int main()
{

int i,j,k,l;
double alfa=1.0 ,C ,tf=1.0 , dx , dt;
double x0=0.0;
double xf=1.0;
double **A, **T;
double *t;
double *x;
double *T0, *Ta, *Tb;

int pasox=100, pasot=2000;

dx=(xf-x0)/pasox;
dt=(tf)/pasot;
C=(alfa*dt)/(dx*dx);

x= VectDin(pasox+1);
t= VectDin(pasot+1);
T0= VectDin(pasox+1);
A= MatDin(pasox-1, pasox-1);
T= MatDin(pasot+1, pasox+1);

/*Vectores tiempo y espacio discretizados*/
for(j=0; j<pasox+1;j++ )
 {
		x[j]=x0+j*dx;
	}
for(i=0; i<pasot+1;i++ )
 {
		t[i]=i*dt;
	}
for(j=0; j<pasox+1;j++ ) /*Condición de frontera T_0(x)=e^{x}*/
 {
		T0[j]=exp(x[j]);
	}

/*Matriz A=(I-CK)*/
for(i=0; i<pasox-1;i++){
		for(j=0;j<pasox-1;j++){
			if(j==i){
				A[i][j]=1-2*C;
			}else if(j==i-1){
				A[i][j]=C;
			}else if (j==i+1){
				A[i][j]=C;
			}else{
				A[i][j]=0.0;
			}
		}
	}

/* Matriz final T^{k+1} que es la A*T^{k}+dt*q^{k}, solo las condiciones de frontera */
for(j=0; j<pasox+1;j++)
  {
		T[0][j]=T0[j];
	}
	for(i=0;i<pasot+1;i++)
  {
		T[i][0]=0.0;
		T[i][pasox]=0.0;
	}

/* Elemento q*dt*/
double *qdt = VectDin(pasox-1);
double *v = VectDin(pasox-1);
for(i=1; i<pasot+1;i++)
{
  for(j=0; j<pasox-1;j++)
  {
    qdt[j]=cos(M_PI*t[i])*sin(2*M_PI*x[j+1])*dt;
/* Se van creando vectores T^{k} para luego multiplicarlos con A, con x variando y t fijo*/
    v[j]=T[i-1][j+1];
  }

/* Solución final Euler Explícito*/
double *ATk= MatMult(A, v, pasox-1, pasox-1);
  for(k=0; k<pasox-1;k++)
  {
    T[i][k+1]=ATk[k]+qdt[k];
    
  }
}

for (i=0;i<pasot+1;i++){
    for (j=0;j<pasox+1;j++){
      
      printf("%f \t",T[i][j]);
    }
    printf("\n");
  }

/* Método Euler Implícito */


/*
double **TI;
double **AI;

TI = MatDin(pasot+1, pasox+1);
AI = MatDin(pasox-1, pasox-1);
*/

/*Matriz AI=(I+CK)*/

/*
for(i=0; i<pasox-1;i++){
		for(j=0;j<pasox-1;j++){
			if(j==i){
				AI[i][j]=1+2*C;
			}else if(j==i-1){
				AI[i][j]=-C;
			}else if (j==i+1){
				AI[i][j]=-C;
			}else{
				AI[i][j]=0.0d;
			}
		}
	}

*/

/* Matriz final T^{k+1} que es la A*T^{k}+dt*q^{k}, solo las condiciones de frontera */

/*

for(j=0; j<pasox+1;j++)
  {
		TI[0][j]=T0[j];
	}
	for(i=0;i<pasot+1;i++)
  {
		TI[i][0]=0.0d;
		TI[i][pasox]=0.0d;
	}


*/


/* Elemento q*dt*/
/*

double *qIdt = VectDin(pasox-1);
double *vI = VectDin(pasox-1);
double *v2 = VectDin(pasox-1);
for(i=1; i<pasot+1;i++)
{
  for(j=0; j<pasox-1;j++)
  {
    qIdt[j]=cos(M_PI*t[i+1])*sin(2*M_PI*x[j+1])*dt;


  */

    /* Se van creando vectores T^{k} para luego sumarlo con q^{k+1}dt*/

/*

    vI[j]=TI[i-1][j+1];
  }
}


*/

/* Suma TIk +q^{k+1}*dt*/

/*


for(i=1; i<pasot+1;i++)
{
  for(j=0; j<pasox-1;j++)
  {
    v2[j] = vI[j] + qIdt[j];
  }
}

*/

/* Se resuelve el sistema de ecuaciones lineales utilizando Jacobi */












}

