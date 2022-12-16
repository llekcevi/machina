/* 
novi red je ascii znak !
carriage return

u random_test ne treba array za svih milijun brojeva

crlf
lf

veliki brojevi i čitljivost - odvojiti apostrofima npr. 1'000'000

standard deviation

imenovati varijablje u loopovima na razumljiv način

danas još malo o funkcijama

ram kao vrpca pa funkcije koje imaju dvodimenzionalno polje u parametru treba točnu veličinu polja
prva dimenzija se može izostaviti, ali "ako vam je do ljepote koda, ostavite"


pointer - adresa, pokazivač na original

što kad ne žališ da ti funkcija promijeni original?
    stavi argument kao konstant (const) - read only - često u dokumentaciji

reference
problem s return - vraća samo jednu vrijednost

int& broj;

to je referenca na int imena broj - drugo ime za isti objekt, to je alias
pomoću reference možeš promijeniti original kada ne mijenja original u argumentu unutar f() 

deklaracija i definicija funkcije

compiler i linker
header file ne ulazi u compile proces - možeš ga uključiti u pojedinačne .cpp fileove #include
tu su deklaracije funkcija, a u .cpp fajlovima su definicije
 */