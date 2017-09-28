#include <stdio.h>

float function(float x)
{
    float fx;

    //Interchangable Formula
    fx = 3 * x  + 4 * ( x * x );
    //Interchangable Formula

    return fx;
}

void left(float small, float rectangles, float deltax)
{
    int i;
    float subtotal, total = 0, final;
    for (i = 0; i < rectangles; i++)
    {
        subtotal = function(small);
        total = total + subtotal;
        small = small + deltax;
    }
    final = total * deltax;
    printf("%f\n", final);
}
void right(float large, float rectangles, float deltax)
{
    int i;
    float subtotal, total = 0, final;
    for (i = 0; i < rectangles; i++)
    {
        subtotal = function(large);
        total = total + subtotal;
        large = large - deltax;
    }
    final = total * deltax;
    printf("%f\n", final);
}
int mid(float small, float rectangles, float deltax)
{
    int i;
    float subtotal, total = 0, final;
    small = small + (deltax / 2);
    for (i = 0; i < rectangles; i++)
    {
        subtotal = function(small);
        total = total + subtotal;
        small = small + deltax;
    }
    final = total * deltax;
    printf("%f\n", final);
}
int main()
{
    int k = 1;
    int endpoint;
    int rectangles;
    float small, large;
    float deltax, range;

    //Determine which approximation to use
    while (k == 1)
    {
        printf("***Riemann Sum Calculator***\n");
        printf("1. Left endpoint\n");
        printf("2. Right endpoint\n");
        printf("3. Midpoint\n");
        printf("Select one: ");
        scanf("%d", &endpoint);
        if (endpoint == 1 || endpoint == 2 || endpoint == 3)
            k = 0;
    }

    printf("What x range does it cover?\n");
    printf("Lower bound: ");
    scanf("%f", &small);
    printf("Higher bound: ");
    scanf("%f", &large);

    range = large - small;
    printf(" Your range is %.2f\n", range);

    printf("How many rectangles: ");
    scanf("%d", &rectangles);

    deltax = range / rectangles;

    printf("%.8f is your deltax\n", deltax);

    //find area

    switch (endpoint)
    {
    case 1:
        left(small, rectangles, deltax);
        break;
    case 2:
        right(large, rectangles, deltax);
        break;
    case 3:
        mid(small, rectangles, deltax);
        break;
    }

    return 0;
}
