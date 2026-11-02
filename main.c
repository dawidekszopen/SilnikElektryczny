#include <stdio.h>
#include "silnikElektryczny.h"
#include <math.h>

int main(void) {

    FILE *fptr;

    fptr = fopen("wynik.txt","a");

    init(0.05, 0.08, 0.02, 50, 1.5, 0.2, 67);
    // printf("T[s] \t M[N*m] \t ε[rad/s^2] \t W[rad/s] \t α \t v \n");
    fprintf(fptr,"T[s] \t M[N*m] \t ε[rad/s^2] \t W[rad/s] \t α \t v \n");
    while (czyCzasSieSkonczyl()) {
        oblicz();
        fprintf(fptr,"%.2f \t %f \t %f \t %f \t %f \t %f\n", dajT(), dajM(), dajPrzyspieszenieKatowe(), dajW(), fmod(dajAlfa(), 360.0), dajW()*60/(2.0*3.14));

    }


    return 0;
}
