# main是目标，：后头是依赖, 命令前加tab
# @取消回显
main : main.o hello.o
	gcc main.o hello.o -o main

main.o : main.c
	gcc -c main.c

hell.o : hello.c
	gcc -c hello.c

clean :
	@rm *.o
