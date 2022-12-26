#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct complexOptions {
    float realComponent;
    float complexComponent;
} complexOpt;
float  checkSymbols(char *enterParameter);
void solve(complexOpt (*choice) (float, float, float, float, float), float R1, float R2, float L, float C, float fMin, float fMax, float df);
complexOpt schemeFirstOpt (float R1, float R2, float L, float C, float omegas);
complexOpt schemeSecondOpt (float R1, float R2, float L, float C, float omegas);
complexOpt schemeThirdOpt (float R1, float R2, float L, float C, float omegas);
complexOpt schemeForthOpt (float R1, float R2, float L, float C, float omegas);

int main(){
    float R1, R2, L, C, fMin, fMax, df;
    short choice;

    printf("\tPROGRAM TO SOLVE COMPLEX RESISTANCE\n");
    R1 = checkSymbols("R1");
    R2= checkSymbols("R2");
    L= checkSymbols("L");
    C= checkSymbols("C");
    fMin= checkSymbols("fMin");
    fMax= checkSymbols("fMax");
    df= checkSymbols("df");

    do {
        printf("\n--------SELECT_YOUR_CHOICE--------\n");
        printf("\n\t1)Solving first scheme \n\t2)Solving second scheme \n\t3)Solving third scheme ");
        printf("\n\t4)Solving fourth scheme \n\t5)EXIT FROM APP");
        printf("\n-----------------------------------\n");
        printf("\nEnter your choice please(1 to 4) :");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                solve(schemeFirstOpt, R1, R2, L, C, fMin, fMax, df);
                break;
            case 2:
                solve(schemeSecondOpt, R1, R2, L, C, fMin, fMax, df);
                break;
            case 3:
                solve(schemeThirdOpt, R1, R2, L, C, fMin, fMax, df);
                break;
            case 4:
                solve(schemeForthOpt, R1, R2, L, C, fMin, fMax, df);
                break;
            case 5:
                exit(0);
            default:
                printf("not an appropriate choice");
        }
    }     while (choice != 5);
}
float  checkSymbols(char *enterParameter){
    char ch,error;
    float value;
    do {
        error = 0;
        printf("Please enter %s ->",enterParameter);
        scanf("%f%c", &value, &ch);

        if((ch) != '\n') {
            printf("Invalid data\n");
            error = 1;
            fflush(stdin);
        }
    } while(error);
    return value;
}

complexOpt division(complexOpt n1, complexOpt n2) { // division of two complex numbers
    complexOpt n;
    n.realComponent = (n1.realComponent * n2.realComponent + n1.complexComponent * n2.complexComponent) / (n2.realComponent * n2.realComponent + n2.complexComponent * n2.complexComponent);
    n.complexComponent = (n1.complexComponent * n2.realComponent - n1.realComponent * n2.complexComponent) / (n2.realComponent * n2.realComponent + n2.complexComponent * n2.complexComponent);
    return n;
}

complexOpt schemeFirstOpt (float R1, float R2, float L, float C, float omegas) {
    complexOpt n1, n2;
    n1.realComponent = L/C;
    n1.complexComponent = (-1) * R1 / (omegas * C);
    n2.realComponent = R1;
    n2.complexComponent = omegas * L - 1 / (omegas * C);
    return division(n1, n2);
}
complexOpt schemeSecondOpt (float R1, float R2, float L, float C, float omegas) {
    complexOpt n1, n2;
    n1.realComponent = L/C;
    n1.complexComponent = R1 / (omegas * C);
    n2.realComponent = R1;
    n2.complexComponent = omegas * L - 1 / (omegas * C);
    return division( n1,n2);
}
complexOpt schemeThirdOpt (float R1, float R2, float L, float C, float omegas) {
    complexOpt n1, n2;
    n1.realComponent = R1 * R2;
    n1.complexComponent = R1 * (omegas * L - 1 / (omegas * C));
    n2.realComponent = R1 + R2;
    n2.complexComponent = omegas * L - 1 / (omegas * C);
    return division(n1, n2);
}
complexOpt schemeForthOpt (float R1, float R2, float L, float C, float omegas) {
    complexOpt n1, n2;
    n1.realComponent = R1 * R2 + L/C;
    n1.complexComponent = omegas * L * R1 - R2 / (omegas * C);
    n2.realComponent = R1 + R2;
    n2.complexComponent = omegas * L - 1 / (omegas * C);
    return division(n1, n2);
}
void displaying (complexOpt n) {
    if(n.complexComponent >= 0) {
        printf("%f + i*%f", n.realComponent, n.complexComponent);
    } else {
        printf("%f - i*%f", n.realComponent, -n.complexComponent);
    }
}
void solve(complexOpt (*choice) (float, float, float, float, float), float R1, float R2, float L, float C, float fMin, float fMax, float df) {
    complexOpt dn;
    float omegas, f0;
    printf("\n|Frequency Value|\t\t|Resonance frequency|\t\t|Resistance|\n");
    while (fMin <= fMax) {
        omegas = 2 * M_PI * fMin;
        f0 = 1 / (2 * M_PI * sqrt(L*C));

        dn = (*choice)(R1, R2, L, C, omegas);
        printf("\t%.2f\t\t\t\t\t\t%2f\t\t\t", fMin, f0);

        displaying(dn);printf("\n\n");
        fMin += df;
    }
}
