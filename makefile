##
## Variables
##
CC = clang++
SRC_DIR = src
BUILD_DIR = build
WARNINGS =-Wall -Wextra -Wshadow -Wconversion
ifeq ($(CC), clang)
  WARNINGS := $(WARNINGS) -Wpedantic -Wno-unused-command-line-argument
endif
C_FLAGS = -O2 $(WARNINGS)

##
## OS Variables
##
ifeq '$(findstring ;,$(PATH))' ';'
  OS := PlainWindows
else
  OS := $(shell uname 2>/dev/null || echo Unknown)
  OS := $(patsubst CYGWIN%,Cygwin,$(OS))
  OS := $(patsubst MSYS%,MSYS,$(OS))
  OS := $(patsubst MINGW%,MINGW,$(OS))
endif

##
## Commands and Files
##
ifeq ($(OS), PlainWindows)
  TARGET = bin/executable.exe
  RM_COMMAND = del /s /q
  CLEAN_PATH = *.o
else
  TARGET = bin/executable.out
  RM_COMMAND = rm -f
  MAKE_DIR = mkdir -p
  C_FILES = $(shell find $(SRC_DIR) -type f -name \*.cpp)
  O_FILES = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(C_FILES:.cpp=.o))
endif

##
## Targets
##
$(TARGET): $(O_FILES)
	@$(MAKE_DIR) $(dir $@)
	$(CC) $^ -o $(TARGET) $(C_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MAKE_DIR) $(dir $@)
	$(CC) $(C_FLAGS) -c -o $@ $<

build: $(TARGET)

run:
	@./$(TARGET)

clean:
	$(RM_COMMAND) $(O_FILES) $(TARGET)
	clear

.PHONY: clean build run
