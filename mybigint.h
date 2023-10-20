#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BIG_INT {
    unsigned char *digit;
    int length;
} BigInt;

void getBigInt(FILE *fp, BigInt *num);
void sumBigInt(BigInt num1, BigInt num2, BigInt *result);
void mulBigInt(BigInt num1, BigInt num2, BigInt *result);
void printBigInt(BigInt num);
void freeBigInt(BigInt *num);