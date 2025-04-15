target :assert.cpp test.cpp
	g++ assert.cpp test.cpp -lgtest -lgtest_main -lpthread -o all.out
run :target
	./all.out
clear :
	rm all.out && clear
