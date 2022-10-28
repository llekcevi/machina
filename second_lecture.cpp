#include <iostream>

int main() {
    
}


/*
RAM - rezervacija rama je varijabla
tip i ime(ne početi s brojem)
i slova su brojevi u RAMu ASCII
u ramu samo cijeli brojevi ieee 754

int 4B (32 bit)
float 4B
double 8B
char 1B (2 na 8 = 256)
(jednostruki i dvostruki komplement)

unsigned int svi dostupni pozitivni cijeli - paziti na unsigned int koji ima - predznak
    - unsigned je modifikator (još short(2B) i long modifikatori)
pretvorba tipova ide tako da prvo pretvori u binarni pa iz binarnog u novi tip

bitiwise operator? programiranje widnows prozora i rijetke ostale uporabe

dijelenje intova daje intove - miče sve iza točke

cast operator (tip podatka) npr. (int)nešto - pretvara nešto u int tip ili pišeš kao funkciju

random generator uz pomoć modullo operatora - dobivaš niz koji ide od 0 do djeljenjik-1

DZ program - ispisuje broj po znamenkama od prve do zadnje

    luhn algorithm za kreditne kartice - zadnji broj je check kao u isbnu
    ako je dvoznamenkast pomnožiš znamenke, ako je jednoznamenkast poduplaš - vrijedi za svaki drugi
    zatim zbrojiš sve brojeve i gledaš koliko fali do sljedeće desetice
    [napraviti za van taj credit card check kao isbn check jer je isbn check kao qed nda]

    5437 7805 4231 787 ?  - treba otkriti zadnju znamenku
    

*/