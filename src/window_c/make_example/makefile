# 定义变量

COPY     = copy
DEL      = del


main:main.o add.o sub.o 
	gcc main.o add.o sub.o -o main 

main.o:main.c
	gcc -c -D_DEBUG main.c -o main.o
add.o:add.c
	gcc -c -D_DEBUG add.c -o add.o
sub.o:sub.c
	gcc -c -D_DEBUG sub.c -o sub.o

# PHONY表示clean是个伪目标文件
.PHONY:clean run
clean:
	-$(DEL) *.o
	-$(DEL) main.exe
	
run:
	-main.exe