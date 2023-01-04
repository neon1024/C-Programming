/*
    Scumpu Ioan Robert 916 (neon1024)
*/

// Category 1: With pointers (pointer arithmetics instead of array[i]), but using
// your own user defined functions: 1. Write a program that reads 2 arrays and
// merges the two arrays into third array. Before merging, sort the 2 arrays
// in ascending order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_ARRAY_LENGTH 100

int get_integer_from_console()
{
    int num;

    printf("%s", "integer: ");
    scanf("%d", &num);

    return num;
}

void read_array(int array[], int length)
{
    for(int i = 0; i < length; i++)
    {
        int element;

        printf("element %d: ", i);
        scanf("%d", &element);

        *(array + i) = element;
    }
}

void sort_array(int array[], int length)
{
    int ok;

    do
    {
        ok = 1;

        for(int i = 0; i < length - 1; i++)
            if(*(array + i) > *(array + i + 1))
            {
                int temp = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = temp;
                ok = 0;
            }

    } while (ok == 0);
    
}


void merge_arrays(int a[], int a_len, int b[], int b_len, int c[])
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;

    while(i < a_len && j < b_len)
    {
        if(*(a + i) < *(b + j))
        {
            *(c + k) = *(a + i);
            i++;
            k++;
        }
        else
        {
            *(c + k) = *(b + j);
            j++;
            k++;
        }
    }

    while(i < a_len)
    {
        *(c + k) = *(a + i);
        i++;
        k++;
    }

    while(j < b_len)
    {
        *(c + k) = *(b + j);
        j++;
        k++;
    }
}

void write_array(int array[], int length)
{
    for(int i = 0; i < length; i++)
        printf("%d ", *(array + i));
}

int main()
{
    int array_a[MAX_ARRAY_LENGTH];
    int array_a_length;
    int array_b[MAX_ARRAY_LENGTH];
    int array_b_length;
    int array_c[MAX_ARRAY_LENGTH];

    array_a_length = get_integer_from_console();

    read_array(array_a, array_a_length);

    array_b_length = get_integer_from_console();

    read_array(array_b, array_b_length);

    sort_array(array_a, array_a_length);

    sort_array(array_b, array_b_length);

    merge_arrays(array_a, array_a_length, array_b, array_b_length, array_c);

    write_array(array_c, array_a_length + array_b_length);
    
    return 0;
}
