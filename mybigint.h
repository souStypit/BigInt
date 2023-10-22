#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gmp.h>

typedef struct BIG_INT {
    char *digit;
    int length;
} BigInt;

bool isPrime(mpz_t num);
void getBigInt(char *str, BigInt *num);
char *getBigIntStr(FILE *fp);
BigInt zeroBigInt(int length);
BigInt sumBigInt(BigInt num1, BigInt num2);
BigInt mulBigInt(BigInt num1, BigInt num2);
void powBigInt(char *str1, char *str2, mpz_t *num1, mpz_t *exp, mpz_t *result);
void printBigInt(BigInt num, FILE *fp);
void freeBigInt(BigInt *num);