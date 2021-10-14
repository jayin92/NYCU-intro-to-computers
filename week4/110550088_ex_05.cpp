#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    double ax, ay, bx, by, cx, cy;
    ax = ((double)rand() / (RAND_MAX + (double)1.0)) * (double)13.0 - (double)6.0;
    ay = ((double)rand() / (RAND_MAX + (double)1.0)) * (double)13.0 - (double)6.0;
    bx = ((double)rand() / (RAND_MAX + (double)1.0)) * (double)13.0 - (double)6.0;
    by = ((double)rand() / (RAND_MAX + (double)1.0)) * (double)13.0 - (double)6.0;
    cx = ((double)rand() / (RAND_MAX + (double)1.0)) * (double)13.0 - (double)6.0;
    cy = ((double)rand() / (RAND_MAX + (double)1.0)) * (double)13.0 - (double)6.0;
    // ax = -1.9; ay = 3.2;
    // bx = -5.5; by = 5.2;
    // cx = 0.9; cy = 5.0;
    printf("point1(%.1lf, %.1lf)\n", ax, ay);
    printf("point2(%.1lf, %.1lf)\n", bx, by);
    printf("point3(%.1lf, %.1lf)\n", cx, cy);

    double x1 = bx - ax;
    double y1 = by - ay;
    double x2 = cx - ax;
    double y2 = cy - ay;
    double ans = fabs(x1 * y2 - y1 * x2) / (double)2.0;
    printf("area: %.1lf\n", ans);
    system("pause");
    return 0;
}

