#include <stdio.h>

int main() {
    float f = 0.1;
    unsigned char bytes[4];
    
    unsigned int f2i = *((unsigned int *)(&f));

    //大端模式
    for(int i=0;i<sizeof(f2i);i++) {
        bytes[i] = (f2i >> i*8) & 0xff;
        printf("[%d] is 0x%x\n",i,bytes[i]);
    }

    unsigned int b2i = 0;
    for(int i=0;i<sizeof(bytes);i++) {
        b2i |= (bytes[i] << 8*i);
    }

    float f1 = *((float *)(&b2i));
    printf("%.1f\r\n",f1);


    return 0;
}