#include <iostream>
#include <string>
// 5437 7805 4231 787 ?

int CalucalteCheckDigit(std::string creditCardNumber)
{
    std::string ready_for_sum;
    int sum=0;
    int last_digit;
    for (int i = 0; i < creditCardNumber.size(); i++)
    {
        if (i % 2 == 0)
        {
            char digit = creditCardNumber[i];
            int intDigit = (digit - '0') * 2;
            if (intDigit > 9)
            {
                intDigit = 1 + intDigit % 10;
            }
            ready_for_sum += std::to_string(intDigit);
        }
        else
        {
            ready_for_sum += creditCardNumber[i];
        }
    }

    for (int i = 0; i < ready_for_sum.size(); i++)
    {
        int digit = (ready_for_sum[i]) - '0';
        sum += digit;
    }
    last_digit = (10 - sum % 10) % 10;
    return last_digit;
}

int main()
{
    std::cout << "Luhn's Algorithm" << std::endl;

    std::string number;
    std::cout << "enter credit card number: " << std::endl;
    std::cin>>number;
    std::cout<<"Check digit is: "<<CalucalteCheckDigit(number)<<std::endl;
    
    return 0;
}
