#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double t1a1[] = {-12, -7.65, -2.4, 0, 1.18, 7.92, 12.888, 24.23};
double t1a2[] = {-13.5, -1.423, 0.023, 1.0112, 2.5};
int t1n1 = 8;
int t1n2 = 5;

double t2a1[] = {-256.44, -101.393, -33.2356, -1.123, 6.8};
double t2a2[] = {-4.543, -1.123, 64.8, 140.231, 236.22, 484.93, 5893.231, 32233.2};
int t2n1 = 5;
int t2n2 = 8;

double t3a1[] = {-23.2, -14.8, 34.69, 39.88, 57.45};
double t3a2[] = {-16.83, -6.34, 8.893, 15.223, 60.54};
int t3n1 = 5;
int t3n2 = 5;

void merge(double a1[], int n1, double a2[], int n2, double res[])
{
    int i1 = 0, i2 = 0, ri = 0;
    while (n1 > i1 && n2 > i2)
    {
        if (a1[i1] > a2[i2])
        {
            if (res[ri - 1] != a2[i2])
            {
                res[ri] = a2[i2];
                printf("%lf ", res[ri]);
                ri++;
            }
            i2++;
        }
        else
        {
            if (res[ri - 1] != a1[i1])
            {
                res[ri] = a1[i1];
                printf("%lf ", res[ri]);
                ri++;
            }
            i1++;
        }
    }
    while (n1 > i1)
    {
        if (res[ri - 1] != a1[i1])
        {
            res[ri] = a1[i1];
            printf("%lf ", res[ri]);
            ri++;
        }
        i1++;
    }
    while (n2 > i2)
    {
        if (res[ri - 1] != a2[i2])
        {
            res[ri] = a2[i2];
            printf("%lf ", res[ri]);
            ri++;
        }
        i2++;
    }
    puts("");
}

int main()
{
    // puts("\ntest case 1");
    // double r1[t1n1 + t1n2];
    // merge(t1a1, t1n1, t1a2, t1n2, r1);

    // puts("\ntest case 2");
    // double r2[t2n1 + t2n2];
    // merge(t2a1, t2n1, t2a2, t2n2, r2);

    // puts("\ntest case 3");
    // double r3[t3n1 + t3n2];
    // merge(t3a1, t3n1, t3a2, t3n2, r3);
    double r1[20], r2[20];
    int n1 = 0, n2 = 0;
    puts("array 1");
    char s1[1000], s2[1000];
    size_t n = 1000;
    char *tok = s1;
    // getline(&tok,&n,stdin);
    fgets(s1,1000,stdin);
    tok = strtok(s1, " ");
    r1[n1] = strtod(s1, NULL);
    n1++;
    while (tok != NULL)
    {
        r1[n1] = strtod(tok,NULL);
        n1++;
        tok = strtok(NULL," ");
    }
    fflush(stdin);

    puts("array 2");
    tok = s2;
    //getline(&tok,&n,stdin);
    fgets(s2,1000,stdin);
    tok = strtok(s2, " ");
    r2[n2] = strtod(s2, NULL);
    n2++;
    while (tok != NULL)
    {
        r2[n2] = strtod(tok,NULL);
        n2++;
        tok = strtok(NULL," ");
    }

    double res[n1 + n2];
    merge(r1, n1, r2, n2, res);
}