#include <stdio.h>
#include <cassert>

#define MY_END_CUSTOM          "\033[0m"
#define MY_BLUE_AND_CURSIVE    "\033[3;34m"
#define MY_GREEN_AND_CURSIVE   "\033[3;32m"

const int MAX_LEN = 100;

void bubble_sort(int* array, int len_array);
void print_array(int* array, int len_array);
void match_elements(int* elem_1, int* elem_2);
void shaker_sort(int* array, int len_array);

int main()
{
    int initial_array_1[MAX_LEN] = {67, 2, 10, 66, 77, 20, 21, 43, 42, 52, 80}; // канарейки есть
    int initial_array_2[MAX_LEN] = {67, 2, 10, 66, 77, 20, 21, 43, 42, 52, 80};

    initial_array_1[MAX_LEN - 1] = 69;
    initial_array_2[MAX_LEN - 1] = 69;

    int* real_data_1 = initial_array_1 + 1;
    int* real_data_2 = initial_array_2 + 1;

// Bubble ----------------------------------------------------------------------------------
    printf(MY_BLUE_AND_CURSIVE "Before Bubble Sort:  " MY_END_CUSTOM);
    print_array(real_data_1, MAX_LEN - 2);

    bubble_sort(real_data_1, MAX_LEN - 2);

    printf(MY_BLUE_AND_CURSIVE "After Bubble Sort:  " MY_END_CUSTOM);
    print_array(real_data_1, MAX_LEN - 2);

    printf(MY_GREEN_AND_CURSIVE "%s\n", "~~~~~~~~~~~~~~~~~~" MY_END_CUSTOM);

// Shaker -----------------------------------------------------------------------------------
    printf(MY_BLUE_AND_CURSIVE "Before Shaker Sort:  " MY_END_CUSTOM);
    print_array(real_data_2, MAX_LEN - 2);

    shaker_sort(real_data_2, MAX_LEN - 2);

    printf(MY_BLUE_AND_CURSIVE "After Shaker Sort:  " MY_END_CUSTOM);
    print_array(real_data_2, MAX_LEN - 2);

    printf(MY_GREEN_AND_CURSIVE "%s\n", "~~~~~~~~~~~~~~~~~~" MY_END_CUSTOM);
}

void bubble_sort(int* array, int len_array)
{
    assert(array[-1] == 67 && array[len_array] == 69); 

    for (int i = 0; i < len_array - 1; i++)
    {
        for (int j = 0; j < len_array - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                match_elements(&array[j], &array[j + 1]);
                assert(array[-1] == 67 && array[len_array] == 69);
            }
        }
    }
}

void shaker_sort(int* array, int len_array)
{
    assert(array[-1] == 67 && array[len_array] == 69);

    int complite = 1;
    int right = len_array;
    int left = 0;
    while (complite != 0)
    {
        complite = 0;
        
        for (int j = left; j < right - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                match_elements(&array[j], &array[j + 1]);
                complite = 1;

                assert(array[-1] == 67 && array[len_array] == 69);
            }
        }

        for (int i = right - 1; i > left; i--)
        {
            if (array[i] < array[i - 1])
            {
                match_elements(&array[i - 1], &array[i]);
                complite = 1;

                assert(array[-1] == 67 && array[len_array] == 69);
            }            
        }
    }
}

// void quick_sort(int* array, int len_array)
// {

// }

void print_array(int* array, int len_array)
{
    for (int i = 0; i < len_array; i++)
    {
        if (array[i] != 0)
        {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

void match_elements(int* elem_1, int* elem_2)
{
    int temp = *elem_1;
    *elem_1 = *elem_2;
    *elem_2 = temp;
}