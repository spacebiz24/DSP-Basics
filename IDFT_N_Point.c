#include <stdio.h>
#include <math.h>

#define N 8
#define pi 3.14159265

float X_Re[N], X_Img[N], x_Re[N], x_Img[N], MagX[N];

void IDFT()
{
    for (int k = 0; k < N; k++)
    {
        for (int n = 0; n < N; n++)
        {
            x_Re[k] += X_Re[n] * cos((2 * pi * n * k) / N) - X_Img[n] * sin((2 * pi * n * k) / N);
            x_Img[k] += X_Img[n] * cos((2 * pi * n * k) / N) + X_Re[n] * sin((2 * pi * n * k) / N);
        }
        x_Re[k] *= 1.0 / (float)N;
        x_Img[k] *= 1.0 / (float)N;
        MagX[k] = sqrt(pow(x_Re[k], 2) + pow(x_Img[k], 2));
    }
}

void getSequence()
{
    printf("\nEnter the %d point sequence in order of real and complex number:\n", N);
    for (int n = 0; n < N; n++)
    {
        printf("%d\t", n + 1);
        scanf("%f %f", &X_Re[n], &X_Img[n]);
    }
    for (int n = 0; n < N; n++)
    {
        x_Re[n] = 0;
        x_Img[n] = 0;
    }
}

void printSequence()
{
    printf("\n%d point IDFT of given sequence:\n\n", N);
    for (int k = 0; k < N; k++)
        printf("%f + (%f)i\n", x_Re[k], x_Img[k]);
    printf("\nMagnitude of DFT is:\n");
    for (int k = 0; k < N; k++)
        printf("%f\n", MagX[k]);
}

void main(void)
{
    getSequence();
    IDFT();
    printSequence();
}