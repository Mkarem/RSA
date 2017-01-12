#include"Header.h"
#include<iostream>
using namespace std;
void main()
{
	biginteger x ("34");
	biginteger y  ("13");
	biginteger ob  (y);
	biginteger w;
	pair<biginteger,biginteger> u;
	u=w.div(x,y,ob);
	cout<<u.first<<endl;
	cout<<u.second<<endl;
	
}