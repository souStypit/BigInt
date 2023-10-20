#include "mybigint.h"

void getBigInt(FILE *fp, BigInt *num) {
    int c;

    while ((c = fgetc(fp)) != ' ' && c != '\n' && c != EOF) {
        if (num->length == 0) num->digit = malloc(sizeof(unsigned char));
        else num->digit = realloc(num->digit, sizeof(unsigned char) * (num->length + 1));

        num->digit[num->length] = c - '0';
        num->length++;
    }
}

BigInt zeroBigInt(int length) {
    BigInt result = { NULL, length };

    result.digit = malloc(sizeof(unsigned char) * result.length);

    for (int i = 0; i < result.length; i++) {
        result.digit[i] = 0;
    }

    return result;
}

int compareBigInt(BigInt num1, BigInt num2) {
    BigInt result;

    if (num1.length != num2.length) {
        return 1;
    };

    for (int i = 0; i < num1.length; i++) {
        if (num1.digit[i] != num2.digit[i]) return 1;
    }

    return 0;
}

BigInt powBigInt(BigInt base, int exp) {
    BigInt result;
    result.length = 1;
    result.digit = malloc(sizeof(int) * result.length);
    result.digit[0] = 1;

    if (exp == 0) {
        return result;
    }

    for (int i = 0; i < exp; i++) {
        result = mulBigInt(base, result);
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

// void printBigInt(BigInt num) {
//     int i = 0;

//     while (num.digit[i] == 0) i++;
//     while (i < num.length) {
//         printf("%d", num.digit[i++]);
//     }
//     printf("\n");
// }

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