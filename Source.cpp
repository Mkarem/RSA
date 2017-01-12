#include"Header.h"
biginteger::biginteger()
{
	bigint="";
}
biginteger::biginteger(string s)
{
	bigint=s;
}
int biginteger::prepair(string&_x , string&_y,int check)
{
	reverse(_x.begin(),_x.end());
	reverse(_y.begin(),_y.end());
	int n1=max(_x.size(),_y.size());
	int n2=min(_x.size(),_y.size());
	if (_x.size()>_y.size())
	{
		for (int i = n2; i < n1; i++)
			_y+="0";
	}
	else if(_x.size()<_y.size())
	{
		for (int i = n2; i < n1; i++)
			_x+="0";
	}
	if (check)
	{
		if (_x[_x.size()-1]<_y[_y.size()-1])
		{
			string tmp=_x;
			_x=_y;
			_y=tmp;
			return 1;
		}
	}
	else
		return 0;
}
biginteger biginteger::addition(string x,string y)
{
	prepair(x,y,0);
	int size=x.size();
	int sum,carry=0;
	biginteger result;
	for (int i=0 ;  i <=size-1  ; i++)
	{
		sum=(x[i]-'0') + (y[i]-'0')+carry;
		if (sum >= 10)
		{
			carry=1;
			sum%=10;
			result.bigint+=to_string(sum);
		}
		else
		{		
			result.bigint+=to_string(sum);
			carry=0;			
		}
		if(i==size-1&&carry==1)
			result.bigint+=to_string(carry);
	}	
	reverse(result.bigint.begin(),result.bigint.end());
	return result;
}
biginteger biginteger::subtraction(string x,string y)
{	
	int swaped=prepair(x,y,1);
	int size=x.size();
	int sub;
	biginteger result;
	for (int i=0;i<=size-1;i++)
	{
		if((x[i]-'0')<(y[i]-'0'))
		{
			x[i]+=10;
			x[i+1]-=1;
			sub=(x[i]-'0')-(y[i]-'0');
			result.bigint+=to_string(sub);
		}
		else
		{				
			sub=x[i]-y[i];
			result.bigint+=to_string(sub);
		}	
	}
	if (swaped)
	{
		result.bigint+='-';
		reverse(result.bigint.begin(),result.bigint.end());
	}
	else
		reverse(result.bigint.begin(),result.bigint.end());

	return result;
}
bool biginteger::operator< (biginteger b)
{
	int i=0;
	if (bigint[i] < b.bigint[i])
		return true;
	else if (bigint[i] = b.bigint[i])
		i++;
	else 
		return false;
}
bool biginteger:: operator> (biginteger b)
{
	int i=0;
	if (bigint[i] >  b.bigint[i])
		return true;
	else if (bigint[i] = b.bigint[i])
		i++;
	else 
		return false;
}

pair<biginteger,biginteger> biginteger::div(biginteger a,biginteger b,biginteger ob)
{
	pair<biginteger,biginteger> qr;
	biginteger q,n;
	if (a.bigint < b.bigint)
	{
		qr.first.bigint="0";
		qr.second=a;
		return qr;
	}
	else
	{
		pair<biginteger,biginteger> u;
	    u=div(a,b+b,ob);
		n.bigint=u.second.bigint;
		q.bigint=u.first.bigint;
		
		if (ob > n)
		{
			return qr;
		}
		else
		{
			q.bigint= q.bigint+"1";
			qr.first=q;
			biginteger y= (n,ob);
			qr.second=n;
			return qr;
		}
	}
}
biginteger biginteger::operator+(biginteger& const a)
{
	return addition(this->bigint,a.bigint);
}
biginteger biginteger::operator-(biginteger& const s)
{
	return subtraction(this->bigint,s.bigint);
}
void biginteger::operator=(biginteger& const e)
{
	this->bigint=e.bigint;
}
bool biginteger::operator==(biginteger&const eq)
{
	if (this->bigint==eq.bigint)
		return true;
	else
		return true;
}
void biginteger::check()
{
	int i=this->bigint[this->bigint.size()-1];
	if (i%2==0)
		cout<<"even"<<endl;
	else
		cout<<"odd"<<endl;
}
ostream& operator<<(ostream& out , biginteger& const res)
{
	out<<res.bigint<<endl;
	return out;
}
istream& operator>>(istream& in ,   biginteger&  s)
{
	in>>s.bigint;
	return in;

}