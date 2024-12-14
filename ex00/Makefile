CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = convert

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	
%.o: %.cpp ScalarConverter.hpp 
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)
    
re: fclean all
