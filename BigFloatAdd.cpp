#include<bits/stdc++.h>
using namespace std;
//�������� 2
//��������ӷ�
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
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //ע��ϸ��
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}

void fl(string s)  // �����������Ϊ�������ֺ�С������
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
        s1=add(b1,b2); // �������ֵļӷ�
        if(e1.size()<e2.size())   // ��С������Ϊ������ͬ���ַ���0���Ӱ����
        {
            for(i=e1.size(); i<e2.size(); i++)
                e1+='0';
        }
        if(e1.size()>e2.size())
        {
            for(i=e2.size(); i<e1.size(); i++)
                e2+='0';
        }
        s2=add(e1,e2);  // С�����ֵļӷ�
        if(s2.size()==e2.size() || s2.size()==e1.size())  // С��������Ӳ���Ҫ��λ������
            s=s1+'.'+s2;
        else
        {
            s3=s2[0];  //��Ҫ��λ������
            s=add(s1,s3)+'.';
            for(i=1; i<s2.size(); i++)
                s+=s2[i];
        }
        int pos=s.size()-1;
        for(i=s.size()-1; i>=0; i--)  //ȥ������ С����ȫ��Ϊ ��ʱС����ҲӦ��ȥ��
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

