#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "tools.h"



/* Método Euler Explícito */
int main(){

int i,j,k,l;
double alfa=1.0 ,C ,tf=1.0 , dx , dt;
double x0=0.0d;
double xf=1.0d;
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
A= MatDin(pasot-1, pasot-1);
T= MatDin(pasot+1, pasot+1);

/*Vectores tiempo y espcacio discretizados*/
for(j=0; j<pasox+1;j++ )
 {
		x[j]=x0+j*dx;
	}
for(i=0; i<pasot+1;i++ )
 {
		t[i]=i*dt;
	}
for(j=0; j<pasox+1;j++ ) /*Condición de frontera*/
 {
		T0[j]=x0+j*dx;
	}

/*Matriz K*/
for(i=0; i<pasox-1;i++){
		for(j=0;j<pasox-1;j++){
			if(j==i-1){
				A[i][j]=C;
			}else if(j==i){
				A[i][j]=1-2*C;
			}else if (j==i+1){
				A[i][j]=C;
			}else{
				A[i][j]=0.0d;
			}
		}
	}














}

