#include "pch.h";
#include <string>; 
#include <vector>;
#include <iostream>;
#include <stack>;
using namespace std;


string Str;
string Mas[35];
string Mas2[sizeof(Mas)];
stack <string> StackOps;

 void StackPush(string Str) {
	string ch;
	int k = Str.length();
	int n = 0;
	for (int i = 0; i < k; i++) {	
		if (Str[i] == '*' || Str[i] == '-' || Str[i] == '+' || Str[i] == '/' || Str[i] == '(' || Str[i] == ')' || Str[i] == '^')
		{
			ch = Str[i];
			if (StackOps.empty() == true) 
			{
				StackOps.push(ch);
				continue;
			}
			else if (Str[i] == '^') {
				if (StackOps.top()[0] == '(')
				{
					StackOps.push(ch);
					continue;
				}
				while (!StackOps.empty())
				{
					if (StackOps.top()[0] != '(') {
						Mas[n] += StackOps.top();
						StackOps.pop();
						n++;
					}
					if (!StackOps.empty()) StackOps.pop();
				}
			}
			else if (Str[i] == '+' || Str[i] == '-') 
			{
				if (StackOps.top()[0] == '(') 
				{
					StackOps.push(ch);
					continue;
				}
				while (!StackOps.empty())
				{
					if (StackOps.top()[0] != '(') {
					Mas[n] += StackOps.top();
					StackOps.pop();
					n++;
					}
					if(!StackOps.empty()) StackOps.pop(); 				
				}
			}
			else if((Str[i] == '*' || Str[i] == '/') && ( StackOps.top()[0] == '*' || StackOps.top()[0] == '/'))
			{
				if (StackOps.top()[0] == '(')
				{
					StackOps.push(ch);
					continue;
				}
				Mas[n] = StackOps.top();
				StackOps.pop();
				n++;
			}
			else if ((Str[i] == '*' || Str[i] == '/') && (StackOps.top()[0] == '*' || StackOps.top()[0] == '/'))
			{
				if (StackOps.top()[0] == '(')
				{
					StackOps.push(ch);
					continue;
				}
				Mas[n] = StackOps.top();
				StackOps.pop();
				n++;
			}
			else if (Str[i] == ')')
			{
				do
				{					
					if (StackOps.top()[0] == '(') {
						StackOps.pop();
						n++;
						break;
					}
					Mas[n++] += StackOps.top();
					StackOps.pop();

				} while (!StackOps.empty());
				n--;
				continue;
			}
			StackOps.push(ch);
			n++;
			continue;
		} //для символов
		if (Str[i] != '(' && Str[i] != ')') 
		{
			if (Str[i + 1] != '+' && Str[i + 1] != '-' && Str[i + 1] != '*' && Str[i + 1] != '/'  &&  Str[i + 1] != ')' &&  Str[i + 1] != '(' &&  Str[i + 1] != '^') { //для операндов
				Mas[n] += Str[i];
			}
			else if (Str[i + 1] == '+' || Str[i + 1] == '-' || Str[i + 1] == '*' || Str[i + 1] == '/' ||  Str[i + 1] != ')' ||  Str[i + 1] != '(' || Str[i + 1] == '^') {
				Mas[n] += Str[i];
				n++;
			}
		
		}

	}

	
	while (StackOps.empty() == false)
	{
		if (StackOps.top()[0] == '(') {
			StackOps.pop();
			continue;
		}
		Mas[++n] = StackOps.top();
		StackOps.pop();
	}
} 

string NoSpaces(string Str) 
{
	string xstr;
	for (int i = 0; i < Str.length(); i++) 
	{
		if (Str[i] != ' ') 
		{
			xstr += Str[i];
		}
	}
	return(xstr);
}

void StackShow() 
{
	if (Str[0] == '-') {
		cout << Mas2[0];
	}
	else cout << Mas2[1];
}

void Answer() 
{
	int k = 1;
	int x = 1;
	Mas2[0] = to_string(0);
	int z;
	for (int n = 0; n < 35; n++)
	{
		if (Mas[n][0] != '*' && Mas[n][0] != '-' && Mas[n][0] != '+' && Mas[n][0] != '/' && Mas[n][0] != ' ' && Mas[n][0] != NULL && Mas[n][0] != '^') {
			Mas2[k] = Mas[n];
			x = k++;
		}
		else {
			if (Mas[n][0] == '*') {
				Mas2[x - 1] =  to_string( stoi(Mas2[x - 1]) * stoi(Mas2[x])); 
				k--;
				x--;
			}
			else if (Mas[n][0] == '/') {
				Mas2[x - 1] = to_string(stoi(Mas2[x - 1]) / stoi(Mas2[x]));
				k--;
				x--;
			}
			else if (Mas[n][0] == '+') {
				Mas2[x - 1] = to_string(stoi(Mas2[x - 1]) + stoi(Mas2[x]));
				k--;
				x--;
			}
			else if (Mas[n][0] == '-') {
				Mas2[x - 1] = to_string(stoi(Mas2[x - 1]) - stoi(Mas2[x]));
				k--;
				x--;
			}
			else if (Mas[n][0] == '^') {
				int u = stoi(Mas2[x - 1]);
				for (int j = 0; j < stoi(Mas2[x]); j++) {
				Mas2[x - 1] = to_string(u * u);
				}
				k--;
				x--;
			}
		}
	}
}

int main()
{
	getline(cin, Str);
	Str = NoSpaces(Str);
	Str += ' ';
	StackPush(Str);
	Answer();
	StackShow();
};



//(6+10-4)/(1+1*2)+1
//(1+2)^2
//2^2^2
