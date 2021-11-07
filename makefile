.PHONY:clean all
	
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

#make loop: 
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

#make recursives: 
libclassrec.a: basicClassification.o advancedClassificationRecursion.o 
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

 #make recursived:
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

#make loopd:
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
mains: libclassrec.a main.o
	gcc -Wall -g -o mains libclassrec.a main.o 

#make maindloop:
maindloop : libclassloops.so main.o
	gcc -Wall -g -o maindloop libclassloops.so main.o 

#make maindrec: 
maindrec:libclassrec.so main.o
	gcc -Wall -g -o maindrec libclassrec.so main.o 

#make clean
clean:
	rm -f *.o *.a *.so mains maindloop maindrec 


 