#include "montgomery.h"

void crtModExp(digit_t *result, digit_t *x, digit_t *e, digit_t *p, digit_t *q, size_t nbDigits) {

}

void montModExp(digit_t *result, digit_t *x, digit_t *e, digit_t *m, size_t nbDigits) {
    digit_t base[1];
    digit_t baseShifted[nbDigits+1];

    base[0] = 2;

    printf("----> Montgomery\n");

    mpShiftLeft(baseShifted, base, nbDigits*sizeof(digit_t)*8-1, nbDigits+1);
    mpPrintNL(baseShifted, nbDigits+1);
}

void montModMultiply(unsigned char *m, unsigned char *a, unsigned char *b, unsigned char *n, unsigned char nPrime, size_t nbChars) {
    unsigned short i;
    unsigned short j;
    unsigned short t;
    unsigned short tmp;

    unsigned char c;
    unsigned char u[nbChars+1];

    unsigned char n0 = n[0];
    unsigned char b0 = b[0];

    for (i = 0; i < nbChars; i++) {
        for (j = 0; j < i; j++) {
            tmp = (unsigned char)(tmp) + a[j]*b[i-j];

            t = t + (tmp >> 8);

            tmp = (unsigned char)(tmp) + m[j]*n[i-j];
            t = t + (tmp >> 8);
        }

        tmp = (unsigned char)(tmp) + a[i]*b0;
        t = t + (tmp >> 8);

        c = (unsigned char)(tmp)*nPrime;
        m[i] = c;

        tmp = (unsigned char)(tmp) + c*n0;
        tmp = t + (tmp >> 8);
        t = tmp >> 8;
    }

    for (i = nbChars; i < 2*nbChars; i++) {
        for (j = i-nbChars+1; j < nbChars; j++) {
            tmp = (unsigned char)(tmp)  + a[j]*b[i-j];
            t = t + (tmp >> 8);

            tmp = (unsigned char)(tmp) + m[j]*n[i-j];
            t = t + (tmp >> 8);
        }

        m[i-nbChars] = (unsigned char)(tmp);
        tmp = (unsigned char)(t);
        t = t >> 8;
    }

    m[nbChars] = tmp;
    tmp = m[0] - n[0];

    for (i=0; i < nbChars; i++) {
        tmp = m[i] - n[i] - (tmp >> 8);
        u[i] = tmp;
    }

    if ((tmp >> 8) == 0) {
        for (i = 0; i < nbChars; i++) {
            m[i] = u[i];
        }
    }
}