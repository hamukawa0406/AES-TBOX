#include <cstdio>
#include <string.h>

#include "AES-KeyExp.h"
#include "AES-Encryption.h"

/* Output is transposed matrix. Row <=> Columns
Cleartext
00 11 22 33
44 55 66 77
88 99 AA BB
CC DD EE FF


Key
00 01 02 03
04 05 06 07
08 09 0A 0B
0C 0D 0E 0F


Ciphertext
69 C4 E0 D8
6A 7B 04 30
D8 CD B7 80
70 B4 C5 5A

*/

int main(int argc, char* argv[])
{
    for(int i = 0; i < 10000; i++){
        BYTE bKey[16]	= { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F };
        BYTE bInput[16] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF };


        BYTE bExpKey[176];

        //Print Cleatext
        /*
        printf("Cleartext\n");
        for(int i = 1; i<=16; i++){
            printf(("%02X%c"),bInput[i-1], i % 4 == 0 ? '\n' : ' ');
        }
        //*/

        KeyExpansion(bKey, bExpKey);
        AesEncyption(bInput, bExpKey);
    }

    /*
    // Print Key
    printf("\n\nKey\n");
    for(int i = 1; i<=16; i++){
        printf("%02X%c", bKey[i-1], i % 4 == 0 ? '\n' : ' ');
    }
    // Print Ciphertext
    printf("\n\nCiphertext\n");
    for(int i = 1; i<=16; i++){
        printf("%02X%c" , bInput[i-1], i % 4 == 0 ? '\n' : ' ');
    }
    //*/

    return 0;
}


