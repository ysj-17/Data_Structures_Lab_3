// Description:  
//  Using double linked list operations to read a file
//  Using that read data and sorting with Radix Sort
// 
// Big O(N):
//  O(nk) not including doubly linked list operations
//
//
// Author: Jason Yoon



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h> 
#include "List.h"
#include "RadixSort.h"

using namespace std;

int main() {

	int intInput = 0;
	string FILE_NAME = "Numbers.txt";
	fstream streamInt(FILE_NAME, ios::in);
	List<int> objectInt;
	RadixSort<int> radixObj;	// Radix Class object containing the algo
	List<int> bucketArray[10];
	int total_ItemsBefore_Sort = 0;
	int total_ItemsAfter_Sort = 0;
	
	

	if (!streamInt) {
		cout << "Error #2: Error opening file. Program aborting." 
				<< endl;
		cin.get();
		return 0; // Exits main if read wrong
	}


	string container;
	while (getline(streamInt, container)) {
		stringstream(container) >> intInput;
		if (objectInt.add(intInput) == false) {
			cout << "Error #3: Error occured in reading the file." 
					<< endl;
			break;
		}
	}

	// For testing
	// Get number of items before Sort
	total_ItemsBefore_Sort = objectInt.sizeOfList();

	// Sorting here
	radixObj.sort(objectInt, bucketArray);

	// For testing
	// Number of items after sort
	total_ItemsAfter_Sort = objectInt.sizeOfList();

	// Output
	objectInt.displayList();
	cout << endl;
	cout << "Total items in List before sort: " 
			<< total_ItemsBefore_Sort << endl;
	cout << "Total items in List after sort: " 
			<< objectInt.sizeOfList() << endl;



	cin.get();
	return 0;
}

