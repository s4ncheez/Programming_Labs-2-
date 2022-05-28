#pragma once

namespace fun {
    struct Circle {
        float x, y, R;
    };
    void change_max1(int *, int *);
    void change_max2(int &, int &);
    void change_fl1(float *);
    void change_fl2(float &);
    void change_R1(Circle *, float);
    void change_R2(Circle &, float);
    void mult_matrix1(float *, float);
    void mult_matrix2(float &, float);
}