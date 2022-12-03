#include <iostream>
#include "lotto_42.h"
#include "lotto_42_functions.cpp"

int main()
{
    int random_numbers[7] = {};
    int chosen_numbers[7] = {};
    int win_number_counter = 0;
    srand(time(0));

    GenerateRandomNumbers(random_numbers);
    ChooseNumbers(chosen_numbers);
    ShowRandomNumbers(random_numbers);
    CheckWin(random_numbers, chosen_numbers, win_number_counter);
    return 0;
}
