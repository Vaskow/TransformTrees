#include "ComTree.h"

void ComTree::ReadComTreeFromFile(string nameFile)
{
	string str2;
	ifstream file2(nameFile); //������ ������ ������ ���� �� ����� � �������� ���

	if (!file2.is_open())
	{
		return;
	}

	while (!file2.eof()) 
	{
		getline(file2, str2);
		if (str2 == "" || str2 == " ")
		{
			break;
		}

		string strNumNode, dateStrNode, childNodes;

		istringstream iss(str2); //����� ��� ��������� �������
		iss >> strNumNode;
		iss >> dateStrNode;
		iss >> childNodes;

		int colon = 0; //����� ���������
		
		for (char sym : strNumNode)
		{
			if (strNumNode[colon] != ':') { colon++; }
		}
		int numNode = stoi(strNumNode.substr(0, colon));


		vector<int> vecChild;
		string strChild = "";
		int startSubStr = 0;
		int endSubStr = 0;

		if (childNodes[0] == '-')
		{
			//��� ��������
			if (childNodes.length() != 1)
			{
				//������������ ����� ������ � ����� ��������
				return;
			}
		}
		else
		{
			for (int i = 0; i < childNodes.size(); ++i)
			{
				if (childNodes[i] == ',')
				{
					endSubStr = i;
					vecChild.push_back(stoi(childNodes.substr(startSubStr, endSubStr)));
					startSubStr = i + 1;
				}
				else if (i == childNodes.size() - 1)
				{
					vecChild.push_back(stoi(childNodes.substr(startSubStr, string::npos)));
					break;
				}
			}
		}
		
		InsertNodeInComTree(numNode, dateStrNode, vecChild);
	};
	file2.close();
}

void ComTree::delete_ComTree(ComNode* _root)
{
	if (_root)
	{
		delete_ComTree(_root->son);
		for (auto br : _root->brot)
		{
			if (br) delete_ComTree(br->son);
		}
		if (_root->brot[0] != _root->pred) //if _root == son
		{
			for (auto br : _root->brot) delete br;
		}

		delete _root;
	}
}

void ComTree::TransformInComTree(BinTree& bt)
{
	bool stop = false;
	int kolBroth = 0; //���������� ������� ��� ������ ���� 
	int NumVerh = 0;  //����� ������� �� son �� ���������� brot
	BinNode* RightBroth;

	root = new ComNode(bt.getRoot()->getData(), bt.getRoot()->getDataStr()); //����� ��� 
	cur = root; //������� �� ������ 

	bt.UpdateStatePassedInNodes();  //�������� ���� ��������� ������ ����� ���������������
	BinNode* curBin = bt.getRoot();
	curBin->setStatePassed(true);
	while (stop != true)
	{
		kolBroth = 0;
		if (curBin->getLeft() != nullptr && curBin->getLeft()->getStatePassed() == false) //����� ���� != nullptr � �� ���� �� �������� � ������ ������ ���� 
		{
			//��� ������ ������ ����
			cur->son = new ComNode(curBin->getLeft()->getData(), curBin->getLeft()->getDataStr());
			cur->son->pred = cur;   //���������� ����������� ��� ������
			cur = cur->son;			//����� ����� �� ������

			//��� ������ ��������� ����
			curBin = curBin->getLeft();		//����� ����� �� ������
			curBin->setStatePassed(true);  //������� ���� ��������� � ������ ������ ����
		}
		else if (curBin->getRight() != nullptr && curBin->getRight()->getStatePassed() == false) //������ ���� != nullptr 
		{
			//��� ������ ������ ����
			if (cur->number_verh == 0) {
				cur->brot[0] = new ComNode(curBin->getRight()->getData(), curBin->getRight()->getDataStr());
				cur->brot[0]->brot[0] = cur; //brot[number_verh-1] <----> son
				cur->brot[0]->number_verh = 1;
				cur->brot[0]->pred = cur;
				cur = cur->brot[0];
			}

			else if (cur->number_verh != 0) { //��� �� 0 ������� ������ �����������
				NumVerh = cur->number_verh;
				cur = cur->brot[0];
				cur->brot.push_back(new ComNode(curBin->getRight()->getData(), curBin->getRight()->getDataStr()));
				cur->brot[NumVerh]->brot[0] = cur;		//brot[number_verh-1] <----> son
				cur->brot[NumVerh]->number_verh = NumVerh + 1;
				cur->brot[NumVerh]->pred = cur->brot[NumVerh - 1];
				cur = cur->brot[NumVerh];
			}

			//��� ������ ��������� ����
			curBin = curBin->getRight();  //����� ����� �� �������
			curBin->setStatePassed(true); //������� ���� ��������� � ������ ������ ����
		}

		else if (curBin->getLeft() == nullptr && curBin->getRight() == nullptr || //����� � ������ ���� ������
			curBin->getLeft() != nullptr && curBin->getLeft()->getStatePassed() == true && curBin->getRight() != nullptr && curBin->getRight()->getStatePassed() == true || //����� � ������ ��������
			curBin->getLeft() != nullptr && curBin->getLeft()->getStatePassed() == true && curBin->getRight() == nullptr && curBin != bt.getRoot() || //����� �������, � ������� ������
			curBin->getRight() != nullptr && curBin->getRight()->getStatePassed() == true && curBin->getLeft() == nullptr && curBin != bt.getRoot()) //������ �������, � ����� ������
		{
			//��� ������ ��������� ����
			curBin = curBin->getPred();

			//��� ������ ������ ����
			cur = cur->pred;
		}
		else if (curBin == bt.getRoot())  stop = true; //��������� � �����
	}
	bt.UpdateStatePassedInNodes();
}

