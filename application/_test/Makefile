NAME := cdt_app_test
DEPENDENCIES := 
LIBS := ../lib/libcdt_app.a ./lib/libmy_module.dll.a
INCLUDE_DIRS := -I/usr/local/include -I../../../lib

CFLAGS := -Wall -Werror -std=gnu++11  

SRC_DIR ?= ./src
TMP_DIR ?= ./tmp
OBJ_DIR ?= $(TMP_DIR)/obj
DEP_DIR ?= $(TMP_DIR)/depend
BIN_DIR ?= ./bin
LIB_DIR ?= ./lib

CPP_FILES := $(SRC_DIR)/main.cpp $(SRC_DIR)/MyApp.cpp

TARGET := $(BIN_DIR)/$(NAME).exe

# include ../../Makefile.generic

# Your targets
.PHONY: all clean exec test

all: module exec

test: module exec
	./$(TARGET)

exec: $(TARGET)

clean:
	rm -rf $(TMP_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(LIB_DIR)

module: $(BIN_DIR)/my_module.dll

$(TARGET): $(CPP_FILES)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(CFLAGS) $(INCLUDE_DIRS) $(CPP_FILES) $(LIBS) -o $(TARGET)

$(BIN_DIR)/my_module.dll: $(SRC_DIR)/MyModule.cpp
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LIB_DIR)
	$(CXX) -DLIB_BUILD -Wall -Werror -std=gnu++11 -I/usr/local/include -I../../../lib \
	-shared -Wl,--out-implib=$(LIB_DIR)/libmy_module.dll.a $< -L../lib -lcdt_app -o $@
