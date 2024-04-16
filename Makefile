CC = g++
CFLAGS = -I/Library/Frameworks/SDL2.Framework/Headers -I/Library/Frameworks/SDL2_Image.Framework/Headers -I/Library/Frameworks/SDL2_mixer.Framework/Headers -I/Library/Frameworks/SDL2_ttf.Framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_Image -framework SDL2_ttf -framework SDL2_mixer

SRC_DIR = src
BUILD_DIR = build
EXEC = main

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC)