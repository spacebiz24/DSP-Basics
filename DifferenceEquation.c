#include <stdio.h>
#include <math.h>

#define I 50

float A[I], B[I], Y[I], X[I], sumY, sumX;
int D, N, choice;

void signalGenerator()
{
    printf("Enter the signal to generate:\n");
    printf("1. Impulse\n");
    printf("2. Pulse of 10\n");
    printf("3. Step\n");
    printf("4. Ramp\n");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        X[0] = 1;
        for (int i = 1; i < I; i++)
            X[i] = 0;
        break;
    case 2:
        for (int i = 0; i < 10; i++)
            X[i] = 1;
        for (int i = 10; i < I; i++)
            X[i] = 0;
        break;
    case 3:
        for (int i = 0; i < I; i++)
            X[i] = 1;
        break;
    case 4:
        for (int i = 0; i < I; i++)
            X[i] = i;
        break;
    default:
        printf("Wrong value!");
        break;
    }
}

void getValues()
{
    printf("Enter the number of coefficients of Y(....): ");
    scanf("%d", &D);
    printf("Enter the coefficients of Y(....):\n");
    for (int i = 0; i < D; i++)
    {
        printf("A[%d]:\t", i);
        scanf("%f", &A[i]);
    }
    printf("Enter the number of coefficients of X(....): ");
    scanf("%d", &N);
    printf("Enter the coefficients of X(....):\n");
    for (int i = 0; i < N; i++)
    {
        printf("B[%d]:\t", i);
        scanf("%f", &B[i]);
    }
    printf("\n\n");
}

void Solver()
{
    for (int n = 0; n < I; n++)
    {
        sumY = 0.0;
        sumX = 0.0;
        for (int k = 1; (k < D) && (k <= n); k++)
            sumY += A[k] * Y[n - k];
        for (int k = 0; (k < N) && (k <= n); k++)
            sumX += B[k] * X[n - k];
        Y[n] = (-sumY + sumX) / A[0];
    }
}

void printSequence()
{
    printf("The output of the sequence is:\n");
    for (int i = 0; i < I; i++)
        printf("Y[%d] = %f\n", i + 1, Y[i]);
}

void main(void)
{
    getValues();
    signalGenerator();
    Solver();
    printSequence();
}
