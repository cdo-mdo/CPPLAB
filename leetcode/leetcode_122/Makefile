BIN=Solution
all:
	g++ $(BIN).cpp -o $(BIN)
	./$(BIN)
	valgrind --leak-check=full ./$(BIN)
clean:
	rm -f $(BIN) *.o
