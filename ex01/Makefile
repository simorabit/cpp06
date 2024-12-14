CC = c++

CFLAGS = #-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = serializer

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	
%.o: %.cpp Serializer.hpp  Data.hpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)
    
re: fclean all
