#include "Reservoir.h"
#include "cstring"
#include <iostream>
using namespace std;


Reservoir::Reservoir(const char* newResName, const char* newTypeName, int length, int width, int depth) //максимальный констурктор
{
	this->length = length;
	this->width = width;
	this->depth = depth;

	if (newResName != nullptr) {
		int resNameSize = strlen(newResName);
		this->reservoirName = new char[resNameSize + 1];
		strcpy_s(this->reservoirName, resNameSize + 1, newResName);
		this->reservoirName[resNameSize] = '\0';
	}
	
	if (newTypeName != nullptr) {
		int resTypeSize = strlen(newTypeName);
		this->typeName = new char[resTypeSize + 1];
		strcpy_s(this->typeName, resTypeSize + 1, newTypeName);
		this->typeName[resTypeSize] = '\0';
	}
	

	
}

Reservoir::Reservoir(const Reservoir& res) // конструктор копирования
{
	this->depth = res.depth;
	this->length = res.length;
	this->width = res.width;

	int resNameSize = strlen(res.reservoirName);
	this -> reservoirName = new char[resNameSize + 1];

	for (int i = 0; i < resNameSize+1; i++) {
		this->reservoirName[i] = res.reservoirName[i];
		if (res.reservoirName[i] == '\0') {
			this->reservoirName[i] = '\0';
			break;
		}
	}

	int resTypeSize = strlen(res.typeName);
	this->typeName = new char[resTypeSize + 1];
	for (int i = 0; i < resTypeSize + 1; i++) {
		this->typeName[i] = res.typeName[i];
		if (res.typeName[i] == '\0') {
			this->typeName[i] = '\0';
			break;
		}

	}

}
//// Set
void Reservoir::setLength(int length)
{
	this->length = length;
}

void Reservoir::setWidth(int width)
{
	this->width = width;
}

void Reservoir::setDepth(int depth)
{
	this->depth = depth;
}

void Reservoir::setResName(char* resName)
{
	int size = strlen(resName);
	this->reservoirName = new char[size + 1];
	for (int i = 0; i < size + 1; i++) {
		this->reservoirName[i] = resName[i];
		if (resName[i] == '\0') {
			this->reservoirName[i] = '\0';
			break;
		}
	}
}

void Reservoir::setResType(char* typeName)
{
	int size = strlen(typeName);
	this->typeName = new char[size + 1];
	for (int i = 0; i < size + 1; i++) {
		this->typeName[i] = typeName[i];
		if (typeName[i] == '\0') {
			this->typeName[i] = '\0';
			break;
		}
	}
}

void Reservoir::input()
{
	const int SIZE = 100;
	char* newName = new char[SIZE];
	cout << "Enter reservoir name: ";
	cin.getline(newName, SIZE);
	setResName(newName);

	char* newType = new char[SIZE];
	cout << "Enter reservoir type: ";
	cin.getline(newType, SIZE);
	setResType(newType);

	int depth, width, length;
	cout << "Enter depth: ";
	cin >> depth;
	setDepth(depth);

	cout << "Enter Length: ";
	cin >> length;
	setLength(length);

	cout << "Enter width: ";
	cin >> width;
	setWidth(width);
	cin.ignore();
}


////Get
int Reservoir::getLength() const
{
	return this->length;
}

int Reservoir::getWidth() const
{
	return this->width;
}

int Reservoir::getDepth() const
{
	return this->depth;
}

char* Reservoir::getResName() const
{
	return this->reservoirName;
}

char* Reservoir::getResType() const
{
	return this->typeName;
}


//Volume 
int Reservoir::reservoirVolume()
{
	return (this->width*this->length)*this->depth;
}

int Reservoir::reservoirSquare() // square
{
	return this->width*this->length;
}

int Reservoir::reservoirSquareCmp(Reservoir& res)
{
	int fstSquare = this->reservoirSquare();
	int secSquare = res.reservoirSquare();

	if (fstSquare > secSquare) {
		return 1;
	}
	
	if (fstSquare < secSquare) {
		return -1;
	}

	if (fstSquare == secSquare) {
		return 0;
	}
}

int Reservoir::reservoirTypeCmp(const Reservoir& res)
{
	int minSize = strlen(this->typeName);

	if (strlen(res.typeName) < minSize) {
		minSize = strlen(res.typeName);
	}

	for (int i = 0; i < minSize; i++) {
		if (this->typeName[i] != res.typeName[i]) {
			return 0;
		}
	}

	return 1;
}

void Reservoir::showRes()
{
	cout << "-----------\n";
	cout << "Reservoir name: " << this->reservoirName << endl;
	cout << "Reservoir type: " << this->typeName << endl;
	cout << "Reservoir length: " << this->length << endl;
	cout << "Reservoir width: " << this->width << endl;
	cout << "Reservoir depth: " << this->depth << endl;
	cout << "--------------\n";



}



//деструктор
Reservoir::~Reservoir()
{
	if (reservoirName != nullptr) {
		delete[] reservoirName;
	}
	
	
	if (typeName != nullptr) {
		delete[] typeName;

	}
	
	
	
	
}

