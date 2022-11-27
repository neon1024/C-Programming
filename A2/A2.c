#include <stdio.h>
#include <string.h>

#define max_set_length 100
#define max_digits 10

int main()
{
    int set_of_integers[max_set_length];
    int number_of_integers_to_read;
    int integer;
    int ok;
    int digit;
    int max_value = 0;
    int min_value = 999999999;

    while(1)
    {
        printf("Number of integers to read: ");

        char user_input[max_digits];

        scanf("%s", &user_input);

        number_of_integers_to_read = 0;

        ok = 1;

        for(int i=0;i<strlen(user_input);i++)
        {
            if(strchr("0123456789", user_input[i])==0 || user_input[i] == '-' || user_input[i] == '.')
            {
                printf("Invalid input. Try again\n");

                ok = 0;

                break;
            }

            digit = user_input[i] - '0';

            number_of_integers_to_read = number_of_integers_to_read*10 + digit;
        }

        if(ok)
            break;
    }

    for(int i=0;i<number_of_integers_to_read;i++)
    {
        while(1)
        {
            printf("integer %d: ", i);

            char user_input[max_digits];

            scanf("%s", &user_input);

            integer = 0;

            ok = 1;

            for(int i=0;i<strlen(user_input);i++)
            {
                if(strchr("0123456789", user_input[i])==0 || user_input[i] == '-' || user_input[i] == '.')
                {
                    printf("Invalid input. Try again\n");

                    ok = 0;

                    break;
                }

                digit = user_input[i] - '0';

                integer = integer*10 + digit;
            }

            set_of_integers[i] = integer;

            if(ok)
                break;
        }

        max_value = (set_of_integers[i] > max_value ? set_of_integers[i] : max_value);

        min_value = (set_of_integers[i] < min_value ? set_of_integers[i] : min_value);
    }

    for(int i=0;i<number_of_integers_to_read;i++)
        printf("%d ", set_of_integers[i]);

    printf("\nMinimum value: %d", min_value);

    printf("\nMaximum value: %d", max_value);

       return 0;
}
