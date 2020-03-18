#include<bits/stdc++.h>
using namespace std;
//大数运算 2
//大数浮点减法
//逐位相乘处理进位法  乘积是逐位相乘，也就是aibj，结果加入到积C的第i+j位，最后处理进位即可

string res_str;
string a,b;


void multiply(vector<int> &res) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i=0;i<a.size(); i++){
		for(int j=0; j<b.size(); j++)
			res[i+j] += (a[i]-'0')*(b[j]-'0');
	}
	for(int i=res.size()-1; i>=0; i--){
		if(res[i]!=0){
			break;
		}
		else res.pop_back();
	}
	int c=0;//进位 
	for(int i=0; i<res.size(); i++){
		res[i]+=c;
		c = res[i]/10;
		res[i]  = res[i]%10;
	}
	if(c!=0){
		res.push_back(c);
	}
}

void numToString(vector<int> &res){
	int size=res.size();  
    for (int i=0;i<res.size();i++)  
    {  
        res_str.push_back(char(res[size-1-i]+'0'));  
    }  
}

int main(){
	cin>>a>>b;
	vector<int> res(a.size()+b.size(),0);  
	multiply(res);  
    numToString(res);  
    cout<<res_str<<endl;
    return 0;
}
