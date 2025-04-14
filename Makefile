CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -pedantic
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = matrizes

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)
