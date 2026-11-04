# Compilation and linkage flags
CFLAGS      = -O2
ASFLAGS     = -m64
LDFLAGS     = -lm -z noexecstack -lcriterion

# Compiler
CC=gcc

# Sources
ASM=./my_mul.S
OBJ=${ASM:.S=.o}
WRAPPER_OBJ=wrapper.o

# Tests Sources
TESTS_SRC=${wildcard *_tests.c}
TESTS_OBJ=${TESTS_SRC:.c=.o}
TESTS_EXEC=${ASM:.S=_test}

all: build

build: ${OBJ} ${TESTS_OBJ}
	${CC} -o ${TESTS_EXEC} ${OBJ} ${WRAPPER_OBJ} ${TESTS_OBJ} ${LDFLAGS}

check: build
	./${TESTS_EXEC}

clean:
	rm -rvf ${OBJ} ${TESTS_OBJ}

fclean:
	rm -rvf ${OBJ} ${TESTS_OBJ} ${TESTS_EXEC}
