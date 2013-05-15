export CC = g++
INCPATH = 
LIBS =
#-lpthread 
#-lmysqlcppconn 
export DEFINES = 
export FLAGS = -g -std=c++0x $(INCPATH) $(LIBS) $(DEFINES)
export EXEC = main.exe

all: $(EXEC)

.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $^;

.c.o :
	$(CC) $(FLAGS) -o $@ -c $^;

$(EXEC) : main.cpp ResourceManager/ResourceManager.hpp
	$(CC) $(FLAGS) -o $@  $^;

clean: 
	@rm -f *.o
	@rm -f $(EXEC)

