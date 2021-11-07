.PHONY:clean all
	
all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o 
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o  

#make basicClassification.o
basicClassification.o: NumClass.h basicClassification.c
	gcc -Wall -g -c basicClassification.c

#make advancedClassificationLoop.o
advancedClassificationLoop.o: NumClass.h advancedClassificationLoop.c
	gcc -Wall -g -c advancedClassificationLoop.c

#make advancedClassificationRecursion.O
advancedClassificationRecursion.o: NumClass.h advancedClassificationRecursion.c
	gcc -Wall -g -c advancedClassificationRecursion.c

#make mains:
mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a 

#make maindloop:
maindloop : main.o libclassloops.so
	gcc -Wall -g -o maindloop main.o libclassloops.so  

#make maindrec: 
maindrec: main.o libclassrec.so
	gcc -Wall -g -o maindrec main.o libclassrec.so  

#make clean
clean:
	rm -f *.o *.a *.so mains maindloop maindrec 


 