#include "ComBinTrees.h"
#include <iostream>

using namespace std;

BinTree* BinTree::CreateBinTree()
{
	BinTree * bt = NULL;
	bt = new BinTree;
	if(bt == NULL) exit(1);
	bt->root = NULL;
	//bt->par = NULL; "PAR"
	bt->cur = NULL;

	return bt;
}

BinTree* BinTree::insert(BinTree * bt, int _data)
{
	bt->cur = bt ->root;
	Node *node = new Node;
	Node *cur_node = new Node; 
	node->data = _data; node->left = NULL; node->right = NULL; node->existInComTree = false;
	if(bt->root == NULL){ bt->root = node; /*bt->root->number_verh = 1;*/ return bt; }

	while(bt->cur)
	{
		cur_node = bt->cur;
		if(node->data > bt->cur->data) { bt->cur = bt->cur->right; }
		else
			if(node->data < bt->cur->data) { bt->cur = bt->cur->left; }
			else
			{ return bt; }
	
	}

	if(node->data > cur_node->data) cur_node->right = node;
	else cur_node->left = node;
	bt->cur = node;
	return bt;
}

void BinTree::print_tree(Node *root, int Num)
{
	if (root == NULL) return;
	print_tree(root->right,Num+1);
	for(int i = 0; i < Num + 1; i++)
	cout << "    ";
		cout << root->data << endl;
		print_tree(root->left, Num+1);


}

void BinTree::UpdateBoolBinNodes(BinTree *bt)
{
	bool stop = false;

	bt->cur = bt->root;
	bt->cur->existInComTree = false;

	while (stop != true)
	{

		if(bt->cur->left != NULL && bt->cur->left->existInComTree == true) //����� ���� != NULL � �� ���� �� �������� � ������ ������ ���� 
		{
			
			bt->cur = bt->cur->left; //����� ����� �� ������
			bt->cur->existInComTree = false; //������� ���� ��������� � ������ ������ ����

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == true) //������ ���� != NULL 
		{
			
			bt->cur = bt->cur->right;  //����� ����� �� �������
			bt->cur->existInComTree = false; //������� ���� ��������� � ������ ������ ����

		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //����� � ������ ���� ������
			bt->cur->left != NULL && bt->cur->left->existInComTree == false && bt->cur->right != NULL && bt->cur->right->existInComTree == false || //����� � ������ ��������
			bt->cur->left != NULL && bt->cur->left->existInComTree == false && bt->cur->right == NULL && bt->cur != bt->root || //����� �������, � ������� ������
			bt->cur->right != NULL && bt->cur->right->existInComTree == false && bt->cur->left == NULL && bt->cur != bt->root) //������ �������, � ����� ������
		{ 
			//��� ������ ��������� ����
			bt->cur = bt->cur->pred;

		} //�� ��������� � �����, �.�. ��� ���� ��������
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == false)  stop = true; 
	}
}

