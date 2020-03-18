#include<bits/stdc++.h>
using namespace std;
//大数运算 2
//大数浮点减法
//逐位相乘处理进位法  乘积是逐位相乘，也就是aibj，结果加入到积C的第i+j位，最后处理进位即可

string res_str;
string a,b;


void multiply() {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int c=0;
	string temp(a.size()+b.size(),'0'); //将temp全部初始化为0字符  
	for(int i=0;i<a.size(); i++){
		int j=0;
		for( j=0; j<b.size(); j++){
			c+=temp[i+j]-'0'+(a[i]-'0')*(b[j]-'0');
			temp[i+j] = c%10+'0';
			c = c/10;
		}
		while(c){
			temp[i+j]+=c%10;
			c/=10;
			j++;
		}
	}
	for(int i=temp.size()-1; i>=0; i--){
		if(temp[i]!=0){
			break;
		}
		else temp.erase(temp.end()-1);
	}
	reverse(temp.begin(), temp.end());
	cout<<temp;
}



int main(){
	cin>>a>>b;
	multiply();  
    
    return 0;
}
