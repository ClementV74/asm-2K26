# Compilation and linkage flags
CFLAGS      = -O1
ASFLAGS     = -m64
LDFLAGS     = -lm -z noexecstack -lcriterion -no-pie

# Compiler
CC=gcc

# Sources
ASM=./endian_sum.S
OBJ=${ASM:.S=.o}

# Tests Sources
TESTS_SRC=${wildcard *_tests.c}
TESTS_OBJ=${TESTS_SRC:.c=.o}
TESTS_EXEC=${ASM:.S=_test}

all: build

build: ${OBJ} ${TESTS_OBJ}
	${CC} -o ${TESTS_EXEC} ${OBJ} ${TESTS_OBJ} ${LDFLAGS}

check: build
	./${TESTS_EXEC}

clean:
	rm -rvf ${OBJ} ${TESTS_OBJ} ${TESTS_EXEC}
