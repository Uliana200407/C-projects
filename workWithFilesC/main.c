
#include<stdio.h>
#include <stdlib.h>
int avlrollno(int rno);
int deleteFile();
struct Country
{
    int Num;
    char name[50];
    float square;
    float quantityOfPeople;
}country;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
    char error,ch;
    FILE *fp;
    fp = fopen("Record", "a");
    do
    {
        error=0;
        printf("Enter the roll number :");
        scanf("%d%c", &country.Num, &ch);
        if (ch!='\n')
        {
            error=1;
            fflush(stdin);
            printf("Error inputting roll number\n");
        }
        ch = 0;
    } while(error);

    printf("Enter the name of the country :");
    scanf("%s",&country.name);

    do
    {
        error=0;
        printf("Enter the square of the country :");
        scanf("%f%c", &country.square,&ch);
        if (ch!='\n')
        {
            error=1;
            fflush(stdin);
            printf("Error inputting square\n");
        }
        ch = 0;
    } while(error);
    do
    {
        error=0;
        printf("Enter the quantity of people in the country :");
        scanf("%f%c", &country.quantityOfPeople,&ch);
        if (ch!='\n')
        {
            error=1;
            fflush(stdin);
            printf("Error inputting quantity\n");
        }
        ch = 0;
    } while(error);

    fwrite(&country, sizeof(country), 1, fp);
    fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
    FILE *fp1;
    fp1 = fopen("Record", "r");
    printf("\nNum\t\tName\t\tSquare\t\tQuantityOfPeople\n\n");
    while (fread(&country, sizeof(country), 1, fp1))
        printf("  %d\t\t%s\t\t%.2f\t\t\t%.2f\n", country.Num, country.name, country.square, country.quantityOfPeople);

    fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
    FILE *fp2;
    int r, s, avl;
    char error,ch;
    do
    {
        error=0;
        printf("\nEnter the roll number you want to search :");
        scanf("%d%c", &r,&ch);
        if (ch!='\n')
        {
            error=1;
            fflush(stdin);
            printf("Error inputting square\n");
        }
        ch = 0;
    } while(error);

    avl = avlrollno(r);
    if (avl == 0)
        printf("Roll No %d is not available in the file\n",r);
    else
    {
        fp2 = fopen("Record", "r");
        while (fread(&country, sizeof(country), 1, fp2))
        {
            s = country.Num;
            if (s == r)
            {
                printf("\nRoll number = %d", country.Num);
                printf("\nName = %s", country.name);
                printf("\nSquare = %.2f", country.square);
                printf("\nQuantity = %.2f\n", country.quantityOfPeople);
            }
        }
        fclose(fp2);
    }
}
//    FUNCTION TO DELETE A RECORD


