#include <iostream>

void DrawMillion(int array[])
{ //  fills random_array with numbers between 1 and 42
    for (int i = 0; i < 1000001; i++)
    {
        array[i] = (rand() % 42 + 1);
    }
}

void CountNumbers(int array[], int counter[])
{ // every time a number j appears in array, 1 is added to the counter_array on index of j-1
    for (int i = 0; i < 1000001; i++)
    {
        for (int j = 1; j < 43; j++)
        {
            if (array[i] == j)
            {
                counter[j - 1] += 1;
            }
        }
    }
}

void ShowNumberFrequency(int counter[])
{// prints how many times each number occured
    std::cout << "After one milion draws: " << std::endl;

    for (int i = 0; i < 42; i++)
    {
        std::cout << "Number " << i + 1 << " has appeared " << counter[i] << " times." << std::endl;
    }
}

int main()
{
    srand(time(NULL));

    int random_array[1000000];
    int counter_array[42] = {0};

    DrawMillion(random_array);
    CountNumbers(random_array, counter_array);
    ShowNumberFrequency(counter_array);

    return 0;
}