# Compiler and flags
CC     = gcc
CFLAGS = -std=c2x -Iinclude -Wall -Wextra -Werror -Wconversion -Wformat -Wunreachable-code -Wfloat-equal -Wshadow -Wpointer-arith -Wstrict-prototypes -Winit-self -g -fsanitize=address,undefined
LDFLAGS = 

# Directories
SRC_DIR     = src
BUILD_DIR   = build
INCLUDE_DIR = include

# Files
SRCS   = $(wildcard $(SRC_DIR)/*.c)
OBJS   = $(patsubst $(SRC_DIR)/*.c, $(BUILD_DIR)/*.o, $(SRCS))
DEPS   = $(patsubst $(SRC_DIR)/*.c, $(BUILD_DIR)/*.d, $(SRCS))
TARGET = casiocalc


# update .o and executable
all: $(BUILD_DIR) $(TARGET)

# .o to executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# .c to .o + .d files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
-include $(DEPS)

run: $(TARGET)
	./$(TARGET)

clean: rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean run
