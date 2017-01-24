CC = g++ -std=c++11

INCLUDES = -I.
LIBRARIES = -pthread $(filter-out -lippicv, $(shell pkg-config --libs opencv))

SRC := $(shell find ./ -name '*.cpp')
FILE_NAMES_SRC = $(SRC:.cpp=.o)

EXEC = Data


.cpp.o: $(SRC)
	$(CC) -c $(INCLUDES) $(LIBRARIES) -Wall -o $@ $< -w

all: $(EXEC)
	@echo Executando... Aguarde.

run:
	./$(EXEC)

$(EXEC): $(FILE_NAMES_SRC)
	@$(CC) -w -o $(EXEC) $(FILE_NAMES_SRC) $(INCLUDES) $(LIBRARIES)

clean:
	rm $(EXEC) $(FILE_NAMES_SRC)