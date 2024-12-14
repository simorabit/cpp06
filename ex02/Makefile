CC = c++

CFLAGS = #-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp 

OBJS = $(SRCS:.cpp=.o)

TARGET = dynamic

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	
%.o: %.cpp A.hpp  B.hpp C.hpp Base.hpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)
    
re: fclean all
