NAME = 	so_long

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR) -I$(MLX_DIR) -g3

EXT_FLAGS = -lX11 -lm -lz -lXext

OPTI_FLAGS = -Ofast -march=native -flto -fno-signed-zeros -funroll-loops

DFLAGS = -MMD -MP

LIBFT_DIR = libft

LIBFT = libft.a

MLX_DIR = minilibx-linux

MLX = libmlx.a

SRC_DIR = srcs

BUILD_DIR = .build

SRC_FILES = main.c \
			make_area.c \
			check_map.c \
			exit.c \
			check_path.c \
			init_struct.c \
			key_move.c \
			display.c

INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)


$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OPTI_FLAGS) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(EXT_FLAGS)
.PHONY: mlx
$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

.PHONY: libf
$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
	$(MAKE) -C $(LIBFT_DIR)/ clean
	$(MAKE) -C $(MLX_DIR)/ clean
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	$(RM) $(NAME)

.PHONY: re
re : fclean
	$(MAKE) all

.PHONY: FORCE
FORCE:
