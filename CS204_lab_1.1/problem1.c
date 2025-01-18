/*In big endian format the most significant byte is stored first, thus gets stored at the smallest address byte, while in little endian format the least significant byte is stored first.*/

#include <stdio.h>

int main(){
    unsigned int x = 0x42690071;
    char *c = (char*) &x; //char pointer assigned to x's address by casting x to char pointer
    printf("*c is: 0x%x\n", *c);

    if(*c == 0x71){ // if c is pointing to LSB, then the system is little-endian
        printf("The underlying system is little endian as the char pointer is pointing to LSB. \n");
    }
    else{
        printf("The underlying system is big endian as the char pointer is pointing to MSB. \n");
    }
    return 0;
}   