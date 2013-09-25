all:
	g++ main.cpp io.cpp data_types.cpp functions.cpp memo.cpp struct.cpp union.cpp enum.cpp oop.cpp template.cpp namespace.cpp exception.cpp typeid.cpp casting.cpp -o tutorial

clean:
	rm -rf *.o tutorial