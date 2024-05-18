#include <iostream>
#include "Reservoir.h"
#include <string>
using namespace std;

void resMenuList() {
	cout << endl;
	cout << "1 - add new reservoir\n";
	cout << "2 - show all reservoir`s\n";
	cout << "3 - delete reservoir\n";
	cout << "4 - compare reservoirs by volume\n";
	cout << "5 - compare reservoirs by type\n";
	cout << "0 - Exit\n";
	cout << "---------\n";
	cout << "Enter choice: ";
}

int searchedResIndex(const Reservoir* arr,int size) {
	try {
		int index = -1;
		const int MAXSIZE = 100;
		char* searchedName = new char[MAXSIZE];


		cout << "Enter name of searched reservoir: ";
		cin.getline(searchedName, MAXSIZE);
		for (int i = 0; i < size; i++) {
			if (strcmp(arr[i].getResName(), searchedName) == 0) {
				index = i;
				break;
			}
		}
		if (index >= 0) {
			return index;
		}
		else {
			throw exception("Reservoir index cant be found\n");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}

	
}

void delResFromArr(Reservoir* arr,int& size) {

	try {
		Reservoir* newArr = new Reservoir[size - 1];
		int index = searchedResIndex(arr, size);
		if (index >= 0) {
			for (int i = 0; i < size - 1; i++) {
				if (i >= index) {
					newArr[i].setResName(arr[i + 1].getResName());
					newArr[i].setResType(arr[i + 1].getResType());
					newArr[i].setWidth(arr[i + 1].getWidth());
					newArr[i].setLength(arr[i + 1].getLength());
					newArr[i].setDepth(arr[i + 1].getDepth());
				}
				else if (i < index) {
					newArr[i].setResName(arr[i].getResName());
					newArr[i].setResType(arr[i].getResType());
					newArr[i].setWidth(arr[i].getWidth());
					newArr[i].setLength(arr[i].getLength());
					newArr[i].setDepth(arr[i].getDepth());
				}
			}
			size--;
			delete[] arr;
			arr = newArr;
		}
		else {
			throw exception("can`t find any matches for delete\n");
			delete[]newArr;
		}
	}
	catch(exception& ex){
		cout << ex.what() << endl;
	}

	
}

void addRes(Reservoir*& arr, int& size) { 
	
	Reservoir* newArr = new Reservoir[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i].setResName(arr[i].getResName());
		newArr[i].setResType(arr[i].getResType());
		newArr[i].setWidth(arr[i].getWidth());
		newArr[i].setLength(arr[i].getLength());
		newArr[i].setDepth(arr[i].getDepth());

	}

	newArr[size].input();

	size++;
	delete[] arr; 
	arr = newArr;
}

void showRes(Reservoir* arr, int&size) {

	try {
		if (arr != nullptr) {
			for (int i = 0; i < size; i++) {
				arr[i].showRes();
			}
		}
		else {
			throw exception("No reservoir in array\n");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}

void compareResBySquare(Reservoir* arr,int size) {

	try {
		int fstIndex = searchedResIndex(arr, size);
		int secIndex = searchedResIndex(arr, size);
		int result = arr[fstIndex].reservoirSquareCmp(arr[secIndex]);
		if (fstIndex >= 0 && secIndex >= 0) {
			if (result == 0) {
				cout << "Reservoirs equal\n";
			}
			else if (result == 1) {
				cout << "Reservoir  '" << arr[fstIndex].getResName() << "'  is larger\n";
				cout << arr[fstIndex].reservoirSquare() << "m^3" << endl;
			}
			else if (result == -1) {
				cout << "Reservoir " << arr[secIndex].getResName() << " is larger\n";
				cout << arr[secIndex].reservoirSquare() << "m^3" << endl;
			}
		}
		else {
			throw  exception("Wrong index by sqaure\n");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}

}

void compareResByTypeName(Reservoir* arr, int size) {

	int fstIndex = searchedResIndex(arr, size);
	int secIndex = searchedResIndex(arr, size);
	int result = arr[fstIndex].reservoirTypeCmp(arr[secIndex]);
	if (result == 0) {
		cout << "\n";
		cout << "DIFFERENT types of reservoirs\n";

	}
	else if(result == 1){

		cout << "Type of reservoir is SAME\n";
	}
}

int main() {

	int size = 0;
	Reservoir* resArr = nullptr;

	int choice;
	do {
		resMenuList();
		cin >> choice;
		cin.ignore();

		switch (choice){
		case 1:
			addRes(resArr, size);
			break;
		case 2:
			showRes(resArr, size);
			break;	
		case 3:
			delResFromArr(resArr, size);
			break;
		case 4: 
			
			compareResBySquare(resArr, size);
			
			
			break;
		case 5:
			compareResByTypeName(resArr, size);
			break;
		case 0:
			cout << "Bye!!!\n";
			delete[] resArr;
			break;

		default:
			cout << "You enter wrong choice\n";
			break;
		}
	} while (choice != 0);
	

	 

	
	
	
	

	


	return 0;
}