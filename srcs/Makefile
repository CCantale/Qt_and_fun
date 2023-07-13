CC			=			g++
FLAGS			=			-Wall -Wextra -Werror

APP_NAME		=			..\test.exe
INCLUDES		=			-IQt/includes -IQt/includes/QtCore
LINKS			=			-LQt/lib -lQt6Core 

SRCS			=			main.cpp

QOBJS			=			test.cpp

MOCS			=			$(addprefix moc_, $(QOBJS))

OBJS			=			$(SRCS:.cpp=.o) $(QOBJS:.cpp=.o)


all: $(APP_NAME)

$(APP_NAME): $(MOCS) $(OBJS)
	@$(CC) $(OBJS) -o $(APP_NAME) $(LINKS)

moc_%.cpp: %.hpp
	@echo CULO
	@moc $(INCLUDES) -i $< -o $@

%.o: %.cpp
	@$(CC) $(FLAGS) $(INCLUDES) -c $<

clean:
	@del /q /s *.o
	@del /q /s moc_*.cpp

fclean:
	@del $(APP_NAME)

kill: clean fclean
	@echo Everything was successfully exterminated.

re: kill
	@make

r: all
	@./$(APP_NAME)

.PHONY: all clean fclean kill re r
