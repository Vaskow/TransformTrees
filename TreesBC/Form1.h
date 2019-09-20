#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h> //string
#include "ComBinTrees.h"


using namespace std;
#pragma once

namespace TreesBC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		//Принимаем дерево общего вида и преобразовываем в бинарное
		BinTree *bt3;
		CommonTree *ct3;

		int NumberVerh; //количество принятых вершин
		int* levelVerh; //уровень в дереве для каждой вершины
		int *masX; //координаты точек
		int *masY;

		int* levelVerhBin; //уровень в дереве для каждой вершины
		int *masXBin; //координаты точек
		int *masYBin;

		//Принимаем дерево бинарного вида и преобразовываем в общее
		BinTree *bt2;
		CommonTree *ct2;

		//если нужно будет для 2-го случая дополнитьленые параметры
		//int _NumberVerh; //количество принятых вершин
		//int* _levelVerh; //уровень в дереве для каждой вершины
		//int *_masX; //координаты точек
		//int *_masY;

		//int* _levelVerhBin; //уровень в дереве для каждой вершины
		//int *_masXBin; //координаты точек
		//int *_masYBin;




	private: System::Windows::Forms::TextBox^  textBox3;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
			 int *Numberlevel; //количество уровней в дереве
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(357, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Получить дерево общего вида и преобразовать в бинарное дерево";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(435, 29);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(134, 20);
			this->textBox3->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 133);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(875, 454);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(435, 90);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(134, 20);
			this->textBox4->TabIndex = 7;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(652, 15);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(236, 32);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Восстановить путь до указанной вершины";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(10, 78);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(357, 34);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Получить бинарное дерево и преобразовать в дерево общего вида";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(651, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(236, 32);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Восстановить путь до указанной вершины";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(382, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(261, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Укажите текстовое поле вершины для случая №1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(382, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(261, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Укажите текстовое поле вершины для случая №2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 700);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	BinTree bt;
	CommonTree ct;
	int B[8]={11,1,3,2,8,4,5,6};
	int C[6]={12,7,8,11,9,10};

	setlocale(LC_CTYPE, "Russian");

	ct3 = ct.CreateComTree();
	NumberVerh = 0; //количество принятых вершин дерева
	string str;

   ifstream file("Tree.txt"/*,ios::in*/); //чтение дерева вида из файла и создание его

   while(file)
   {

	int nVerh;
	string _dataStr;
	int *masVerh;
	int numChild = 0; //количество потомков для вершины родителя

	int length2 = 0; // длина str2
	int length3 = 0, ind3;
	int length4 = 0, ind4;

	int ind = 0; //используется для подсчета потомков и в их отделении из строки
	int ind2 = 0;
	int length = 0; //длина номеров потомков

	NumberVerh++; //подсчет количества вершин для рисования дерева общего вида
	
    getline(file, str);
	

	while(str[length2] != ':' && str[length2] != ' '){ length2++; }  //получили первое слов
	ind3 = length2 + 2;
	while(str[ind3] != ' '){ length3++; ind3++; }  //получили второе слово
	ind4 = ind3 + 1;
    while(ind4 != str.length()){ length4++; ind4++; } //получили третье слово 

	string str2(str,0,length2); // первое слово
	string str3(str,length2 + 2,length3); //второе слово
	string str4(str,ind3 + 1,length4); //третье слово, содержащее потомков

	nVerh = stoi(str2);   //запомнили номер вершины (имя)
	_dataStr = str3; //запомнили информацию вершины

	while(ind != str4.length() ) //подсчитываем количество потомков, узнав количество ','
	{
		if(str4[ind] == ','){numChild++;}
		ind++;
	}
	
	masVerh = new int[numChild+1]; //захватываем память под количество потомков
	if(numChild == 0 && str4[0] == '-') { masVerh[0] = 0; } //если нет потомков, то в массив отправим 0       Ye;yj j,hf,jnfnm
	else
	{
	ind = 0;
	for(int i = 0; i < numChild+1; i++) //разобьем строку на числа (номера потомков)
	{
		length = 0;
		if (i == 0) 
		{
		  while(ind < str4.length() && str4[ind] != ','){length++; ind++;}
		  string str1(str4,0,length);
		  masVerh[0] = stoi(str1);   //запомнили номер первого потомка
		  ind++; //сдвигаемся вправо от ','
		  ind2 = ind; //ind2 будет использоваться для подсчета, а ind для отделения числа (№ потомка)
		}
		else
		{
		 while(ind2 < str4.length() && str4[ind2] != ','){length++; ind2++;}
		 string str1(str4,ind,length);
		 masVerh[i] = stoi(str1);
		 ind2++;
		 ind = ind2;
		}
	}
	}

	ct.CreateComTr(nVerh, _dataStr, masVerh, numChild+1, ct3);  //по вершинам создаем дерево
	ct.UpdateBoolComNodes(ct3);
    cout<<str<<endl;
	cout<<nVerh << " " <<_dataStr; for(int i = 0; i < numChild+1; i++) {cout << " "<< masVerh[i]; } cout << endl;
   };
   file.close();
   NumberVerh -= 1; // посчитали количество приняты вершин
   levelVerh = new int[NumberVerh];
   masX = new int[NumberVerh];
   masY = new int[NumberVerh];

   ct.levelVerhComTree(ct3, levelVerh, NumberVerh); //получили уровни вершин
   ct.UpdateBoolComNodes(ct3); //обновили пройденные вершины для следующего обхода

   //нужно разбить область на уровни, где вершины располагаются на расстоянии область/вершины_на_уровне+1 и в координаты забить
   //for(int i = 0; i < NumberVerh; i++)
   //{
   //textBox1->Text += Convert::ToString(levelVerh[i]) + " "; //вывод
   //}
   int maxLevel = 1;
   for(int i = 0; i < NumberVerh; i++)
   {
	   if(levelVerh[i] > maxLevel) { maxLevel = levelVerh[i];}
   }
   //textBox1->Text = Convert::ToString(maxLevel);   //вывод

   Numberlevel = new int[maxLevel];  //массив под количество уровней вершин, чтобы вычислить расстояние между ними при рисовании
   for(int i = 0; i < maxLevel; i++)
   {
		Numberlevel[i] = 0;  //проинициализировали 0 
   }

   for(int i = 0; i < maxLevel; i++)
   {
	   for(int j = 0; j < NumberVerh; j++)
	   {
		   if(levelVerh[j] == i+1) { Numberlevel[i]++;}
	   }
   }
   //for(int i = 0; i < maxLevel; i++)
   //{
   //textBox1->Text += Convert::ToString(Numberlevel[i]) + " ";  //вывод
   //}

   //вычислим для каждой вершины координаты по Х в зависимости от их количества на уровне
   
   for(int i = 0; i < NumberVerh; i++)
   {
	   masX[i] = 0; masY[i] = 0;
   }
   int *masDubl = new int [maxLevel]; //массив, для увеличения расстояния между вершинами на одном уровне
   for(int i = 0; i < maxLevel; i++)
   {
	   masDubl[i] = 1;
   }

   for(int i = 0; i < NumberVerh; i++)
   {
	   masX[i] = 350 / (Numberlevel[levelVerh[i]-1] + 1) + 4;

	   for(int j = 0; j < i; j++)
	   {
		   if(masX[i] == masX[j] && Numberlevel[levelVerh[i]-1] != 1 && i != 0 && masX[i] != 0 && masDubl[levelVerh[i]-1] <= Numberlevel[levelVerh[i]-1]){ masDubl[levelVerh[i]-1]+= 1; masX[i] = (350 / (Numberlevel[levelVerh[i]-1] + 1) + 4) * masDubl[levelVerh[i]-1]; j = NumberVerh; }
	   }
	   masY[i] = 50 * levelVerh[i] + 10;
   }

   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox2->Text += Convert::ToString(masX[i]) + " "; //дополнительный контейнер для вывода
   //}
   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox3->Text += Convert::ToString(masY[i]) + " "; //дополнительный контейнер для вывода
   //}


   Graphics ^ g = pictureBox1->CreateGraphics();
   g->Clear(Color::White); //очистка pb1

   for(int i = 0; i < NumberVerh; i++)
   {
	   g->DrawEllipse(Pens::Red, masX[i], masY[i], 17, 17);
   }


   //Построим ребра для нарисованных вершин

    bool stop = false;
	int indBr = 0;
	int obVerh = 0; //обход вершин
	int indpredVerh = 0; //индекс предыдущей вершины в обходе для братьев
	int *maspredVerh = new int[NumberVerh]; //массив вершин предков для братьев
	for(int i = 0; i < NumberVerh; i++)
    {
		maspredVerh[i] = -1;
	}

	ct3->cur = ct3->root;
	ct3->cur->existInBinTree = true; 
	g->DrawString(Convert::ToString(ct3->root->data), Font ,Brushes::Red, PointF(masX[0]+1, masY[0]+1));          

	while (stop != true)
	{
		if(ct3->cur->son != NULL && ct3->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{

			ct3->cur = ct3->cur->son;   //Сделали текущим son          
			g->DrawLine(Pens::Red, masX[obVerh]+7, masY[obVerh]+17, masX[obVerh+1]+8, masY[obVerh+1]);
			ct3->cur->existInBinTree = true; //сброс переменной на false
			indBr = 0; //сбрасываем счетчик братьев
			maspredVerh[indpredVerh] = obVerh;
			indpredVerh++; //добавили предка в обход
			obVerh++;
			g->DrawString(Convert::ToString(ct3->cur->data), Font ,Brushes::Red, PointF(masX[obVerh]+1, masY[obVerh]+1)); 

		}
		else if(ct3->cur->number_verh != 0 && indBr < ct3->cur->count_verh-1 && ct3->cur->brot[0]->brot[indBr] != NULL && ct3->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct3->cur = ct3->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct3->cur->existInBinTree = true; //добавлен в бинарное дерево
			g->DrawLine(Pens::Red, masX[maspredVerh[indpredVerh-1]]+7, masY[maspredVerh[indpredVerh-1]]+17, masX[obVerh+1]+8, masY[obVerh+1]);
			obVerh++;
			g->DrawString(Convert::ToString(ct3->cur->data), Font ,Brushes::Red, PointF(masX[obVerh]+1, masY[obVerh]+1)); 
		}
		else if(ct3->cur->number_verh == 0 && ct3->cur->brot != NULL && ct3->cur->brot[indBr] != NULL && ct3->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct3->cur = ct3->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct3->cur->existInBinTree = true; //добавлен в бинарное дерево
			g->DrawLine(Pens::Red, masX[maspredVerh[indpredVerh-1]]+7, masY[maspredVerh[indpredVerh-1]]+17, masX[obVerh+1]+8, masY[obVerh+1]);
			obVerh++;
			g->DrawString(Convert::ToString(ct3->cur->data), Font ,Brushes::Red, PointF(masX[obVerh]+1, masY[obVerh]+1)); 
		}
		else if(ct3->cur->son == NULL && ct3->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh >= ct3->cur->count_verh-1 || //левый и правый пройдены
			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh < ct3->cur->count_verh-1 && ct3->cur->brot[0]->brot[ct3->cur->number_verh]->existInBinTree == true||
			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot != NULL && ct3->cur->number_verh == 0 && ct3->cur->brot[ct3->cur->number_verh]->existInBinTree == true ||

			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot == NULL && ct3->cur != ct3->root || //левый пройден, а правого пустой

			ct3->cur->brot != NULL && ct3->cur->number_verh == 0 && ct3->cur->brot[ct3->cur->number_verh]->existInBinTree == true && ct3->cur->son == NULL && ct3->cur != ct3->root ||
			ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh < ct3->cur->count_verh-1 && ct3->cur->brot[0]->brot[ct3->cur->number_verh]->existInBinTree == true && ct3->cur->son == NULL && ct3->cur != ct3->root ||
			ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh >= ct3->cur->count_verh-1 && ct3->cur->son == NULL && ct3->cur != ct3->root) //правый пройден, а левый пустой
		{ 
			if(ct3->cur->pred->son == ct3->cur) {indpredVerh--;}
			ct3->cur = ct3->cur->pred;
            indBr = ct3->cur->number_verh;


		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct3->cur == ct3->root && ct3->cur->son->existInBinTree == true)  {stop = true; }
	}

	//Получим бинарное дерево из дерева общего вида

	bt3 = bt.CreateBinTree(); //бинарное дерево из дерева общего вида
	ct.UpdateBoolComNodes(ct3); //обновили пройденные вершины для следующего обхода
    ct.TransformBinarTree(bt3, ct3); //получаем бинарное дерево

	levelVerhBin = new int[NumberVerh];
    masXBin = new int[NumberVerh];
    masYBin = new int[NumberVerh];

	bt.levelVerhBinTree(bt3, levelVerhBin, NumberVerh); //получили уровни вершин
    bt.UpdateBoolBinNodes(bt3); //обновили пройденные вершины для следующего обхода

	//нужно разбить область на уровни, где вершины располагаются на расстоянии область/вершины_на_уровне+1 и в координаты забить
   //for(int i = 0; i < NumberVerh; i++)
   //{
   //textBox4->Text += Convert::ToString(levelVerhBin[i]) + " "; //вывод
   //}
   int maxLevelBin = 1;  //определяем макс уровень для размера массива
   for(int i = 0; i < NumberVerh; i++)
   {
	   if(levelVerhBin[i] > maxLevelBin) { maxLevelBin = levelVerhBin[i];}
   }

   int *NumberlevelBin = new int[maxLevelBin];  //массив под количество уровней вершин, чтобы вычислить расстояние между ними при рисовании
   for(int i = 0; i < maxLevelBin; i++)
   {
		NumberlevelBin[i] = 0;  //проинициализировали 0 
   }

   for(int i = 0; i < maxLevelBin; i++)
   {
	   for(int j = 0; j < NumberVerh; j++)
	   {
		   if(levelVerhBin[j] == i+1) { NumberlevelBin[i]++;} //запоминаем количество вершин на каждом уровне
	   }
   }

   //for(int i = 0; i < maxLevelBin; i++)
   //{
   //textBox4->Text += Convert::ToString(NumberlevelBin[i]) + " "; //вывод
   //}

   //вычислим для каждой вершины координаты по Х в зависимости от их количества на уровне
   
   for(int i = 0; i < NumberVerh; i++)
   {
	   masXBin[i] = 0; masYBin[i] = 0;
   }
   int *masDublBin = new int [maxLevelBin]; //массив, для увеличения расстояния между вершинами на одном уровне
   for(int i = 0; i < maxLevelBin; i++)
   {
	   masDublBin[i] = 1;
   }

	  
   for(int i = 0; i < NumberVerh; i++)
   {
	   masXBin[i] = 350 + 350 / (NumberlevelBin[levelVerhBin[i]-1] + 1) + 4;

	   for(int j = 0; j < i; j++)
	   {
		   if(masXBin[i] == masXBin[j] && NumberlevelBin[levelVerhBin[i]-1] != 1 && i != 0 && masXBin[i] != 0 && masDublBin[levelVerhBin[i]-1] <= NumberlevelBin[levelVerhBin[i]-1]){ masDublBin[levelVerhBin[i]-1]+= 1; masXBin[i] = 350 + (390 / (NumberlevelBin[levelVerhBin[i]-1] + 1) + 4) * masDublBin[levelVerhBin[i]-1]; j = NumberVerh; }
	   }


	   masYBin[i] = 50 * levelVerhBin[i] + 10;
   }


   //Нужно поставить вершины левее или правее родителя, для этого потребуется обойти дерево 
   stop = false;

    bool pred2 = false; //обход возвращается по пройденным вершинам
	bool onerigh2 = false; //после pred случился переход вправо
	bool backrigh2 = false; //для возврата к пред. индексу
	int indpredVerhBin2 = 0; //индекс предыдущей вершины в обходе при левой ветви
	int *maspredVerhBin2 = new int[NumberVerh]; //запоминает текущий индекс на левых ветвях
	for(int i = 0; i < NumberVerh; i++)
    {
	  maspredVerhBin2[i] = 0;
	} 

	int NumVerh = 0;
    int obVerhB = 0;

    bt3->cur = bt3->root;
	bt3->cur->existInComTree = true;

   while(stop != true)
   {
	   

		 if(bt3->cur->left != NULL && bt3->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		 {

			//для дерева бинарного вида
			bt3->cur = bt3->cur->left; //смена текущ на левого
			bt3->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

			maspredVerhBin2[indpredVerhBin2]++; //повышаем номер вершины
			obVerhB++;
			if(masXBin[obVerhB] == masXBin[obVerhB-1] || masXBin[obVerhB] < masXBin[obVerhB-1]-25 || masXBin[obVerhB] > masXBin[obVerhB-1] ) {masXBin[obVerhB] = masXBin[obVerhB-1] - 60;}

		 }
		 else if(bt3->cur->right != NULL && bt3->cur->right->existInComTree == false) //Правый узел != NULL 
		 {
			//для дерева бинарного вида
			bt3->cur = bt3->cur->right;  //смена текущ на правого
			bt3->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

            if(onerigh2 == true) {indpredVerhBin2++; maspredVerhBin2[indpredVerhBin2] = obVerhB; onerigh2 = false;}
			if(pred2 == false) {maspredVerhBin2[indpredVerhBin2] = obVerhB; onerigh2 = false;} //если не идем обратно, то идекс по обходу
			else if(pred2 == true) {onerigh2 = true; pred2 = false;} //если идем обратно, то индекс остается
			if(masXBin[obVerhB+1] == masXBin[maspredVerhBin2[indpredVerhBin2]] || masXBin[obVerhB+1] > masXBin[maspredVerhBin2[indpredVerhBin2]]+25 || masXBin[obVerhB+1] < masXBin[maspredVerhBin2[indpredVerhBin2]] ) {masXBin[obVerhB+1] = masXBin[maspredVerhBin2[indpredVerhBin2]] + 60;}
			

			maspredVerhBin2[indpredVerhBin2]++;
			obVerhB++;
			
			
		 }
		 else if(bt3->cur->left == NULL && bt3->cur->right == NULL || //левый и правый узлы пустые
			bt3->cur->left != NULL && bt3->cur->left->existInComTree == true && bt3->cur->right != NULL && bt3->cur->right->existInComTree == true || //левый и правый пройдены
			bt3->cur->left != NULL && bt3->cur->left->existInComTree == true && bt3->cur->right == NULL && bt3->cur != bt3->root || //левый пройден, а правого пустой
			bt3->cur->right != NULL && bt3->cur->right->existInComTree == true && bt3->cur->left == NULL && bt3->cur != bt3->root) //правый пройден, а левый пустой
		 { 
			if(backrigh2 == true) { indpredVerhBin2--; backrigh2 = false;} //при двух шагах вправо к пред. вершинам сменяется индекс пройденных вершин на пред.
			if(bt3->cur->pred->right == bt3->cur && indpredVerhBin2 > 0) {backrigh2 = true;} //если был добавлен индекс левой ветви и идем по правой назад
			pred2 = true; onerigh2 = false;
			bt3->cur = bt3->cur->pred;
			maspredVerhBin2[indpredVerhBin2]--; //уменьшаем индекс, если возвращаемся к пройденным вершинам

		 } //мы поднялись к корню, т.к. все узлы заполнены
		 else if(bt3->cur == bt3->root && bt3->cur->left->existInComTree == true)  stop = true;
   }

    bt.UpdateBoolBinNodes(bt3); //обновили пройденные вершины для следующего обхода
	
	//если вершины будут совпадать
	for(int i = 0; i < NumberVerh; i++)
    {
		for(int j = 0; j < NumberVerh; j++)
		{
			if(i != j && masXBin[i] == masXBin[j] && masYBin[i] == masYBin[j]) 
			{
				masXBin[i] = masXBin[i] - 17;
				masXBin[j] = masXBin[j] + 17;
			}
			else if (i != j && (masXBin[i] - masXBin[j]) == 7 && masYBin[i] == masYBin[j])
			{
				masXBin[i] = masXBin[i] + 10;
				masXBin[j] = masXBin[j] - 10;
			}
			else if (i != j && (masXBin[i] - masXBin[j]) == -7 && masYBin[i] == masYBin[j])
			{
				masXBin[i] = masXBin[i] - 10;
				masXBin[j] = masXBin[j] + 10;
			}
		}
	}


   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox2->Text += Convert::ToString(masXBin[i]) + " "; //дополнительный контейнер для вывода
   //}
   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox3->Text += Convert::ToString(masYBin[i]) + " "; //дополнительный контейнер для вывода
   //}


   for(int i = 0; i < NumberVerh; i++)
   {
	   g->DrawEllipse(Pens::Red, masXBin[i], masYBin[i], 17, 17); //построим вершины бинарного дерева
   }


   //Построим ребра для нарисованных вершин

    bool stop2 = false;
	bool pred = false; //обход возвращается по пройденным вершинам
	bool onerigh = false; //после pred случился переход вправо
	bool backrigh = false; //для возврата к пред. индексу
	int obVerhBin = 0; //обход вершин
	int indpredVerhBin = 0; //индекс предыдущей вершины в обходе при левой ветви
	int *maspredVerhBin = new int[NumberVerh]; //запоминает текущий индекс на левых ветвях
	for(int i = 0; i < NumberVerh; i++)
    {
	  maspredVerhBin[i] = 0;
	} 
	NumVerh = 0;
	bt3->cur = bt3->root;
	bt3->cur->existInComTree = true; 
	g->DrawString(Convert::ToString(bt3->root->data), Font ,Brushes::Red, PointF(masXBin[0]+1, masYBin[0]+1));          

	while (stop2 != true)
	{
		if(bt3->cur->left != NULL && bt3->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		 {

			//для дерева бинарного вида
			bt3->cur = bt3->cur->left; //смена текущ на левого
			g->DrawLine(Pens::Red, masXBin[obVerhBin]+7, masYBin[obVerhBin]+17, masXBin[obVerhBin+1]+8, masYBin[obVerhBin+1]);
			bt3->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			maspredVerhBin[indpredVerhBin]++; //повышаем номер вершины
			obVerhBin++;
			g->DrawString(Convert::ToString(bt3->cur->data), Font ,Brushes::Red, PointF(masXBin[obVerhBin]+1, masYBin[obVerhBin]+1));
		
		 }
		 else if(bt3->cur->right != NULL && bt3->cur->right->existInComTree == false) //Правый узел != NULL 
		 {
			//для дерева бинарного вида
			bt3->cur = bt3->cur->right;  //смена текущ на правого
			bt3->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			if(onerigh == true) {indpredVerhBin++; maspredVerhBin[indpredVerhBin] = obVerhBin; onerigh = false;}
			if(pred == false) {maspredVerhBin[indpredVerhBin] = obVerhBin; onerigh = false;} //если не идем обратно, то идекс по обходу
			else if(pred == true) {onerigh = true; pred = false;} //если идем обратно, то индекс остается
			g->DrawLine(Pens::Red, masXBin[maspredVerhBin[indpredVerhBin]]+7, masYBin[maspredVerhBin[indpredVerhBin]]+17, masXBin[obVerhBin+1]+8, masYBin[obVerhBin+1]);

			maspredVerhBin[indpredVerhBin]++;
			obVerhBin++;
			g->DrawString(Convert::ToString(bt3->cur->data), Font ,Brushes::Red, PointF(masXBin[obVerhBin]+1, masYBin[obVerhBin]+1));
			
		 }
		 else if(bt3->cur->left == NULL && bt3->cur->right == NULL || //левый и правый узлы пустые
			bt3->cur->left != NULL && bt3->cur->left->existInComTree == true && bt3->cur->right != NULL && bt3->cur->right->existInComTree == true || //левый и правый пройдены
			bt3->cur->left != NULL && bt3->cur->left->existInComTree == true && bt3->cur->right == NULL && bt3->cur != bt3->root || //левый пройден, а правого пустой
			bt3->cur->right != NULL && bt3->cur->right->existInComTree == true && bt3->cur->left == NULL && bt3->cur != bt3->root) //правый пройден, а левый пустой
		 { 
			//для дерева бинарного вида
			if(backrigh == true) { indpredVerhBin--; backrigh = false;} //при двух шагах вправо к пред. вершинам сменяется индекс пройденных вершин на пред.
			if(bt3->cur->pred->right == bt3->cur && indpredVerhBin > 0) {backrigh = true;} //если был добавлен индекс левой ветви и идем по правой назад
			pred = true; onerigh = false;
			bt3->cur = bt3->cur->pred;
			maspredVerhBin[indpredVerhBin]--; //уменьшаем индекс, если возвращаемся к пройденным вершинам

		 } //мы поднялись к корню, т.к. все узлы заполнены
		 else if(bt3->cur == bt3->root && bt3->cur->left->existInComTree == true)  stop2 = true;
	}


	bt.UpdateBoolBinNodes(bt3); //обновили пройденные вершины для следующего обхода


	/*for(int i = 0; i < NumberVerh; i++)
    {
	textBox4->Text += Convert::ToString(maspredVerhBin[i]) + " ";
	}*/
	




   
   //g->DrawEllipse(Pens::Red, 50, 50, 15, 15);
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {                        //BUTTON2

    BinTree bt;
	CommonTree ct;
	int *solution;
	int NumSol = 0;
	String^ solStr = textBox3->Text;
	std::string normalString = msclr::interop::marshal_as<std::string>(solStr); 

	Graphics ^ g = pictureBox1->CreateGraphics();
	solution = bt.FindSolution(bt3, normalString);
	
	//textBox4->Text = Convert::ToString(solution[2]);

	NumSol = solution[0];

	
    bool stop = false;
	int indBr = 0;
	int obVerh = 0; //обход вершин
	int indsolVerh = 1; //индекс предыдущей вершины в обходе для братьев
	/*levelVerh = new int[NumberVerh];*/
	int *masVerhsol = new int[NumSol-1]; //для запоминания номеров в обходе

	ct.UpdateBoolComNodes(ct3); //обновили пройденные вершины для следующего обхода

	ct3->cur = ct3->root;
	ct3->cur->existInBinTree = true;           
	g->DrawEllipse(Pens::Green, masX[0]-1, masY[0]-1, 17.5, 17.5);
	g->DrawEllipse(Pens::Green, masX[0], masY[0], 17.5, 17.5);
	g->DrawEllipse(Pens::Green, masX[0], masY[0], 17.7, 17.7);
	g->DrawEllipse(Pens::Green, masX[0]-1, masY[0]-1, 17.3, 17.3);

	masVerhsol[0] = 0; //записали корень, который войдет в конец решения

	while (stop != true)
	{
		if(ct3->cur->son != NULL && ct3->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{

			ct3->cur = ct3->cur->son;   //Сделали текущим son          
			ct3->cur->existInBinTree = true; //сброс переменной на false
			indBr = 0; //сбрасываем счетчик братьев
			for(int i = 1; i < NumSol; i++)
			{
			  if(ct3->cur->data == solution[i]) 
			  {
				  g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.7, 17.7);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.3, 17.3);
			  
			      masVerhsol[indsolVerh] = obVerh+1;
			      indsolVerh++;
			  }
			}
			
			obVerh++;

		}
		else if(ct3->cur->number_verh != 0 && indBr < ct3->cur->count_verh-1 && ct3->cur->brot[0]->brot[indBr] != NULL && ct3->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct3->cur = ct3->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct3->cur->existInBinTree = true; //добавлен в бинарное дерево
			for(int i = 1; i < NumSol; i++)
			{
			  if(ct3->cur->data == solution[i]) 
			  {
				  g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.7, 17.7);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.3, 17.3);
			  
			      masVerhsol[indsolVerh] = obVerh+1;
			      indsolVerh++;
			  }
			}
			obVerh++;
		}
		else if(ct3->cur->number_verh == 0 && ct3->cur->brot != NULL && ct3->cur->brot[indBr] != NULL && ct3->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct3->cur = ct3->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct3->cur->existInBinTree = true; //добавлен в бинарное дерево
			for(int i = 1; i < NumSol; i++)
			{
			  if(ct3->cur->data == solution[i]) 
			  {
				  g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.7, 17.7);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.3, 17.3);
			  
			      masVerhsol[indsolVerh] = obVerh+1;
			      indsolVerh++;
			  }
			}
			obVerh++;
		}
		else if(ct3->cur->son == NULL && ct3->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh >= ct3->cur->count_verh-1 || //левый и правый пройдены
			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh < ct3->cur->count_verh-1 && ct3->cur->brot[0]->brot[ct3->cur->number_verh]->existInBinTree == true||
			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot != NULL && ct3->cur->number_verh == 0 && ct3->cur->brot[ct3->cur->number_verh]->existInBinTree == true ||

			ct3->cur->son != NULL && ct3->cur->son->existInBinTree == true && ct3->cur->brot == NULL && ct3->cur != ct3->root || //левый пройден, а правого пустой

			ct3->cur->brot != NULL && ct3->cur->number_verh == 0 && ct3->cur->brot[ct3->cur->number_verh]->existInBinTree == true && ct3->cur->son == NULL && ct3->cur != ct3->root ||
			ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh < ct3->cur->count_verh-1 && ct3->cur->brot[0]->brot[ct3->cur->number_verh]->existInBinTree == true && ct3->cur->son == NULL && ct3->cur != ct3->root ||
			ct3->cur->brot != NULL && ct3->cur->number_verh != 0 && ct3->cur->number_verh >= ct3->cur->count_verh-1 && ct3->cur->son == NULL && ct3->cur != ct3->root) //правый пройден, а левый пустой
		{ 

			ct3->cur = ct3->cur->pred;
            indBr = ct3->cur->number_verh;


		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct3->cur == ct3->root && ct3->cur->son->existInBinTree == true)  {stop = true; }
	}

	ct.UpdateBoolComNodes(ct3); //обновили пройденные вершины для следующего обхода

	textBox4->Text = Convert::ToString(masVerhsol[0]);

	for(int i = 0; i < NumSol-1; i++)
	{
		if( (i+1) < NumSol-1) {g->DrawLine(Pens::Green, masX[masVerhsol[i]]+7, masY[masVerhsol[i]]+17, masX[masVerhsol[i+1]]+8, masY[masVerhsol[i+1]]);}
	}
	

}//end Button2

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }



