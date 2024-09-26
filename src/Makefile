# Компилятор и флаги
CC := g++
CFLAGS := -std=c++17 -Werror -Wextra -Wall
TFLAGS := -lgtest -lpthread -lgtest_main

# Директории
SRC_DIR := .
LIB_DIR := lib
TEST_DIR := tests

# Исходные файлы
LIBS_SRC := $(wildcard $(LIB_DIR)/*.cc)
TEST_SRC := $(wildcard $(TEST_DIR)/*test.cc)
# CCFILES := $(wildcard $(SRC_DIR)/*.cc)

# Обьектные файлы
LIBS_OBJ := $(LIBS_SRC:.cc=.o)
TEST_OBJ := $(TEST_SRC:.cc=.o)

# Библиотеки
LIBS := $(LIBS_SRC:.cc=.a)


TEST_EXE := tests

# цель по умолчанию
all: test

# Сборка тестов (нужно поправить, скорее всего не работает)
test: $(TEST_OBJ) $(LIBS)
	$(CC) (CFLAGS) $^ -o $(TEST_EXE) $(TFLAGS)
	./$(TEST_EXE)

# Сборка библиотек
%.a: %.o:
	ar rcs $@ $<

# Сборка объектных файлов
%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf *.o *.a *.gch $(TEST_EXE) *.out *.gcda *.gcno *.gcov *.info
