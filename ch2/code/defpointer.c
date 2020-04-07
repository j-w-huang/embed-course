#include <stdio.h>
#define SIZE 16

//定义原型,返回值是整型指针
int* f(void);

int max(int a, int b);

int main() {
    int i = 0;
    int* p = &i;
    int** q = &p;

    // 数组中每个元素都是 int* 指针
    int *w[SIZE];

    // s是指针型变量，指向w的首地址
    int** s = &(w[0]);

    // 定义一个函数指针，指向某个函数原型
    int (*c)(int,int);

    // 对函数指针变量c赋值，付给了一个同样原型的函数
    c = max;

    printf("%d is max\r\n",c(2,3));

    return 0;
}

int* f(void) {
    
   // 返回空指针 
   return (void *) 0;
}

int max(int a, int b) {
    return a>b ? a : b;
}
