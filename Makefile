SRC = $(wildcard *.cpp NeuralNetwork/*.cpp Utils/*.cpp NeuralNetwork/Activation/*.cpp NeuralNetwork/Cost/*.cpp)
HEADERS = $(*.h NeuralNetwork/*.h Utils/*.h NeuralNetwork/Activation/*.h NeuralNetwork/Cost/*.h)
OBJ = ${SRC:.cpp=.o}

CXX = g++

main: ${OBJ}
	${CXX} ${CFLAGS}  $^ -o $@ -lm

%.o: %.c ${HEADERS}
	${CXX} ${CFLAGS} -c  $<  -o $@ -lm

clean:
	rm -f *.o
