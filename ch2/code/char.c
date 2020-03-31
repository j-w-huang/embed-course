#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); 

    wchar_t wch = L'你';
    printf("%C",wch);
    return 0;
}