void ComTree::PrintCommonTree()
{
	bool stop = false;
	int indBr = 0; // ������ ����� 

	cur = root;
	cout << endl << " ������ ������ ����: " << endl;
	cout << " ������: " << cur->data << endl;
	cur->statePassed = true;

	while (stop != true)
	{
		if (cur->son != nullptr && cur->son->statePassed == false) //Son != nullptr � �� ��� �������
		{
			cout << " ����: " << cur->son->pred->data << " ���. ����: " << cur->son->pred->dataStr << ", " << endl;
			cur = cur->son;
			cout << " �������:";
			for (int i = 0; i < cur->brot.size() + 1; i++) {
				if (i == 0) { cout << " " << cur->data << " ���. ����: " << cur->dataStr << ","; }
				else if (cur->brot[0] != nullptr) { cout << "  " << cur->brot[i - 1]->data << " ���. ����: " << cur->brot[i - 1]->dataStr << ","; }
			}
			cout << endl;
			cur->statePassed = true;
			indBr = 0;
			cout << endl;
		}
		else if (cur->number_verh != 0 && indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr && cur->brot[0]->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			cur->statePassed = true;

		}
		else if (cur->number_verh == 0 && cur->brot[0] != nullptr && cur->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			cur->statePassed = true;

		}
		else if (cur->son == nullptr && cur->brot[0] == nullptr ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true ||

			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] == nullptr && cur != root ||

			cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() && cur->son == nullptr && cur != root)
		{
			//��� ������ ������ ����
			cur = cur->pred;
			indBr = cur->number_verh;
		}
		else if (cur == root)  stop = true; //��������� � �����
	}
	UpdateStatePassedInNodes();
}


void ComTree::UpdateStatePassedInNodes() 
{
	bool stop = false;

	int indBr = 0; // ������ ����� 

	cur = root; //������� �� ������ � ������ ������ ����
	cur->statePassed = false; //���� �������

	while (stop != true)
	{
		if (cur->son != nullptr && cur->son->statePassed == true) //Son != nullptr � �� ��� ��������
		{
			cur = cur->son;   //������� ������� son 
			cur->statePassed = false; //���� �������

			indBr = 0; //���������� ������� �������
		}
		else if (cur->number_verh != 0 && indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr && cur->brot[0]->brot[indBr]->statePassed == true) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			cur->statePassed = false; //�������� � �������� ������
		}
		else if (cur->number_verh == 0 && cur->brot[0] != nullptr && cur->brot[indBr]->statePassed == true) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			cur->statePassed = false; //�������� � �������� ������
		}
		else if (cur->son == nullptr && cur->brot[0] == nullptr ||
			cur->son != nullptr && cur->son->statePassed == false && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() ||
			cur->son != nullptr && cur->son->statePassed == false && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == false ||
			cur->son != nullptr && cur->son->statePassed == false && cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == false ||

			cur->son != nullptr && cur->son->statePassed == false && cur->brot[0] == nullptr && cur != root ||

			cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == false && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == false && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() && cur->son == nullptr && cur != root)
		{
			cur = cur->pred;
			indBr = cur->number_verh;
		}
		else if (cur == root)  stop = true; //��������� � �����
	}
}

