#include<bits/stdc++.h>
using namespace std;
//大数运算 2
//大数减法
int c[1000]; 		//存储最后的结果
bool compareLength(string a, string b){ 	//判断 a 和 b的长度 长的做被减数 短的做减数 
 	if(a.size() > b.size()) 
 		return true;
 	else if(a.size() < b.size())
 		return false;
 	else{
  		for(int i = 0; i < a.size(); ++i){
  	 		if(a[i] > b[i]) 
  	 			return true;
   			else if(a[i] < b[i]) 
   				return false;
  		}
  	return true;//如果a的长度==b的长度返回true   
 	
	}					// 总体就是 ： a>=b true   a<b false
}
void solve(string a, string b){ 	//参数是长字符串的在前，短的在后 
 	reverse(a.begin(), a.end());
 	reverse(b.begin(), b.end());
 	int d = 0;
 	memset(c, 0, sizeof(c));
 	for(int i=0; i<b.size(); ++i){ // 先让结果的长度到达短的，b.size(), 因为string的长度只有输入的那么长 
  		if(a[i] - b[i] < 0){  		//  如果直接到达a.size()，会有减不了的数,比如: 314 
   			c[d] += a[i] - b[i] + 10;//             -12  那个4就减不了  
   			c[d+1] -= 1;
   			d++;
  		}
  		else c[d++] = a[i] - b[i];
 	}
 	for(int i=b.size(); i<a.size(); ++i){
  		c[d++] += a[i] - '0'; //在从b.size() ,一直到 a.size()，把结果全部储存完毕 
 	}
}

int main(){
	string a, b;
 	while(cin>>a>>b){
	  	if(x(a,b)){ //如果a>=b ,返回true ,否则返回false 
	   		solve(a,b);
	   		int len;
	   		if(c[a.size()-1]==0){ // 比如123 
	    		len=a.size()-2;  //    -  33  == 090 所以判断最后一个数是否为0 如果为0，则不要这个数 
	   		}
	   		else len=a.size()-1;
	   		for(int i=len; i>=0; --i){
	   			printf("%d",c[i]);
	   		}
		}
	  	else{
	   		solve(b,a);
	   		int len;
	   		if(c[b.size()-1]==0){
	    		len=b.size()-2;
	   		}
	   		else  len=b.size()-1;
	   		for(int i=len; i>=0; --i){
	   			printf("%d",c[i]);
	   		}
		}
	  	printf("\n");
 	}
	return 0;
} 
