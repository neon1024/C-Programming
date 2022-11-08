/*
        5. Knowing that we have coins of 1, 2 and 5 units, determine the minimum number of coins t pay a gievn amount.
*/

#include <stdio.h>

int main()
{
        int coin[6]={0};

        int amount;

        printf("Given amount to pay: ");

        scanf("%d", &amount);

        while(amount/5)
        {
                amount-=5;

                coin[5]++;
        }

        while(amount/2)
        {

                amount-=2;

                coin[2]++;
        }

        while(amount)
        {

                amount--;

                coin[1]++;
        }

        printf("Coins of type 5 used: %d\n", coin[5]);

        printf("Coins of type 2 used: %d\n", coin[2]);

        printf("Coins of type 1 used: %d\n", coin[1]);

        return 0;
}
