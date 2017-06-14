NAME := cdt_app
DEPENDENCIES := ./bin/cdt_core.dll
LIBS := -libcdt_core.dll
LIBS_PATH := /usr/local/lib/cdt/core/libcdt_core.dll.a
INCLUDE_DIRS := -I../../lib

# [exec|shared|static]
BIN_TYPE := static

INSTALL_DIR := cdt/application

# TEST_DIR ?= ./_test
# TEST_BIN ?= $(NAME)_test.exe
# TEST_EXEC ?= $(TEST_DIR)/bin/$(TEST_BIN)

# CXX ?= g++
# CFLAGS ?= -Wall -Werror -std=gnu++11 -I/usr/local/include

# SRC_DIR ?= ./src
# TMP_DIR ?= ./tmp
# OBJ_DIR ?= $(TMP_DIR)/obj
# DEP_DIR ?= $(TMP_DIR)/depend
# BIN_DIR ?= ./bin
# INC_DIR ?= $(SRC_DIR)/includes
# INSTALL_DIR ?= /usr/local
# INSTALL_BIN_DIR ?= $(INSTALL_DIR)/bin
# INSTALL_INC_DIR ?= $(INSTALL_DIR)/include

include ../Makefile.generic

# Your targets

./bin/cdt_core.dll: 
	$(call copy_file, /usr/local/bin/cdt/core/$(notdir $@), $@)