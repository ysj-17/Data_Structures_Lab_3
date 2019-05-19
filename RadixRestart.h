#ifndef LAB3_RADIX
#define LAB3_RADIX
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



template<class T>
void RadixSort<T>:: sort(List<T> &objectInt, List<T> bucketArray[10]) {

	// int maxDigits = 5;
	int pow10 = 1;
	int counter = 0;
	int container = 0;
	
	int dataSize = objectInt.sizeOfList();

	int maxDigits = radixGetMaxLength(objectInt, dataSize);

	/*cout << endl << dataSize << " " << maxDigits;*/

	for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
		// This for loop controls putting the data into the buckets
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
				for (int bucketListIndex = 0; bucketListIndex < sizeList; 
														bucketListIndex++) {

					T copier = bucketArray[index].returnValue(bucketListIndex);
					objectInt.add(copier); // Put in new data into original List
				}
			}
			else; // Else do nothing if list is less than 0 size

			
		}
		pow10 = 10 * pow10;
		// Clear buckets
		for (int clear = 0; clear < 10; clear++)
			bucketArray[clear].clear();
	}
	
}



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