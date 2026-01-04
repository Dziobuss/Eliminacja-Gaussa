#include "backsubst.h"

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int i, j;

    if (mat->r != mat->c || mat->r != b->r || x->r != mat->c || b->c != 1) {
        return 2;
    }

    for (i = mat->r - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0) {
            return 1;
        }

        double s = 0;
        for (j = i + 1; j < mat->r; j++) {
            s += mat->data[i][j] * x->data[j][0];
        }

        x->data[i][0] = (b->data[i][0] - s) / mat->data[i][i];
    }

    return 0;
}