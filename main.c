#include "mybigint.h"

#define DIGITS "digits.txt"
#define RESULT_FILE "result.txt"

int main() {
    BigInt num1, num2, result;
    int c, i = 0, asd, choice;

    printf("1.SUM\n2.MULTIPLY\n3. POW\nCHOOSE: ");
    
    if (scanf("%d", &choice) != 1) return 1;

    FILE *fp = fopen(DIGITS, "r");
    if (!fp) {
        printf("File %s can't be opened!", DIGITS);
        return 1;
    }
    FILE *resultFp = fopen(RESULT_FILE, "w");
    if (!resultFp) {
        printf("File %s can't be opened!", RESULT_FILE);
        return 1;
    }

    getBigInt(fp, &num1);
    getBigInt(fp, &num2);

    switch (choice) {
    case 1:
        result = sumBigInt(num1, num2);
        break;
    case 2:
        result = mulBigInt(num1, num2);
        break;
    case 3:
        int exp;
        printf(" ENTER EXP: ");

        if (scanf("%d", &exp) != 1) return 1;

        result = powBigInt(num1, exp);
        break;
    case 4:
        return 0;
    }

    printBigInt(result, resultFp);
    // printf("%d", compareBigInt(num1, num2));

    freeBigInt(&num1);
    freeBigInt(&num2);
    freeBigInt(&result);

    return 0;
}