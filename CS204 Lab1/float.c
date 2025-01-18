#include <string.h>
#include <math.h>
#include <stdio.h>

#define FP2BIN_STRING_MAX 1077
#define FRACTIONAL_BITS_LIMIT 52 // Limit for fractional part bits

// Handle the integer part of the number
void fp2bin_int(double fp_int, char *binString)
{
    int bitCount = 0;
    int i;
    char binStringTemp[FP2BIN_STRING_MAX];

    do
    {
        binStringTemp[bitCount++] = '0' + (int)fmod(fp_int, 2);
        fp_int = floor(fp_int / 2);
    } while (fp_int > 0);

    for (i = 0; i < bitCount; i++)
    {
        binString[i] = binStringTemp[bitCount - i - 1];
    }
    binString[bitCount] = '\0';
}

// Handle the fractional part of the number
void fp2bin_f(double fp_frac, char *binString)
{
    int bitCount = 0;
    double fp_int;
    while (fp_frac > 0 && bitCount < FRACTIONAL_BITS_LIMIT)
    {
        fp_frac *= 2;
        fp_frac = modf(fp_frac, &fp_int);
        binString[bitCount++] = '0' + (int)fp_int;
    }
    binString[bitCount] = '\0';
}

// Convert a floating-point number to a binary string
void fp2bin(double fp, char *binString)
{
    double fp_int, fp_frac;

    fp_frac = modf(fp, &fp_int);

    if (fp_int != 0)
    {
        fp2bin_int(fp_int, binString);
    }
    else
    {
        strcpy(binString, "0");
    }

    strcat(binString, ".");

    if (fp_frac != 0)
    {
        fp2bin_f(fp_frac, binString + strlen(binString));
    }
    else
    {
        strcat(binString, "0");
    }
}

int main()
{
    char binString[FP2BIN_STRING_MAX];

    double fp;
    printf("Enter a floating-point number: ");
    scanf("%lf", &fp);

    fp2bin(fp, binString);

    printf("Binary representation: %s\n", binString);

    return 0;
}
