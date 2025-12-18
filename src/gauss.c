#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double temp;
	for (int i =0;i<mat->r;i++){
		temp = mat->data[i][i];
		if (temp ==0){
			return 1;
		}
		for(int j = i;j<mat->r;j++){ //podziel wiersz
			mat->data[i][j] = mat->data[i][j]/temp;
		}
		for (int j = 0; j<mat->r;j++){
			b->data[i][j] = b->data[i][j]/temp;
		}
		for (int j = 0;j<mat->r;j++){ //odejmij kolejne wiersze
			if (i==j){
				continue;
			}
			temp = mat->data[j][i];
			for(int k = i;k<mat->r;k++){
				mat->data[j][k] = mat->data[j][k] - temp*mat->data[i][k];
			}
		
		
			for(int k = 0;k<mat->r;k++){
				b->data[j][k] = b->data[j][k] - temp*b->data[i][k];
				}
			}
	}
	return 0;
}
