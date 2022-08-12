#include <stdio.h>
#include <math.h>

#define N 8
#define pi 3.14159265

float X_Re[N], X_Img[N], x_Re[N], x_Img[N], MagX[N];

void DFT()
{
    for (int k = 0; k < N; k++)
    {
        for (int n = 0; n < N; n++)
        {
            X_Re[k] += x_Re[n] * cos((2 * pi * n * k) / N) + x_Img[n] * sin((2 * pi * n * k) / N);
            X_Img[k] += x_Img[n] * cos((2 * pi * n * k) / N) - x_Re[n] * sin((2 * pi * n * k) / N);
        }
        MagX[k] = sqrt(pow(X_Re[k], 2) + pow(X_Img[k], 2));
    }
}

void getSequence()
{
    printf("\nEnter the %d point sequence in order of real and complex number:\n", N);
    for (int n = 0; n < N; n++)
    {
        printf("%d\t", n + 1);
        scanf("%f %f", &x_Re[n], &x_Img[n]);
    }
    for (int n = 0; n < N; n++)
    {
        X_Re[n] = 0;
        X_Img[n] = 0;
    }
}

void printSequence()
{
    printf("\n%d point DFT of given sequence:\n\n", N);
    for (int k = 0; k < N; k++)
        printf("%f + (%f)i\n", X_Re[k], X_Img[k]);
    printf("\nMagnitude of DFT is:\n");
    for (int k = 0; k < N; k++)
        printf("%f\n", MagX[k]);
}

void main(void)
{
    getSequence();
    DFT();
    printSequence();
}
