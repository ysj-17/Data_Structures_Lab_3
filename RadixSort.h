#ifndef RADIX_SORT
#define RADIX_SORT
#include <string>
#include "List.h"

template<class T>
class RadixSort {

public:
	RadixSort() {}; // constructor

	// sort function
	void sort(List<T> &objectInt, List<T> bucketArray[10]);
	int radixGetMaxLength(List<T> &objectInt, int size);
	int radixGetLength(int num);
	

};


// Function:
// Recieves List of data and also array containing 10 lists (bucketArray)
// bucketArray is the intermediary structure to contain sorted data
// Returns sorted linked list by reference
template<class T>
void RadixSort<T>:: sort(List<T> &objectInt, List<T> bucketArray[10]) {

	int pow10 = 1;
	int counter = 0;
	int container = 0;
	int dataSize = objectInt.sizeOfList();
	int maxDigits = radixGetMaxLength(objectInt, dataSize);

	for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
		// This for loop controls putting the data into the buckets
		// Also handles the sort
		// Ex. 1 goes into bucketArray[1], 9 goes into bucketArray[9]
		// (cont.) then array positions accessed to get sorted integers
		for (int index = 0; index < dataSize; index++) {
			container = objectInt.returnValue(index);
			bucketArray[abs(container / pow10) % 10].add(container); 
		}

		// Clear objectInt to hold new data
		objectInt.clear();

		int arrayIndex = 0;
		for (int index = 0; index < 10; index++) {
			int sizeList = bucketArray[index].sizeOfList();
			if (sizeList != 0) {
				for (int bucketListIndex = 0; bucketListIndex < sizeList; bucketListIndex++) {
					T copier = bucketArray[index].returnValue(bucketListIndex);
					objectInt.add(copier); // Put in new data into original List
				}
			}
			
		}
		pow10 = 10 * pow10;
		// Clear buckets
		for (int clear = 0; clear < 10; clear++)
			bucketArray[clear].clear();
	}
	
}


// Function:
// Recieves List of int and size of list
// Returns maximum length of number found in List
template<class T>
int RadixSort<T>::radixGetMaxLength(List<T> &objectInt, int size) {
	int maxDigits = 0;
	for (int index = 0; index < size; index++) {
		int digitCount = radixGetLength(objectInt.returnValue(index));
		if (digitCount > maxDigits)
			maxDigits = digitCount;
	}
	return maxDigits;
}

// Function: 
// Recieves integer numbers a returns length of number
// Ex. 1514 --> has length of 4
template<class T>
int RadixSort<T>::radixGetLength(int num) {

	if (num == 0)
		return 1;

	int digits = 0;
	while (num != 0) {
		digits += 1;
		num = num / 10;
	}

	return digits;
}


#endif