#include "BinTree.h"

void BinTree::delete_tree(BinNode* _root)
{
	if (_root)
	{
		delete_tree(_root->left);
		delete_tree(_root->right);
		delete _root;
	}
}

void BinTree::ReadBinTreeFromFile(string nameFile)
{
	string str;

	ifstream file1(nameFile); //������ ������ ��������� ���� �� ����� � �������� ���

	if (!file1.is_open())
	{
		return;
	}

	while (!file1.eof())
	{
		getline(file1, str);

		if (str == "" || str == " ")
		{
			break;
		}

		string strNumNode, dateStrNode, childNodes;

		istringstream iss(str); //����� ��� ��������� �������
		iss >> strNumNode;
		iss >> dateStrNode;
		iss >> childNodes;

		int colon = 0; //����� ���������
		for (char sym : strNumNode)
		{
			if (strNumNode[colon] != ':') { colon++; }
		}
		int numNode = stoi(strNumNode.substr(0, colon));

		int indentComma = 0; //������ �� ������� (���� ����)
		bool isComma = false;
		for (char sym : childNodes)
		{
			if (childNodes[indentComma] != ',') { indentComma++; }
			else isComma = true;
		}
		int leftNode = 0;
		int rightNode = 0;
		
		string strChild = "";
		if (isComma) //������� ������� (������ ���� �������)
		{
			strChild = childNodes.substr(0, indentComma);
			if (strChild != "" && strChild != "-")
			{
				leftNode = stoi(strChild); //leftNode
			}
			strChild = "";
			strChild = childNodes.substr(indentComma + 1, string::npos);
			
			if (strChild != "" && strChild != "-")
			{
				rightNode = stoi(strChild); //rightNode
			}
		}

		InsertNodeInBinTree(numNode, dateStrNode, leftNode, rightNode);
	};
	file1.close();
}