void deletefile()
{
    FILE *fpo;
    FILE *fpt;
    int r, s;
    printf("Enter the Roll no you want to delete :");
    scanf("%d", &r);
    if (avlrollno(r) == 0)
        printf("Roll no %d is not available in the file\n", r);
    else
    {
        fpo = fopen("Record", "r");
        fpt = fopen("TempFile", "w");
        while (fread(&country, sizeof(country), 1, fpo))
        {
            s = country.Num;
            if (s != r)
                fwrite(&country, sizeof(country), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record", "w");
        fpt = fopen("TempFile", "r");
        while (fread(&country, sizeof(country), 1, fpt))
            fwrite(&country, sizeof(country), 1, fpo);
        printf("\nRECORD DELETED\n");
        fclose(fpo);
        fclose(fpt);
    }

}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    printf("Enter roll number to update :");
    scanf("%d", &r);
    avl = avlrollno(r);
    if (avl == 0)
    {
        printf("Roll number %d is not Available in the file", r);
    }
    else
    {
        fpo = fopen("Record", "r");
        fpt = fopen("TempFile", "w");
        while (fread(&country, sizeof(country), 1, fpo))
        {
            s = country.Num;
            if (s != r)
                fwrite(&country, sizeof(country), 1, fpt);
            else
            {
                printf("\n\t1. Update Name of Roll Number %d", r);
                printf("\n\t2. Update Square of Roll Number %d", r);
                printf("\n\t3. Update Quantity of Roll Number %d", r);
                printf("\n\t4. Update everything %d", r);
                printf("\nEnter your choice :");
                scanf("%d", &ch);
                switch (ch)
                {
                    case 1:
                        printf("Enter Name :");
                        scanf("%s", &country.name);
                        break;
                    case 2:
                        printf("Enter Square :");
                        scanf("%f", &country.square);
                        break;
                    case 3:
                        printf("Enter Quantity :");
                        scanf("%f", &country.quantityOfPeople);
                        break;
                    case 4:
                        printf("Enter Name :");
                        scanf("%s", &country.name);
                        printf("Enter Square :");
                        scanf("%f", &country.square);
                        printf("Enter Quantity :");
                        scanf("%f", &country.quantityOfPeople);
                        break;

                    default:
                        printf("Invalid Selection");
                        break;
                }
                fwrite(&country, sizeof(country), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record", "w");
        fpt = fopen("TempFile", "r");
        while (fread(&country, sizeof(country), 1, fpt))
        {
            fwrite(&country, sizeof(country), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
        printf("RECORD UPDATED");
    }
}
/* FUNCTION TO SORT THE RECORD */
void sort()
{
    int choice;
    char ch,error;
    do
    {
        error=0;
        printf("Enter 1 to sort in ascending manner and 2 in descending one :");
        scanf("%d%c",&choice,&ch); //!!! checking!!!
        if (ch!='\n')//checking buffering zone inputting (stdin)
        {
            error=1;
            continue;}
        if(choice != 1 && choice != 2) {
            printf("Number is out of our range\n");
            fflush(stdin);
            error = 1;
            ch = ' ';
        }
    } while(error);
    ch = ' ';

    int a[20], count = 0, i, j, t, c;
    FILE *fpo;
    fpo = fopen("Record", "r");
    while (fread(&country, sizeof(country), 1, fpo))
    {
        a[count] = country.Num;
        count++;
    }
    c = count;
    if(choice==1) {
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (a[i] > a[j]) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }
    else if(choice==2){
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (a[i] < a[j]) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }
    printf("Roll No.\tName\t\tSquare\t\tQuantityOfPeople\n\n");
    count = c;
    for (i = 0; i<count; i++)
    {
        rewind(fpo);
        while (fread(&country, sizeof(country), 1, fpo))
        {
            if (a[i] == country.Num)
                printf("\n %d\t\t %s \t\t %2f \t\t %2f\n", country.Num, country.name, country.square, country.quantityOfPeople);
        }

    }
}
//    FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avlrollno(int rno)
{
    FILE *fp;
    int c = 0;
    fp = fopen("Record", "r");
    while (!feof(fp))
    {
        fread(&country, sizeof(country), 1, fp);

        if (rno == country.Num)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
    int c = 0;
    FILE *fp;
    fp = fopen("Record", "r");
    while (fread(&country, sizeof(country), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
int deleteFile() {
    if( remove("Record") != 0 )
        printf("Error of deleting file");
    else
        printf ("Deleting file succeed");
    return 0;}
// MAIN PROGRAM
int main()
{
    int c, emp;
    do
    {
        printf("\n\t------SELECT_YOUR_CHOICE------\n");
        printf("\n\t1) INSERT RECORDS\n\t2) DISPLAY FILE\n\t3) SEARCH RECORDS");
        printf("\n\t4) DELETE RECORDS\n\t5) UPDATE RECORDS\n\t6) SORT FILE");
        printf("\n\t7) DELETE FILE\n\t8) EXIT FROM APP");
        printf("\n\t-------------------------------\n");
        printf("\nEnter your choice please(1 to 8) :");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
            case 1:
                insert();
                break;
            case 2:
                emp = empty();
                if (emp == 0)
                    printf("\nThe file is EMPTY\n");
                else
                    disp();
                break;
            case 3:
                search();
                break;
            case 4:
                deletefile();
                break;
            case 5:
                update();
                break;
            case 6:
                emp = empty();
                if (emp == 0)
                    printf("\n The file is EMPTY\n");
                else
                    sort();
                break;
            case 7:
                deleteFile();
                break;
            case 8:
                exit(1);
                break;
            default:
                printf("\nYour choice is wrong\nPlease try again...\n");
                break;

        }
    } while (c != 7);
}