# compilateur
CC := g++
# options de compilation
CFLAGS := -std=c++98 -Wall -Wextra -pedantic -ggdb 

# règle de compilation --- exécutables
all : graphe

graphe : main.cpp graphe.hpp sommet.hpp tas.hpp tas_id.hpp couple.hpp
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< 

# options de compilation
clean:
	rm *.o graphe
