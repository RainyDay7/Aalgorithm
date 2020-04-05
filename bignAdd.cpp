#include<bits/stdc++.h>
using namespace std;
struct bign{
	int d[1000];
	int len;
	bign(){//在结构体内部加上构造函数 
		memset(d,0,sizeof(d));
		len=0;
	}
}; 

bign change(char str[]){//将输入的整数字符串转换为bign
	bign a;
	a.len = strlen(str);
	for(int i=0; i<a.len;i++){
		a.d[i] = str[a.len-i-1]-'0';//逆着赋值 
	} 
	return a; 
} 

int compare(bign a, bign b){//比较a和b的大小，a>b  1, a<b -1, a==b 0;
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	for(int i=a.len-1; i>=0; i--){
		if(a.d[i]>b.d[i]) return 1;
		else if(a.d[i]<b.d[i]) return -1;
	}
	return 0;
}

bign add(bign a,bign b){
	bign c;
	int carry=0;//进位
	for(int i=0; i<a.len||i<b.len; i++){
		int temp = a.d[i]+b.d[i]+carry;
		c.d[c.len++] = temp%10;
		carry /=10;
	} 
	if(carry!=0){
		c.d[c.len++]=carry;
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
	print(add(a,b));
	return 0;
}
