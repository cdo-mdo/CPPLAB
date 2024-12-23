BIN=Solution
all:
	g++ $(BIN).cpp -o $(BIN)
	./$(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(BIN)

clean:
	rm $(BIN)
