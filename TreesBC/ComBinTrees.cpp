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

		if(bt->cur->left != NULL && bt->cur->left->existInComTree == true) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		{
			
			bt->cur = bt->cur->left; //смена текущ на левого
			bt->cur->existInComTree = false; //вершина была добавлена в дерево общего вида

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == true) //Правый узел != NULL 
		{
			
			bt->cur = bt->cur->right;  //смена текущ на правого
			bt->cur->existInComTree = false; //вершина была добавлена в дерево общего вида

		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //левый и правый узлы пустые
			bt->cur->left != NULL && bt->cur->left->existInComTree == false && bt->cur->right != NULL && bt->cur->right->existInComTree == false || //левый и правый пройдены
			bt->cur->left != NULL && bt->cur->left->existInComTree == false && bt->cur->right == NULL && bt->cur != bt->root || //левый пройден, а правого пустой
			bt->cur->right != NULL && bt->cur->right->existInComTree == false && bt->cur->left == NULL && bt->cur != bt->root) //правый пройден, а левый пустой
		{ 
			//для дерева бинарного вида
			bt->cur = bt->cur->pred;

		} //мы поднялись к корню, т.к. все узлы пройдены
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == false)  stop = true; 
	}
}

void BinTree::print_BtreeNode(BinTree *bt)
{
	bool stop = false;

	cout << endl << " Дерево бинарного вида " << endl;
	cout << " Корень ";
	bt->cur = bt->root;
	cout << bt->cur->data << endl;
	bt->cur->existInComTree = true;
	while (stop != true)
	{
		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		{
			cout << " Предок:  " << bt->cur->data;
			bt->cur = bt->cur->left;
			cout << " Текущая вершина:  " << bt->cur->data;
			if(bt->cur->left != NULL){cout << " Левый: " << bt->cur->left->data;}
			else {cout << " Левый: нет ";}

			if(bt->cur->right != NULL){cout << " Правый: " << bt->cur->right->data;}
			else {cout << " Правый: нет ";}

			cout << endl;
			bt->cur->existInComTree = true; //вершина была пройдена

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //Правый узел != NULL 
		{
			
			cout << " Предок:  " << bt->cur->data;
			bt->cur = bt->cur->right;  //смена текущ на правого
			cout << " Текущая вершина:  " << bt->cur->data;

			if(bt->cur->left != NULL) {cout << " Левый: " << bt->cur->left->data;}
			else {cout << " Левый: нет ";}

			if(bt->cur->right != NULL){cout << " Правый: " << bt->cur->right->data;}
			else {cout << " Правый: нет ";}

			cout << endl;
			bt->cur->existInComTree = true; //вершина была пройдена

		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //левый и правый узлы пустые
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //левый и правый пройдены
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //левый пройден, а правого пустой
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //правый пройден, а левый пустой
		{ 

			bt->cur = bt->cur->pred;

		} //мы поднялись к корню, т.к. все узлы пройдены
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}
	bt->UpdateBoolBinNodes(bt);
}

//создание дерева бинарного вида через текстовый файл
void BinTree::CreateBinTr(int dataVerh, string dataStr, int leftVerh, int rightVerh, BinTree* bt)
{

	bool stop = false;
	Node * node;

	if(dataVerh == 1)
	{
        node = bt->root->getBinNode(); //создали вершину
	    node->data = dataVerh;
	    node->dataStr = dataStr;		//запомнили текстовое поле
	    bt->root = node; //Корень, левый, правый (КЛП)
	    bt->cur = bt->root; //текущий на корень 
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
	while (stop != true)  //находим нужную вершину
	{

		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		{
			
			bt->cur = bt->cur->left; //смена текущ на левого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			if (bt->cur->data == dataVerh) {stop = true; findVerh = true;}

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //Правый узел != NULL 
		{
			
			bt->cur = bt->cur->right;  //смена текущ на правого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			if (bt->cur->data == dataVerh) {stop = true; findVerh = true;}
		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //левый и правый узлы пустые
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //левый и правый пройдены
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //левый пройден, а правого пустой
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //правый пройден, а левый пустой
		{ 
			//для дерева бинарного вида
			bt->cur = bt->cur->pred;

		} //мы поднялись к корню, т.к. все узлы пройдены
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}

	if (findVerh = true) 
	{
		bt->cur->dataStr = dataStr; //текущий на корень 
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
	int numVerh = 0; //количество пройденных вершин вниз
	int *sol; //путь до решения, нулевой элемент будет содержать количество вершин
	bool stop = false;
	bool findVerh = false;
	bt->UpdateBoolBinNodes(bt); //если у дерево будет готово к обходу, то обновим все вершины
	while (stop != true)  //находим нужную вершину
	{

		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		{
			
			bt->cur = bt->cur->left; //смена текущ на левого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			numVerh++;	//идем по левой вершине => она может войти в путь к решению
			if (bt->cur->dataStr == _dataStr) {stop = true; findVerh = true;}

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //Правый узел != NULL 
		{
			
			bt->cur = bt->cur->right;  //смена текущ на правого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			if (bt->cur->dataStr == _dataStr) {stop = true; findVerh = true;}
		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //левый и правый узлы пустые
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //левый и правый пройдены
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //левый пройден, а правого пустой
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //правый пройден, а левый пустой
		{ 
			//для дерева бинарного вида
			if(bt->cur->pred->left == bt->cur){ numVerh--; } //если отходим назад по левому => понижаем уровень 
			bt->cur = bt->cur->pred;

		} //мы поднялись к корню, т.к. все узлы пройдены
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}

	//bt->UpdateBoolBinNodes(bt); //обновляем вершины после обхода

	int ind = 2; //т.к. нулевой элемент будет занят
	if(findVerh) //запоминаем пройденный путь
	{
		numVerh += 2; //прибавили к пути само решение и элемент под количество вершин (элементов массива будет n+1, где n - путь из вершин) 
		sol = new int[numVerh];
		sol[0] = numVerh; //записали количество вершин в 1 элемент массива
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
	int kolBroth = 0; //количество братьев для общего вида 
	int NumVerh;  //номер вершины 
	Node *RightBroth;
	ComNode * Cnode;
	Cnode = ct->root->getComNode(); //создали вершину
	Cnode->data = bt->root->data;
	Cnode->dataStr = bt->root->dataStr;									//запомнили текстовое поле
	ct->root = Cnode; //КЛП 
	ct->cur = ct->root; //текущий на корень 
	ct->cur->existInBinTree = false;

	bt->UpdateBoolBinNodes(bt);  //обновили узлы бинарного дерева перед преобразованием
	bt->cur = bt->root;
	bt->cur->existInComTree = true;
	while (stop != true)
	{
		kolBroth = 0;
		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		{
			//для дерева общего вида
			Cnode = ct->root->getComNode(); //создали вершину
			Cnode->data = bt->cur->left->data;
			Cnode->dataStr = bt->cur->left->dataStr;				   //запомнили текстовое поле
			ct->cur->son = Cnode; //добавление информации для левого
			ct->cur->son->pred = ct->cur; //добавление предыдущего для левого
			ct->cur = ct->cur->son; //смена текущ на левого
			ct->cur->existInBinTree = false;

			//для дерева бинарного вида
			bt->cur->left->pred = bt->cur; //добавили предыдущего для левого
			bt->cur = bt->cur->left; //смена текущ на левого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

			//для братьев (общий вид)
			RightBroth = bt->cur->right; //для просмотра братьев от левого
			while(RightBroth !=NULL){RightBroth = RightBroth->right; kolBroth += 1;} //посчитали количество правых узлов от текущего
			if( kolBroth != 0) {
			ct->cur->brot = new ComNode*[kolBroth+1]; //формируем массив указателей на братьев (правых)
			for(int i = 0; i < kolBroth; i++) {ct->cur->brot[i] = NULL;}
			ct->cur->number_verh = 0; //для массива указателей номер вершины 
	 		ct->cur->count_verh = kolBroth + 1; //количество братьев + сын

            Cnode = ct->root->getComNode(); //создали вершину
			ct->cur->brot[0] = Cnode;
			ct->cur->brot[0]->pred = ct->cur; //текущего сделали предыдущим для брата, если они у него есть 
			}
	 		else {ct->cur->count_verh = 1; }

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //Правый узел != NULL 
		{
			//для дерева общего вида

			if(ct->cur->number_verh == 0){

				Cnode = ct->root->getComNode();
				ct->cur->brot[0] = Cnode; //т.к. number_verh на 1 меньше индекса массива brot
				ct->cur->brot[0]->brot = new ComNode*[1]; //son ---> brot[NumVerh-1] 
				ct->cur->brot[0]->brot[0] = ct->cur; //brot[NumVerh-1] <----> son
				ct->cur->brot[0]->number_verh = 1;
	 			ct->cur->brot[0]->count_verh = ct->cur->count_verh;
				ct->cur->brot[0]->pred = ct->cur;
				ct->cur = ct->cur->brot[0];
				ct->cur->existInBinTree = false;
			}

			else if(ct->cur->number_verh != 0){ //для не 0 братьев делаем предыдущего

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
			ct->cur->data = bt->cur->right->data; //заполнили правого под номером number_verh
			ct->cur->dataStr = bt->cur->right->dataStr;				//запомнили текстовое поле

			//для дерева бинарного вида
			bt->cur->right->pred = bt->cur;//добавили предыдущего для правого
			bt->cur = bt->cur->right;  //смена текущ на правого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //левый и правый узлы пустые
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //левый и правый пройдены
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //левый пройден, а правого пустой
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //правый пройден, а левый пустой
		{ 
			//для дерева бинарного вида
			bt->cur = bt->cur->pred;

			//для дерева общего вида
			ct->cur = ct->cur->pred;
			ct->cur->existInBinTree = false;

		} //мы поднялись к корню, т.к. все узлы заполнены
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}
	bt->UpdateBoolBinNodes(bt);
}

void CommonTree::print_CommonTree(CommonTree *ct)
{
	bool stop = false;
	int indBr = 0; // индекс брата 

	ct->cur = ct->root;
	cout << endl << " Дерево общего вида: " << endl;
	cout << " Корень: " << ct->cur->data << endl;
	ct->cur->existInBinTree = true;

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{
			cout << " Предок " << ct->cur->son->pred->data << " Инф. поле: " << ct->cur->son->pred->dataStr << ", ";
			ct->cur = ct->cur->son;
			cout << " Потомки:";
			for(int i = 0; i < ct->cur->count_verh; i++) {
				if (i == 0){cout << " " << ct->cur->data << " Инф. поле: " << ct->cur->dataStr <<",";}
				else {cout << "  " << ct->cur->brot[i-1]->data << " Инф. поле: " << ct->cur->brot[i-1]->dataStr <<",";}
			}

			ct->cur->existInBinTree = true;
			indBr = 0;
			cout << endl;
		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; 

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; 

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //левый и правый пройдены
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //левый пройден, а правого пустой

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //правый пройден, а левый пустой
		{
			//для дерева общего вида
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //мы поднялись к корню, т.к. все узлы пройдены
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  stop = true; 
	}
	ct->UpdateBoolComNodes(ct);
}
void CommonTree::TransformBinarTree(BinTree * bt, CommonTree* ct)
{
	bool stop = false;
	int iX = 50, iY = 50;
	int t = 3, p = 3, Up = 0;
	int indBr = 0; // индекс брата 
	int NumVerh;
	Node *Bnode;
	Bnode = bt->root->getBinNode(); //создали вершину
	Bnode->data = ct->root->data;
	Bnode->dataStr = ct->root->dataStr;	//запомнили текстовое поле
	Bnode->existInComTree = false;

	bt->root = Bnode; //добавили узел в корень бинарного дерева
	bt->cur = bt->root;
	bt->cur->existInComTree = false;

	ct->cur = ct->root; //текущий на корень в дереве общего вида
	ct->cur->existInBinTree = true; //добавлен в бинарное дерево

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{
			//для дерева общего вида
			ct->cur = ct->cur->son;   //Сделали текущим son 
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево

			//для дерева бинарного вида
			Bnode = bt->root->getBinNode(); //создали вершину
			Bnode->data = ct->cur->data;
			Bnode->dataStr = ct->cur->dataStr;			//запомнили текстовое поле
			
			bt->cur->left = Bnode;   //добавили созданную вершину в левый узел 
			bt->cur->left->pred = bt->cur;
			bt->cur = bt->cur->left;
			indBr = 0; //сбрасываем счетчик братьев
			bt->cur->existInComTree = false;

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			//для дерева общего вида
			ct->cur = ct->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево
			//для дерева бинарного вида

			Bnode = bt->root->getBinNode();
			Bnode->data = ct->cur->data;
			Bnode->dataStr = ct->cur->dataStr;		   //запомнили текстовое поле
			Bnode->pred = bt->cur;

			bt->cur->right = Bnode;
			bt->cur = bt->cur->right;
			bt->cur->existInComTree = false;
		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			//для дерева общего вида
			ct->cur = ct->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево
			//для дерева бинарного вида

			Bnode = bt->root->getBinNode();
			Bnode->data = ct->cur->data;
			Bnode->dataStr = ct->cur->dataStr; //запомнили текстовое поле
			Bnode->pred = bt->cur;

			bt->cur->right = Bnode;
			bt->cur = bt->cur->right;
			bt->cur->existInComTree = false;
		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //левый и правый пройдены
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //левый пройден, а правого пустой

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //правый пройден, а левый пустой
		{ 
			//для дерева бинарного вида
			bt->cur = bt->cur->pred;
			bt->cur->existInComTree = false;

			//для дерева общего вида
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //мы поднялись к корню, т.к. все узлы заполнены
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  stop = true; 
	}
	ct->UpdateBoolComNodes(ct);
	//bt->UpdateBoolBinNodes(bt);

}
void CommonTree::UpdateBoolComNodes(CommonTree *ct)
{
	bool stop = false;

	int indBr = 0; // индекс брата 

	ct->cur = ct->root; //текущий на корень в дереве общего вида
	ct->cur->existInBinTree = false; //добавлен в бинарное дерево

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == true) //Son != NULL и не был добавлен
		{

			ct->cur = ct->cur->son;   //Сделали текущим son 
			ct->cur->existInBinTree = false; //сброс переменной на false

			indBr = 0; //сбрасываем счетчик братьев

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == true) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = false; //добавлен в бинарное дерево

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == true) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = false; //добавлен в бинарное дерево

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //левый и правый пройдены
			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == false||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == false ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == false && ct->cur->brot == NULL && ct->cur != ct->root || //левый пройден, а правого пустой

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == false && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == false && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //правый пройден, а левый пустой
		{ 
			
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == false)  stop = true; 
	}
}


//создание дерева общего вида через текстовый файл
void CommonTree::CreateComTr(int dataVerh, string dataStr, int *masVerh, int numVerh, CommonTree* ct)
{
	bool stop = false;
	int NumVerh;  //номер вершины 
	int indBrot = 0;
	ComNode * Cnode;

	if(dataVerh == 1)
	{
        Cnode = ct->root->getComNode(); //создали вершину
	    Cnode->data = dataVerh;
	    Cnode->dataStr = dataStr;		//запомнили текстовое поле
	    ct->root = Cnode; //КЛП 
	    ct->cur = ct->root; //текущий на корень 
	    ct->cur->existInBinTree = false;
		if(numVerh != 0)
		{
			if(numVerh == 1) 
			{

			  if(masVerh[0] != 0) // единственный потомок != 0
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
				ct->cur->brot = new ComNode*[numVerh-1]; //формируем массив указателей на потомков
				for(int i = 0; i < numVerh-1; i++) 
				{
					ct->cur->brot[i] = ct->root->getComNode();
					ct->cur->brot[i]->data = masVerh[i+1];
					ct->cur->brot[i]->number_verh = i+1;     //задали номер потомка
					ct->cur->brot[i]->count_verh = ct->cur->count_verh; //задали количество вершин братьев
					ct->cur->brot[i]->brot = new ComNode*[1];
					ct->cur->brot[i]->brot[0] = ct->cur;  //каждый брат может сослаться на начального
					ct->cur->brot[i]->existInBinTree = false;
					if(i == 0){ct->cur->brot[0]->pred = ct->cur;}  //задали предыдущего 
					else {ct->cur->brot[i]->pred = ct->cur->brot[i-1];}
				}

			}
		}
		stop = true;
	}
	
	int indBr = 0; // индекс брата 
	bool noVerh = false; //не нашли вершину
	bool findVerh = false;

	ct->cur = ct->root;
	ct->cur->existInBinTree = true; 

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{

			ct->cur = ct->cur->son;   //Сделали текущим son 
			ct->cur->existInBinTree = true; //сброс переменной на false
			if (ct->cur->data == dataVerh) {stop = true; findVerh = true;}

			indBr = 0; //сбрасываем счетчик братьев

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево
			if (ct->cur->data == dataVerh) {stop = true; findVerh = true;}

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево
			if (ct->cur->data == dataVerh) {stop = true; findVerh = true;}

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //левый и правый пройдены
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //левый пройден, а правого пустой

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //правый пройден, а левый пустой
		{ 
			
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;

		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  {stop = true; noVerh = true;}
	}


	//}

	if (noVerh) {cout << " не нашли вершину"; } 

	if(findVerh = true)  //исключение не сработало, значит вершна найдена
	{
		cout << " найдена вершина " <<  ct->cur->data << " "; 
	    ct->cur->dataStr = dataStr;
	    ct->cur->existInBinTree = true;
		if(numVerh != 0)
		{
			if(numVerh == 1) 
			{
			  if (masVerh[0] != 0 ) //единственный потомок != 0
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
				ct->cur->brot = new ComNode*[numVerh-1]; //формируем массив указателей на потомков
				for(int i = 0; i < numVerh-1; i++) 
				{
					ct->cur->brot[i] = ct->root->getComNode();
					ct->cur->brot[i]->data = masVerh[i+1];
					ct->cur->brot[i]->number_verh = i+1;     //задали номер потомка
					ct->cur->brot[i]->count_verh = ct->cur->count_verh; //задали количество вершин братьев
					ct->cur->brot[i]->brot = new ComNode*[1];
					ct->cur->brot[i]->brot[0] = ct->cur;  //каждый брат может сослаться на начального
					ct->cur->brot[i]->existInBinTree = true;
					if(i == 0){ct->cur->brot[0]->pred = ct->cur;}  //задали предыдущего 
					else {ct->cur->brot[i]->pred = ct->cur->brot[i-1];}
				}

			}
		}
	}
	

}

void SetColor(int text, int bg)   //для выделения решения при выводе дерева
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void BinTree::levelVerhBinTree(BinTree* bt, int *levelVerhBin, int NumberVerh)
{
	bool stop = false;
	int NumVerh = 1;  //номер вершины в массиве levelVerhBin
	int LevelTree = 1; //уровень вершины при обходе

	bt->cur = bt->root;
	bt->cur->existInComTree = true;
	levelVerhBin[0] = 1;

	while (stop != true)
	{
		if(bt->cur->left != NULL && bt->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		{

			//для дерева бинарного вида
			bt->cur = bt->cur->left; //смена текущ на левого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

			LevelTree++; //повышаем уровень 
			levelVerhBin[NumVerh] = LevelTree;
			NumVerh++; //повышаем номер вершины 

		}
		else if(bt->cur->right != NULL && bt->cur->right->existInComTree == false) //Правый узел != NULL 
		{
			//для дерева бинарного вида
			bt->cur = bt->cur->right;  //смена текущ на правого
			bt->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

			LevelTree++; //повышаем уровень 
			levelVerhBin[NumVerh] = LevelTree;
			NumVerh++; //повышаем номер вершины 
		}
		else if(bt->cur->left == NULL && bt->cur->right == NULL || //левый и правый узлы пустые
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right != NULL && bt->cur->right->existInComTree == true || //левый и правый пройдены
			bt->cur->left != NULL && bt->cur->left->existInComTree == true && bt->cur->right == NULL && bt->cur != bt->root || //левый пройден, а правого пустой
			bt->cur->right != NULL && bt->cur->right->existInComTree == true && bt->cur->left == NULL && bt->cur != bt->root) //правый пройден, а левый пустой
		{ 
			//для дерева бинарного вида
			bt->cur = bt->cur->pred;
			LevelTree--;//понижаем уровень 

		} //мы поднялись к корню, т.к. все узлы заполнены
		else if(bt->cur == bt->root && bt->cur->left->existInComTree == true)  stop = true; 
	}
}

void CommonTree::levelVerhComTree(CommonTree* ct, int *levelVerh, int NumberVerh) //определяем уровни вершин дерева общего вида
{
	bool stop = false;
	int NumVerh = 1;  //номер вершины в массиве levelVerh
	int indBr = 0;
	int LevelTree = 1; //уровень вершины при обходе

	ct->cur = ct->root;
	ct->cur->existInBinTree = true; 
	levelVerh[0] = 1;

	while (stop != true)
	{
		if(ct->cur->son != NULL && ct->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{

			ct->cur = ct->cur->son;   //Сделали текущим son 
			ct->cur->existInBinTree = true; //сброс переменной на false
			LevelTree++; //повышаем уровень 
			levelVerh[NumVerh] = LevelTree;
			NumVerh++; //повышаем номер вершины 
			indBr = 0; //сбрасываем счетчик братьев

		}
		else if(ct->cur->number_verh != 0 && indBr < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[indBr] != NULL && ct->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			levelVerh[NumVerh] = LevelTree;
			NumVerh++; //повышаем номер вершины 
			indBr += 1;
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево

		}
		else if(ct->cur->number_verh == 0 && ct->cur->brot != NULL && ct->cur->brot[indBr] != NULL && ct->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct->cur = ct->cur->brot[indBr]; //заполнили правого под номером number_verh
			levelVerh[NumVerh] = LevelTree;
			NumVerh++; //повышаем номер вершины 
			indBr += 1;
			ct->cur->existInBinTree = true; //добавлен в бинарное дерево

		}
		else if(ct->cur->son == NULL && ct->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 || //левый и правый пройдены
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true||
			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true ||

			ct->cur->son != NULL && ct->cur->son->existInBinTree == true && ct->cur->brot == NULL && ct->cur != ct->root || //левый пройден, а правого пустой

			ct->cur->brot != NULL && ct->cur->number_verh == 0 && ct->cur->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh < ct->cur->count_verh-1 && ct->cur->brot[0]->brot[ct->cur->number_verh]->existInBinTree == true && ct->cur->son == NULL && ct->cur != ct->root ||
			ct->cur->brot != NULL && ct->cur->number_verh != 0 && ct->cur->number_verh >= ct->cur->count_verh-1 && ct->cur->son == NULL && ct->cur != ct->root) //правый пройден, а левый пустой
		{ 

			if(ct->cur->pred->son == ct->cur) {LevelTree--;}
			ct->cur = ct->cur->pred;
            indBr = ct->cur->number_verh;


		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct->cur == ct->root && ct->cur->son->existInBinTree == true)  {stop = true; }
	}
}
