#include <stdio.h>

#include "swap.h"

int swapInt(int* left, int* right){
	int success = 0;
	int aux;

	if (left != NULL && right != NULL){
		aux = *left;
		*left = *right;
		*right = aux;
		success = 1;
	}

	return success;
}

int swapAvion(eAvion* left, eAvion* right){
	int success = 0;
	eAvion aux;

	if (left != NULL && right != NULL){
		aux = *left;
		*left = *right;
		*right = aux;
		success = 1;
	}

	return success;
}
