#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <time.h>


/* Creación Matriz dinámica para producto Matriz-vector */
double **MatDin(int fil, int col){
	 int i;
	 double **A = NULL;
	 A = (double **)malloc(fil*sizeof(double *));
	 if(A == NULL){
	   perror("ERROR. There is not enough memory");
	   exit(EXIT_FAILURE);
	 }
	 for(i=0;i<fil;i++){
		 A[i]=(double *)malloc(col*sizeof(double));
		 if(A[i] == NULL){
		   perror("ERROR. There is not enough memory");
		   exit(EXIT_FAILURE);
		 }
	 }
   
	 return A;
}

/* Genero Vector Dinámico para producto */
double *VectDin(int n){
	double *vector=NULL;
	vector=(double *) malloc((size_t) n * sizeof(double) );
	if(vector==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	return vector;
  
  
  /*Multiplicación Matriz Vector*/
  
  double *MatMult(double **A, double *xx, int dimension, int fil){
	
	int i,j;
	double *bb=NULL;
	result=(double *) malloc((size_t) fil* sizeof(double) );
	if(result==NULL){
		perror("ERROR. There is not enough memory");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<fil; i++){
		double contador=0.0d;
		for(j=0; j<dimension;j++){
			contador+=A[i][j]*xx[j];
		}
		bb[i]=contador;
		
	}
	return bb;
    
	
	
}
  
  
