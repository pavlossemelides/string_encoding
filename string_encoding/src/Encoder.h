/*
 * Encoder.h
 *
 *  Created on: Jun 9, 2021
 *      Author: pavlo
 */

#include <iostream>
#ifndef ENCODER_H_
#define ENCODER_H_

using namespace std;

class Encoder {
public:

public:
	Encoder();
	string compressString(string decompressedValue);
	string decompressString(string compressedValue);
	virtual ~Encoder();
};

#endif /* ENCODER_H_ */
