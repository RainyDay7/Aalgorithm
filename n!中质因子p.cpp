#include<bits/stdc++.h>
using namespace std;

//����n�����ж��ٸ�������p  
//O(logn) �ȼ���n/p +n/p^2+n/p^3���� 
int cal(int n, int p){
	 int ans = 0;
	 while(n){
	 	ans+=n/p;//�ۼ�n/p^k 
	 	n/=p;//�൱�ڷ�ĸ���һ��p 
	 }
} 

int cal2(int n, int p){
	if(n<p) return 0;
	return n/p+cal(n/p,p);
} 

int main(){
	
	return 0;
} 
