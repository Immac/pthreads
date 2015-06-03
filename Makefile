all: t-sum t-synch st-sum mt-sum
t-sum: bin/sum-thread.exe
t-synch: bin/thread-synchronization.exe
st-sum: bin/single-threaded-sum-many.exe
mt-sum: bin/multi-threaded-sum-many.exe

bin/sum-thread.exe: src/sum-thread.c bin/
	gcc -std=c99 -pthread -time $< -o $@
	chmod +x $@
bin/thread-synchronization.exe: src/thread-synchronization.c bin/
	gcc -std=c99 -pthread $< -o $@
	chmod +x $@
bin/single-threaded-sum-many.exe: src/single-threaded-sum-many.c bin/
	gcc -std=c99 -pthread $< -o $@
	chmod +x $@
bin/multi-threaded-sum-many.exe: src/multi-threaded-sum-many.c bin/
	gcc -std=c99 -pthread $< -o $@
	chmod +x $@
bin/:
	mkdir -p bin
clean:
	
	rm -f *.o
	rm -f bin/*.exe