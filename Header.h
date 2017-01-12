#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
class biginteger
{
	string bigint;
public:
	biginteger();
	biginteger(string);
	int prepair(string& , string&,int);
	biginteger addition(string,string);
	biginteger subtraction(string,string);
	pair<biginteger,biginteger> div(biginteger ,biginteger ,biginteger);
	bool less(string,string);
	biginteger operator+(biginteger&const);
	biginteger operator-(biginteger&const);
	void check();
	void operator=(biginteger&const);
	bool operator==(biginteger&const);
	bool operator< (biginteger );
	bool operator> (biginteger );
	friend	ostream&   operator<<(ostream& ,biginteger&const);
	friend  istream&   operator>>(istream&, biginteger&);
};

