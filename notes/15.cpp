#include <iostream>
#include <string>

/* 
dinamička alokacija memorije
    - new i delete
- dvije kategorije rama - stack i heap
- stack je lokalna memorija, operativna
    - stupac na koji slažemo lokalne varijable
    - nije zamišljeno za pohranu, nego za trenutno korištenje

- new rezervira nešto memorije na heapu i vrati pointer na nju


pointeri
- varijabla koja pamti adresu u ramu
 */

int main ()
{
    std::string address = "1.1.1.1";

    std::cout<<address<<std::endl;

    for (int i = 0; i < address.size(); i++)
        {   
            if (address[i] == '.')
                {
                    address.insert(i, "[");
                    address.insert(i+2, "]");
                    i++;
                }
        }
    std::cout<<address<<std::endl;

    return 0;
}