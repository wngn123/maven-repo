# 定义变量

COPY     = copy
DEL      = del


main:main.o hello.dll
	gcc -o main.exe main.o -L./ -lhello

main.o:main.c
	gcc -c -D_DEBUG main.c -o main.o
hello.dll:hello.o
	gcc -shared -o hello.dll hello.o -Wl,--out-implib,libhello.a 
hello.o:hello.c
	gcc -c -DBUILD_DLL hello.c 
	
	
# PHONY表示clean是个伪目标文件
.PHONY:clean run
clean:
	-$(DEL) *.o
	-$(DEL) *.dll
	-$(DEL) *.a
	-$(DEL) main.exe
	
run:
	-main.exe
	
# 1、编译hello.c 
# gcc -c hello.c 
# 2、编译hello.dll 
# gcc -c -DBUILD_DLL dll.c 
# 注意要使用要使用-DBUILD_DLL来设置宏BUILD_DLL 
# 3、创建dll 
# gcc -shared -o message.dll dll.o -Wl,--out-implib,libmessage.a 
# 这一步要详细说明一下 
# -shared参数用来创建共享库，在windows中为dll 
# -Wl 等待下一条信息进行连接 
# --out-implib是给连接程序ld使用的，用于创建要连接dll需要的import library 
# 4、创建可执行文件 
# gcc -o hello.exe hello.o -L./ -lmessage
# -L 指定连接库路径
# -lmessage (or -l message) 指定dll的import library 
#
# 编译静态库，可供windows调用：
# 1、gcc -shared -o print.dll print.c -Wl,--output-def,print.def,--out-implib,libprint.a
# 2、lib /machine:i386 /def:print.def