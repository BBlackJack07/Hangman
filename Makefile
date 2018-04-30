pendu.out : sources/*.cpp headers/*.h
	g++ sources/*.cpp headers/*.h -I headers -o pendu.out -std=c++17
