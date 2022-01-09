CPPFLAGS = -c -Iinc -Wall -pedantic

__start__: projekt_1
		./projekt_1

./projekt_1: obj/main.o obj/comparator.o obj/sequence.o obj/priority_queue.o obj/list.o
		g++ -Wall -pedantic -o projekt_1 obj/main.o obj/comparator.o obj/sequence.o\
		obj/priority_queue.o obj/list.o

obj/main.o: src/main.cpp inc/priority_queue.hh inc/sequence.hh
		g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/comparator.o: src/comparator.cpp inc/comparator.hh
		g++ ${CPPFLAGS} -o obj/comparator.o src/comparator.cpp

obj/sequence.o: src/sequence.cpp inc/sequence.hh
		g++ ${CPPFLAGS} -o obj/sequence.o src/sequence.cpp

obj/priority_queue.o: src/priority_queue.cpp inc/priority_queue.hh
		g++ ${CPPFLAGS} -o obj/priority_queue.o src/priority_queue.cpp

obj/list.o: src/list.cpp inc/list.hh 
		g++ ${CPPFLAGS} -o obj/list.o src/list.cpp

clean:
		rm -f obj/*.o projekt_1
