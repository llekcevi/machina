#include <iostream>
#include "lotto_42.h"
#include "lotto_42_functions.cpp"

int main()
{
    int random_numbers[7] = {};
    int chosen_numbers[7] = {};
    srand(time(0));

    GenerateRandomNumbers(random_numbers);
    ChooseNumbers(chosen_numbers);
    system("clear");
    ShowRandomNumbers(random_numbers);
    CheckMatchingNumbers(random_numbers, chosen_numbers);
    return 0;
}