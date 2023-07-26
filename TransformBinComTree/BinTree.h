#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> //stream string
#include <Windows.h>
#pragma once
using namespace std;

class BinNode	//���� ��������� ������
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
	bool statePassed; //��������� ����������� ����
	int xNode;
	int yNode;
};

class BinTree	//�������� ������
{
private:
	void print_tree(BinNode* root, int Num); //����� �� ������� ���� � ��� �������� (��� ����������� ����������)
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

	//��������� �������� ������ � ������������ �� ���������� ����� �� ���������� ����� 
	void ReadBinTreeFromFile(string nameFile);
	//����� �� ������� ��������� ������ � ��� ����� (��� ����������� ����������)
	void PrintBtreeNode();
	//�������� ��������� ���������� ����� � ������
	void UpdateStatePassedInNodes();
	//��������� ���� �� ���� � ������� dataStr (���� �������� ��� ������ � ����� ����)
	vector<int> FindWayToNodeInComTree(string dataStr);
	//���������� �������� ������ � ����. ���������� ������ ������, �� ������� ����� �������� 
	int PaintBinTree(HDC hdc, int heightRoot);
	//�������� ������������ ������� ��������� ������
	int MaxDepthBinTree();
	//���������� ���� � ���������� � ������������� ��� �������� � �������� ������
	void InsertNodeInBinTree(int dataVerh, string dataStr, int leftVerh, int rightVerh);

private:
	BinNode* root;
	BinNode* cur;
	int amountNodes;
};

