#include <stdio.h>

void print_base16(int nbr)
{
    char hex[16] = "0123456789ABCDEF";
    char result[20];
    int i = 0;
    unsigned int n;

    if (nbr < 0)
        n = -nbr;
    else
        n = nbr;

    if (n == 0) {
        result[i++] = '0';
    } else {
        while (n > 0) {
            result[i++] = hex[n % 16];
            n /= 16;
        }
    }

        if (nbr < 0)
        putchar('-');

    while (i--)
        putchar(result[i]);

    putchar('\n');
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Base16: ");
    print_base16(number);

    return 0;
}

