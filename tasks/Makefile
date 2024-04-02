CXX = g++
CXXFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -g -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=4 -Wswitch-default -Wundef -Werror -Wno-unused

all: dop_task_week4 check_token 671_C 1527_C cyclic_permutation TestHashTable authorization_server 1792_D

dop_task_week4: dop_task_week4.cpp
	$(CXX) $(CXXFLAGS) -c dop_task_week4.cpp -o dop_task_week4.o
	$(CXX) $(CXXFLAGS)  dop_task_week4.o -o dop_task_week4

1792_D: 1792_D.cpp
	$(CXX) $(CXXFLAGS) -c 1792_D.cpp -o 1792_D.o
	$(CXX) $(CXXFLAGS)  1792_D.o -o 1792_D

authorization_server: token/authorization_server.cpp
	$(CXX) $(CXXFLAGS) -c token/authorization_server.cpp -o authorization_server.o
	$(CXX) $(CXXFLAGS)  authorization_server.o -o authorization_server


check_token: token/check_token.cpp
	$(CXX) $(CXXFLAGS) -c token/check_token.cpp -o check_token.o
	$(CXX) $(CXXFLAGS)  check_token.o -o check_token

671_C: 671_C.cpp
	$(CXX) $(CXXFLAGS) -c 671_C.cpp -o 671_C.o
	$(CXX) $(CXXFLAGS)  671_C.o -o 671_C

1527_C: 1527_C.cpp
	$(CXX) $(CXXFLAGS) -c 1527_C.cpp -o 1527_C.o
	$(CXX) $(CXXFLAGS)  1527_C.o -o 1527_C

cyclic_permutation: cyclic_permutation.cpp
	$(CXX) $(CXXFLAGS) -c cyclic_permutation.cpp -o cyclic_permutation.o
	$(CXX) $(CXXFLAGS)  cyclic_permutation.o -o cyclic_permutation

TestHashtable: TestHashTable.cpp
	$(CXX) $(CXXFLAGS) -c TestHashTable.cpp -o TestHashTable.o
	$(CXX) $(CXXFLAGS)  TestHashTable.o -o TestHashTable


clean:
	rm -rf dop_task_week4 check_token 671_C 1527_C cyclic_permutation TestHashTable authorization_server 1792_D
	rm -rf *.o

rebuild: clean all