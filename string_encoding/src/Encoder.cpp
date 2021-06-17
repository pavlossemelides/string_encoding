/*
 * Encoder.cpp
 *
 *  Created on: Jun 9, 2021
 *      Author: pavlo
 */

#include "Encoder.h"

Encoder::Encoder() {
	// TODO Auto-generated constructor stub

}

string Encoder::compressString(string decompressedValue) {

	//create variables to cycle through decompressedValue.  Use two recorders to detect change in characters, i.e. if recorder != recorder2.
	char recorder1;
	char recorder2;
	int counter = 1;
	int position = 0;
	int length = decompressedValue.length();
	int mod;

	//Create char array to store encoded string.  Make size equal to decompressedValue and trim later.
	char array[length];
	for (int i = 0; i < length; i++) {
		array[i] = '0';
	}
	char *pArray = array;

	//Cycle through decompressedValue string and populate array.
	while (position < length) {

		recorder1 = decompressedValue[position];
		recorder2 = decompressedValue[position + 1];

		//If consecutive entries in decompressedValue are different, create entry in "array" accordingly and reset counter.
		if (recorder2 != recorder1) {
			//if counter > 9 , i.e. double-digit encoding, use modulus and quotient.
			if (counter > 9) {
				mod = counter%10;
				counter /= 10;
				*pArray = char(counter + 48); //convert integer to char.
				pArray++;
				*pArray = char(mod + 48);
				pArray++;
				*pArray = recorder1;
				pArray++;
				counter = 1;
				break;
			}
			//else if single-digit encoding use following.
			*pArray = char(counter + 48);
			pArray++;
			*pArray = recorder1;
			pArray++;
			counter = 1;
		} else
		{
			//Iterate counter whenever consecutive entries in decompressedValue are the same.
			counter++;
		}
		//move up one position in decompressedValue.
		position++;
	}

	//Count how many character entries we made into array.
	int i = 0;
	pArray = array;
	while (*pArray != '0') {
		i++;
		pArray++;
	}

	//Use above count to create decompressedArray.
	char decompressedArray[i];

	//Copy array to decompressedArray, excluding '0's
	for (int j = 0; j < i; j++) {
		decompressedArray[j] = array[j];
	}

	string compressedValue = decompressedArray;

	return compressedValue;
}

string Encoder::decompressString(string compressedValue) {

	//"8A4B11C3D"
	//Create char array to copy string "compressedValue" to.
	int length = compressedValue.length();
	char array[length];
	cout << length << endl;
	compressedValue.copy(array, length);

	//Create variables and pVehicles to cycle through char array.
	int position = 0;
	char *pVehicle1 = array;
	char *pVehicle2 = pVehicle1 + 1;
	char *pVehicle3;

	//Cycle through char array and count how many chars our decompressedValue will hold.
	int counter = 0;

	while (position < length) {
		if ((int) *pVehicle1 < 58 && (int) *pVehicle2 > 58) { //for single-digit char encoding.
			counter += *pVehicle1 - '0';
			pVehicle1 = pVehicle1 + 2;
			pVehicle2 = pVehicle2 + 2;
			position = position + 2;
		} else if ((int) *pVehicle1 < 58 && (int) *pVehicle2 < 58) { //for double-digit char encoding.
			counter += (*pVehicle1 - '0') * 10 + (*pVehicle2 - '0');
			pVehicle1 = pVehicle1 + 3;
			pVehicle2 = pVehicle2 + 3;
			position = position + 3;
		}
	}

	cout << counter << endl;

	//Initialize array of decompressed characters.
	char decompressedArray[counter];
	for (int i = 0; i < counter; i++) {
		decompressedArray[i] = '0';
	}

	//counter for character encoding. E.g. for "8A" encodingCounter = 8
	int encodingCounter = 0;

	//setup variables and pVehicles to cycle through encoded char array and populate decompressed array "decompressedArray".
	pVehicle1 = array;
	pVehicle2 = pVehicle1 + 1;
	position = 0;
	int j = 0;


	while (position < length) {
		//if single-digit encoding, convert pVehicle1 to int and populate decompressedArray accordingly, using char from pVehicle2.
		if ((int) *pVehicle1 < 58 && (int) *pVehicle2 > 58) {
			encodingCounter = *pVehicle1 - '0';
			cout << encodingCounter << endl;
			for (int i = 0; i < encodingCounter; i++) {
				decompressedArray[i + j] = *pVehicle2;
			}
			j += encodingCounter;
			pVehicle1 = pVehicle1 + 2;
			pVehicle2 = pVehicle2 + 2;
			position = position + 2;

			//if double-digit encoding, convert pVehicle1 & pVehicle2 to int and combine.
			//Intorduce pVehicle3 to point at encoded char. E.g. "11C", pVehicle1 = 1, pVehicle2 = 1, pVehicle3 = C
		} else if ((int) *pVehicle1 < 58 && (int) *pVehicle2 < 58) {
			encodingCounter = (*pVehicle1 - '0') * 10 + (*pVehicle2 - '0');
			cout << encodingCounter << endl;
			pVehicle3 = pVehicle2 + 1;
			for (int i = 0; i < encodingCounter; i++) {
				decompressedArray[i + j] = *pVehicle3;
			}
			j += encodingCounter;
			pVehicle1 = pVehicle1 + 3;
			pVehicle2 = pVehicle2 + 3;
			position = position + 3;
		}
	}

	//Assign decompressedArray to string decompressedValue and return.
	string decompressedValue = decompressedArray;
	return decompressedValue;
}

Encoder::~Encoder() {
	// TODO Auto-generated destructor stub
}

