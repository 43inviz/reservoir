#pragma once
class Reservoir
{
	char* reservoirName;
	char* typeName;
	int width;
	int length;
	int depth;

public:

	//�����������
	Reservoir(const char* newResName, const char* newTypeName, int length, int width, int depth);

	//������������� ������������
	Reservoir() :Reservoir(nullptr, nullptr , 0, 0, 0) {}
	Reservoir(char* newResName, char* type, int width) :Reservoir(newResName, type, width, 0, 0) {}

	//����������� �����������
	explicit Reservoir(const Reservoir& res);

	// Seters\geters

	void setLength(int length);
	void setWidth(int width);
	void setDepth(int depth);
	void setResName(char* resName);
	void setResType(char* typeName);

	void input();


	int getLength() const ;
	int getWidth()const;
	int getDepth() const ;
	char* getResName() const;
	char* getResType() const;
	/// 

	///Metod`s 
	int reservoirVolume();
	int reservoirSquare();
	
	int reservoirSquareCmp(Reservoir& res); /// vozvrat: 1- fst> \ -1 - sec> \ 0 - equal
	int reservoirTypeCmp(const Reservoir& res); // 1 - equal \ 0 - diff

	void showRes();

	~Reservoir();

};

