#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gmp.h>

#define DIGITS "digits.txt"
#define PRIME_NUMBER "primes.txt"
#define RESULT_F_SUM "results/result_sum.txt"
#define RESULT_F_MUL "results/result_mul.txt"
#define RESULT_F_POW "results/result_pow.txt"
#define RESULT_F_BIGGEST_PRIME "results/result_biggest_prime.txt"
#define RESULT_F_PRIME_NUMBER "results/result_prime_number.txt"
#define RESULT_F_REL_PRIME_NUMBER "results/result_rel_prime_number.txt"
#define RESULT_F_GEN_PRIME_NUMBER "results/result_gen_prime_number.txt"
#define RESULT_F_GEN_REL_PRIME_NUMBER "results/result_gen_rel_prime_number.txt"

enum fileVars {
    resultFpSum,
    resultFpMul,
    resultFpPow,
    resultFpBiggestPrime,
    resultFpPrimeNumber,
    resultFpRelPrimeNumber,
    resultFpGenPrimeNumber,
    resultFpGenRelPrimeNumber,
    filesAmount
};

typedef struct BIG_INT {
    char *digit;
    int length;
} BigInt;

void generatePrimeNumbers   (FILE *fp, mpz_t maxNum);
void generateRelPrimeNumbers(FILE *fp, mpz_t maxNum);

bool isPrime(mpz_t num);
bool isRelPrime(mpz_t num1, mpz_t num2);

void getBigInt(char *str, BigInt *num);
char *getBigIntStr(FILE *fp);

BigInt zeroBigInt(int length);
BigInt sumBigInt(BigInt num1, BigInt num2);
BigInt mulBigInt(BigInt num1, BigInt num2);
void powBigInt(char *str1, char *str2, mpz_t *num1, mpz_t *exp, mpz_t *result);
void printBigInt(BigInt num, FILE *fp);
void freeBigInt(BigInt *num);