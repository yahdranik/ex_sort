#include <stdio.h>
#include <cassert>

#define MY_END_CUSTOM          "\033[0m"
#define MY_BLUE_AND_CURSIVE    "\033[3;34m"
#define MY_GREEN_AND_CURSIVE   "\033[3;32m"

const int MAX_LEN = 100;
const size_t ONE = 1;

void bubble_sort(int* array, int len_array);
void print_array(int* array, int len_array);
void swap(int* elem_1, int* elem_2);
void shaker_sort(int* array, int len_array);
void quick_sort(int* array, size_t len_array);

int main()
{
    int initial_array_1[MAX_LEN] = {67, 2, 10, 66, 77, 20, 21, 43, 42, 52, 80}; // канарейки есть
    int initial_array_2[MAX_LEN] = {67, 2, 10, 66, 77, 20, 21, 43, 42, 52, 80};
    int initial_array_3[MAX_LEN] = {67, 2, 10, 66, 77, 20, 21, 43, 42, 52, 80};

    initial_array_1[MAX_LEN - 1] = 69;
    initial_array_2[MAX_LEN - 1] = 69;
    initial_array_3[MAX_LEN - 1] = 69;

    int* real_data_1 = initial_array_1 + 1;
    int* real_data_2 = initial_array_2 + 1;
    int* real_data_3 = initial_array_3 + 1;

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

// Quick --------------------------------------------------------------------------------------
    printf(MY_BLUE_AND_CURSIVE "Before Quick Sort:  " MY_END_CUSTOM);
    print_array(real_data_3, MAX_LEN - 2);

    quick_sort(real_data_3, MAX_LEN - 2);

    printf(MY_BLUE_AND_CURSIVE "After Quick Sort:  " MY_END_CUSTOM);
    print_array(real_data_3, MAX_LEN - 2);
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
                swap(&array[j], &array[j + 1]);
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
                swap(&array[j], &array[j + 1]);
                complite = 1;

                assert(array[-1] == 67 && array[len_array] == 69);
            }
        }

        for (int i = right - 1; i > left; i--)
        {
            if (array[i] < array[i - 1])
            {
                swap(&array[i - 1], &array[i]);
                complite = 1;

                assert(array[-1] == 67 && array[len_array] == 69);
            }            
        }
    }
    assert(array[-1] == 67 && array[len_array] == 69);
}

void quick_sort(void* array, size_t len_array, size_t size_element, int (*compare)(const void* a, const void* b))
{
    uint8_t* ptr = (uint8_t *) array;

    if (len_array <= 1)
    {
        return;
    }

    uint8_t* pivot = ptr;
    uint8_t* left = ptr + size_element;
    uint8_t* right = ptr + len_array * size_element - size_element;

    while ( right > left )
    {
        while (compare(left, pivot) <= 0 && right >= left)
        {
            left += size_element;
        }
        
        while (compare(right, pivot) > 0 && right >= left)
        {
            right -= size_element;
        }

        if (left < right)
        {
            swap(left, right, size_element);
        }
    }

    swap(pivot, right, size_element);
    quick_sort(ptr, (right - ptr) / size_element, size_element, compare);
    quick_sort(right + size_element, len_array - (right - ptr) / size_element - 1, size_element, compare);
}

void print_array(void* array, size_t len_array)
{   
    char* ptr = (char*) array;

    for (int i = 0; i < len_array; i++)
    {
        if (ptr[i] != 0)
        {
            printf("%d ", ptr[i]);
        }
    }
    printf("\n");
}

void swap(void* elem_1, void* elem_2, size_t size_element)
{
    uint8_t temp[size_element];
    memcpy(temp, elem_1, size_element);
    memcpy(elem_1, elem_2, size_element);
    memcpy(elem_2, temp, size_element);

}