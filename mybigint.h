#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BIG_INT {
    unsigned char *digit;
    int length;
} BigInt;

void getBigInt(FILE *fp, BigInt *num);
BigInt zeroBigInt(int length);
BigInt sumBigInt(BigInt num1, BigInt num2);
BigInt mulBigInt(BigInt num1, BigInt num2);
BigInt powBigInt(BigInt base, int exp);
int compareBigInt(BigInt num1, BigInt num2);
// void printBigInt(BigInt num);
void printBigInt(BigInt num, FILE *fp);
void freeBigInt(BigInt *num);