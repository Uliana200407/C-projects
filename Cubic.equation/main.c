#include <stdio.h>
#include <math.h>
#include <curses.h>
#include <stdlib.h>

int main() {
    float a, b, c, x1, x2, x3, q, p, u, v, y1, d;
    char ch, er;
    printf("\t\t\t\tSolver_Cubic_Equations\n");
    printf("----------------------------------------------------------\n");
    printf("Input a,b,c where x*x*x + a*x*x* + b*x + c:\n\n");
    printf("\t\t\t\t\t\tUser_Input\n");
    printf("----------------------------------------------------------\n");
    do {
        er = 0;
        printf("Input a cofficient = ");
        scanf("%f%c", &a, &ch);// s7- "s7\n" 7s5-"s5\n" 75s-"s\n" 75-"\n"
        if (ch != '\n') //перевірка буферу введення stdin
        {
            er = 1;
            fflush(stdin);
            printf("Error input a\n");
        }
        ch = 0;
    } while (er);

    do {
        er = 0;
        printf("Input b cofficient =");
        scanf("%f%c", &b, &ch);
        if (ch != '\n') //перевірка буферу введення stdin
        {
            er = 1;
            fflush(stdin);
            printf("Error input b\n");
        }
        ch = 0;
    } while (er);

    do {
        er = 0;
        printf("Input c cofficient = ");
        scanf("%f%c", &c, &ch);
        if (ch != '\n') //перевірка буферу введення stdin
        {
            er = 1;
            fflush(stdin);
            printf("Error input c\n");
        }
        ch = 0;
    } while (er);
    printf("\t\t\t\t\tResulting_Equation\n");
    printf("----------------------------------------------------------\n");
    
    printf(("x^3 + (%f)*x^2 + (%f)*x + (%f) = 0\n"), a, b, c); //output of whole
    printf("\t\t\t\t\t\tSolving\n");

    p = b - ((pow(a, 2)) / 3);
    q = (2 * (pow(a, 3)) / 27) - ((a * b) / 3) + c; //Formulas to find out p,q,d
    d = (pow(p, 3) / 27) + (pow(q, 2) / 4);


    if (d > 0) {
        float interData1, interData2;
        if (isnan(y1) == 1) {}  // checking for being a number

        u = cbrt(-q / 2 + sqrt(d));
        v = -p / (3 * u);
        y1 = u + v;


        x1 = y1 - a / 3;
        interData1 = -y1 / 2 - a / 3;
        interData2 = sqrt(3) * (u - v) / 2;
        if (isnan(x1) || isnan(x2) || isnan(x3)) {
            printf("Error! Algo is  incorrect");
        } else {
        printf("x1 =%f\n", x1);
        printf("x2 =%f+i*%f\n", interData1, interData2);
        printf("x3 =%f-i*%f\n", interData1, interData2);}
        printf("----------------------------------------------------------\n");
    }
    if (d == 0) {
        if (isnan(y1) == 1) {}
        x1 = 3 * q / p - a / 3;
        x2 = -3 * q / (2 * p) - a / 3;
        x3 = -3 * q / (2 * p) - a / 3;

        if (isnan(x1) || isnan(x2) || isnan(x3)) {
            printf("Error! Algo is  incorrect");
        } else {
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        printf("x3 = %f\n", x3);}

    }
    if (d < 0) {
        float r, f;
        if (isnan(y1) == 1) {}
        r = sqrt(-pow(p, 3) / 27);
        f = acos(-q / (2 * r));

        x1 = 2 * fabs(pow(r, 1.0 / 3)) * cos(f / 3) - a / 3;
        x2 = 2 * fabs(pow(r, 1.0 / 3)) * cos((f + 2 * M_PI) / 3) - a / 3;
        x3 = 2 * fabs(pow(r, 1.0 / 3)) * cos((f + 4 * M_PI) / 3) - a / 3;

        if (isnan(x1) || isnan(x2) || isnan(x3)) {
            printf("Error! Algo is  incorrect\n");
        } else {

            printf("x1 = %f\n", x1);
            printf("x2 = %f\n", x2);
            printf("x3 = %f\n", x3);

        }
        getchar();
        return 0;


    }


}
