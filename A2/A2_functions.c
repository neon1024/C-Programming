#include <stdio.h>
#include <string.h>

#define max_set_length 100
#define max_digits 10

void print_set(int set[], int set_length)
{
    for(int i=0;i<set_length;i++)
        printf("%d ", set[i]);
}

int is_digit(char character)
{
    return (strchr("0123456789", character));
}

int valid_integer(char user_input[], int *integer)
{
    *integer = 0;

    int is_valid_integer = 1;

    for(int i=0;i<strlen(user_input);i++)
    {
        if(!is_digit(user_input[i]))
        {
            printf("Invalid input. Try again\n");

            is_valid_integer = 0;

            break;
        }

        int digit = user_input[i] - '0';

        *integer = (*integer)*10 + digit;
    }

    return is_valid_integer;
}

int main()
{
    int set_of_integers[max_set_length];
    int number_of_integers_to_read;
    int integer;
    int is_valid_integer;
    int digit;
    int max_value = 0;
    int min_value = 999999999;

    while(1)
    {
        printf("Number of integers to read: ");

        char user_input[max_digits];

        scanf("%s", &user_input);

        is_valid_integer = valid_integer(user_input, &number_of_integers_to_read);

        if(is_valid_integer)
            break;
    }

    for(int i=0;i<number_of_integers_to_read;i++)
    {
        while(1)
        {
            printf("integer %d: ", i);

            char user_input[max_digits];

            scanf("%s", &user_input);

            is_valid_integer = valid_integer(user_input, &integer);

            set_of_integers[i] = integer;

            if(is_valid_integer)
                break;
        }

        max_value = (set_of_integers[i] > max_value ? set_of_integers[i] : max_value);

        min_value = (set_of_integers[i] < min_value ? set_of_integers[i] : min_value);
    }

    print_set(set_of_integers, number_of_integers_to_read);

    printf("\nMinimum value: %d", min_value);

    printf("\nMaximum value: %d", max_value);

       return 0;
}
