#include<bits/stdc++.h>
using namespace std;
//大数运算 
//大数加法

string bigAdd1(string a, string b){
	int i = a.size()-1; 
	int j = b.size()-1;
	int cnt = 0;
	string res = "";
	for(; i>=0 && j>=0; i--,j--){
		int x = a[i]-'0';
		int y = b[j]-'0';
		res+=char((x+y+cnt)%10+'0');
		cnt = (x+y+cnt)/10;
	}
	while(i>=0){
		int x = a[i--]-'0';
		res+=char((x+cnt)%10+'0');
		cnt = (x+cnt)/10;
	}
	while(j>=0){
		int y = b[j--]-'0';
		res+=char((y+cnt)%10+'0');
		cnt = (y+cnt)/10;
	}
	if(cnt) res+=char(cnt+'0');
	reverse(res.begin(), res.end());
	return res;
}


string bigAdd2(string s1,string s2)
{
	if(s1.length()<s2.length())
	{
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	int i,j;
	for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}


int main(){
	string a,b;
	cin>>a>>b;
	string res = bigAdd1(a,b);
	cout<<res;
	res = bigAdd2(a,b);
	cout<<res;
	return 0;
}
