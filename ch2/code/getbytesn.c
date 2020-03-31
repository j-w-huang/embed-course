#include <stdio.h>

#define	GET_LOW_BYTE0(x)	((x >>  0) & 0x000000ff)	/* 获取第0个字节 */
#define	GET_LOW_BYTE1(x)	((x >>  8) & 0x000000ff)	/* 获取第1个字节 */
#define	GET_LOW_BYTE2(x)	((x >> 16) & 0x000000ff)	/* 获取第2个字节 */
#define	GET_LOW_BYTE3(x)	((x >> 24) & 0x000000ff)	/* 获取第3个字节 */


int main() {
    //转换成字节数组，int-->4bytes
    int n = 0x12345678;

    printf("0x%x [0] is 0x%x\r\n",n,GET_LOW_BYTE0(n));
    printf("0x%x [1] is 0x%x\r\n",n,GET_LOW_BYTE1(n));
    printf("0x%x [2] is 0x%x\r\n",n,GET_LOW_BYTE2(n));
    printf("0x%x [3] is 0x%x\r\n",n,GET_LOW_BYTE3(n));


    return 0;
}