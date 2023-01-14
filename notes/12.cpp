/* 
state machine

primjer semafora - različiti int simboliziraju različita stanja pa trebamo
varijablu koja pohranjuje trenutno stanje
trenutno stanje je neki int, a kad se stanje promijeni, na njegovom mjestu je neki drugi int

invalid state, neodređeno stanje - paziti što kreće nakon njega

enum? - način da nekom broju daš ime
kad ti je važnije što neka vrijednost predstavlja nego koji je to broj
vrijednosti unutra su indeksi
enum kad se imenuje dolazi kao type

enum class - scoped  enum
<argument> je template argument

<stl>

vektori - niz podataka varijabilne veličine

accesing a value
vektor[] ne radi provjeru valjanosti indeksa

string je vektor charova

 */

#include <iostream>
#include <cmath>

enum StanjeSemafora{
    crveno,
    crveno_zuto,
    zuto,
    zuto_treperi,
    zeleno,
    zeleno_treperi
};

int main()
{   
    std::vector<int> vektor;

    std::cout<<vektor.capacity()<<std::endl;
    return 0;
}