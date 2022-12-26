
# include <stdio.h>
# include <math.h>

/* Driver program to test above function */
int main()
{
    int n;
    printf("Please enter n\n",n);
    scanf("%d",&n);
    if (n%2 == 0){
        printf("2 ");
    }

    while (n%2==0){
        n = n/2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        if (n%i == 0)
        {
            int result = i;
            printf("%d ", result);

            while (n%i==0){
                n = n/i;
            }
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        int result = n;
        printf ("%d ", result);
    }
    return 0;
}

