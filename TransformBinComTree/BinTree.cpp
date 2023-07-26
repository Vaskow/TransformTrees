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

	ifstream file1(nameFile); //чтение дерева бинарного вида из файла и создание его

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

		istringstream iss(str); //поток для разбиения команды
		iss >> strNumNode;
		iss >> dateStrNode;
		iss >> childNodes;

		int colon = 0; //поиск двоеточия
		for (char sym : strNumNode)
		{
			if (strNumNode[colon] != ':') { colon++; }
		}
		int numNode = stoi(strNumNode.substr(0, colon));

		int indentComma = 0; //отступ до запятой (если есть)
		bool isComma = false;
		for (char sym : childNodes)
		{
			if (childNodes[indentComma] != ',') { indentComma++; }
			else isComma = true;
		}
		int leftNode = 0;
		int rightNode = 0;
		
		string strChild = "";
		if (isComma) //найдена запятая (значит есть потомок)
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
	if (root == nullptr) //создание корня
	{
		root = new BinNode(numVerh, dataStr); //создали вершину (обход КЛП)
		cur = root; //текущий на корень 
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
	while (stop != true)  //нахождение нужной вершины
	{
		if (cur->left != nullptr && cur->left->statePassed == false) //левый узел != nullptr и он пока не добавлен в дерево общего вида 
		{
			cur = cur->left; //смена текущего на левого
			cur->statePassed = true; //вершина стала пройденной
			if (cur->data == numVerh) { stop = true; findVerh = true; }
		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //правый узел != nullptr 
		{
			cur = cur->right;  //смена текущего на правого
			cur->statePassed = true; //вершина стала пройденной
			if (cur->data == numVerh) { stop = true; findVerh = true; }
		}
		else if (cur->left == nullptr && cur->right == nullptr || //левый и правый узлы пустые
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //левый и правый пройдены
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //левый пройден, а правый пустой
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //правый пройден, а левый пустой
		{
			cur = cur->pred; //поднялись выше, т.к. все узлы на текущем уровне пройдены 
		}
		else if (cur == root)  stop = true; //поднялись к корню
	}

	if (findVerh = true) //добавление вершины
	{
		cur->dataStr = dataStr;
		cur->statePassed = true; //вершина стала пройденной
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

	UpdateStatePassedInNodes(); //вернем для пройденных вершин начальное состояние
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
	cout << endl << " Схема дерева бинарного вида: " << endl;
	cout << endl;
	print_tree(root, 1); //вывод бинарного дерева

	//Вывод узлов бинарного дерева
	bool stop = false;

	cout << endl;
	cout << " Узлы дерева бинарного вида: " << endl;
	cout << " Корень ";
	cur = root;
	cout << cur->data << endl;
	cur->statePassed = true;
	while (stop != true)
	{
		if (cur->left != nullptr && cur->left->statePassed == false) //левый узел != nullptr и он пока не добавлен в дерево общего вида 
		{
			cout << " Предок:  " << cur->data;
			cur = cur->left;
			cout << " Текущая вершина:  " << cur->data;
			if (cur->left != nullptr) { cout << " Левый: " << cur->left->data; }
			else { cout << " Левый: нет "; }

			if (cur->right != nullptr) { cout << " Правый: " << cur->right->data; }
			else { cout << " Правый: нет "; }

			cout << endl;
			cur->statePassed = true; //вершина была пройдена

		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //правый узел != nullptr 
		{

			cout << " Предок:  " << cur->data;
			cur = cur->right;  //смена текущего на правого
			cout << " Текущая вершина:  " << cur->data;

			if (cur->left != nullptr) { cout << " Левый: " << cur->left->data; }
			else { cout << " Левый: нет "; }

			if (cur->right != nullptr) { cout << " Правый: " << cur->right->data; }
			else { cout << " Правый: нет "; }

			cout << endl;
			cur->statePassed = true; //вершина была пройдена

		}
		else if (cur->left == nullptr && cur->right == nullptr || //левый и правый узлы пустые
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //левый и правый пройдены
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //левый пройден, а правого пустой
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //правый пройден, а левый пустой
		{
			cur = cur->pred; //поднялись выше, т.к. все узлы на текущем уровне пройдены 
		}
		else if (cur == root)  stop = true; //поднялись к корню
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
	vector<int> sol; //путь до решения
	bool stop = false;
	bool findVerh = false;

	cur = root;
	cur->statePassed = true;
	
	while (stop != true)  //находим нужную вершину
	{

		if (cur->left != nullptr && cur->left->statePassed == false) //левый узел != nullptr и он пока не добавлен в дерево общего вида 
		{
			cur = cur->left;
			cur->statePassed = true;
			if (cur->dataStr == _dataStr) { stop = true; findVerh = true; }

		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //правый узел != nullptr 
		{
			cur = cur->right;  //смена текущего на правого
			cur->statePassed = true;
			if (cur->dataStr == _dataStr) { stop = true; findVerh = true; }
		}
		else if (cur->left == nullptr && cur->right == nullptr || //левый и правый узлы пустые
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //левый и правый пройдены
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //левый пройден, а правый пустой
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //правый пройден, а левый пустой
		{
			cur = cur->pred; //поднялись выше, т.к. все узлы на текущем уровне пройдены 
		}
		else if (cur == root)  stop = true; //поднялись к корню
	}

	if (findVerh) //запоминаем пройденный путь
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
	int maxDepthTree = 0; //максимальная глубина в бинарном дереве
	int curDepth = 0;  //текущая глубина
	bool stop = false;
	cur = root;
	cur->statePassed = true;

	while (stop != true)
	{

		if (cur->left != nullptr && cur->left->statePassed == false) //левый узел != nullptr и он пока не добавлен в дерево общего вида 
		{
			cur = cur->left;
			cur->statePassed = true;
			curDepth++;
		}
		else if (cur->right != nullptr && cur->right->statePassed == false) //правый узел != nullptr 
		{
			cur = cur->right;  //смена текущего на правого
			cur->statePassed = true;
			curDepth++;
		}
		else if (cur->left == nullptr && cur->right == nullptr || //левый и правый узлы пустые
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //левый и правый пройдены
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //левый пройден, а правый пустой
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //правый пройден, а левый пустой
		{
			cur = cur->pred; //поднялись выше, т.к. все узлы на текущем уровне пройдены
			if (maxDepthTree < curDepth) maxDepthTree = curDepth;
			curDepth--;
		}
		else if (cur == root)  stop = true; //поднялись к корню
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
	int yHeightTree = heightRoot; //высота нарисованного дерева

	int maxDepth = MaxDepthBinTree();
	yHeightTree = yHeightTree + (maxDepth + 1) * 35; //высота нарисованного дерева, с которой можно рисовать

	vector<int> xLastNodeinDepth(maxDepth); //вектор последней отрисованной вершины на i глубине (считая с потомков корня)
	int cur_depth = -1; //текущая глубина дерева (с потомков от корня дерева)

	bool ifRoot = true;

	int xLevel = 3 * (maxDepth + 1); //величина для уменьшения расстояния с повышением уровня
	cur = root;
	Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);

	HFONT hFont = CreateFont(14, 5, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, L"Times New Roman");
	SelectObject(hdc, hFont);

	TCHAR  buffer[10];
	swprintf_s(buffer, 10, L"%d", root->data);
	TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));

	cur->statePassed = true;
	while (stop != true)  //нахождение нужной вершины
	{
		if (cur->left != nullptr && cur->left->statePassed == false) //левый узел != nullptr и он пока не добавлен в дерево общего вида 
		{
			cur_depth++;

			cur = cur->left; //смена текущего на левого
			cur->statePassed = true; //вершина стала пройденной
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
		else if (cur->right != nullptr && cur->right->statePassed == false) //правый узел != nullptr 
		{
			cur_depth++;

			cur = cur->right;  //смена текущего на правого
			cur->statePassed = true; //вершина стала пройденной
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
		else if (cur->left == nullptr && cur->right == nullptr || //левый и правый узлы пустые
			cur->left != nullptr && cur->left->statePassed == true && cur->right != nullptr && cur->right->statePassed == true || //левый и правый пройдены
			cur->left != nullptr && cur->left->statePassed == true && cur->right == nullptr && cur != root || //левый пройден, а правый пустой
			cur->right != nullptr && cur->right->statePassed == true && cur->left == nullptr && cur != root) //правый пройден, а левый пустой
		{
			xLevel = xLevel + 3;
			cur_depth--;

			cur = cur->pred; //поднялись выше, т.к. все узлы на текущем уровне пройдены
			xNode = cur->xNode;
			yNode = cur->yNode;
			if (cur != root)
			{
				xPredNode = cur->pred->xNode;
				yPredNode = cur->pred->yNode;
			}
		}
		else if (cur == root)  stop = true; //поднялись к корню
	}

	DeleteObject(hFont);
	UpdateStatePassedInNodes();

	return yHeightTree;
}