01: 01.o country_codes.o
	gcc -o 01 01.o country_codes.o

01.o: 01.c country_codes.h
	gcc -c 01.c

country_codes.o: country_codes.c country_codes.h
	gcc -c country_codes.c