void ComTree::TransformInBinTree(BinTree& bt)
{
	bool stop = false;
	int indBr = 0; // ������ ����� 

	//���������� ����� ������
	if (root->son != nullptr)
	{
		bt.InsertNodeInBinTree(root->data, root->dataStr, root->son->data, 0);
	}
	else
	{
		bt.InsertNodeInBinTree(root->data, root->dataStr, 0, 0); //������ �� 1 �������
		return;
	}

	cur = root; //������� �� ������
	cur->statePassed = true; //������ ��� ��������

	while (stop != true)
	{
		if (cur->son != nullptr && cur->son->statePassed == false) //son != nullptr � �� ��� �������
		{
			//��� ������ ������ ����
			cur = cur->son;   //������� ������� son 
			cur->statePassed = true; //�������� � �������� ������

			//��� ������ ��������� ����
			if (cur->son != nullptr && cur->brot[0] != nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, cur->son->data, cur->brot[0]->data);
			}
			else if (cur->son != nullptr && cur->brot[0] == nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, cur->son->data, 0);
			}
			else if (cur->son == nullptr && cur->brot[0] != nullptr)
			{ 
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, 0, cur->brot[0]->data);
			}
			else if (cur->son == nullptr && cur->brot[0] == nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, 0, 0);
			}

			indBr = 0; //���������� ������� �������
		}
		else if (cur->number_verh != 0 && indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr && cur->brot[0]->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			//��� ������ ������ ����
			cur = cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			cur->statePassed = true; //�������� � �������� ������

			//��� ������ ��������� ����
			if (cur->son != nullptr && indBr + 1 < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr + 1] != nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, cur->son->data, cur->brot[0]->brot[indBr + 1]->data);
			}
			else if (cur->son != nullptr && indBr + 1 >= cur->brot[0]->brot.size())
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, cur->son->data, 0);
			}
			else if (cur->son == nullptr && indBr + 1 < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr + 1] != nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, 0, cur->brot[0]->brot[indBr + 1]->data);
			}
			else if (cur->son == nullptr && indBr + 1 >= cur->brot[0]->brot.size())
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, 0, 0);
			}

			indBr += 1;
		}
		else if (cur->number_verh == 0 && cur->brot[0] != nullptr && cur->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			//��� ������ ������ ����
			cur = cur->brot[0]; //��������� ������� ��� ������� number_verh
			cur->statePassed = true; //�������� � �������� ������

			//��� ������ ��������� ����
			if (cur->son != nullptr && 1 < cur->brot[0]->brot.size() && cur->brot[0]->brot[1] != nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, cur->son->data, cur->brot[0]->brot[1]->data);
			}
			else if (cur->son != nullptr && 1 >= cur->brot[0]->brot.size())
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, cur->son->data, 0);
			}
			else if (cur->son == nullptr && 1 < cur->brot[0]->brot.size() && cur->brot[0]->brot[1] != nullptr)
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, 0, cur->brot[0]->brot[1]->data);
			}
			else if (cur->son == nullptr && 1 >= cur->brot[0]->brot.size())
			{
				bt.InsertNodeInBinTree(cur->data, cur->dataStr, 0, 0);
			}

			indBr += 1;
		}
		else if (cur->son == nullptr && cur->brot[0] == nullptr ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true ||

			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] == nullptr && cur != root ||

			cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() && cur->son == nullptr && cur != root)
		{
			//��� ������ ������ ����
			cur = cur->pred;
			indBr = cur->number_verh;
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	UpdateStatePassedInNodes();
}



