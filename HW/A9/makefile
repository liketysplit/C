SRC_DIR = ./src_files
INC_DIR = ./inc_files
OBJ_DIR = ./obj_files
BIN_DIR = ./bin_files

CC = gcc
_OBJS = basic_stat.o mean.o sum.o stdev.o 
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(_OBJS))
_SRCS = $(patsubst %.o, %.c, $(_OBJS))
SRCS = $(patsubst %, $(SRC_DIR)/%, $(_SRCS))
CFLAGS = -g -I$(INC_DIR)
LDFLAGS = -lm 

all: $(BIN_DIR)/basic_stat

$(BIN_DIR)/basic_stat: $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

dependencies:  $(SRCS)
	$(CC) -I$(INC_DIR) -MM $^ | sed '/^.*.o:/ s#^#$(OBJ_DIR)/#' > $@

include dependencies