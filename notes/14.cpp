#include <iostream>
/*
- moje pitanje o rješenju koje je predložio
    vektor projektila
    prilikom crtanja svaki pomakneš za jedan

    design pattern s managerima

union - svi članovi dijele istu memorijsku lokaciju - ako promijeniš jedan član, mijenjaš sve

posebni članovi structa
    - this pointer
    - konstruktori - funkcija koja ima ime klase
        - mogu imati overloadove - mogu primati različite parametre
        - member initialization - dvotočka između ) i { kod definicije konstruktora
    - destruktor - na kraju scopea se poziva
    - operatori  - new(dinamička alokacija memorije) - ako pozoveš objekt pointerom, ne radi audomatski konstruktor, ali
                    ako staviš "new", onda se poziva konstruktor i sprema se adresa u pointer varijablu.
        std::ostream ima definiciju operatora << (bitless shift left)
        overload operatora - npr kako zbrajaš dva objekta - što ima smisla kad zbrojiš npr. dvije koordinate
 
 */



int main()
{
    float c = 36.50;
    float F;
    float K;

    F = (c * 1.80) + 32;
    K = c + 273.15;

    std::cout << "celsius" << c << std::endl;
    std::cout << "fahrenheit" << F << std::endl;
    std::cout << "kelvin" << K << std::endl;
    return 0;
}