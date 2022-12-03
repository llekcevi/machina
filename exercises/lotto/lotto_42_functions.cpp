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

void ChooseNumbers(int chosenNumbers[7])
{
    for (int i = 0; i < 7; i++)
    {
        bool valid_number = true;
        int number;

        do
        {
            std::cout << "Input " << i + 1 << ". number (1 - 42)" << std::endl;
            std::cin >> number;
            valid_number = !CheckForDuplicates(chosenNumbers, number) &&
                           ((number > 0) && (number < 43));

        } while (!valid_number);
        chosenNumbers[i] = number;
    }
    std::cout << "-----------------------" << std::endl;
}

void GenerateRandomNumbers(int randomNumbers[7])
{
    for (int i = 0; i < 7; i++)
    {
        bool valid_number = true;
        int number;

        do
        {
            number = rand() % 42 + 1;
            valid_number = !CheckForDuplicates(randomNumbers, number);

        } while (!valid_number);

        randomNumbers[i] = number;
    }
}

void ShowRandomNumbers(int randomNumbers[7])
{   std::cout<<"Lotto numbers: "<<std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << randomNumbers[i] << " ";
    }
    std::cout << " \n-----------------------" << std::endl;
}

void CheckMatchingNumbers(int randomNumbers[7], int chosenNumbers[7])
{
    std::cout << "you have guessed: " << std::endl;

    for (int r = 0; r < 7; r++)
    {
        for (int c = 0; c < 7; c++)
        {
            if (randomNumbers[r] == chosenNumbers[c])
                std::cout << chosenNumbers[c];
        }
    }
    std::cout << "\n-----------------------" << std::endl;
    std::cout << std::endl;
}