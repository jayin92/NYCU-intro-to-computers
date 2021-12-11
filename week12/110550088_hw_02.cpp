#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);

double callback_execution(double* params, double(**callbacks)(double, double), int num_of_callbacks);

int main() {
    typedef double (f_pointer)(double, double);
    while(true){
        printf("Enter whether to continue or quit(1,0): ");
        int cq;
        scanf("%d", &cq);
        if(cq == 0){
            break;
        }
        int n = 0;
        f_pointer **callbacks = (f_pointer**)calloc(1000, sizeof(f_pointer*));
        double *params = (double*)calloc(1000, sizeof(double));
        while(printf("%2d Enter parameter and function code(+,-,*,/): ", n)){
            double num;
            char op;
            scanf("%lf %c", &num, &op);
            params[n] = num;
            if(op == 'q'){
                break;
            } else if(op == '+'){
                callbacks[n] = add;
            } else if(op == '-'){
                callbacks[n] = sub;
            } else if(op == '*'){
                callbacks[n] = mul;
            } else if(op == '/'){
                callbacks[n] = div;
            }
            n++;
        }
        double res = callback_execution(params, callbacks, n);
        printf("Final Result: %.6f\n", res);
    }

    system("pause");
    return 0;
}

double add(double a, double b){
    return a + b;
}
double sub(double a, double b){
    return a - b;
}
double mul(double a, double b){
    return a * b;
}
double div(double a, double b){
    return a / b;
}

double callback_execution(double* params, double(**callbacks)(double, double), int num_of_callbacks){
    double res = params[0];
    for(int i=0;i<num_of_callbacks;i++){
        res = callbacks[i](res, params[i+1]);
    }

    return res;
}