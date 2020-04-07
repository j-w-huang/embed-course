#include <stdio.h>

int main() {
    int i = 0;
    int* p = &i;
    long q = (long)p;

    printf("0x%lx\r\n",q);
    printf("%p\r\n",p);

    printf("0x%lx\r\n",q+4);
    printf("%p\r\n",++p);

    return 0;
}