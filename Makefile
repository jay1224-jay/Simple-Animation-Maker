
LIB_DIR =  # your SFML lib dir
LIB = \
-lpthread -lsfml-graphics -lsfml-window -lsfml-system 

INCLUDE_DIR = # your SFML include dir

# note: i don't have to add LIB_DIR and INCLUDE_DIR.
#
# In case you installed SFML to a non-standard path,
# 
# add "-L$(LIB_DIR)" before "$(LIB)"
# example: "g++ ... -L$(LIB_DIR) $(LIB) ..."
# 
# add "-I$(INCLUDE_DIR)" at the end.
# example: "g++ -c main.cpp ... -I$(INCLUDE_DIR)"
# 

main: main.o ps.o
	g++ main.o ps.o -o main $(LIB) 

main.o: main.cpp button.hpp common.h
	g++ -c main.cpp 

ps.o: ps.cpp common.h
	g++ -c ps.cpp

clean:
	rm main.o ps.o main
