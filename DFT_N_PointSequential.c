#include <stdio.h>
#include <math.h>

void main(void)
{
    int N = 8;
    float pi = 3.14159265;
    float x_Re[N], x_Img[N], X_Re[N], X_Img[N], MagX[N];
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
    for (int k = 0; k < N; k++)
    {
        for (int n = 0; n < N; n++)
        {
            X_Re[k] += x_Re[n] * cos((2 * pi * n * k) / N) + x_Img[n] * sin((2 * pi * n * k) / N);
            X_Img[k] += x_Img[n] * cos((2 * pi * n * k) / N) - x_Re[n] * sin((2 * pi * n * k) / N);
        }
        MagX[k] = sqrt(pow(X_Re[k], 2) + pow(X_Img[k], 2));
    }
    printf("\n%d point DFT of given sequence:\n\n", N);
    for (int k = 0; k < N; k++)
        printf("%f + (%f)i\n", X_Re[k], X_Img[k]);
    printf("\nMagnitude of DFT is:\n");
    for (int k = 0; k < N; k++)
        printf("%f\n", MagX[k]);
}