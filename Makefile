# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/26 18:52:01 by ulefebvr          #+#    #+#              #
#    Updated: 2016/12/26 18:52:05 by ulefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_EXEC ?= fillit

BUILD_DIR ?= ./build
SRC_DIRS ?= ./srcs
INC_DIR ?= ./includes ./libft/includes

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(INC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall -Werror -Wextra

# Extra flags to give to compilers when they are supposed to invoke the linker, ‘ld’, such as -L.
# Libraries (-lfoo) should be added to the LDLIBS variable instead.
LDFLAGS ?= -Llibft -lft

all: libft/libft.a $(TARGET_EXEC) $(OBJS)

libft/libft.a:
	make -C libft

$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) -O

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
