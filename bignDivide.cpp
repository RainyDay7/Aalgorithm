 
#include<bits/stdc++.h>
using namespace std;
struct bign{
	int d[1000];
	int len;
	bign(){//�ڽṹ���ڲ����Ϲ��캯�� 
		memset(d,0,sizeof(d));
		len=0;
	}
}; 

bign change(char str[]){//������������ַ���ת��Ϊbign
	bign a;
	a.len = strlen(str);
	for(int i=0; i<a.len;i++){
		a.d[i] = str[a.len-i-1]-'0';//���Ÿ�ֵ 
	} 
	return a; 
} 

int compare(bign a, bign b){//�Ƚ�a��b�Ĵ�С��a>b  1, a<b -1, a==b 0;
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	for(int i=a.len-1; i>=0; i--){
		if(a.d[i]>b.d[i]) return 1;
		else if(a.d[i]<b.d[i]) return -1;
	}
	return 0;
}
//�߾�����;��ȵĳ��� 
bign divide(bign a, int b, int &r){//�߾��ȳ��� rΪ���� 
	bign c;
	c.len= a.len;
	for(int i=a.len-1; i>=0;i--){
		r = r*10+a.d[i];
		if(r<b) c.d[i]=0;
		else{
			c.d[i] = r/b;
			r = r%b;
		}
	} 
	while(c.len-1>=1 && c.d[c.len-1]==0){
		c.len--;
	}
	return c;
}

void print(bign a){
	for(int i=a.len-1; i>=0;i--){
		printf("%d",a.d[i]);
	}
}

int main(){
	char s1[100], s2[100];
	scanf("%s", s1);
	bign a = change(s1);
	int b;
	scanf("%d", &b);
	int r=0;
	print(divide(a,b,r));
	return 0;
}