void BinTree::InsertNodeInBinTree(int numVerh, string dataStr, int leftVerh, int rightVerh)
{
	if (root == nullptr) //�������� �����
	{
		root = new BinNode(numVerh, dataStr); //������� ������� (����� ���)
		cur = root; //������� �� ������ 
		amountNodes++;
		if (leftVerh != 0 || rightVerh != 0)
		{
			if (leftVerh != 0 && rightVerh != 0)
			{
				cur->left = new BinNode(leftVerh, "*");
				cur->left->pred = cur;

				cur->right = new BinNode(rightVerh, "*");
				cur->right->pred = cur;
			}
			else if (leftVerh == 0 && rightVerh != 0)
			{
				cur->right = new BinNode(rightVerh, "*");
				cur->right->pred = cur;
			}
			else if (leftVerh != 0 && rightVerh == 0)
			{
				cur->left = new BinNode(leftVerh, "*");
				cur->left->pred = cur;
			}
		}

		return;
	}

	bool stop = false;
	bool findVerh = false;
	cur = root;
	cur->statePassed = true;
	while (stop != true)  //���������� ������ �������
	{
		if (cur->left != nullptr && cur->left->statePassed == false) //����� ���� != nullptr � �� ���� �� �������� � ������ ������ ���� 
		{
			cur = cur->left; //����� �������� �� ������
			cur->statePassed = true; //������� ����� ����������
			if (cur->data == numVerh) { stop = true; findVerh = true; }
		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //������ ���� != nullptr 
		{
			cur = cur->right;  //����� �������� �� �������
			cur->statePassed = true; //������� ����� ����������
			if (cur->data == numVerh) { stop = true; findVerh = true; }
		}
		else if (cur->left == nullptr && cur->right == nullptr || //����� � ������ ���� ������
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //����� � ������ ��������
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //����� �������, � ������ ������
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //������ �������, � ����� ������
		{
			cur = cur->pred; //��������� ����, �.�. ��� ���� �� ������� ������ �������� 
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	if (findVerh = true) //���������� �������
	{
		cur->dataStr = dataStr;
		cur->statePassed = true; //������� ����� ����������
		amountNodes++;
		if (leftVerh != 0 || rightVerh != 0)
		{
			if (leftVerh != 0 && rightVerh != 0)
			{
				cur->left = new BinNode(leftVerh, "*");
				cur->left->pred = cur;

				cur->right = new BinNode(rightVerh, "*");
				cur->right->pred = cur;
			}
			else if (leftVerh == 0 && rightVerh != 0)
			{
				cur->right = new BinNode(rightVerh, "*");
				cur->right->pred = cur;
			}
			else if (leftVerh != 0 && rightVerh == 0)
			{
				cur->left = new BinNode(leftVerh, "*");
				cur->left->pred = cur;
			}
		}
	}

	UpdateStatePassedInNodes(); //������ ��� ���������� ������ ��������� ���������
}

void BinTree::UpdateStatePassedInNodes()
{
	UpdateStatePassedInNodes(root);
}

void BinTree::UpdateStatePassedInNodes(BinNode* _root)
{
	if (_root)
	{
		UpdateStatePassedInNodes(_root->left);
		UpdateStatePassedInNodes(_root->right);
		_root->statePassed = false;
	}
}

void BinTree::PrintBtreeNode()
{
	cout << endl << " ����� ������ ��������� ����: " << endl;
	cout << endl;
	print_tree(root, 1); //����� ��������� ������

	//����� ����� ��������� ������
	bool stop = false;

	cout << endl;
	cout << " ���� ������ ��������� ����: " << endl;
	cout << " ������ ";
	cur = root;
	cout << cur->data << endl;
	cur->statePassed = true;
	while (stop != true)
	{
		if (cur->left != nullptr && cur->left->statePassed == false) //����� ���� != nullptr � �� ���� �� �������� � ������ ������ ���� 
		{
			cout << " ������:  " << cur->data;
			cur = cur->left;
			cout << " ������� �������:  " << cur->data;
			if (cur->left != nullptr) { cout << " �����: " << cur->left->data; }
			else { cout << " �����: ��� "; }

			if (cur->right != nullptr) { cout << " ������: " << cur->right->data; }
			else { cout << " ������: ��� "; }

			cout << endl;
			cur->statePassed = true; //������� ���� ��������

		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //������ ���� != nullptr 
		{

			cout << " ������:  " << cur->data;
			cur = cur->right;  //����� �������� �� �������
			cout << " ������� �������:  " << cur->data;

			if (cur->left != nullptr) { cout << " �����: " << cur->left->data; }
			else { cout << " �����: ��� "; }

			if (cur->right != nullptr) { cout << " ������: " << cur->right->data; }
			else { cout << " ������: ��� "; }

			cout << endl;
			cur->statePassed = true; //������� ���� ��������

		}
		else if (cur->left == nullptr && cur->right == nullptr || //����� � ������ ���� ������
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //����� � ������ ��������
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //����� �������, � ������� ������
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //������ �������, � ����� ������
		{
			cur = cur->pred; //��������� ����, �.�. ��� ���� �� ������� ������ �������� 
		}
		else if (cur == root)  stop = true; //��������� � �����
	}
	UpdateStatePassedInNodes();
}


void BinTree::print_tree(BinNode* root, int Num)
{
	if (root == nullptr) return;
	print_tree(root->right, Num + 1);
	for (int i = 0; i < Num + 1; i++)
		cout << "    ";
	cout << root->data << endl;
	print_tree(root->left, Num + 1);
}


vector<int> BinTree::FindWayToNodeInComTree(string _dataStr)
{
	vector<int> sol; //���� �� �������
	bool stop = false;
	bool findVerh = false;

	cur = root;
	cur->statePassed = true;
	
	while (stop != true)  //������� ������ �������
	{

		if (cur->left != nullptr && cur->left->statePassed == false) //����� ���� != nullptr � �� ���� �� �������� � ������ ������ ���� 
		{
			cur = cur->left;
			cur->statePassed = true;
			if (cur->dataStr == _dataStr) { stop = true; findVerh = true; }

		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //������ ���� != nullptr 
		{
			cur = cur->right;  //����� �������� �� �������
			cur->statePassed = true;
			if (cur->dataStr == _dataStr) { stop = true; findVerh = true; }
		}
		else if (cur->left == nullptr && cur->right == nullptr || //����� � ������ ���� ������
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //����� � ������ ��������
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //����� �������, � ������ ������
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //������ �������, � ����� ������
		{
			cur = cur->pred; //��������� ����, �.�. ��� ���� �� ������� ������ �������� 
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	if (findVerh) //���������� ���������� ����
	{
		sol.push_back(cur->data);
		while (cur != root)
		{
			if (cur->pred->right == cur) { cur = cur->pred; }
			else if (cur->pred->left == cur) { cur = cur->pred; sol.push_back(cur->data); }
		}
	}

	UpdateStatePassedInNodes();

	return sol;
}


int BinTree::MaxDepthBinTree()
{
	int maxDepthTree = 0; //������������ ������� � �������� ������
	int curDepth = 0;  //������� �������
	bool stop = false;
	cur = root;
	cur->statePassed = true;

	while (stop != true)
	{

		if (cur->left != nullptr && cur->left->statePassed == false) //����� ���� != nullptr � �� ���� �� �������� � ������ ������ ���� 
		{
			cur = cur->left;
			cur->statePassed = true;
			curDepth++;
		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //������ ���� != nullptr 
		{
			cur = cur->right;  //����� �������� �� �������
			cur->statePassed = true;
			curDepth++;
		}
		else if (cur->left == nullptr && cur->right == nullptr || //����� � ������ ���� ������
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //����� � ������ ��������
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //����� �������, � ������ ������
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //������ �������, � ����� ������
		{
			cur = cur->pred; //��������� ����, �.�. ��� ���� �� ������� ������ ��������
			if (maxDepthTree < curDepth) maxDepthTree = curDepth;
			curDepth--;
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	UpdateStatePassedInNodes();

	return maxDepthTree;
}


int BinTree::PaintBinTree(HDC hdc, int heightRoot)
{
	bool stop = false;
	int xNode = 700;
	int yNode = heightRoot;
	int xPredNode = xNode;
	int yPredNode = yNode;
	int yHeightTree = heightRoot; //������ ������������� ������

	int maxDepth = MaxDepthBinTree();
	yHeightTree = yHeightTree + (maxDepth + 1) * 35; //������ ������������� ������, � ������� ����� ��������

	vector<int> xLastNodeinDepth(maxDepth); //������ ��������� ������������ ������� �� i ������� (������ � �������� �����)
	int cur_depth = -1; //������� ������� ������ (� �������� �� ����� ������)

	bool ifRoot = true;

	int xLevel = 3 * (maxDepth + 1); //�������� ��� ���������� ���������� � ���������� ������
	cur = root;
	Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);

	HFONT hFont = CreateFont(14, 5, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, L"Times New Roman");
	SelectObject(hdc, hFont);

	TCHAR  buffer[10];
	swprintf_s(buffer, 10, L"%d", root->data);
	TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));

	cur->statePassed = true;
	while (stop != true)  //���������� ������ �������
	{
		if (cur->left != nullptr && cur->left->statePassed == false) //����� ���� != nullptr � �� ���� �� �������� � ������ ������ ���� 
		{
			cur_depth++;

			cur = cur->left; //����� �������� �� ������
			cur->statePassed = true; //������� ����� ����������
			yPredNode = yNode;
			xPredNode = xNode;

			if (!ifRoot)
			{
				xNode = xNode - (maxDepth - cur_depth + 5) * xLevel / (cur_depth + 1);
				xLevel = xLevel - 3;
			}
			else
			{
				xNode = xNode - 30;
				ifRoot = false;
			}
			yNode += 35;

			cur->xNode = xNode;
			cur->yNode = yNode;

			Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);
			swprintf_s(buffer, 10, L"%d", cur->data);
			TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));
			MoveToEx(hdc, xPredNode, yPredNode + 8, nullptr);
			LineTo(hdc, xNode + 12, yNode + 2);
			
		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //������ ���� != nullptr 
		{
			cur_depth++;

			cur = cur->right;  //����� �������� �� �������
			cur->statePassed = true; //������� ����� ����������
			yPredNode = yNode;
			xPredNode = xNode;
			
			xNode = xNode + (maxDepth - cur_depth + 5) * xLevel / (cur_depth + 1);
			yNode += 35;
			xLevel = xLevel - 3;

			cur->xNode = xNode;
			cur->yNode = yNode;

			Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);
			swprintf_s(buffer, 10, L"%d", cur->data);
			TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));
			MoveToEx(hdc, xPredNode + 16, yPredNode + 8, nullptr);
			LineTo(hdc, xNode + 12, yNode + 1);
			
		}
		else if (cur->left == nullptr && cur->right == nullptr || //����� � ������ ���� ������
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //����� � ������ ��������
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //����� �������, � ������ ������
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //������ �������, � ����� ������
		{
			xLevel = xLevel + 3;
			cur_depth--;

			cur = cur->pred; //��������� ����, �.�. ��� ���� �� ������� ������ ��������
			xNode = cur->xNode;
			yNode = cur->yNode;
			if (cur != root)
			{
				xPredNode = cur->pred->xNode;
				yPredNode = cur->pred->yNode;
			}
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	DeleteObject(hFont);
	UpdateStatePassedInNodes();

	return yHeightTree;
}