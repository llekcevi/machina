/* 
ninth lecture

objekti - dobra paralela excel ili db

klase, strukture i unije su objekti u c++

struct

instance objekta - konkretan objekt nastao iz "kalupa" klase

unutar metode objekta imaš pristup varijablama objekta

interface objekta - otvor vanjskom svijetu

 */

struct koordinata
{
    float x, y;   
    void funkcija();
};

void koordinata :: funkcija() 
{

}

int main()
{

    koordinata k;
    k.funkcija;
    return 0;

}