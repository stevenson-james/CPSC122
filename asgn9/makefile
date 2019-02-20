#name the compiler CC
CC=g++

#List all of the .h files. These form a dependency list so that an incorrect 
#change in any of them will trigger a compile error 
DEPS = Calc.h Stack.h List.h

#List all of the object files
OBJ = CalcTst.o Calc.o Stack.o List.o

#Creating an object file depends upon the .cpp files which, in turn,
#depends upon the .h files
#$@ corresponds to %.o for each output object file.  $< says begin with
#the first dependency in the DEPS list
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

#Create the executable by linking all of the object files
#$@ refers to calc
#$^ refers to the  object files, $(OBJ)
calc:	$(OBJ)
	$(CC) -o $@ $^

#type make clean to remove the executable and all .o files. .PHONY
#prevents the removal of the executable
.PHONY:	clean 
clean:	
	rm -f $(OBJ) 
