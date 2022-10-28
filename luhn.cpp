#include <iostream>
#include <string>
//5437 7805 4231 787 ?

int main() {
    std::cout << "Luhn Algorithm" << std::endl;

    std::string number = "543778054231787";
    std::string digits_ready;
    int sum;
    int last_digit;

    for (int i = 0; i < number.size(); i++) {
        if (i%2 == 0) {
            char digit = number[i];
            int idigit = (digit - '0')*2;
            if (idigit > 9) {idigit = 1 + idigit%10;}
            //std::cout<<idigit<<std::endl;
            digits_ready += std::to_string(idigit);
        }
        else {digits_ready += number[i];}
        //std::cout << number[i] << std::endl;;
    }

    for (int i = 0; i < digits_ready.size(); i++) {
        int digit = (digits_ready[i])-'0';
        sum += digit;
    }

    last_digit = 10 - sum % 10;
    std::cout << number << std::endl;
    /* std::cout << digits_ready << std::endl;
    std::cout<<sum<<std::endl; */
    std::cout<<"Last digit is "<<last_digit<<std::endl;
    return 0;
}
