#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> //stream string
#include <Windows.h>
#pragma once
using namespace std;

class BinNode	//узел бинарного дерева
{
	friend class BinTree;	

public:

	BinNode(int _data, string _str) :data(_data), dataStr(_str), left(nullptr),
		right(nullptr), pred(nullptr), statePassed(false), xNode(0), yNode(0)
	{}

	int getData() {
		return data;
	}

	string getDataStr() {
		return dataStr;
	}

	BinNode* getRight() {
		return right;
	}

	BinNode* getLeft() {
		return left;
	}

	BinNode* getPred() {
		return pred;
	}

	bool getStatePassed() {
		return statePassed;
	}

	void setStatePassed(bool newState) {
		statePassed = newState;
	}

private:
	int data;
	string dataStr;
	BinNode* left;
	BinNode* right;
	BinNode* pred;
	bool statePassed; //состо€ние пройденного узла
	int xNode;
	int yNode;
};

class BinTree	//бинарное дерево
{
private:
	void print_tree(BinNode* root, int Num); //вывод на консоль узла и его потомков (дл€ консольного приложени€)
	void delete_tree(BinNode* root);
	void UpdateStatePassedInNodes(BinNode* root);

public:

	BinTree() : root(nullptr), cur(nullptr), amountNodes(0)
	{}

	~BinTree()
	{
		delete_tree(root);
	}

	BinNode* getRoot()
	{
		return root;
	}
	BinNode* getCur()
	{
		return cur;
	}

	//«аполнить бинарное дерево в соответствии со значени€ми узлов из текстового файла 
	void ReadBinTreeFromFile(string nameFile);
	//¬ывод на консоль бинарного дерева и его узлов (дл€ консольного приложени€)
	void PrintBtreeNode();
	//ќбновить состо€ние пройденных узлов в дереве
	void UpdateStatePassedInNodes();
	//ѕолучение пути до узла с данными dataStr (путь актуален дл€ дерева в общем виде)
	vector<int> FindWayToNodeInComTree(string dataStr);
	//Ќарисовать бинарное дерево в окне. ¬озвращает высоту дерева, от которой можно рисовать 
	int PaintBinTree(HDC hdc, int heightRoot);
	//ѕолучить маскимальную глубину бинарного дерева
	int MaxDepthBinTree();
	//ƒобавлени€ узла и информации о существовании его потомков в бинарное дерево
	void InsertNodeInBinTree(int dataVerh, string dataStr, int leftVerh, int rightVerh);

private:
	BinNode* root;
	BinNode* cur;
	int amountNodes;
};

