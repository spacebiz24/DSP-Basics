#include <stdio.h>
#include <math.h>

#define N 8

float H[N], X[N], HMat[N][N], C[N];

void setVars()
{
    for (int i = 0; i < N; i++)
    {
        H[i] = 0.0;
        X[i] = 0.0;
        C[i] = 0.0;
        for (int j = 0; j < N; j++)
            HMat[i][j] = 0.0;
    }
}

void getSequences()
{
    int S1, S2;
    printf("Enter the sizes of both signals:\n");
    scanf("%d %d", &S1, &S2);
    printf("Enter the first signal whose size is less than %d:\n", N);
    for (int n = 0; n < S1; n++)
    {
        printf("%d\t", n + 1);
        scanf("%f", &X[n]);
    }
    printf("Enter the second signal whose size is less than %d:\n", N);
    for (int n = 0; n < S2; n++)
    {
        printf("%d\t", n + 1);
        scanf("%f", &H[n]);
    }
}

void matrixArrange()
{
    float temp;
    for (int n = 0; n < N; n++)
    {
        for (int k = 0; k < N; k++)
        {
            HMat[k][n] = H[k];
        }
        temp = H[N - 1];
        for (int i = N - 1; i >= 0; i--)
        {
            H[i] = H[i - 1];
        }
        H[0] = temp;
    }
}

void matrixMultiply()
{
    for (int n = 0; n < N; n++)
    {
        for (int k = 0; k < N; k++)
        {
            C[n] += HMat[n][k] * X[k];
        }
    }
}

void printSequences()
{
    printf("The convolution sum is:\n");
    for (int k = 0; k < N; k++)
        printf("%f\t", C[k]);
}

void main(void)
{
    setVars();
    getSequences();
    matrixArrange();
    matrixMultiply();
    printSequences();
}