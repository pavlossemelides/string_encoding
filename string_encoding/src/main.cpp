//============================================================================
// Name        : NCR.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Encoder.h"
using namespace std;

int main() {

	Encoder encoder;

	string test;

	string test2;

	string decompressedValue = "AAAAAAAABBBBCCCCCCCCCCCDDD";

	string compressedValue = "8A4B11C3D";

	test = encoder.compressString(decompressedValue);

	test2 = encoder.decompressString(compressedValue);

	cout << test << endl;

	cout << test2 << endl;



	return 0;
}
