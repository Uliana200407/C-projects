#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("\t\tThat is the app to solve SLAR matrix \n\n");
    printf("-----------------------------------------------------\n");
    int n, i, j, k;
    double d, s;
    char error,ch;

    do {
        error = 0;
        printf("Enter here order plese (quantity of aS in one line): ");//checking for symbols and minus values
        scanf("%d%c", &n,&ch);
        if((ch != '\n')||(n<=0)) {
            printf("Invalid data\n");
            fflush(stdin);
            error = 1;
        }
    } while(error);
    ch = ' ';



    double **a = calloc (n * n, sizeof (double *)); //The above statement allocates contiguous space in memory for n*n elements

    for (i = 0; i <= n; i++)   //until i is equal to n, we move through the cycle
        a[i] = calloc (n, sizeof (double *));//when they become i>=n, we start entering the coefficients
    double **a1 = calloc (n, sizeof (double *));
    for (i = 0; i <= n; i++)
        a1[i] = calloc (n, sizeof (double *));//erasing memory for arrays
    double *b = calloc (n, sizeof (double *));
    double *x = calloc (n, sizeof (double *));
    printf("Enter cofficients and free members :\n");
    for (i = 1; i <= n; i++)
    {                         //creating loop,which will go to n times,every time i increases for 1 point(for rows and columns)
        for (j = 1; j <= n; j++)
        {
            do {
                error = 0;
                printf("a[%d,%d]=",i,j);
                scanf("%lf%c", &a[i][j], &ch); //checking for symbols ,inputing a cofficients
                if(ch != '\n') {
                    printf("Invalid data\n");
                    fflush(stdin);
                    error = 1;
                }
            } while(error);
            ch = ' ';

            a1[i][j] = a[i][j]; //comparing arrays
        }
        
        do {
            error = 0;
        printf("b[%d]=",i);
        scanf("%lf%c", &b[i],&ch); //checking for symbols,inputing b cofficients
            if(ch != '\n') {
                printf("Invalid data\n");
                fflush(stdin);
                error = 1;
            }
        } while(error);
        ch = ' ';
    }
    for (k = 1; k <= n; k++) // forward step - The direct move of the Gaussian method consists in the successive elimination of the coefficients of the unknowns, starting from the first column.
    {
        for (j = k + 1; j <= n; j++)
        {
            d = a[j][k] / a[k][k]; // formula 1
            for (i = k; i <= n; i++)
            {
                a[j][i] = a[j][i] - d * a[k][i]; // formula 2
            }
            b[j] = b[j] - d * b[k]; //formula 3
        }
    }
    for (k = n; k >= 1; k--) //  The second stage - the definition of unknowns - is called the reverse move,
    {
        d = 0;
        for (j = k + 1; j <= n; j++)
        {
            s = a[k][j] * x[j]; // formula 4
            d = d + s; // formula 4
        }
        x[k] = (b[k] - d) / a[k][k]; // formula 4
    }
    printf("-----------------------------------------------------\n");
    printf("\t\t\t\t\tSystem roots: \n");
    for( i = 1; i <= n; i++)
        printf("x[%d]=%lf\n", i, x[i]);
    free(a1);
    free(b);//erasing memory for massives a1,x,b  with function free
    free(x);
    return 0;
}
