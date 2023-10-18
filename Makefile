OBJS = main.o RatNum.o
CC = g++
CFLAGS = -Wall -Wextra -std=c++23 -g
OBJ_NAME = main.exe
BUILD_DIR = build

main.exe: $(OBJS)
	$(CC) -o $(BUILD_DIR)/$(OBJ_NAME) $(addprefix $(BUILD_DIR)/, $(OBJS)) $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $(BUILD_DIR)/$@ $< $(CFLAGS)
	
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(OBJ_NAME)
