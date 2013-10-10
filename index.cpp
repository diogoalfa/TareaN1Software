//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main(int argc, char * argv[]) {
	int i = 0;
	cout << "Ejecutable:" << argv[0] << "\n";
	for (i = 0; i < argc; i++)
		cout << "Argumento["<< i<<"]: " << argv[i] << "\n";
	// cout << "hola mundo";
	return 0;
}
