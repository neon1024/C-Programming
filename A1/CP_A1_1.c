/*
        2. Read two integers and compute their sum, average and sum of the squares of the numbers
*/

#include <stdio.h>

int main()
{
        int a;

        int b;

        printf("First integer: ");

        scanf("%d", &a);

        printf("Second integer: ");

        scanf("%d", &b);

        printf("Their sum is: %d\n", a+b);

        printf("Their average sum is: %d\n", (a+b)/2);

        printf("Their squares sum is: %d\n", a*a+b*b);

        return 0;
}
