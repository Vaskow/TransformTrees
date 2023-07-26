#include "BinTree.h"
#pragma once

class ComNode //узел дерева общего вида
{
	friend class ComTree; 

public:
	ComNode(int _data, string _str) : data(_data), dataStr(_str), son(nullptr),
		brot{ nullptr }, pred(nullptr), statePassed(false), number_verh(0), xNode(0), yNode(0)
	{}


private:
	int data;
	string dataStr;
	ComNode* son;
	vector<ComNode*> brot;
	ComNode* pred;
	bool statePassed;
	int number_verh; //номер потомка с 0
	int xNode;
	int yNode;
};

class ComTree  //дерево общего вида
{
private:
	void delete_ComTree(ComNode* root);

public:
	ComTree(int _data = 0, string _str = "*") : root(nullptr), cur(nullptr), amountNodes(0)
	{}

	~ComTree()
	{
		delete_ComTree(root);
	}

	//«аполнить дерево общего вида в соответствии со значени€ми узлов из текстового файла 
	void ReadComTreeFromFile(string nameFile);
	//ѕеревести бинарное дерево в дерево общего вида
	void TransformInComTree(BinTree& bt);
	//ѕеревести дерево общего вида в бинарное дерево
	void TransformInBinTree(BinTree& bt);
	//ќбновить состо€ние пройденных узлов в дереве
	void UpdateStatePassedInNodes();
	//¬ывод на консоль узлов дерева общего вида (дл€ консольного приложени€)
	void PrintCommonTree();
	//Ќарисовать дерево общего вида в окне. ¬озвращает высоту дерева, от которой можно рисовать
	int PaintComTree(HDC hdc, int heightRoot);
	//ѕолучить маскимальную глубину бинарного дерева
	int MaxDepthComTree();
	friend void BinTree::InsertNodeInBinTree(int dataVerh, string dataStr, int leftVerh, int rightVerh);

private:
	//ƒобавлени€ узла и информации о существовании его потомков в дерево общего вида
	void InsertNodeInComTree(int dataVerh, string dataStr, vector<int>& vecChild);
	
	ComNode* root;
	ComNode* cur;
	int amountNodes;
};
