#ifndef SILNIKELEKTRYCZNY_SILNIKELEKTRYCZNY_H
#define SILNIKELEKTRYCZNY_SILNIKELEKTRYCZNY_H
//Funkcja która rozpoczyna bibliotekę i oblicza moment bezwładności.
//szerokość: szerokość ramki metry
//wysokość: długość ramki metry
//masa: całkowita masa ramki. kilogramy
//liczba_zwojów: liczba zwojów. po prostu liczba
//natezenie_pradu: Natężenie prądu. ampery
//indukcja_magnetyczna: wektor indukcji magnetycznej. jak silne są magnesy w środku silnika
//krokCzasowy: krok czasowy. [s]
//czasTrwania: całkowity czas symulacji [s]
void init(
    double szerokość,
    double wysokość,
    double masa,
    double liczbaZwojow,
    double natezeniePradu,
    double indukcjaMagnetyczna,
    double czasTrwania);

//sprawdzenie czy czas trwania programu się skończył
int czyCzasSieSkonczyl();

//zaczyna obliczenia:
//momentu siły i przyśpieszenie kątowe
void oblicz();

double dajPrzyspieszenieKatowe();
//dostajesz moment bezwładności
double dajJ();
//dostajesz moment siły
double dajM();
//dostajesz prędkość obrotową
double dajW();
//dostajesz aktualny czas trwania programu
double dajT();
//dostajesz kąt
double dajAlfa();

//ustawiasz moment bezwładności
void ustawN(double noweN);
//ustawiasz moment siły
void ustawI(double noweI);
//ustawiasz prędkość obrotową
void ustawB(double noweB);
//ustawiasz aktualny czas trwania programu
void ustawTmax(double noweTmax);
//ustawiasz moment siły
void ustawSzerokosc(double nowaSzerokosc);
//ustawiasz prędkość obrotową
void ustawWysokosc(double nowaWysokosc);
//ustawiasz aktualny czas trwania programu
void ustawMasa(double noweMasa);


#endif //SILNIKELEKTRYCZNY_SILNIKELEKTRYCZNY_H
