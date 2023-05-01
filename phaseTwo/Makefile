MAKEFLAGS += -L

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 


gerp: gerp.o file.o hash_table_values.o main.o DirNode.o FSTree.o \
stringProcessing.o
	${CXX} ${CXXFLAGS} -o gerp file.o hash_table_values.o gerp.o main.o \
	DirNode.o FSTree.o stringProcessing.o

main.o: gerp.h file.o hash_table_values.o DirNode.o FSTree.o
	${CXX} ${CXXFLAGS} main.cpp -c

gerp.o: gerp.h file.o hash_table_values.o DirNode.o FSTree.o
	${CXX} ${CXXFLAGS} gerp.cpp -c

file.o: file.h DirNode.o FSTree.o
	${CXX} ${CXXFLAGS} file.cpp -c

stringProcessing.o: stringProcessing.h
	${CXX} ${CXXFLAGS} stringProcessing.cpp -c

hash_table_values.o: hash_table_values.h 
	${CXX} ${CXXFLAGS} hash_table_values.cpp -c

unit_test: unit_test_driver.o gerp.o file.o hash_table_values.o DirNode.o \
FSTree.o
	$(CXX) $(CXXFLAGS) $^

provide:
	provide comp15 proj4_gerp FSTreeTraversal.cpp 	\
	stringProcessing.h stringProcessing.cpp Makefile README \
	gerp.cpp gerp.h file.h file.cpp hash_table_values.cpp  \
	hash_table_values.h main.cpp test_main.cpp unit_tests.h \
	2letter.in 3letter.in 4letter.in 5letter.in empty.in large.in

clean:
	rm main.o gerp.o file.o stringProcessing.o hash_table_values.o
