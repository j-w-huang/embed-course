#include <stdio.h>

// 定义一个函数指针变量类型callback;
typedef void (*callback)(int,int,int);

// callback的默认实现 
void defaultCb(int a,int b, int max);

// 算完max,后回调一下
int max(int a, int b, callback cb);

int main() {
    // callback cb = defaultCb;
    callback cb = NULL;
    max(2,3,cb);

    return 0;
}

int max(int a, int b, callback cb) {
    int iMax = a>b ? a : b;
    if(cb != NULL) {
        cb(a,b,iMax);
    } else {
        printf("the callback is null.\r\n");
    }
    
    return iMax;
}

void defaultCb(int a,int b, int max) {
    printf("you input a is %d\r\n",a);
    printf("you input b is %d\r\n",b);
    printf("max is %d\r\n",max);
}