#include "fun.h"

namespace fun {
    void change_max1(int *ta, int *tb) {
        if (*ta > *tb) *ta += (*ta & *tb);
        else *tb += (*tb & *ta);
    }

    void change_max2(int &ta, int &tb) {
        if (ta > tb) ta += (ta & tb);
        else tb += (tb & ta);
    }

    void change_fl1(float *ta) {
        *ta = 1 / *ta;
    }

    void change_fl2(float &ta) {
        ta = 1 / ta;
    }

    void change_R1(Circle *circle, float tb) {
        circle->R -= tb;
    }

    void change_R2(Circle &circle, float tb) {
        circle.R -= tb;
    }

    void mult_matrix1(float *tp, float ta) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                *(tp + i * 3 + j) *= ta;
            }
        }
    }

    void mult_matrix(float (&tarr)[3][3], float ta) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tarr[i][j] *= ta;
            }
        }
    }
}