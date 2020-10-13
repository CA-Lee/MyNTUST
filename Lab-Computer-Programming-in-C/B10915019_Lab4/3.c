#include <stdio.h>

int main()
{
    float prices[5] = {2.98, 4.5, 9.98, 4.49, 6.87};
    int vals[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        int id, qty;
        scanf("%d", &id);
        for (int j = 0; j < 7; j++)
        {
            scanf("%d", &qty);
            switch (id)
            {
            case 1:
                vals[0] += qty;
                break;
            case 2:
                vals[1] += qty;
                break;
            case 3:
                vals[2] += qty;
                break;
            case 4:
                vals[3] += qty;
                break;
            case 5:
                vals[4] += qty;
                break;
            }
        }
    }
    double sum = 0;
    for (int i = 0; i < 5; i++)sum+=vals[i]*prices[i];
    printf("%lf",sum);
}