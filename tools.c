#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "tools.h"


/* Creación Matriz dinámica para producto Matriz-vector */
double **MatDin(int fil, int col)
{
	 int i;
	 double **A = NULL;
	 A = (double **)malloc(fil*sizeof(double *));
	 for(i=0;i<fil;i++)
   {
		 A[i]=(double *)malloc(col*sizeof(double));
		 if(A[i] == NULL)
     {
		   perror("ERROR. There is not enough memory");
		   exit(EXIT_FAILURE);
		 }
	 }

	 return A;
}

/* Genero Vector Dinámico para producto */
double *VectDin(int n)
{
	double *vector=NULL;
	vector=(double *) malloc((size_t) n * sizeof(double) );
	if(vector==NULL)
  {
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	return vector;
}



  /*Multiplicación Matriz Vector*/

  double *MatMult(double **A, double *xx, int dimension, int fil)
{

	int i,j;
	double *bb=NULL;
	bb=(double *) malloc((size_t) fil* sizeof(double) );
	if(bb==NULL)
  {
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<fil; i++)
  {
		double contador=0.0;
		for(j=0; j<dimension;j++)
    {
			contador+=A[i][j]*xx[j];
		}
		bb[i]=contador;

	}
	return bb;

}

int Jacobi(int n, double **A, double *b, int *xi, double eps, int maxIt){
	
	int i, j, k = 0;
	double *xk=NULL;  //Nuevo Vector a formar 
	xk = (double *) malloc(n * sizeof(double));
	if (xk==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	
	double err;

	while (k < maxIt, k++){
		for (i = 0; i < n; i++){
			
			double sum, diff;
			
			sum = b[i];
			for (j = 0; j < n; j++){
				sum = sum - A[i][j]*xi[j];
			}
			
			sum = sum + A[i][i]*xi[i];
			xk[i] = sum/A[i][i];
			
			diff = xk[i] - xi[i];
			err = err + diff*diff;
		}
		
		if (err < eps){
			break;
			
		} else{
			xi[i] = xk[i];
			
		}
		
	}
	
	return k;
}