//�������� ������ ������ ���� ����� ��������� ����
void ComTree::InsertNodeInComTree(int dataVerh, string dataStr, vector<int>& vecChild)
{
	if (root == nullptr) //�������� �����
	{
		root = new ComNode(dataVerh, dataStr); //������� ������� (����� ���)
		cur = root;
		amountNodes++;
		if (vecChild.size() != 0)
		{
			if (vecChild.size() == 1)
			{
				cur->son = new ComNode(vecChild[0], "*");
				cur->son->pred = cur;
			}
			else
			{
				cur->son = new ComNode(vecChild[0], "*");
				cur->son->pred = cur;

				cur = cur->son;
				for (int i = 0; i < vecChild.size() - 1; ++i)
				{
					if (i == 0)
					{
						cur->brot[0] = new ComNode(vecChild[i + 1], "*");
						cur->brot[0]->brot[0] = cur; //brot[number_verh-1] <----> son
						cur->brot[0]->number_verh = 1;
						cur->brot[0]->pred = cur;
					}
					else
					{
						cur->brot.push_back(new ComNode(vecChild[i + 1], "*"));
						cur->brot[i]->brot[0] = cur;		//brot[number_verh-1] <----> son
						cur->brot[i]->number_verh = i + 1;
						cur->brot[i]->pred = cur->brot[i - 1];
					}
				}
			}
		}
		return;
	}

	int indBr = 0; // ������ ����� 
	bool findVerh = false;
	bool stop = false;

	cur = root;
	cur->statePassed = true;

	while (stop != true) //���������� ������ �������
	{
		if (cur->son != nullptr && cur->son->statePassed == false) //Son != nullptr � �� ��� �������
		{
			cur = cur->son;
			cur->statePassed = true;
			if (cur->data == dataVerh) { stop = true; findVerh = true; }
			indBr = 0;
		}
		else if (cur->number_verh != 0 && indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr && cur->brot[0]->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			cur->statePassed = true;
			if (cur->data == dataVerh) { stop = true; findVerh = true; }
			indBr += 1;
		}
		else if (cur->number_verh == 0 && cur->brot[0] != nullptr && cur->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			cur->statePassed = true;
			if (cur->data == dataVerh) { stop = true; findVerh = true; }
			indBr += 1;
		}
		else if (cur->son == nullptr && cur->brot[0] == nullptr ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true ||

			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] == nullptr && cur != root ||

			cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() && cur->son == nullptr && cur != root)
		{
			//��� ������ ������ ����
			cur = cur->pred;
			indBr = cur->number_verh;
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	if (findVerh = true) //���������� �������
	{
		cur->dataStr = dataStr;
		cur->statePassed = true;
		amountNodes++;
		if (vecChild.size() != 0)
		{
			if (vecChild.size() == 1)
			{
				cur->son = new ComNode(vecChild[0], "*");
				cur->son->pred = cur;
			}
			else
			{
				cur->son = new ComNode(vecChild[0], "*");
				cur->son->pred = cur;

				cur = cur->son;
				for (int i = 0; i < vecChild.size() - 1; ++i)
				{
					if (i == 0)
					{
						cur->brot[0] = new ComNode(vecChild[i + 1], "*");
						cur->brot[0]->brot[0] = cur; //brot[number_verh-1] <----> son
						cur->brot[0]->number_verh = 1;
						cur->brot[0]->pred = cur;
					}
					else
					{
						cur->brot.push_back(new ComNode(vecChild[i + 1], "*"));
						cur->brot[i]->brot[0] = cur;		//brot[number_verh-1] <----> son
						cur->brot[i]->number_verh = i + 1;
						cur->brot[i]->pred = cur->brot[i - 1];
					}
				}
			}
		}
	}
	UpdateStatePassedInNodes();
}

int ComTree::MaxDepthComTree()
{
	bool stop = false;
	int indBr = 0; // ������ ����� 

	int maxDepthTree = 0; //������������ ������� � ������ ������ ����
	int curDepth = 0;  //������� �������

	cur = root;
	cur->statePassed = true;

	while (stop != true)
	{
		if (cur->son != nullptr && cur->son->statePassed == false) //Son != nullptr � �� ��� �������
		{
			cur = cur->son;
			cur->statePassed = true;
			indBr = 0;
			curDepth++;
		}
		else if (cur->number_verh != 0 && indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr && cur->brot[0]->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			cur->statePassed = true;
		}
		else if (cur->number_verh == 0 && cur->brot[0] != nullptr && cur->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			cur->statePassed = true;
		}
		else if (cur->son == nullptr && cur->brot[0] == nullptr ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true ||

			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] == nullptr && cur != root ||

			cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() && cur->son == nullptr && cur != root)
		{
			if (maxDepthTree < curDepth) maxDepthTree = curDepth;
			if (cur->pred != nullptr && cur == cur->pred->son) curDepth--;
			if (cur->pred != nullptr)
			{
				cur = cur->pred;
				indBr = cur->number_verh;
			}
		}
		else if (cur == root)  stop = true; //��������� � �����
	}

	UpdateStatePassedInNodes();

	return maxDepthTree;
}


