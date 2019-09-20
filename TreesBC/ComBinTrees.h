#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

class Node //узел бинарного дерева
{
  public:
	int data;
	string dataStr;
	Node *left;
	Node *right;
	Node *pred;
	bool existInComTree; //узел существует в дереве общего вида (да или нет)
	~Node()
	{
		delete left;
		delete right;
		delete pred;
	}

	Node* getBinNode();
};

class BinTree  //бинарное дерево
{

  public:
	Node *root;
	Node *cur;

	BinTree* CreateBinTree();   //создание дерева
	BinTree* insert(BinTree * bt, int data); //добавление узла
	void print_tree(Node *root, int Num); //печать бинарного дерева
	void print_BtreeNode(BinTree * bt); //вывод узлов бинарного дерева
	void UpdateBoolBinNodes(BinTree *bt);//обновить в узлах existInComTree на false для дальнейшей работы с ним
	void CreateBinTr(int dataVerh, string dataStr, int leftVerh, int rightVerh, BinTree* bt); //строит бинарное дерево из файла
	int *FindSolution(BinTree* bt, string dataStr); //находит решение dataStr и запоминает путь в массив из номеров вершин
	void levelVerhBinTree(BinTree* bt, int *levelVerh, int NumberVerh);
};

class ComNode //узел дерева общего вида
{
  public:
	int data;
	string dataStr;
	ComNode *son;
	ComNode **brot;
	ComNode *pred;
	int number_verh; //номер вершины с 0
	int count_verh; //количество вершин
	bool existInBinTree;
	~ComNode()
	{
		delete son;
		delete pred;
		for(int i = 0; i < count_verh; i++)
		{
			delete brot[i];
		}
		delete brot;
	}

	ComNode* getComNode();
};

class CommonTree //дерево общего вида
{
  public:
	ComNode *root;
	ComNode *cur;
	CommonTree* CreateComTree();   //создание дерева
	void TransformCommonTree(BinTree *bt, CommonTree *ct); //перевод из бинарного в общий вид
	void TransformBinarTree(BinTree *bt, CommonTree *ct);  //перевод из общего в бинарный вид
	void UpdateBoolComNodes(CommonTree *ct); //обновить в узлах existInBinTree на false для дальнейшей работы с ним
	void print_CommonTree(CommonTree* ct); //вывод узлов дерева общего вида
	void CreateComTr(int dataVerh, string dataStr, int *masVerh, int numVerh, CommonTree* ct); //создание дерева по вершинам из файла (номер вершины, информация, массив вершин, количество вершин в массиве, указатель на дерево)
	void levelVerhComTree(CommonTree* ct, int *levelVerh, int NumberVerh);
};

void SetColor(int text, int bg); //для изменения цвета некоторым символам при выводе дерева
