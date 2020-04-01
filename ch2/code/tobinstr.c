#include <stdio.h>

int main() {
    int n = 0xaecdef12;

    for(int i=sizeof(n)*8-1;i>-1;i--) {
        unsigned char ch = ((n >> i) & 0x01) == 0 ? '0' : '1';
        printf("%c",ch);
    }
    printf("\r\n");

    printf("0x");
    for(int i=0;i<sizeof(n);i++) {
        unsigned char byte = (n>>(sizeof(n)-i-1)*8) & 0xff;
        unsigned char lo = byte & 0xf;
        unsigned char hi = (byte>>4) & 0xf;
        char lohex = lo < 10 ? lo + '0' : lo + 'A' - 0x0a;
        char hihex = hi < 10 ? hi + '0' : hi + 'A' - 0x0a;
        printf("%c%c",hihex,lohex);
    }
    printf("\r\n");
}