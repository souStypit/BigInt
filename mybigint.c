#include "mybigint.h"

bool isPrime(mpz_t num) {
    mpz_t sqrt_num, i, result;
    mpz_inits(sqrt_num, i, result, NULL);

    if (mpz_cmp_ui(num, 1) == 0) return true;

    mpz_sqrt(sqrt_num, num);

    for (mpz_set_ui(i, 2); mpz_cmp(i, sqrt_num) <= 0; mpz_add_ui(i, i, 1)) {
        mpz_mod(result, num, i);

        if (mpz_cmp_ui(result, 0) == 0) {
            mpz_clears(sqrt_num, i, result, NULL);
            return false;
        }
    }

    mpz_clears(sqrt_num, i, result, NULL);

    if (mpz_cmp_ui(num, 1) <= 0) return false;

    return true;
}

void powBigInt(char *str1, char *str2, mpz_t *num1, mpz_t *exp, mpz_t *result) {
    mpz_inits(*num1, *result, *exp, NULL);

    mpz_set_str(*num1, str1, 10);
    mpz_set_str(*exp, str2, 10);

    mpz_pow_ui(*result, *num1, mpz_get_ui(*exp));
}

void getBigInt(char *str, BigInt *num) {
    int c, i = 0;

    num->length = strlen(str);
    num->digit = malloc(sizeof(char) * num->length);
    
    while ((c = str[i]) != ' ' && c != '\n' && c != EOF && c != '\0') {
        num->digit[i++] = c - '0';
    }
}

char *getBigIntStr(FILE *fp) {
    int c, strlen;

    char *str;
    str = malloc(sizeof(char));
    str[0] = '\0';
    strlen = 1;
    
    while ((c = fgetc(fp)) != ' ' && c != '\n' && c != EOF) {
        str = realloc(str, sizeof(char) * (strlen + 1));

        str[strlen - 1] = c;
        strlen++;
    }

    str[strlen] = '\0';

    return str;
}

BigInt zeroBigInt(int length) {
    BigInt result = { NULL, length };

    result.digit = malloc(sizeof(unsigned char) * result.length);

    for (int i = 0; i < result.length; i++) {
        result.digit[i] = 0;
    }

    return result;
}

BigInt mulBigInt(BigInt num1, BigInt num2) {
    BigInt result;
    
    int i = num1.length - 1, j = num2.length - 1, k;
    int remain = 0, shift = 0;

    result = zeroBigInt(num1.length + num2.length);

    while (j >= 0) {
        int mul = 0;
        remain = 0;
        k = result.length - 1 - shift;
        i = num1.length - 1;

        while (i >= 0) {
            int a = result.digit[k] + num1.digit[i--] * num2.digit[j] + remain;
            mul = a % 10;
            remain = a / 10;
            result.digit[k--] = mul;
        }
        
        result.digit[k] += remain;
        shift++;
        j--;
    }

    if (remain) {
        result.digit[k] = remain;
    }

    return result;
}

BigInt sumBigInt(BigInt num1, BigInt num2) {
    BigInt result;

    int i = num1.length - 1, j = num2.length - 1, k, remain = 0;

    if (i > j) result = zeroBigInt(num1.length + 1);
    else result = zeroBigInt(num2.length + 1);

    k = result.length - 1;

    while (i >= 0 || j >= 0) {
        unsigned char a = 0, b = 0, sum;
        if (i >= 0) a = num1.digit[i--];
        if (j >= 0) b = num2.digit[j--];

        sum = a + b + remain;
        result.digit[k--] = sum % 10;
        remain = sum / 10;
    }

    if (remain) {
        result.digit[0] = remain;
    }

    return result;
}

void printBigInt(BigInt num, FILE *fp) {
    int i = 0;

    while (num.digit[i] == 0) i++;
    while (i < num.length) {
        fprintf(fp, "%d", num.digit[i++]);
    }
    fprintf(fp, "\n");
}

void freeBigInt(BigInt *num) {
    if (num->digit) free(num->digit);
}