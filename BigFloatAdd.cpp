#include<bits/stdc++.h>
using namespace std;
//大数运算 2
//大数浮点加法
string b,b2,e,e2,b1,e1;

string add(string s1,string s2)
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

void fl(string s)  // 将浮点数拆分为整数部分和小数部分
{
	int loc = s.find('.',0);
	if( loc != string::npos ){
		b = s.substr(0, loc);
		e = s.substr(loc+1, s.length()-loc-1);
		cout<<b<<" "<<e<<endl;
	}
}

int main()
{
    string a,c,s1,s2,s3,s;
    int i;
    while(cin>>a>>c)
    {
        s="";
        fl(a);
        b1=b;
        e1=e;
        fl(c);
        b2=b;
        e2=e;
        s1=add(b1,b2); // 整数部分的加法
        if(e1.size()<e2.size())   // 将小数处理为长度相同的字符用0填补不影响结果
        {
            for(i=e1.size(); i<e2.size(); i++)
                e1+='0';
        }
        if(e1.size()>e2.size())
        {
            for(i=e2.size(); i<e1.size(); i++)
                e2+='0';
        }
        s2=add(e1,e2);  // 小数部分的加法
        if(s2.size()==e2.size() || s2.size()==e1.size())  // 小数部分相加不需要进位的链接
            s=s1+'.'+s2;
        else
        {
            s3=s2[0];  //需要进位的链接
            s=add(s1,s3)+'.';
            for(i=1; i<s2.size(); i++)
                s+=s2[i];
        }
        int pos=s.size()-1;
        for(i=s.size()-1; i>=0; i--)  //去除后倒零 小数后全部为 零时小数点也应该去掉
        {
            if(s[i]=='0')
                pos=i-1;
            else  if(s[i]=='.')
            {
                pos=i-1;
                break;
            }
            else if(s[i]!='0')
                break;
        }
        int pos1=0;
        for(i=pos1; i<=pos; i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}

