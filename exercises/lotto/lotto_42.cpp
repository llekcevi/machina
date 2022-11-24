#include <iostream>

bool CheckForDuplicates(int array[], int number)
{
    for (int i = 0; i < 7; i++)
    {
        if (number == array[i])
        {
            return true;
        }
        else
            continue;
    }
    return false;
}

void ChooseNumbers(int choosenNumbers[7])
{
    for (int i = 0; i < 7; i++)
    {
        bool valid_number = true;
        // include do while loop
        // dok broj nije valid treba vraćati stalno unos, a tek kad bude valid upisuje vrijednost na mjesto
        while (valid_number)
        {
            int number;
            std::cout << "Input " << i + 1 << ". number (1 - 42)" << std::endl;
            std::cin >> number;
            valid_number = !CheckForDuplicates(choosenNumbers, number);
            if (valid_number)
            {
                std::cout << "if" << std::endl;
                choosenNumbers[i] = number;
                break;
            }
            else
            {
                std::cout << "else" << std::endl;

                std::cout << "error" << std::endl;
            }
        }
    }
    std::cout << "-----------------------" << std::endl;
}

void GenerateRandomNumbers(int randomNumbers[7])
{
    for (int i = 0; i < 7; i++)
    {
        randomNumbers[i] = rand() % 42 + 1;
    }
}

void CheckWin(int randomNumbers[7], int choosenNumbers[7], int winNumberCounter)
{
    for (int r = 0; r < 7; r++)
    {
        for (int c = 0; c < 7; c++)
        {
            if (randomNumbers[r] == choosenNumbers[c])
                std::cout << "you have guessed: " << choosenNumbers[c] << std::endl;
            winNumberCounter = winNumberCounter + 1;
        }
    }
}

int main()
{
    int random_numbers[7];
    int choosen_numbers[7] = {};
    int win_number_counter = 0;
    srand(time(0));

    GenerateRandomNumbers(random_numbers);
    ChooseNumbers(choosen_numbers);

    for (int i = 0; i < 7; i++)
    {
        std::cout << random_numbers[i] << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    CheckWin(random_numbers, choosen_numbers, win_number_counter);
    return 0;
}
/* int *a = std::find(std::begin(choosen_numbers), std::end(choosen_numbers), number);

     if (a != std::end(choosen_numbers))
     {
         std::cout << "Number already choosen.";
     }
     else
     {
         choosen_numbers[i] = number;
     } */