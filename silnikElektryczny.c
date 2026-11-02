#include "silnikElektryczny.h"

#include <math.h>

static double szerokosc;//szerokość ramki [m]
static double wysokosc;//długość ramki [m]
static double masaCalkowita;//całkowita masa ramki. [kg]
static double N;//liczba zwojów. po prostu liczba
static double I;//Natężenie prądu. [A]
static double B;//wektor indukcji magnetycznej. jak silne są magnesy w środku silnika
static double alfa;//kąt pod którym znajdzuję się ramka

static double Tkrok = 0.001;// krok czasowy. [s]
static double Tmax;// całkowity czas symulacji [s]
static double T;// czas w aktualnym momencie programu

//moment bezwładności ramki
static double J;

//moment siły
static double M;

//Prędkość obrotowa
static double W;

//przyspieszenieKatowe
static double przyspieszenieKatowe;


//OBLICZENIA

static double komutator(double alfa1, double I1) {
    if (sin(alfa1) >= 0) {
        return I1;
    }
    return -I1;
}

static void obliczMomentBezwładności() {
    double masaSzerokosc = masaCalkowita*(szerokosc/(2.0*szerokosc + 2.0*wysokosc));
    double masaWysokosc = masaCalkowita*(wysokosc/(2.0*szerokosc + 2.0*wysokosc));

    double JWysokosc = 2.0*(masaWysokosc*pow(szerokosc/2.0, 2.0));
    double JSzerokosc = 2.0*((1.0/12.0)*masaSzerokosc*pow(szerokosc,2.0));
    J = JWysokosc + JSzerokosc;
}


static void obliczMomentSiły() {
    M = N*komutator(alfa, I)*(szerokosc*wysokosc)*B*sin(alfa);
}

static void obliczPrzyspieszenieKatowe() {
    przyspieszenieKatowe = M/J;

    W = W+przyspieszenieKatowe*Tkrok;

    alfa = alfa + W*Tkrok;
}

void oblicz() {
    obliczMomentSiły();
    obliczPrzyspieszenieKatowe();

    T = T + Tkrok;
}

int czyCzasSieSkonczyl() {
    return T<=Tmax;
}
//DOSTAWANIE I ZMIENIANIE DANYCH

double dajPrzyspieszenieKatowe() {
    return przyspieszenieKatowe;
}

//dostajesz moment bezwładności
double dajJ() {
    return J;
}

//dostajesz moment siły
double dajM() {
    return M;
}

//dostajesz prędkość obrotową
double dajW() {
    return W;
}

//dostajesz aktualny czas trwania programu
double dajT() {
    return T;
}

//dostajesz kąt
double dajAlfa() {
    return alfa;
}

//ustawiasz moment bezwładności
void ustawN(double noweN) {
    N = noweN;
}

//ustawiasz moment siły
void ustawI(double noweI) {
    I = noweI;
}

//ustawiasz prędkość obrotową
void ustawB(double noweB) {
    B = noweB;
}

//ustawiasz aktualny czas trwania programu
void ustawTmax(double noweTmax) {
    Tmax = noweTmax;
}

//ustawiasz moment siły
void ustawSzerokosc(double nowaSzerokosc) {
    szerokosc = nowaSzerokosc;
    obliczMomentBezwładności();
}

//ustawiasz prędkość obrotową
void ustawWysokosc(double nowaWysokosc) {
    wysokosc = nowaWysokosc;
    obliczMomentBezwładności();
}

//ustawiasz aktualny czas trwania programu
void ustawMasa(double noweMasa) {
    masaCalkowita = noweMasa;
    obliczMomentBezwładności();
}


//INICJALIZACJA WSTAWIANIE DANYCH

void init(
    double szerokość,
    double wysokość,
    double masa,
    double liczbaZwojow,
    double natezeniePradu,
    double indukcjaMagnetyczna,
    double czasTrwania) {

    szerokosc = szerokość;
    wysokosc = wysokość;
    masaCalkowita = masa;
    N = liczbaZwojow;
    I = natezeniePradu;
    B = indukcjaMagnetyczna;
    alfa = 0.01;

    T = 0;
    Tmax = czasTrwania;

    obliczMomentBezwładności();
}