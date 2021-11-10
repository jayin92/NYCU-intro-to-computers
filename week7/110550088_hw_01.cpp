#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tempC2F(int a) {
    double res = a;
    res *= (double)9.0 / (double)5.0;
    res += 32;

    return (int)(round(res));
}

int main() {
    int a;
    printf("What's the temprature (Celsius): ");
    scanf("%d", &a);
    printf("Celsius = %d, Fahrenheit = %d\n", a, tempC2F(a));

    system("PAUSE");
    return 0;
}
