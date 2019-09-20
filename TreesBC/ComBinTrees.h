#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

class Node //���� ��������� ������
{
  public:
	int data;
	string dataStr;
	Node *left;
	Node *right;
	Node *pred;
	bool existInComTree; //���� ���������� � ������ ������ ���� (�� ��� ���)
	~Node()
	{
		delete left;
		delete right;
		delete pred;
	}

	Node* getBinNode();
};

class BinTree  //�������� ������
{

  public:
	Node *root;
	Node *cur;

	BinTree* CreateBinTree();   //�������� ������
	BinTree* insert(BinTree * bt, int data); //���������� ����
	void print_tree(Node *root, int Num); //������ ��������� ������
	void print_BtreeNode(BinTree * bt); //����� ����� ��������� ������
	void UpdateBoolBinNodes(BinTree *bt);//�������� � ����� existInComTree �� false ��� ���������� ������ � ���
	void CreateBinTr(int dataVerh, string dataStr, int leftVerh, int rightVerh, BinTree* bt); //������ �������� ������ �� �����
	int *FindSolution(BinTree* bt, string dataStr); //������� ������� dataStr � ���������� ���� � ������ �� ������� ������
	void levelVerhBinTree(BinTree* bt, int *levelVerh, int NumberVerh);
};

class ComNode //���� ������ ������ ����
{
  public:
	int data;
	string dataStr;
	ComNode *son;
	ComNode **brot;
	ComNode *pred;
	int number_verh; //����� ������� � 0
	int count_verh; //���������� ������
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

class CommonTree //������ ������ ����
{
  public:
	ComNode *root;
	ComNode *cur;
	CommonTree* CreateComTree();   //�������� ������
	void TransformCommonTree(BinTree *bt, CommonTree *ct); //������� �� ��������� � ����� ���
	void TransformBinarTree(BinTree *bt, CommonTree *ct);  //������� �� ������ � �������� ���
	void UpdateBoolComNodes(CommonTree *ct); //�������� � ����� existInBinTree �� false ��� ���������� ������ � ���
	void print_CommonTree(CommonTree* ct); //����� ����� ������ ������ ����
	void CreateComTr(int dataVerh, string dataStr, int *masVerh, int numVerh, CommonTree* ct); //�������� ������ �� �������� �� ����� (����� �������, ����������, ������ ������, ���������� ������ � �������, ��������� �� ������)
	void levelVerhComTree(CommonTree* ct, int *levelVerh, int NumberVerh);
};

void SetColor(int text, int bg); //��� ��������� ����� ��������� �������� ��� ������ ������
