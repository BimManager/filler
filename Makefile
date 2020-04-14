# filler Makefile

CC := gcc
AR := ar
LD := ld

CFLAGS := -g -Wall -Werror -Wextra -c \
		-I./include -I./libft/include
ARFLAGS := -q -c
LDFLAGS := -lc -L./libft -lft \
			-e _main -arch x86_64 -macosx_version_min 10.13

INCDIR := include
SRCDIR := src
OBJDIR := build

SRCS := $(addprefix $(SRCDIR)/, \
		main.c \
		filler.c ft_fillernew.c ft_fillerdel.c \
		ft_tokensparse.c ft_sizeparse.c \
		ft_heatmapupdate.c ft_heatmaprecalc.c ft_heatmapput.c \
		ft_piecenew.c ft_piecedel.c ft_pieceplace.c \
		ft_nbsparse.c)

OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

NAME := kkozlov.filler

all : $(NAME)

$(NAME) : $(OBJS)
	@if [[ ! -e ./libft/libft.a ]]; then make -C ./libft; fi
	$(LD) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@if [[ ! -e $(OBJDIR) ]]; then mkdir $(OBJDIR); fi
	@$(CC) $(CFLAGS) $< -o $@

.PNOHY : all clean fclean re

clean :
	@if [[ -e $(OBJDIR) ]]; then rm -rf $(OBJDIR); fi
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all