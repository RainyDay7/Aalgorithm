#include<bits/stdc++.h>
using namespace std;
//�������� 2
//��������
int c[1000]; 		//�洢���Ľ��
bool compareLength(string a, string b){ 	//�ж� a �� b�ĳ��� ������������ �̵������� 
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
  	return true;//���a�ĳ���==b�ĳ��ȷ���true   
 	
	}					// ������� �� a>=b true   a<b false
}
void solve(string a, string b){ 	//�����ǳ��ַ�������ǰ���̵��ں� 
 	reverse(a.begin(), a.end());
 	reverse(b.begin(), b.end());
 	int d = 0;
 	memset(c, 0, sizeof(c));
 	for(int i=0; i<b.size(); ++i){ // ���ý���ĳ��ȵ���̵ģ�b.size(), ��Ϊstring�ĳ���ֻ���������ô�� 
  		if(a[i] - b[i] < 0){  		//  ���ֱ�ӵ���a.size()�����м����˵���,����: 314 
   			c[d] += a[i] - b[i] + 10;//             -12  �Ǹ�4�ͼ�����  
   			c[d+1] -= 1;
   			d++;
  		}
  		else c[d++] = a[i] - b[i];
 	}
 	for(int i=b.size(); i<a.size(); ++i){
  		c[d++] += a[i] - '0'; //�ڴ�b.size() ,һֱ�� a.size()���ѽ��ȫ��������� 
 	}
}

int main(){
	string a, b;
 	while(cin>>a>>b){
	  	if(x(a,b)){ //���a>=b ,����true ,���򷵻�false 
	   		solve(a,b);
	   		int len;
	   		if(c[a.size()-1]==0){ // ����123 
	    		len=a.size()-2;  //    -  33  == 090 �����ж����һ�����Ƿ�Ϊ0 ���Ϊ0����Ҫ����� 
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
