/*
 * 1. 写一个循环队列，实现入队，出队，队空，队满操作
 * 2. 写一个串口处理函数
 * 3. 写一个串口处理回调，是处理函数的参数
 * 4. 模拟入队，出队过程
 */
#include <stdio.h>
#define U16 unsigned short
#define SIZE (int)(1<<5)

typedef void (*callback)(U16 data);
void defCallback(U16 data);
void transData(U16 data, callback cb);

U16 buf[SIZE];
int p,q; // p: 队头，q:队尾

void Push(U16 data);
void Pop(U16* recvBuf, U16 size);
int GetLen(void);
int IsEmpty(void);
int IsFully(void);

int main () {

    // 中断。。来了数据
    U16 data;

    U16 recvData[16];
   
    callback cb;
    cb = defCallback;

    for(int i=0;i<17;i++) {
        data = (short) i;
        transData(data,cb);
    }
    
    // ..

    // for主循环..
    for(int i=0;i<100;i++) {
        if(((q-p+SIZE) & (SIZE-1)) >= 16) {
            //出队列
            Pop(recvData,16);
        }
    }
    //    

    return 0;
}

void transData(U16 data, callback cb) {
    if(cb!=NULL) {
        cb(data);
    }
}

void defCallback(U16 data) {
    Push(data);
}

// 入到循环队列；
void Push(U16 data) {
    buf[q++] = data;
    
     // p %= len，取模非常耗费指令周期，如果len是2的n次方，
     // 我们可以有优化的算法, 等效算法；
     q &= (SIZE - 1);
     printf("push: %d\r\n",data);
}

// 循环队列出队
void Pop(U16* recvBuf, U16 size) {
    for(int i=0;i<size;i++) {
        recvBuf[i] = buf[p++];
        p &= (SIZE - 1);
        printf("pop: %d\r\n",recvBuf[i]);
    }
}

int GetLen(void) {
    return ((q-p+SIZE) & (SIZE-1));
}

int IsEmpty(void) {
    return p==q;
}

int IsFully(void) {
    return ((q+1)& (SIZE-1)) ==p;
}
