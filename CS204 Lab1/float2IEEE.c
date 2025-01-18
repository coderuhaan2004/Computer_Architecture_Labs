#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Function to process a floating-point number: decompose, truncate, and reconstruct
float process_float(float input)
{
    // Treat the float as an unsigned 32-bit integer
    uint32_t bits = *((uint32_t *)&input);

    // Step 1: Extract the components
    int sign = (bits >> 31) & 1;                // Extract sign bit
    int exponent = ((bits >> 23) & 0xFF) - 127; // Extract exponent (bias 127)
    int mantissa = bits & 0x7FFFFF;             // Extract 23-bit mantissa

    // Step 2: Truncate the mantissa to 7 bits
    int truncated_mantissa = mantissa >> 16; // Keep only the top 7 bits

    // Step 3: Reconstruct the float
    uint32_t new_bits = 0;

    // Add the sign bit
    new_bits |= (sign & 1) << 31;

    // Adjust and add the exponent (re-bias with 127)
    new_bits |= ((exponent + 127) & 0xFF) << 23;

    // Add the truncated mantissa, shifted to the correct position
    new_bits |= (truncated_mantissa & 0x7F) << 16;

    // Interpret the new bit pattern as a float
    return *((float *)&new_bits);
}

int main()
{
    float input;

    // Get the input from the user
    printf("Enter a floating-point number: ");
    scanf("%f", &input);

    // Process the input and generate the new float
    float new_float = process_float(input);

    // Print the results
    printf("Original number: %f\n", input);
    printf("New number with 7-bit mantissa: %f\n", new_float);

    return 0;
}
