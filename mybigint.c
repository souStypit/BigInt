#include "mybigint.h"

void getBigInt(FILE *fp, BigInt *num) {
    int c;

    while ((c = fgetc(fp)) != ' ' && c != '\n') {
        if (num->length == 0)   num->digit = malloc(sizeof(unsigned char));
        else                    num->digit = realloc(num->digit, sizeof(unsigned char) * (num->length + 1));

        num->digit[num->length] = c - '0';
        num->length++;
    }
}

void mulBigInt(BigInt num1, BigInt num2, BigInt *result) {
    int i = num1.length - 1, j = num2.length - 1, k, remain = 0;

    result->length = num1.length + num1.length - 1;
    
    result->digit = malloc(sizeof(unsigned char) * result->length);
    for (int z = 0; z < result->length; z++) {
        result->digit[z] = 0;
    }

    int counter = 0;
    int mul = 0;
    while (j >= 0) {
        remain = 0;
        k = result->length - 1 - counter;
        i = num1.length - 1;
        while (i >= 0) {
            int a = num1.digit[i--] * num2.digit[j];
            mul = (result->digit[k] + a + remain) % 10;
            remain = (result->digit[k] + a + remain) / 10;
            result->digit[k--] = mul;
        }
        result->digit[k] += remain;
        counter++;
        j--;
    }

    if (remain) {
        result->digit[k] = remain;
    }
}

void sumBigInt(BigInt num1, BigInt num2, BigInt *result) {
    int i = num1.length - 1, j = num2.length - 1, k, remain = 0;

    if (i > j) result->length = num1.length + 1;
    else result->length = num2.length + 1;
    
    result->digit = malloc(sizeof(unsigned char) * result->length);
    k = result->length - 1;

    while (i >= 0 || j >= 0) {
        unsigned char a = 0, b = 0, sum;
        if (i >= 0) a = num1.digit[i--];
        if (j >= 0) b = num2.digit[j--];

        sum = a + b + remain;

        result->digit[k--] = sum % 10;

        remain = sum / 10;
    }

    if (remain) {
        result->digit[0] = remain;
    }
}

void printBigInt(BigInt num) {
    for (int i = 0; i < num.length; i++) {
        printf("%d", num.digit[i]);
    }
    printf("\n");
}

void freeBigInt(BigInt *num) {
    free(num->digit);
}