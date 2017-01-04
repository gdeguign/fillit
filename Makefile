# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/26 18:52:01 by ulefebvr          #+#    #+#              #
#    Updated: 2017/01/03 14:49:01 by ulefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_EXEC ?= fillit

BUILD_DIR ?= ./build
SRC_DIRS ?= ./srcs
INC_DIR ?= ./includes ./libft/includes

SRCS := srcs/main.c \
		srcs/parsing/initialization.c \
		srcs/parsing/parsing.c \
		srcs/parsing/tools.c \
		srcs/resolve/find_solution.c \
		srcs/resolve/resolve.c \
		srcs/resolve/space2keepgoing.c \
		srcs/resolve/tetriminos_specific/tetriminos_0.c \
		srcs/resolve/tetriminos_specific/tetriminos_1.c \
		srcs/resolve/tetriminos_specific/tetriminos_10.c \
		srcs/resolve/tetriminos_specific/tetriminos_11.c \
		srcs/resolve/tetriminos_specific/tetriminos_12.c \
		srcs/resolve/tetriminos_specific/tetriminos_13.c \
		srcs/resolve/tetriminos_specific/tetriminos_14.c \
		srcs/resolve/tetriminos_specific/tetriminos_15.c \
		srcs/resolve/tetriminos_specific/tetriminos_16.c \
		srcs/resolve/tetriminos_specific/tetriminos_17.c \
		srcs/resolve/tetriminos_specific/tetriminos_18.c \
		srcs/resolve/tetriminos_specific/tetriminos_2.c \
		srcs/resolve/tetriminos_specific/tetriminos_3.c \
		srcs/resolve/tetriminos_specific/tetriminos_4.c \
		srcs/resolve/tetriminos_specific/tetriminos_5.c \
		srcs/resolve/tetriminos_specific/tetriminos_6.c \
		srcs/resolve/tetriminos_specific/tetriminos_7.c \
		srcs/resolve/tetriminos_specific/tetriminos_8.c \
		srcs/resolve/tetriminos_specific/tetriminos_9.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(INC_DIR)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall -Werror -Wextra

# Extra flags to give to compilers when they are supposed to invoke the linker, ‘ld’, such as -L.
# Libraries (-lfoo) should be added to the LDLIBS variable instead.
LDFLAGS ?= -Llibft -lft

all: libft/libft.a $(TARGET_EXEC) $(OBJS)

libft/libft.a:
	make -C libft

$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	@$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean fclean re

clean:
	make clean -C libft
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C libft
	$(RM) $(TARGET_EXEC)

re: fclean
	make

-include $(DEPS)

MKDIR_P ?= mkdir -p
