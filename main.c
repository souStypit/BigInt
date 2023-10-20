#include "mybigint.h"

#define DIGITS "digits.txt"

int main() {
    BigInt num1, num2, result;
    int c, i = 0, asd;

    FILE *fp = fopen(DIGITS, "r");
    
    if (!fp) {
        printf("File can't be opened!");
        return 1;
    }

    getBigInt(fp, &num1);
    getBigInt(fp, &num2);

    // sumBigInt(num1, num2, &result);    
    
    // printBigInt(num1);
    // printBigInt(num2);
    // printBigInt(result);

    mulBigInt(num1, num2, &result);

    printBigInt(num1);
    printBigInt(num2);
    printBigInt(result);

    freeBigInt(&num1);
    freeBigInt(&num2);
    freeBigInt(&result);

    return 0;
}