// Program Name: Lab3
//
// Description:  
//  Using double linked list operations to read a file
//  Using that read data and sorting with Radix Sort
//
// What's on your mind about this lab?
//  It was very difficult for me to get the sort working
//  Double checking the quality of the lists, data, and sizes
//  was very tedious - but in the process I learned alot more.
//
// Author: Jason Yoon
//
// Date: 7/20/2018
//
// IDE Used: Visual Microsoft
//

//--- New Functions in List.h ---
//int sizeOfList();
//T returnValue(int size);
//void radixSort(List<int> objectInt);
//int radixGetMaxLength(int *unsorted, int arraySize);
//int radixGetLength(int dataInput);
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h> 
#include "List.h"
#include "RadixRestart.h"

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


	//objectInt.displayList();
	//Sleep(5000);

	// Get number of items before Sort
	total_ItemsBefore_Sort = objectInt.sizeOfList();

	// Sorting here
	radixObj.sort(objectInt, bucketArray);

	// Number of items after sort
	total_ItemsAfter_Sort = objectInt.sizeOfList();

	// Output
	objectInt.displayList();
	cout << endl;
	cout << "Total items in List before sort: " 
			<< total_ItemsBefore_Sort << endl;
	cout << "Total items in List after sort: " 
			<< objectInt.sizeOfList() << endl;



	// cin.ignore();
	cin.get();
	return 0;
}

