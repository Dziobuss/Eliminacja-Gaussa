#include "gauss.h"

/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa (pivot = 0)
 */
int eliminate(Matrix *mat, Matrix *b)
{
    double factor;
    for (int i = 0; i < mat->r - 1; i++) {
        if (mat->data[i][i] == 0) {
            return 1;
        }
        for (int j = i + 1; j < mat->r; j++) {

            factor = mat->data[j][i] / mat->data[i][i];
            for (int k = i; k < mat->c; k++) {
                mat->data[j][k] -= factor * mat->data[i][k];
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }
    if (mat->data[mat->r - 1][mat->r - 1] == 0) {
        return 1;
    }

    return 0;
}
