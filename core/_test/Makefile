NAME := cdt_core_test
DEPENDENCIES := ./bin/cdt_core.dll
LIBS := -lcdt_test -lcdt_core.dll
LIB_DIRS:= -L../lib -L/usr/local/lib/cdt/test
INCLUDE_DIRS := -I../../../lib

# [exec|shared|static]
BIN_TYPE := exec

# CXX := g++
# CFLAGS := -Wall -Werror -std=gnu++11 -I/usr/local/include

# SRC_DIR := ./src
# TMP_DIR := ./tmp
# OBJ_DIR := $(TMP_DIR)/obj
# DEP_DIR := $(TMP_DIR)/depend
# BIN_DIR := ./bin

include ../../Makefile.test.generic

# Your targets

./bin/cdt_core.dll: 
	$(call copy_file, ../bin/$(notdir $@), $@)