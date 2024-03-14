C = g++
CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -g -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=4 -Wswitch-default -Wundef -Werror -Wno-unused

all: dop_task_week4 check_token 671_C 1527_C cyclic_permutation TestHashTable authorization_server 1792_D

dop_task_week4: dop_task_week4.cpp
	$(C) $(CFLAGS) -c dop_task_week4.cpp -o dop_task_week4.o
	$(C) $(CFLAGS)  dop_task_week4.o -o dop_task_week4

1792_D: 1792_D.cpp
	$(C) $(CFLAGS) -c 1792_D.cpp -o 1792_D.o
	$(C) $(CFLAGS)  1792_D.o -o 1792_D

authorization_server: token/authorization_server.cpp
	$(C) $(CFLAGS) -c token/authorization_server.cpp -o authorization_server.o
	$(C) $(CFLAGS)  authorization_server.o -o authorization_server


check_token: token/check_token.cpp
	$(C) $(CFLAGS) -c token/check_token.cpp -o check_token.o
	$(C) $(CFLAGS)  check_token.o -o check_token

671_C: 671_C.cpp
	$(C) $(CFLAGS) -c 671_C.cpp -o 671_C.o
	$(C) $(CFLAGS)  671_C.o -o 671_C

1527_C: 1527_C.cpp
	$(C) $(CFLAGS) -c 1527_C.cpp -o 1527_C.o
	$(C) $(CFLAGS)  1527_C.o -o 1527_C

cyclic_permutation: cyclic_permutation.cpp
	$(C) $(CFLAGS) -c cyclic_permutation.cpp -o cyclic_permutation.o
	$(C) $(CFLAGS)  cyclic_permutation.o -o cyclic_permutation

TestHashtable: TestHashTable.cpp
	$(C) $(CFLAGS) -c TestHashTable.cpp -o TestHashTable.o
	$(C) $(CFLAGS)  TestHashTable.o -o TestHashTable


clean:
	rm -rf dop_task_week4 check_token 671_C 1527_C cyclic_permutation TestHashTable authorization_server 1792_D
	rm -rf *.o

rebuild: clean all