int ComTree::PaintComTree(HDC hdc, int heightRoot)
{
	bool stop = false;
	int indBr = 0; // ������ ����� 

	int xNode = 700;
	int yNode = heightRoot;
	int xPredNode = xNode;
	int yPredNode = yNode;
	int xSizeDepth = 14;
	int yHeightTree = heightRoot; //������ ������������� ������

	int maxDepth = MaxDepthComTree();
	yHeightTree = yHeightTree + (maxDepth + 1) * 35; //������ ������������� ������, � ������� ����� ��������
	
	int xShiftLeft = 20; //����� ����� �������� �� ��� X
	vector<int> xLastNodeinDepth(maxDepth); //������ ��������� ������������ ������� �� i ������� (������ � �������� �����)
	int cur_depth = -1; //������� ������� ������ (� �������� �� ����� ������)
	bool isBrot = false; //�������� �� ���� ������ son
	
	Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);

	HFONT hFont = CreateFont(14, 5, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, L"Times New Roman");
	SelectObject(hdc, hFont);

	TCHAR  buffer[10];
	swprintf_s(buffer, 10, L"%d", root->data);
	TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));

	cur = root;
	cur->statePassed = true;
	cur->xNode = xNode;
	cur->yNode = yNode;

	while (stop != true)
	{
		if (cur->son != nullptr && cur->son->statePassed == false) //Son != nullptr � �� ��� �������
		{
			if (isBrot && xLastNodeinDepth[cur_depth + 1] != 0) xNode = xLastNodeinDepth[cur_depth + 1] + xSizeDepth;
			else xNode -= xSizeDepth;
			
			cur_depth++;

			yPredNode = yNode;
			yNode += 35;

			int xNodeToShift = xNode; //���������� �� ������

			cur = cur->son;
			cur->xNode = xNode;
			cur->yNode = yNode;

			for (int i = 0; i < cur->brot.size() + 1; i++) {
				if (i == 0) 
				{ 
					Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);
					swprintf_s(buffer, 10, L"%d", cur->data);
					TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));
					MoveToEx(hdc, xPredNode + 7, yPredNode + 14, nullptr);
					LineTo(hdc, xNode + 12, yNode + 2);

					xNode += xShiftLeft; //����� ��� ���������� �����
				}
				else if (cur->brot[0] != nullptr) 
				{ 
					Ellipse(hdc, xNode, yNode, xNode + 17, yNode + 17);
					swprintf_s(buffer, 10, L"%d", cur->brot[i - 1]->data);
					TextOut(hdc, xNode + 3, yNode + 2, buffer, wcslen(buffer));
					MoveToEx(hdc, xPredNode + 7, yPredNode + 14, nullptr);
					LineTo(hdc, xNode + 12, yNode + 2);

					cur->brot[i-1]->xNode = xNode;
					cur->brot[i-1]->yNode = yNode;

					xNode += xShiftLeft; //����� ��� ���������� �����
				}
			}
			xLastNodeinDepth[cur_depth] = xNode;
			xNode = xNodeToShift;

			cur->statePassed = true;
			indBr = 0;
			xPredNode = xNode;
		}
		else if (cur->number_verh != 0 && indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr && cur->brot[0]->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			xNode += xShiftLeft;
			isBrot = true;
			indBr += 1;
			cur->statePassed = true;

			if (cur->son != nullptr || (indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr))
			{
				xPredNode = xNode;
				yPredNode = yNode;
			}
		}
		else if (cur->number_verh == 0 && cur->brot[0] != nullptr && cur->brot[indBr]->statePassed == false) //brot[] != nullptr � �� ��� �������
		{
			cur = cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			xNode += xShiftLeft;
			isBrot = true;
			indBr += 1;
			cur->statePassed = true;
			
			if (cur->son != nullptr || (indBr < cur->brot[0]->brot.size() && cur->brot[0]->brot[indBr] != nullptr))
			{
				xPredNode = xNode;
				yPredNode = yNode;
			}
		}
		else if (cur->son == nullptr && cur->brot[0] == nullptr ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true ||
			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true ||

			cur->son != nullptr && cur->son->statePassed == true && cur->brot[0] == nullptr && cur != root ||

			cur->brot[0] != nullptr && cur->number_verh == 0 && cur->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh < cur->brot.size() && cur->brot[0]->brot[cur->number_verh]->statePassed == true && cur->son == nullptr && cur != root ||
			cur->brot[0] != nullptr && cur->number_verh != 0 && cur->number_verh >= cur->brot.size() && cur->son == nullptr && cur != root)
		{
			if (cur->pred->son == cur)
			{
				isBrot = false;
				cur_depth--;
			}
			else //������� �� ������� (son)
			{
				if (cur->pred->number_verh == 0) 
				{ 
					isBrot = false;
				}
			}
			cur = cur->pred;
			indBr = cur->number_verh;

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
