#include "mybigint.h"

#define DIGITS "digits.txt"
#define PRIME_NUMBER "primes.txt"
#define RESULT_F_SUM "results/result_sum.txt"
#define RESULT_F_MUL "results/result_mul.txt"
#define RESULT_F_POW "results/result_pow.txt"
#define RESULT_F_BIGGEST_PRIME "results/result_biggest_prime.txt"
#define RESULT_F_PRIME_NUMBER "results/result_prime_number.txt"

int fopen_msg(FILE **fp, const char *str, const char *mode) {
    *fp = fopen(str, mode);
    if (!*fp) {
        printf("File %s can't be opened!", str);
        return 1;
    }
    return 0;
}

int main() {
    FILE *fp, *primesFp, *resultFpSum, *resultFpMul, *resultFpPow, *resultFpBiggestPrime, *resultFpPrimeNumber;
    BigInt num1, num2, result;
    mpz_t mpzNum1, mpzResult, mpzExp;
    char *str1, *str2, *primeStr;
    bool isPrimeNumber;
    int res = 0;

    res += fopen_msg(&fp, DIGITS, "r");
    res += fopen_msg(&primesFp, PRIME_NUMBER, "r");
    res += fopen_msg(&resultFpSum, RESULT_F_SUM, "w");
    res += fopen_msg(&resultFpMul, RESULT_F_MUL, "w");
    res += fopen_msg(&resultFpPow, RESULT_F_POW, "w");
    res += fopen_msg(&resultFpBiggestPrime, RESULT_F_BIGGEST_PRIME, "w");
    res += fopen_msg(&resultFpPrimeNumber, RESULT_F_PRIME_NUMBER, "w");

    if (res) return 1;

    str1 = getBigIntStr(fp);
    str2 = getBigIntStr(fp);
    primeStr = getBigIntStr(primesFp);

    if (!strlen(str1) || !strlen(str2)) {
        printf("Number format error: 2 numbers in %s required!", DIGITS);
        return 1;
    }

    if (!strlen(primeStr)) {
        printf("Number format error: 1 number in %s required!", PRIME_NUMBER);
        return 1;
    }

    // SUM()
    getBigInt(str1, &num1);
    getBigInt(str2, &num2);
    result = sumBigInt(num1, num2);
    printBigInt(result, resultFpSum);
    freeBigInt(&num1);
    freeBigInt(&num2);
    freeBigInt(&result);
    ////

    // MUL()
    getBigInt(str1, &num1);
    getBigInt(str2, &num2);
    result = mulBigInt(num1, num2);
    printBigInt(result, resultFpMul);
    freeBigInt(&num1);
    freeBigInt(&num2);
    freeBigInt(&result);
    ////

    // POW()
    powBigInt(str1, str2, &mpzNum1, &mpzExp, &mpzResult);
    gmp_fprintf(resultFpPow, "%Zd\n", mpzResult);
    mpz_clears(mpzNum1, mpzExp, mpzResult, NULL);
    ////

    // // BIGGEST PRIME
    powBigInt("2", "82589933", &mpzNum1, &mpzExp, &mpzResult) ;
    mpz_sub_ui(mpzResult, mpzResult, 1);
    gmp_fprintf(resultFpBiggestPrime, "%Zd\n", mpzResult);
    mpz_clears(mpzNum1, mpzResult, NULL);
    // ////

    // PRIME
    mpz_init(mpzNum1);
    mpz_set_str(mpzNum1, primeStr, 10);
    isPrimeNumber = isPrime(mpzNum1); 
    gmp_fprintf(resultFpPrimeNumber, "Number below is %s number\n%Zd\n", isPrimeNumber ? "a prime" : "not a prime", mpzNum1);
    mpz_clear(mpzNum1);

    fclose(fp);
    fclose(primesFp);
    fclose(resultFpSum);
    fclose(resultFpMul);
    fclose(resultFpPow);
    fclose(resultFpBiggestPrime);
    fclose(resultFpPrimeNumber);
    free(str1);
    free(str2);
    free(primeStr);

    return 0;
}