private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {


	BinTree bt;
	CommonTree ct;

	NumberVerh = 0; //обнуляем количество вершин
	string str;
	bt2 = bt.CreateBinTree(); //бинарное дерево из дерева общего вида

	ifstream file2("BinTree.txt"/*,ios::in*/); //чтение дерева бинарного вида из файла и создание его

   while(file2) //Для считывания дерева бинарного вида
   {

	int nVerh;
	string _dataStr;
	int *masVerh;
	int numChild = 0; //количество потомков для вершины родителя
	int leftVerh = 0; //левый потомок
	int rightVerh = 0;//правый потомок

	//string str2; //строка для взятия кусочков str
	int length2 = 0; // длина str2
	int length3 = 0, ind3;
	int length4 = 0, ind4;

	int ind = 0; //используется для подсчета потомков и в их отделении из строки
	int ind2 = 0;
	int length = 0; //длина номеров потомков

	NumberVerh++; //считаем вершины
	
    getline(file2, str);
	
	//for(int i = 0; i < str.length(); i++)
	//{
		while(str[length2] != ':' && str[length2] != ' '){ length2++; }  //получили первое слов
		ind3 = length2 + 2;
		while(str[ind3] != ' '){ length3++; ind3++; }  //получили второе слово
		ind4 = ind3 + 1;
		while(ind4 != str.length()){ length4++; ind4++; } //получили третье слово 

		/*string str3[lenght2];
		if(str[i] != ':') { str2 = str[i]; }
		else i = str.length();*/
	/*}*/
	string str2(str,0,length2); // первое слово
	string str3(str,length2 + 2,length3); //второе слово
	string str4(str,ind3 + 1,length4); //третье слово, содержащее потомков

	nVerh = stoi(str2);   //запомнили номер вершины (имя)
	_dataStr = str3; //запомнили информацию вершины


	bool comma = false;    //проверка на запятую
	bool leftdash = false; //проверка на левое тире (перед запятой)
	bool rightdash = false;//проверка на правое тире
	int numDash = 0;
	while(ind < str4.length() ) //подсчитываем количество потомков, узнав количество ','
	{
		if(str4[ind] == ','){comma = true;}
		if(str4[ind] == '-' && ind == 0){leftdash = true;}
		if(comma == true && str4[ind] == '-'){rightdash = true;}
		//if(str[str4.length()] == '-'){rightdash = true;}
		//if(str4[ind] == '-') { numDash++; }
		ind++;
	}
	//cout << " ~ " << numDash << " ~ ";


	if(comma && !leftdash && !rightdash){ numChild = 2; }		//есть левый и правый предки
	else if(comma && leftdash && !rightdash || comma && !leftdash && rightdash){ numChild = 1; } //есть 1 предок
	else if(!comma && leftdash && !rightdash){ numChild = 0; }

	if(numChild != 0)
	{
	ind = 0;
	for(int i = 0; i < numChild; i++) //разобьем строку на числа (номера потомков)
	{
		length = 0;
		if (comma && !leftdash && ind == 0) //есть запятая и есть число перед ней
		{
		  while(ind < str4.length() && str4[ind] != ','){length++; ind++;}
		  string str1(str4,0,length);
		  leftVerh = stoi(str1);   //запомнили номер первого потомка
		  ind++; //сдвигаемся вправо от ','
		}
		else if(comma && !rightdash)
		{
		 if(ind == 0){ while(ind < str4.length() && str4[ind] != ','){ind++;} ind++; } //если нет левого потомка, посчитаем индекс до запятой
		 ind2 = ind;
		 while(ind2 < str4.length()){length++; ind2++;}
		 string str1(str4,ind,length);
		 rightVerh = stoi(str1);
		}//в оставшихся случаях левого и правого нет
	}
	}

	cout << str2 << " ";
	cout << str3 << " ";
	cout << str4 << " ";

	bt.CreateBinTr(nVerh, _dataStr, leftVerh, rightVerh, bt2);
	bt.UpdateBoolBinNodes(bt2);
	cout<< " ! " <<nVerh << " " <<_dataStr << " " << leftVerh << " " << rightVerh;  cout << endl;
   };
   file2.close();

   NumberVerh -= 1; //уменьшаем счетчик на лишнюю вершину

   //Нарисуем полученное бинарное дерево
   levelVerhBin = new int[NumberVerh];
    masXBin = new int[NumberVerh];
    masYBin = new int[NumberVerh];

	bt.levelVerhBinTree(bt2, levelVerhBin, NumberVerh); //получили уровни вершин
    bt.UpdateBoolBinNodes(bt2); //обновили пройденные вершины для следующего обхода

	//нужно разбить область на уровни, где вершины располагаются на расстоянии область/вершины_на_уровне+1 и в координаты забить
   //for(int i = 0; i < NumberVerh; i++)
   //{
   //textBox4->Text += Convert::ToString(levelVerhBin[i]) + " "; //вывод
   //}
   int maxLevelBin = 1;  //определяем макс уровень для размера массива
   for(int i = 0; i < NumberVerh; i++)
   {
	   if(levelVerhBin[i] > maxLevelBin) { maxLevelBin = levelVerhBin[i];}
   }

   int *NumberlevelBin = new int[maxLevelBin];  //массив под количество уровней вершин, чтобы вычислить расстояние между ними при рисовании
   for(int i = 0; i < maxLevelBin; i++)
   {
		NumberlevelBin[i] = 0;  //проинициализировали 0 
   }

   for(int i = 0; i < maxLevelBin; i++)
   {
	   for(int j = 0; j < NumberVerh; j++)
	   {
		   if(levelVerhBin[j] == i+1) { NumberlevelBin[i]++;} //запоминаем количество вершин на каждом уровне
	   }
   }

   //for(int i = 0; i < maxLevelBin; i++)
   //{
   //textBox4->Text += Convert::ToString(NumberlevelBin[i]) + " "; //вывод
   //}

   //вычислим для каждой вершины координаты по Х в зависимости от их количества на уровне
   
   for(int i = 0; i < NumberVerh; i++)
   {
	   masXBin[i] = 0; masYBin[i] = 0;
   }
   int *masDublBin = new int [maxLevelBin]; //массив, для увеличения расстояния между вершинами на одном уровне
   for(int i = 0; i < maxLevelBin; i++)
   {
	   masDublBin[i] = 1;
   }

	  
   for(int i = 0; i < NumberVerh; i++)
   {
	   masXBin[i] = 350 / (NumberlevelBin[levelVerhBin[i]-1] + 1) + 4;

	   /*for(int j = 0; j < NumberVerh; j++)  (предыдущий вариант со 150, вычитанием расстояния, что не нужно, и с разбиением на n уровней, вместо n+1
	   {
		   if(masX[i] == masX[j] && i != 0 && masX[i] != 0 && masDubl[levelVerh[i]-1] <= Numberlevel[levelVerh[i]-1]){ masDubl[levelVerh[i]-1]+= 1; masX[i] = (150 / Numberlevel[levelVerh[i]-1] - 10) * masDubl[levelVerh[i]-1]; j = NumberVerh; }
	   }*/
	   for(int j = 0; j < i; j++)
	   {
		   if(masXBin[i] == masXBin[j] && NumberlevelBin[levelVerhBin[i]-1] != 1 && i != 0 && masXBin[i] != 0 && masDublBin[levelVerhBin[i]-1] <= NumberlevelBin[levelVerhBin[i]-1]){ masDublBin[levelVerhBin[i]-1]+= 1; masXBin[i] = 25 + (390 / (NumberlevelBin[levelVerhBin[i]-1] + 1) + 4) * masDublBin[levelVerhBin[i]-1]; j = NumberVerh; }
	   }


	   masYBin[i] = 50 * levelVerhBin[i] + 10;
   }


   //Нужно поставить вершины левее или правее родителя, для этого потребуется обойти дерево 

    bool stop = false;
    bool pred2 = false; //обход возвращается по пройденным вершинам
	bool onerigh2 = false; //после pred случился переход вправо
	bool backrigh2 = false; //для возврата к пред. индексу
	int indpredVerhBin2 = 0; //индекс предыдущей вершины в обходе при левой ветви
	int *maspredVerhBin2 = new int[NumberVerh]; //запоминает текущий индекс на левых ветвях
	for(int i = 0; i < NumberVerh; i++)
    {
	  maspredVerhBin2[i] = 0;
	} 

	int NumVerh = 0;
    int obVerhB = 0;

    bt2->cur = bt2->root;
	bt2->cur->existInComTree = true;

   while(stop != true)
   {
	   

		 if(bt2->cur->left != NULL && bt2->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		 {

			//для дерева бинарного вида
			bt2->cur = bt2->cur->left; //смена текущ на левого
			bt2->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

			maspredVerhBin2[indpredVerhBin2]++; //повышаем номер вершины
			obVerhB++;
			if(masXBin[obVerhB] == masXBin[obVerhB-1] || masXBin[obVerhB] < masXBin[obVerhB-1]-25 || masXBin[obVerhB] > masXBin[obVerhB-1] ) {masXBin[obVerhB] = masXBin[obVerhB-1] - 60;}

		 }
		 else if(bt2->cur->right != NULL && bt2->cur->right->existInComTree == false) //Правый узел != NULL 
		 {
			//для дерева бинарного вида
			bt2->cur = bt2->cur->right;  //смена текущ на правого
			bt2->cur->existInComTree = true; //вершина была добавлена в дерево общего вида

            if(onerigh2 == true) {indpredVerhBin2++; maspredVerhBin2[indpredVerhBin2] = obVerhB; onerigh2 = false;}
			if(pred2 == false) {maspredVerhBin2[indpredVerhBin2] = obVerhB; onerigh2 = false;} //если не идем обратно, то идекс по обходу
			else if(pred2 == true) {onerigh2 = true; pred2 = false;} //если идем обратно, то индекс остается
			if(masXBin[obVerhB+1] == masXBin[maspredVerhBin2[indpredVerhBin2]] || masXBin[obVerhB+1] > masXBin[maspredVerhBin2[indpredVerhBin2]]+25 || masXBin[obVerhB+1] < masXBin[maspredVerhBin2[indpredVerhBin2]] ) {masXBin[obVerhB+1] = masXBin[maspredVerhBin2[indpredVerhBin2]] + 60;}
			

			maspredVerhBin2[indpredVerhBin2]++;
			obVerhB++;
			
			
		 }
		 else if(bt2->cur->left == NULL && bt2->cur->right == NULL || //левый и правый узлы пустые
			bt2->cur->left != NULL && bt2->cur->left->existInComTree == true && bt2->cur->right != NULL && bt2->cur->right->existInComTree == true || //левый и правый пройдены
			bt2->cur->left != NULL && bt2->cur->left->existInComTree == true && bt2->cur->right == NULL && bt2->cur != bt2->root || //левый пройден, а правого пустой
			bt2->cur->right != NULL && bt2->cur->right->existInComTree == true && bt2->cur->left == NULL && bt2->cur != bt2->root) //правый пройден, а левый пустой
		 { 
			if(backrigh2 == true) { indpredVerhBin2--; backrigh2 = false;} //при двух шагах вправо к пред. вершинам сменяется индекс пройденных вершин на пред.
			if(bt2->cur->pred->right == bt2->cur && indpredVerhBin2 > 0) {backrigh2 = true;} //если был добавлен индекс левой ветви и идем по правой назад
			pred2 = true; onerigh2 = false;
			bt2->cur = bt2->cur->pred;
			maspredVerhBin2[indpredVerhBin2]--; //уменьшаем индекс, если возвращаемся к пройденным вершинам

		 } //мы поднялись к корню, т.к. все узлы заполнены
		 else if(bt2->cur == bt2->root && bt2->cur->left->existInComTree == true)  stop = true;
   }

    bt.UpdateBoolBinNodes(bt2); //обновили пройденные вершины для следующего обхода
	
	//если вершины будут совпадать
	for(int i = 0; i < NumberVerh; i++)
    {
		for(int j = 0; j < NumberVerh; j++)
		{
			if(i != j && masXBin[i] == masXBin[j] && masYBin[i] == masYBin[j]) 
			{
				masXBin[i] = masXBin[i] - 17;
				masXBin[j] = masXBin[j] + 17;
			}
			else if (i != j && (masXBin[i] - masXBin[j]) == 7 && masYBin[i] == masYBin[j])
			{
				masXBin[i] = masXBin[i] + 10;
				masXBin[j] = masXBin[j] - 10;
			}
			else if (i != j && (masXBin[i] - masXBin[j]) == -7 && masYBin[i] == masYBin[j])
			{
				masXBin[i] = masXBin[i] - 10;
				masXBin[j] = masXBin[j] + 10;
			}
		}
	}

	Graphics ^ g = pictureBox1->CreateGraphics(); 
	g->Clear(Color::White); //очистка pb1

   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox2->Text += Convert::ToString(masXBin[i]) + " "; //дополнительный контейнер для вывода
   //}
   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox3->Text += Convert::ToString(masYBin[i]) + " "; //дополнительный контейнер для вывода
   //}


   for(int i = 0; i < NumberVerh; i++)
   {
	   g->DrawEllipse(Pens::Red, masXBin[i], masYBin[i], 17, 17); //построим вершины бинарного дерева
   }


   //Построим ребра для нарисованных вершин

    bool stop2 = false;
	bool pred = false; //обход возвращается по пройденным вершинам
	bool onerigh = false; //после pred случился переход вправо
	bool backrigh = false; //для возврата к пред. индексу
	int obVerhBin = 0; //обход вершин
	int indpredVerhBin = 0; //индекс предыдущей вершины в обходе при левой ветви
	int *maspredVerhBin = new int[NumberVerh]; //запоминает текущий индекс на левых ветвях
	for(int i = 0; i < NumberVerh; i++)
    {
	  maspredVerhBin[i] = 0;
	} 
	NumVerh = 0;
	bt2->cur = bt2->root;
	bt2->cur->existInComTree = true; 
	g->DrawString(Convert::ToString(bt2->root->data), Font ,Brushes::Red, PointF(masXBin[0]+1, masYBin[0]+1));          

	while (stop2 != true)
	{
		if(bt2->cur->left != NULL && bt2->cur->left->existInComTree == false) //Левый узел != NULL и он пока не добавлен в дерево общего вида 
		 {

			//для дерева бинарного вида
			bt2->cur = bt2->cur->left; //смена текущ на левого
			g->DrawLine(Pens::Red, masXBin[obVerhBin]+7, masYBin[obVerhBin]+17, masXBin[obVerhBin+1]+8, masYBin[obVerhBin+1]);
			bt2->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			maspredVerhBin[indpredVerhBin]++; //повышаем номер вершины
			obVerhBin++;
			g->DrawString(Convert::ToString(bt2->cur->data), Font ,Brushes::Red, PointF(masXBin[obVerhBin]+1, masYBin[obVerhBin]+1));
		
		 }
		 else if(bt2->cur->right != NULL && bt2->cur->right->existInComTree == false) //Правый узел != NULL 
		 {
			//для дерева бинарного вида
			bt2->cur = bt2->cur->right;  //смена текущ на правого
			bt2->cur->existInComTree = true; //вершина была добавлена в дерево общего вида
			if(onerigh == true) {indpredVerhBin++; maspredVerhBin[indpredVerhBin] = obVerhBin; onerigh = false;}
			if(pred == false) {maspredVerhBin[indpredVerhBin] = obVerhBin; onerigh = false;} //если не идем обратно, то идекс по обходу
			else if(pred == true) {onerigh = true; pred = false;} //если идем обратно, то индекс остается
			g->DrawLine(Pens::Red, masXBin[maspredVerhBin[indpredVerhBin]]+7, masYBin[maspredVerhBin[indpredVerhBin]]+17, masXBin[obVerhBin+1]+8, masYBin[obVerhBin+1]);

			maspredVerhBin[indpredVerhBin]++;
			obVerhBin++;
			g->DrawString(Convert::ToString(bt2->cur->data), Font ,Brushes::Red, PointF(masXBin[obVerhBin]+1, masYBin[obVerhBin]+1));
			
		 }
		 else if(bt2->cur->left == NULL && bt2->cur->right == NULL || //левый и правый узлы пустые
			bt2->cur->left != NULL && bt2->cur->left->existInComTree == true && bt2->cur->right != NULL && bt2->cur->right->existInComTree == true || //левый и правый пройдены
			bt2->cur->left != NULL && bt2->cur->left->existInComTree == true && bt2->cur->right == NULL && bt2->cur != bt2->root || //левый пройден, а правого пустой
			bt2->cur->right != NULL && bt2->cur->right->existInComTree == true && bt2->cur->left == NULL && bt2->cur != bt2->root) //правый пройден, а левый пустой
		 { 
			//для дерева бинарного вида
			if(backrigh == true) { indpredVerhBin--; backrigh = false;} //при двух шагах вправо к пред. вершинам сменяется индекс пройденных вершин на пред.
			if(bt2->cur->pred->right == bt2->cur && indpredVerhBin > 0) {backrigh = true;} //если был добавлен индекс левой ветви и идем по правой назад
			pred = true; onerigh = false;
			bt2->cur = bt2->cur->pred;
			maspredVerhBin[indpredVerhBin]--; //уменьшаем индекс, если возвращаемся к пройденным вершинам

		 } //мы поднялись к корню, т.к. все узлы заполнены
		 else if(bt2->cur == bt2->root && bt2->cur->left->existInComTree == true)  stop2 = true;
	}


	bt.UpdateBoolBinNodes(bt2); //обновили пройденные вершины для следующего обхода



   //Получим дерево общего вида 
   ct2 = ct.CreateComTree(); //дерево общего вида, которое будет получено из бинарного
   ct.TransformCommonTree(bt2, ct2); //получим дерево общего вида из бинарного

   levelVerh = new int[NumberVerh];
   masX = new int[NumberVerh];
   masY = new int[NumberVerh];

   ct.levelVerhComTree(ct2, levelVerh, NumberVerh); //получили уровни вершин
   ct.UpdateBoolComNodes(ct2); //обновили пройденные вершины для следующего обхода

   //нужно разбить область на уровни, где вершины располагаются на расстоянии область/вершины_на_уровне+1 и в координаты забить
   //for(int i = 0; i < NumberVerh; i++)
   //{
   //textBox1->Text += Convert::ToString(levelVerh[i]) + " "; //вывод
   //}
   int maxLevel = 1;
   for(int i = 0; i < NumberVerh; i++)
   {
	   if(levelVerh[i] > maxLevel) { maxLevel = levelVerh[i];}
   }
   //textBox1->Text = Convert::ToString(maxLevel);   //вывод

   Numberlevel = new int[maxLevel];  //массив под количество уровней вершин, чтобы вычислить расстояние между ними при рисовании
   for(int i = 0; i < maxLevel; i++)
   {
		Numberlevel[i] = 0;  //проинициализировали 0 
   }

   for(int i = 0; i < maxLevel; i++)
   {
	   for(int j = 0; j < NumberVerh; j++)
	   {
		   if(levelVerh[j] == i+1) { Numberlevel[i]++;}
	   }
   }
   //for(int i = 0; i < maxLevel; i++)
   //{
   //textBox1->Text += Convert::ToString(Numberlevel[i]) + " ";  //вывод
   //}

   //вычислим для каждой вершины координаты по Х в зависимости от их количества на уровне
   
   for(int i = 0; i < NumberVerh; i++)
   {
	   masX[i] = 0; masY[i] = 0;
   }
   int *masDubl = new int [maxLevel]; //массив, для увеличения расстояния между вершинами на одном уровне
   for(int i = 0; i < maxLevel; i++)
   {
	   masDubl[i] = 1;
   }

   for(int i = 0; i < NumberVerh; i++)
   {
	   masX[i] = 350 + 350 / (Numberlevel[levelVerh[i]-1] + 1) + 4;

	   /*for(int j = 0; j < NumberVerh; j++)  (предыдущий вариант со 150, вычитанием расстояния, что не нужно, и с разбиением на n уровней, вместо n+1
	   {
		   if(masX[i] == masX[j] && i != 0 && masX[i] != 0 && masDubl[levelVerh[i]-1] <= Numberlevel[levelVerh[i]-1]){ masDubl[levelVerh[i]-1]+= 1; masX[i] = (150 / Numberlevel[levelVerh[i]-1] - 10) * masDubl[levelVerh[i]-1]; j = NumberVerh; }
	   }*/
	   for(int j = 0; j < i; j++)
	   {
		   if(masX[i] == masX[j] && Numberlevel[levelVerh[i]-1] != 1 && i != 0 && masX[i] != 0 && masDubl[levelVerh[i]-1] <= Numberlevel[levelVerh[i]-1]){ masDubl[levelVerh[i]-1]+= 1; masX[i] = 350 + (350 / (Numberlevel[levelVerh[i]-1] + 1) + 4) * masDubl[levelVerh[i]-1]; j = NumberVerh; }
	   }
	   masY[i] = 50 * levelVerh[i] + 10;
   }

   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox2->Text += Convert::ToString(masX[i]) + " "; //дополнительный контейнер для вывода
   //}
   //for(int i = 0; i < NumberVerh; i++)
   //{
	  // textBox3->Text += Convert::ToString(masY[i]) + " "; //дополнительный контейнер для вывода
   //}

   //Graphics^ g = Graphics::FromHwnd(this->Handle);

   for(int i = 0; i < NumberVerh; i++)
   {
	   g->DrawEllipse(Pens::Red, masX[i], masY[i], 17, 17);
   }


   //Построим ребра для нарисованных вершин

    stop = false;
	int indBr = 0;
	int obVerh = 0; //обход вершин
	int indpredVerh = 0; //индекс предыдущей вершины в обходе для братьев
	/*levelVerh = new int[NumberVerh];*/
	int *maspredVerh = new int[NumberVerh]; //массив вершин предков для братьев
	for(int i = 0; i < NumberVerh; i++)
    {
		maspredVerh[i] = -1;
	}

	ct2->cur = ct2->root;
	ct2->cur->existInBinTree = true; 
	g->DrawString(Convert::ToString(ct2->root->data), Font ,Brushes::Red, PointF(masX[0]+1, masY[0]+1));          

	while (stop != true)
	{
		if(ct2->cur->son != NULL && ct2->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{

			ct2->cur = ct2->cur->son;   //Сделали текущим son          
			g->DrawLine(Pens::Red, masX[obVerh]+7, masY[obVerh]+17, masX[obVerh+1]+8, masY[obVerh+1]);
			ct2->cur->existInBinTree = true; //сброс переменной на false
			indBr = 0; //сбрасываем счетчик братьев
			maspredVerh[indpredVerh] = obVerh;
			indpredVerh++; //добавили предка в обход
			obVerh++;
			g->DrawString(Convert::ToString(ct2->cur->data), Font ,Brushes::Red, PointF(masX[obVerh]+1, masY[obVerh]+1)); 

		}
		else if(ct2->cur->number_verh != 0 && indBr < ct2->cur->count_verh-1 && ct2->cur->brot[0]->brot[indBr] != NULL && ct2->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct2->cur = ct2->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct2->cur->existInBinTree = true; //добавлен в бинарное дерево
			g->DrawLine(Pens::Red, masX[maspredVerh[indpredVerh-1]]+7, masY[maspredVerh[indpredVerh-1]]+17, masX[obVerh+1]+8, masY[obVerh+1]);
			obVerh++;
			g->DrawString(Convert::ToString(ct2->cur->data), Font ,Brushes::Red, PointF(masX[obVerh]+1, masY[obVerh]+1)); 
		}
		else if(ct2->cur->number_verh == 0 && ct2->cur->brot != NULL && ct2->cur->brot[indBr] != NULL && ct2->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct2->cur = ct2->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct2->cur->existInBinTree = true; //добавлен в бинарное дерево
			g->DrawLine(Pens::Red, masX[maspredVerh[indpredVerh-1]]+7, masY[maspredVerh[indpredVerh-1]]+17, masX[obVerh+1]+8, masY[obVerh+1]);
			obVerh++;
			g->DrawString(Convert::ToString(ct2->cur->data), Font ,Brushes::Red, PointF(masX[obVerh]+1, masY[obVerh]+1)); 
		}
		else if(ct2->cur->son == NULL && ct2->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh >= ct2->cur->count_verh-1 || //левый и правый пройдены
			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh < ct2->cur->count_verh-1 && ct2->cur->brot[0]->brot[ct2->cur->number_verh]->existInBinTree == true||
			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot != NULL && ct2->cur->number_verh == 0 && ct2->cur->brot[ct2->cur->number_verh]->existInBinTree == true ||

			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot == NULL && ct2->cur != ct2->root || //левый пройден, а правого пустой

			ct2->cur->brot != NULL && ct2->cur->number_verh == 0 && ct2->cur->brot[ct2->cur->number_verh]->existInBinTree == true && ct2->cur->son == NULL && ct2->cur != ct2->root ||
			ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh < ct2->cur->count_verh-1 && ct2->cur->brot[0]->brot[ct2->cur->number_verh]->existInBinTree == true && ct2->cur->son == NULL && ct2->cur != ct2->root ||
			ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh >= ct2->cur->count_verh-1 && ct2->cur->son == NULL && ct2->cur != ct2->root) //правый пройден, а левый пустой
		{ 
			if(ct2->cur->pred->son == ct2->cur) {indpredVerh--;}
			ct2->cur = ct2->cur->pred;
            indBr = ct2->cur->number_verh;


		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct2->cur == ct2->root && ct2->cur->son->existInBinTree == true)  {stop = true; }
	}

	ct.UpdateBoolComNodes(ct2); //обновили пройденные вершины для следующего обхода



		 }


private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {


	BinTree bt;
	CommonTree ct;
	int *solution;
	int NumSol = 0;
	String^ solStr = textBox4->Text;
	std::string normalString = msclr::interop::marshal_as<std::string>(solStr);

	Graphics ^ g = pictureBox1->CreateGraphics();
	solution = bt.FindSolution(bt2, normalString);
	
	//textBox4->Text = Convert::ToString(solution[2]);

	NumSol = solution[0];

	
    bool stop = false;
	int indBr = 0;
	int obVerh = 0; //обход вершин
	int indsolVerh = 1; //индекс предыдущей вершины в обходе для братьев
	/*levelVerh = new int[NumberVerh];*/
	int *masVerhsol = new int[NumSol-1]; //для запоминания номеров в обходе

	ct.UpdateBoolComNodes(ct2); //обновили пройденные вершины для следующего обхода

	ct2->cur = ct2->root;
	ct2->cur->existInBinTree = true;           
	g->DrawEllipse(Pens::Green, masX[0]-1, masY[0]-1, 17.5, 17.5);
	g->DrawEllipse(Pens::Green, masX[0], masY[0], 17.5, 17.5);
	g->DrawEllipse(Pens::Green, masX[0], masY[0], 17.7, 17.7);
	g->DrawEllipse(Pens::Green, masX[0]-1, masY[0]-1, 17.3, 17.3);

	masVerhsol[0] = 0; //записали корень, который войдет в конец решения

	while (stop != true)
	{
		if(ct2->cur->son != NULL && ct2->cur->son->existInBinTree == false) //Son != NULL и не был добавлен
		{

			ct2->cur = ct2->cur->son;   //Сделали текущим son          
			ct2->cur->existInBinTree = true; //сброс переменной на false
			indBr = 0; //сбрасываем счетчик братьев
			for(int i = 1; i < NumSol; i++)
			{
			  if(ct2->cur->data == solution[i]) 
			  {
				  g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.7, 17.7);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.3, 17.3);
			  
			      masVerhsol[indsolVerh] = obVerh+1;
			      indsolVerh++;
			  }
			}
			
			obVerh++;

		}
		else if(ct2->cur->number_verh != 0 && indBr < ct2->cur->count_verh-1 && ct2->cur->brot[0]->brot[indBr] != NULL && ct2->cur->brot[0]->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct2->cur = ct2->cur->brot[0]->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct2->cur->existInBinTree = true; //добавлен в бинарное дерево
			for(int i = 1; i < NumSol; i++)
			{
			  if(ct2->cur->data == solution[i]) 
			  {
				  g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.7, 17.7);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.3, 17.3);
			  
			      masVerhsol[indsolVerh] = obVerh+1;
			      indsolVerh++;
			  }
			}
			obVerh++;
		}
		else if(ct2->cur->number_verh == 0 && ct2->cur->brot != NULL && ct2->cur->brot[indBr] != NULL && ct2->cur->brot[indBr]->existInBinTree == false) //brot[] != NULL и не был добавлен
		{
			ct2->cur = ct2->cur->brot[indBr]; //заполнили правого под номером number_verh
			indBr += 1;
			ct2->cur->existInBinTree = true; //добавлен в бинарное дерево
			for(int i = 1; i < NumSol; i++)
			{
			  if(ct2->cur->data == solution[i]) 
			  {
				  g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.5, 17.5);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1], masY[obVerh+1], 17.7, 17.7);
	              g->DrawEllipse(Pens::Green, masX[obVerh+1]-1, masY[obVerh+1]-1, 17.3, 17.3);
			  
			      masVerhsol[indsolVerh] = obVerh+1;
			      indsolVerh++;
			  }
			}
			obVerh++;
		}
		else if(ct2->cur->son == NULL && ct2->cur->brot == NULL || //son и brot узлы пустые  можно поставить на != NULL конкрентого брата
			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh >= ct2->cur->count_verh-1 || //левый и правый пройдены
			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh < ct2->cur->count_verh-1 && ct2->cur->brot[0]->brot[ct2->cur->number_verh]->existInBinTree == true||
			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot != NULL && ct2->cur->number_verh == 0 && ct2->cur->brot[ct2->cur->number_verh]->existInBinTree == true ||

			ct2->cur->son != NULL && ct2->cur->son->existInBinTree == true && ct2->cur->brot == NULL && ct2->cur != ct2->root || //левый пройден, а правого пустой

			ct2->cur->brot != NULL && ct2->cur->number_verh == 0 && ct2->cur->brot[ct2->cur->number_verh]->existInBinTree == true && ct2->cur->son == NULL && ct2->cur != ct2->root ||
			ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh < ct2->cur->count_verh-1 && ct2->cur->brot[0]->brot[ct2->cur->number_verh]->existInBinTree == true && ct2->cur->son == NULL && ct2->cur != ct2->root ||
			ct2->cur->brot != NULL && ct2->cur->number_verh != 0 && ct2->cur->number_verh >= ct2->cur->count_verh-1 && ct2->cur->son == NULL && ct2->cur != ct2->root) //правый пройден, а левый пустой
		{ 

			ct2->cur = ct2->cur->pred;
            indBr = ct2->cur->number_verh;


		} //мы поднялись к корню, т.к. все узлы пройдены 
		else if(ct2->cur == ct2->root && ct2->cur->son->existInBinTree == true)  {stop = true; }
	}


	ct.UpdateBoolComNodes(ct2); //обновили пройденные вершины для следующего обхода

	textBox4->Text = Convert::ToString(masVerhsol[0]);

	for(int i = 0; i < NumSol-1; i++)
	{
		if( (i+1) < NumSol-1) {g->DrawLine(Pens::Green, masX[masVerhsol[i]]+7, masY[masVerhsol[i]]+17, masX[masVerhsol[i+1]]+8, masY[masVerhsol[i+1]]);}
		//g->DrawLine(Pens::Green, masX[masVerhsol[i]]+7, masY[masVerhsol[i]]+17, masX[masVerhsol[i+1]]+8, masY[masVerhsol[i+1]]);
	}



}//end Button4





};
}
