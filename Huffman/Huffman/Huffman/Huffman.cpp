#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string> 
#include <fstream>

using namespace std;
//Программа сначала зашифровывает картинку, потом берёт зашифрованный файл и расшифровывает.
// Елизаров, ПР-20

class Node
{
	public:
		int a;
		char c;
	Node *left, *right;

	Node() {
		left = right = NULL;
	}

	Node(Node *L, Node *R) {
		left = L;
		right = R;
		a = L->a + R->a;
	}
};

struct  MyCompare
{
	bool operator()(const Node* l, const Node* r)const {
		return l->a < r->a;
	}
};

/*void print(Node* root, unsigned k = 0) { //рекурсиввно строит дерево
	if (root != NULL) {
		print(root->left, k + 3);
		for (unsigned i = 0; i < k; i++) {
			cout << "  ";
		}

		if (root->c) cout << root->a << " (" << root->c << ")" << endl;
		else cout << root->a << endl;
		print(root->right, k + 3);
	}

}*/

vector<bool> code;
map<char, vector<bool>> table;

void BuildTable(Node *root) { //рекурсиввно вставляет в мап построенный по узлу код
	
	if (root->left != NULL) {
		code.push_back(0);
		BuildTable(root->left);
	}
	if (root->right != NULL) {
		code.push_back(1);
		BuildTable(root->right);
	} 
	if (root->c) {
		table[root->c] = code;
	}
	if (code.size() > 0)
		code.pop_back();
}

int main() 
{
	ifstream f("../../Step1.txt");
	
	map<char, int> m;//Обьявляем мап
	map<char, int>::iterator i;

	while (!f.eof()) { //считываем строку в мап
		char c;
		c= f.get();
		m[c]++;
	}

	list<Node*> t;//Создаём класс и лист указателей на этот класс
	for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr) {
		Node *p = new Node;
		p->c = itr->first;
		p->a = itr->second;
		t.push_back(p);
	}

	while (t.size() != 1) { //Посредством структкры делаем из первых двух элементов указатели на потомков и вычёркиваем их из листа, парента вставляем.
		t.sort(MyCompare());

		Node *SonL = t.front();
		t.pop_front();
		Node *SonR = t.front();
		t.pop_front();

		Node *parent = new Node(SonL, SonR);
		t.push_back(parent);
	}
	
	Node *root = t.front();

	//print(root);
	BuildTable(root);


	f.clear();
	f.seekg(0);
	while(!f.eof()) {
		char c;
		c = f.get();
		vector<bool> x = table[c];

		for (int n = 0; n < x.size(); n++)
			cout << x[n];
	}
	ofstream g("../../step2.lxs"); //Пишем шифр в файл

	int count = 0; char buf = 0;

	f.clear();
	f.seekg(0);
	while (!f.eof()) { 
		char c;
		c = f.get();
		vector<bool> x = table[c];

		for (int n = 0; n < x.size(); n++) {
			buf = buf | x[n]<<(7 - count);
			count++;
			if (count == 8) {
				count = 0;
				g << buf; buf = 0;
			}
		}
	}
	/*for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		vector<bool> x = table[c];

		for (int n = 0; n < x.size(); n++)
			cout << x[n];
	}*/
	g.close();
	f.close();
	//Начинаем расшифровывать

	ifstream F("../../Step2.lxs");
	ofstream T("../../Step3.txt");

	Node *p = root;
	count = 0; char byte;
	F >> byte;
	vector<bool> vec;
	while (!F.eof()) {
		bool b = byte & (1 << (7-count));
		if (b) p = p->right; else p = p->left;
		if (p->left == NULL && p->right == NULL) { T << p->c; p = root; }
		count++;
		if (count == 8) { count = 0; F >> byte;}
	}


	T.close();

	return 0;
}
/*
	list<int> L;
list<int>::iterator itr1;
L.push_front(34);
L.push_back(134);
L.pop_back();
L.pop_front();
for (itr1 = L.begin; itr1 != L.end(); itr1++) {
	cout << *itr1 << endl;

vector<int> x(10);
vector<int>::iterator itr;
x.push_back(34);
x.push_back(134);
x.push_back(3142);
x.push_back(124);
for (itr = x.begin; itr != x.end(); itr++) {
	cout << *itr << endl;

Class AAA(){
	AAA(int num, char ch){
	a = num;
	c = ch;
	}

	bool operaror<(AAA t) const{
	return a < t.a; // помогает делать sort по а
	}
}
*/
