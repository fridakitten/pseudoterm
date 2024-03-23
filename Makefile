#Makefile

all:
	@clang -lreadline main.c libhost/libhost.c libinfo/libinfo.m libconv/libconv.c -o pterm