void BinTree::print_BtreeNode(BinTree *bt)
{
	bool stop = false;

	cout << endl << " ������ ��������� ���� " << endl;
	cout << " ������ ";
	bt->cur = bt->root;
	cout << bt->cur->data << endl;
	bt->cur->existInComTree = true;
	while (stop != true)
	{
		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //����� ���� != NULL � �� ���� �� �������� � ������ ������ ���� 
		{
			cout << " ������:  " << bt->cur->data;
			bt->cur = bt->cur->left;
			cout << " ������� �������:  " << bt->cur->data;
			if(bt->cur->left != NULL){cout << " �����: " << bt->cur->left->data;}
			else {cout << " �����: ��� ";}

			if(bt->cur->right != NULL){cout << " ������: " << bt->cur->right->data;}
			else {cout << " ������: ��� ";}

			cout << endl;
			bt->cur->existInComTree = true; //������� ���� ��������

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //������ ���� != NULL 
		{
			
			cout << " ������:  " << bt->cur->data;
			bt->cur = bt->cur->right;  //����� ����� �� �������
			cout << " ������� �������:  " << bt->cur->data;

			if(bt->cur->left != NULL) {cout << " �����: " << bt->cur->left->data;}
			else {cout << " �����: ��� ";}

			if(bt->cur->right != NULL){cout << " ������: " << bt->cur->right->data;}
			else {cout << " ������: ��� ";}

			cout << endl;
			bt->cur->existInComTree = true; //������� ���� ��������

		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //����� � ������ ���� ������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //����� � ������ ��������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //����� �������, � ������� ������
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //������ �������, � ����� ������
		{ 

			bt->cur = bt->cur->pred;

		} //�� ��������� � �����, �.�. ��� ���� ��������
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}
	bt->UpdateBoolBinNodes(bt);
}

//�������� ������ ��������� ���� ����� ��������� ����
void BinTree::CreateBinTr(int dataVerh, string dataStr, int leftVerh, int rightVerh, BinTree* bt)
{

	bool stop = false;
	Node * node;

	if(dataVerh == 1)
	{
        node = bt->root->getBinNode(); //������� �������
	    node->data = dataVerh;
	    node->dataStr = dataStr;		//��������� ��������� ����
	    bt->root = node; //������, �����, ������ (���)
	    bt->cur = bt->root; //������� �� ������ 
	    bt->cur->existInComTree = true;
		if(leftVerh != 0 || rightVerh != 0)
		{
			if(leftVerh != 0 && rightVerh != 0) 
			{
				bt->cur->left = bt->root->getBinNode();
				bt->cur->left->data = leftVerh;
				bt->cur->left->pred = bt->cur;
				bt->cur->left->existInComTree = false;

				bt->cur->right = bt->root->getBinNode();
				bt->cur->right->data = rightVerh;
				bt->cur->right->pred = bt->cur;
				bt->cur->right->existInComTree = false;
			}
			else if(leftVerh == 0 && rightVerh != 0)
			{
				bt->cur->right = bt->root->getBinNode();
				bt->cur->right->data = rightVerh;
				bt->cur->right->pred = bt->cur;
				bt->cur->right->existInComTree = false;
			}
			else if(leftVerh != 0 && rightVerh == 0)
			{
				bt->cur->left = bt->root->getBinNode();
				bt->cur->left->data = leftVerh;
				bt->cur->left->pred = bt->cur;
				bt->cur->left->existInComTree = false;
			}

		}

		stop = true;
	}

	bool findVerh = false;
	bt->cur = bt->root;
	while (stop != true)  //������� ������ �������
	{

		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //����� ���� != NULL � �� ���� �� �������� � ������ ������ ���� 
		{
			
			bt->cur = bt->cur->left; //����� ����� �� ������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����
			if (bt->cur->data == dataVerh) {stop = true; findVerh = true;}

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //������ ���� != NULL 
		{
			
			bt->cur = bt->cur->right;  //����� ����� �� �������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����
			if (bt->cur->data == dataVerh) {stop = true; findVerh = true;}
		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //����� � ������ ���� ������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //����� � ������ ��������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //����� �������, � ������� ������
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //������ �������, � ����� ������
		{ 
			//��� ������ ��������� ����
			bt->cur = bt->cur->pred;

		} //�� ��������� � �����, �.�. ��� ���� ��������
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}

	if (findVerh = true) 
	{
		bt->cur->dataStr = dataStr; //������� �� ������ 
	    bt->cur->existInComTree = false;
		if(leftVerh != 0 || rightVerh != 0)
		{
			if(leftVerh != 0 && rightVerh != 0) 
			{
				bt->cur->left = bt->cur->getBinNode();
				bt->cur->left->data = leftVerh;
				bt->cur->left->pred = bt->cur;
				bt->cur->left->existInComTree = false;

				bt->cur->right = bt->cur->getBinNode();
				bt->cur->right->data = rightVerh;
				bt->cur->right->pred = bt->cur;
				bt->cur->right->existInComTree = false;
			}
			else if(leftVerh == 0 && rightVerh != 0)
			{
				bt->cur->right = bt->cur->getBinNode();
				bt->cur->right->data = rightVerh;
				bt->cur->right->pred = bt->cur;
				bt->cur->right->existInComTree = false;
			}
			else if(leftVerh != 0 && rightVerh == 0)
			{
				bt->cur->left = bt->cur->getBinNode();
				bt->cur->left->data = leftVerh;
				bt->cur->left->pred = bt->cur;
				bt->cur->left->existInComTree = false;
			}

		}
	}

}

int *BinTree::FindSolution(BinTree* bt, string _dataStr)
{
	int numVerh = 0; //���������� ���������� ������ ����
	int *sol; //���� �� �������, ������� ������� ����� ��������� ���������� ������
	bool stop = false;
	bool findVerh = false;
	bt->UpdateBoolBinNodes(bt); //���� � ������ ����� ������ � ������, �� ������� ��� �������
	while (stop != true)  //������� ������ �������
	{

		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //����� ���� != NULL � �� ���� �� �������� � ������ ������ ���� 
		{
			
			bt->cur = bt->cur->left; //����� ����� �� ������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����
			numVerh++;	//���� �� ����� ������� => ��� ����� ����� � ���� � �������
			if (bt->cur->dataStr == _dataStr) {stop = true; findVerh = true;}

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //������ ���� != NULL 
		{
			
			bt->cur = bt->cur->right;  //����� ����� �� �������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����
			if (bt->cur->dataStr == _dataStr) {stop = true; findVerh = true;}
		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //����� � ������ ���� ������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //����� � ������ ��������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //����� �������, � ������� ������
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //������ �������, � ����� ������
		{ 
			//��� ������ ��������� ����
			if(bt->cur->pred->left == bt->cur){ numVerh--; } //���� ������� ����� �� ������ => �������� ������� 
			bt->cur = bt->cur->pred;

		} //�� ��������� � �����, �.�. ��� ���� ��������
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}

	//bt->UpdateBoolBinNodes(bt); //��������� ������� ����� ������

	int ind = 2; //�.�. ������� ������� ����� �����
	if(findVerh) //���������� ���������� ����
	{
		numVerh += 2; //��������� � ���� ���� ������� � ������� ��� ���������� ������ (��������� ������� ����� n+1, ��� n - ���� �� ������) 
		sol = new int[numVerh];
		sol[0] = numVerh; //�������� ���������� ������ � 1 ������� �������
		sol[1] = bt->cur->data;
		while(bt->cur != bt->root)
		{
		 if(bt->cur->pred->right == bt->cur) {bt->cur = bt->cur->pred;}
		 else if(bt->cur->pred->left == bt->cur) {bt->cur = bt->cur->pred; sol[ind] = bt->cur->data; ind++;}
		}
	}
	return sol;
}



Node* Node::getBinNode()
{
	Node *node = new Node();
	node->left = NULL;
	node->pred = NULL; 
	node->right = NULL;
	node->existInComTree = false;

	return node;
}


CommonTree* CommonTree::CreateComTree()
{
	CommonTree* ct = NULL;
	ct = new CommonTree;
	if(ct == NULL) exit(1);

	root = NULL;
    cur = NULL;
	
	return ct;
}
ComNode* ComNode::getComNode()
{
	ComNode *node = new ComNode();
	node->brot = NULL;
	node->pred = NULL; 
	node->son = NULL;
	node->existInBinTree = false;

	return node;
}

void CommonTree::TransformCommonTree(BinTree * bt, CommonTree* ct)
{
	bool stop = false;
	int kolBroth = 0; //���������� ������� ��� ������ ���� 
	int NumVerh;  //����� ������� 
	Node *RightBroth;
	ComNode * Cnode;
	Cnode = ct->root->getComNode(); //������� �������
	Cnode->data = bt->root->data;
	Cnode->dataStr = bt->root->dataStr;									//��������� ��������� ����
	ct->root = Cnode; //��� 
	ct->cur = ct->root; //������� �� ������ 
	ct->cur->existInBinTree = false;

	bt->UpdateBoolBinNodes(bt);  //�������� ���� ��������� ������ ����� ���������������
	bt->cur = bt->root;
	bt->cur->existInComTree = true;
	while (stop != true)
	{
		kolBroth = 0;
		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //����� ���� != NULL � �� ���� �� �������� � ������ ������ ���� 
		{
			//��� ������ ������ ����
			Cnode = ct->root->getComNode(); //������� �������
			Cnode->data = bt->cur->left->data;
			Cnode->dataStr = bt->cur->left->dataStr;				   //��������� ��������� ����
			ct->cur->son = Cnode; //���������� ���������� ��� ������
			ct->cur->son->pred = ct->cur; //���������� ����������� ��� ������
			ct->cur = ct->cur->son; //����� ����� �� ������
			ct->cur->existInBinTree = false;

			//��� ������ ��������� ����
			bt->cur->left->pred = bt->cur; //�������� ����������� ��� ������
			bt->cur = bt->cur->left; //����� ����� �� ������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����

			//��� ������� (����� ���)
			RightBroth = bt->cur->right; //��� ��������� ������� �� ������
			while(RightBroth !=NULL){RightBroth = RightBroth->right; kolBroth += 1;} //��������� ���������� ������ ����� �� ��������
			if( kolBroth != 0) {
			ct->cur->brot = new ComNode*[kolBroth+1]; //��������� ������ ���������� �� ������� (������)
			for(int i = 0; i < kolBroth; i++) {ct->cur->brot[i] = NULL;}
			ct->cur->number_verh = 0; //��� ������� ���������� ����� ������� 
	 		ct->cur->count_verh = kolBroth + 1; //���������� ������� + ���

            Cnode = ct->root->getComNode(); //������� �������
			ct->cur->brot[0] = Cnode;
			ct->cur->brot[0]->pred = ct->cur; //�������� ������� ���������� ��� �����, ���� ��� � ���� ���� 
			}
	 		else {ct->cur->count_verh = 1; }

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //������ ���� != NULL 
		{
			//��� ������ ������ ����

			if(ct->cur->number_verh == 0){

				Cnode = ct->root->getComNode();
				ct->cur->brot[0] = Cnode; //�.�. number_verh �� 1 ������ ������� ������� brot
				ct->cur->brot[0]->brot = new ComNode*[1]; //son ---> brot[NumVerh-1] 
				ct->cur->brot[0]->brot[0] = ct->cur; //brot[NumVerh-1] <----> son
				ct->cur->brot[0]->number_verh = 1;
	 			ct->cur->brot[0]->count_verh = ct->cur->count_verh;
				ct->cur->brot[0]->pred = ct->cur;
				ct->cur = ct->cur->brot[0];
				ct->cur->existInBinTree = false;
			}

			else if(ct->cur->number_verh != 0){ //��� �� 0 ������� ������ �����������

				NumVerh = ct->cur->number_verh;
				ct->cur = ct->cur->brot[0];
				Cnode = ct->root->getComNode();
				ct->cur->brot[NumVerh] = Cnode;
				ct->cur->brot[NumVerh]->brot = new ComNode*[1];
				ct->cur->brot[NumVerh]->brot[0] = ct->cur;
				ct->cur->brot[NumVerh]->number_verh = NumVerh + 1;
	 			ct->cur->brot[NumVerh]->count_verh = ct->cur->count_verh;
				ct->cur->brot[NumVerh]->pred = ct->cur->brot[NumVerh-1];
				ct->cur = ct->cur->brot[NumVerh];
				ct->cur->existInBinTree = false;

			}
			ct->cur->data = bt->cur->right->data; //��������� ������� ��� ������� number_verh
			ct->cur->dataStr = bt->cur->right->dataStr;				//��������� ��������� ����

			//��� ������ ��������� ����
			bt->cur->right->pred = bt->cur;//�������� ����������� ��� �������
			bt->cur = bt->cur->right;  //����� ����� �� �������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����

		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //����� � ������ ���� ������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //����� � ������ ��������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //����� �������, � ������� ������
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //������ �������, � ����� ������
		{ 
			//��� ������ ��������� ����
			bt->cur = bt->cur->pred;

			//��� ������ ������ ����
			ct->cur = ct->cur->pred;
			ct->cur->existInBinTree = false;

		} //�� ��������� � �����, �.�. ��� ���� ���������
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}
	bt->UpdateBoolBinNodes(bt);
}

void CommonTree::print_CommonTree(CommonTree *ct)
{
	bool stop = false;
	int indBr = 0; // ������ ����� 

	ct->cur = ct->root;
	cout << endl << " ������ ������ ����: " << endl;
	cout << " ������: " << ct->cur->data << endl;
	ct->cur->existInBinTree = true;

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL � �� ��� ��������
		{
			cout << " ������ " << ct->cur->son->pred->data << " ���. ����: " << ct->cur->son->pred->dataStr << ", ";
			ct->cur = ct->cur->son;
			cout << " �������:";
			for(int i = 0; i < ct->cur->count_verh; i++) {
				if (i == 0){cout << " " << ct->cur->data << " ���. ����: " << ct->cur->dataStr <<",";}
				else {cout << "  " << ct->cur->brot[i-1]->data << " ���. ����: " << ct->cur->brot[i-1]->dataStr <<",";}
			}

			ct->cur->existInBinTree = true;
			indBr = 0;
			cout << endl;
		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; 

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; 

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son � brot ���� ������  ����� ��������� �� != NULL ����������� �����
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //����� � ������ ��������
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //����� �������, � ������� ������

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //������ �������, � ����� ������
		{
			//��� ������ ������ ����
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //�� ��������� � �����, �.�. ��� ���� ��������
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  stop = true; 
	}
	ct->UpdateBoolComNodes(ct);
}
void CommonTree::TransformBinarTree(BinTree * bt, CommonTree* ct)
{
	bool stop = false;
	int iX = 50, iY = 50;
	int t = 3, p = 3, Up = 0;
	int indBr = 0; // ������ ����� 
	int NumVerh;
	Node *Bnode;
	Bnode = bt->root->getBinNode(); //������� �������
	Bnode->data = ct->root->data;
	Bnode->dataStr = ct->root->dataStr;	//��������� ��������� ����
	Bnode->existInComTree = false;

	bt->root = Bnode; //�������� ���� � ������ ��������� ������
	bt->cur = bt->root;
	bt->cur->existInComTree = false;

	ct->cur = ct->root; //������� �� ������ � ������ ������ ����
	ct->cur->existInBinTree = true; //�������� � �������� ������

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL � �� ��� ��������
		{
			//��� ������ ������ ����
			ct->cur = ct->cur->son;   //������� ������� son 
			ct->cur->existInBinTree = true; //�������� � �������� ������

			//��� ������ ��������� ����
			Bnode = bt->root->getBinNode(); //������� �������
			Bnode->data = ct->cur->data;
			Bnode->dataStr = ct->cur->dataStr;			//��������� ��������� ����
			
			bt->cur->left = Bnode;   //�������� ��������� ������� � ����� ���� 
			bt->cur->left->pred = bt->cur;
			bt->cur = bt->cur->left;
			indBr = 0; //���������� ������� �������
			bt->cur->existInComTree = false;

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			//��� ������ ������ ����
			ct->cur = ct->cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //�������� � �������� ������
			//��� ������ ��������� ����

			Bnode = bt->root->getBinNode();
			Bnode->data = ct->cur->data;
			Bnode->dataStr = ct->cur->dataStr;		   //��������� ��������� ����
			Bnode->pred = bt->cur;

			bt->cur->right = Bnode;
			bt->cur = bt->cur->right;
			bt->cur->existInComTree = false;
		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			//��� ������ ������ ����
			ct->cur = ct->cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //�������� � �������� ������
			//��� ������ ��������� ����

			Bnode = bt->root->getBinNode();
			Bnode->data = ct->cur->data;
			Bnode->dataStr = ct->cur->dataStr; //��������� ��������� ����
			Bnode->pred = bt->cur;

			bt->cur->right = Bnode;
			bt->cur = bt->cur->right;
			bt->cur->existInComTree = false;
		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son � brot ���� ������  ����� ��������� �� != NULL ����������� �����
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //����� � ������ ��������
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //����� �������, � ������� ������

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //������ �������, � ����� ������
		{ 
			//��� ������ ��������� ����
			bt->cur = bt->cur->pred;
			bt->cur->existInComTree = false;

			//��� ������ ������ ����
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //�� ��������� � �����, �.�. ��� ���� ���������
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  stop = true; 
	}
	ct->UpdateBoolComNodes(ct);
	//bt->UpdateBoolBinNodes(bt);

}
void CommonTree::UpdateBoolComNodes(CommonTree *ct)
{
	bool stop = false;

	int indBr = 0; // ������ ����� 

	ct->cur = ct->root; //������� �� ������ � ������ ������ ����
	ct->cur->existInBinTree = false; //�������� � �������� ������

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == true) //Son != NULL � �� ��� ��������
		{

			ct->cur = ct->cur->son;   //������� ������� son 
			ct->cur->existInBinTree = false; //����� ���������� �� false

			indBr = 0; //���������� ������� �������

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == true) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = false; //�������� � �������� ������

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == true) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = false; //�������� � �������� ������

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son � brot ���� ������  ����� ��������� �� != NULL ����������� �����
			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //����� � ������ ��������
			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == false||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == false ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot == NULL && ct->cur != ct->root || //����� �������, � ������� ������

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == false && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == false && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //������ �������, � ����� ������
		{ 
			
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //�� ��������� � �����, �.�. ��� ���� �������� 
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == false)  stop = true; 
	}
}


//�������� ������ ������ ���� ����� ��������� ����
void CommonTree::CreateComTr(int dataVerh, string dataStr, int *masVerh, int numVerh, CommonTree* ct)
{
	bool stop = false;
	int NumVerh;  //����� ������� 
	int indBrot = 0;
	ComNode * Cnode;

	if(dataVerh == 1)
	{
        Cnode = ct->root->getComNode(); //������� �������
	    Cnode->data = dataVerh;
	    Cnode->dataStr = dataStr;		//��������� ��������� ����
	    ct->root = Cnode; //��� 
	    ct->cur = ct->root; //������� �� ������ 
	    ct->cur->existInBinTree = false;
		if(numVerh != 0)
		{
			if(numVerh == 1) 
			{

			  if(masVerh[0] != 0) // ������������ ������� != 0
			  {
				ct->cur->son = ct->root->getComNode();
				ct->cur->son->data = masVerh[0];
				ct->cur->son->pred = ct->cur;
				ct->cur->son->count_verh = 1;
				ct->cur->son->number_verh = 0;
				ct->cur->existInBinTree = false;
			  }
			}
			else
			{
				ct->cur->son = ct->root->getComNode();
				ct->cur->son->data = masVerh[0];
				ct->cur->son->pred = ct->cur;
				ct->cur->son->count_verh = numVerh;
				ct->cur->son->existInBinTree = false;

				ct->cur = ct->cur->son;
				ct->cur->number_verh = 0;
				ct->cur->brot = new ComNode*[numVerh-1]; //��������� ������ ���������� �� ��������
				for(int i = 0; i < numVerh-1; i++) 
				{
					ct->cur->brot[i] = ct->root->getComNode();
					ct->cur->brot[i]->data = masVerh[i+1];
					ct->cur->brot[i]->number_verh = i+1;     //������ ����� �������
					ct->cur->brot[i]->count_verh = ct->cur->count_verh; //������ ���������� ������ �������
					ct->cur->brot[i]->brot = new ComNode*[1];
					ct->cur->brot[i]->brot[0] = ct->cur;  //������ ���� ����� ��������� �� ����������
					ct->cur->brot[i]->existInBinTree = false;
					if(i == 0){ct->cur->brot[0]->pred = ct->cur;}  //������ ����������� 
					else {ct->cur->brot[i]->pred = ct->cur->brot[i-1];}
				}

			}
		}
		stop = true;
	}
	
	int indBr = 0; // ������ ����� 
	bool noVerh = false; //�� ����� �������
	bool findVerh = false;

	ct->cur = ct->root;
	ct->cur->existInBinTree = true; 

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL � �� ��� ��������
		{

			ct->cur = ct->cur->son;   //������� ������� son 
			ct->cur->existInBinTree = true; //����� ���������� �� false
			if (ct->cur->data == dataVerh) {stop = true; findVerh = true;}

			indBr = 0; //���������� ������� �������

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //�������� � �������� ������
			if (ct->cur->data == dataVerh) {stop = true; findVerh = true;}

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //�������� � �������� ������
			if (ct->cur->data == dataVerh) {stop = true; findVerh = true;}

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son � brot ���� ������  ����� ��������� �� != NULL ����������� �����
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //����� � ������ ��������
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //����� �������, � ������� ������

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //������ �������, � ����� ������
		{ 
			
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //�� ��������� � �����, �.�. ��� ���� �������� 
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  {stop = true; noVerh = true;}
	}


	//}

	if (noVerh) {cout << " �� ����� �������"; } 

	if(findVerh = true)  //���������� �� ���������, ������ ������ �������
	{
		cout << " ������� ������� " <<  ct->cur->data << " "; 
	    ct->cur->dataStr = dataStr;
	    ct->cur->existInBinTree = true;
		if(numVerh != 0)
		{
			if(numVerh == 1) 
			{
			  if (masVerh[0] != 0 ) //������������ ������� != 0
			  {
				ct->cur->son = ct->cur->getComNode();
				ct->cur->son->data = masVerh[0];
				ct->cur->son->pred = ct->cur;
				ct->cur->son->count_verh = 1;
				ct->cur->son->number_verh = 0;
				ct->cur->existInBinTree = true;
			  }
			}
			else
			{
				ct->cur->son = ct->cur->getComNode();
				ct->cur->son->data = masVerh[0];
				ct->cur->son->pred = ct->cur;
				ct->cur->son->count_verh = numVerh;
				ct->cur->son->existInBinTree = true;

				ct->cur = ct->cur->son;
				ct->cur->number_verh = 0;
				ct->cur->brot = new ComNode*[numVerh-1]; //��������� ������ ���������� �� ��������
				for(int i = 0; i < numVerh-1; i++) 
				{
					ct->cur->brot[i] = ct->root->getComNode();
					ct->cur->brot[i]->data = masVerh[i+1];
					ct->cur->brot[i]->number_verh = i+1;     //������ ����� �������
					ct->cur->brot[i]->count_verh = ct->cur->count_verh; //������ ���������� ������ �������
					ct->cur->brot[i]->brot = new ComNode*[1];
					ct->cur->brot[i]->brot[0] = ct->cur;  //������ ���� ����� ��������� �� ����������
					ct->cur->brot[i]->existInBinTree = true;
					if(i == 0){ct->cur->brot[0]->pred = ct->cur;}  //������ ����������� 
					else {ct->cur->brot[i]->pred = ct->cur->brot[i-1];}
				}

			}
		}
	}
	

}

void SetColor(int text, int bg)   //��� ��������� ������� ��� ������ ������
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void BinTree::levelVerhBinTree(BinTree* bt, int *levelVerhBin, int NumberVerh)
{
	bool stop = false;
	int NumVerh = 1;  //����� ������� � ������� levelVerhBin
	int LevelTree = 1; //������� ������� ��� ������

	bt->cur = bt->root;
	bt->cur->existInComTree = true;
	levelVerhBin[0] = 1;

	while (stop != true)
	{
		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //����� ���� != NULL � �� ���� �� �������� � ������ ������ ���� 
		{

			//��� ������ ��������� ����
			bt->cur = bt->cur->left; //����� ����� �� ������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����

			LevelTree++; //�������� ������� 
			levelVerhBin[NumVerh] = LevelTree;
			NumVerh++; //�������� ����� ������� 

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //������ ���� != NULL 
		{
			//��� ������ ��������� ����
			bt->cur = bt->cur->right;  //����� ����� �� �������
			bt->cur->existInComTree = true; //������� ���� ��������� � ������ ������ ����

			LevelTree++; //�������� ������� 
			levelVerhBin[NumVerh] = LevelTree;
			NumVerh++; //�������� ����� ������� 
		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //����� � ������ ���� ������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //����� � ������ ��������
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //����� �������, � ������� ������
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //������ �������, � ����� ������
		{ 
			//��� ������ ��������� ����
			bt->cur = bt->cur->pred;
			LevelTree--;//�������� ������� 

		} //�� ��������� � �����, �.�. ��� ���� ���������
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}
}

void CommonTree::levelVerhComTree(CommonTree* ct, int *levelVerh, int NumberVerh) //���������� ������ ������ ������ ������ ����
{
	bool stop = false;
	int NumVerh = 1;  //����� ������� � ������� levelVerh
	int indBr = 0;
	int LevelTree = 1; //������� ������� ��� ������

	ct->cur = ct->root;
	ct->cur->existInBinTree = true; 
	levelVerh[0] = 1;

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL � �� ��� ��������
		{

			ct->cur = ct->cur->son;   //������� ������� son 
			ct->cur->existInBinTree = true; //����� ���������� �� false
			LevelTree++; //�������� ������� 
			levelVerh[NumVerh] = LevelTree;
			NumVerh++; //�������� ����� ������� 
			indBr = 0; //���������� ������� �������

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //��������� ������� ��� ������� number_verh
			levelVerh[NumVerh] = LevelTree;
			NumVerh++; //�������� ����� ������� 
			indBr += 1;
			ct->cur->existInBinTree = true; //�������� � �������� ������

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL � �� ��� ��������
		{
			ct->cur = ct->cur->brot[indBr]; //��������� ������� ��� ������� number_verh
			levelVerh[NumVerh] = LevelTree;
			NumVerh++; //�������� ����� ������� 
			indBr += 1;
			ct->cur->existInBinTree = true; //�������� � �������� ������

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son � brot ���� ������  ����� ��������� �� != NULL ����������� �����
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //����� � ������ ��������
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //����� �������, � ������� ������

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //������ �������, � ����� ������
		{ 

			if(ct->cur->pred->son == ct->cur) {LevelTree--;}
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;


		} //�� ��������� � �����, �.�. ��� ���� �������� 
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  {stop = true; }
	}
}
