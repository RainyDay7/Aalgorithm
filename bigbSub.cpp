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

bign sub(bign a,bign b){
	bign c;
	for(int i=0; i<a.len||i<b.len; i++){
		if(a.d[i]<b.d[i]){//������ 
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++] = a.d[i]-b.d[i];
	} 
	while(c.len-1>=1 && c.d[c.len-1] == 0){
		c.len--;//ȥ����λ��0��ͬʱ���ٱ���һλ���λ 
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
	scanf("%s%s", s1,s2);
	bign a = change(s1);
	bign b = change(s2);
	int flag = compare(a,b);
	if(flag==-1) {
		printf("-");
		print(sub(b,a));
	}
	else if (flag==0) printf("0"); 
	else print(sub(a,b));
	return 0;
}
