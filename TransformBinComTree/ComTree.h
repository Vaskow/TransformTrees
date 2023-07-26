#include "BinTree.h"
#pragma once

class ComNode //���� ������ ������ ����
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
	int number_verh; //����� ������� � 0
	int xNode;
	int yNode;
};

class ComTree  //������ ������ ����
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

	//��������� ������ ������ ���� � ������������ �� ���������� ����� �� ���������� ����� 
	void ReadComTreeFromFile(string nameFile);
	//��������� �������� ������ � ������ ������ ����
	void TransformInComTree(BinTree& bt);
	//��������� ������ ������ ���� � �������� ������
	void TransformInBinTree(BinTree& bt);
	//�������� ��������� ���������� ����� � ������
	void UpdateStatePassedInNodes();
	//����� �� ������� ����� ������ ������ ���� (��� ����������� ����������)
	void PrintCommonTree();
	//���������� ������ ������ ���� � ����. ���������� ������ ������, �� ������� ����� ��������
	int PaintComTree(HDC hdc, int heightRoot);
	//�������� ������������ ������� ��������� ������
	int MaxDepthComTree();
	friend void BinTree::InsertNodeInBinTree(int dataVerh, string dataStr, int leftVerh, int rightVerh);

private:
	//���������� ���� � ���������� � ������������� ��� �������� � ������ ������ ����
	void InsertNodeInComTree(int dataVerh, string dataStr, vector<int>& vecChild);
	
	ComNode* root;
	ComNode* cur;
	int amountNodes;
};
