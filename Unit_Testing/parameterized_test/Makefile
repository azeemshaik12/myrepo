target1 :test1.cpp
	g++ test1.cpp -lgtest -lgtest_main -lpthread -o all.out

target2 :test2.cpp
	g++ test2.cpp -lgtest -lgtest_main -lpthread -o as.out

run1 :target1
	./all.out

run2 :target2
	./as.out

clear :
	 clear && (rm *.out)

