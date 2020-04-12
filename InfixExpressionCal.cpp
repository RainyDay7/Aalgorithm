//简单计算器
//若op的优先级>栈顶的操作符，压入
//若op的优先级<栈顶的操作符,弹出栈顶，直到op>栈顶 

#include<bits/stdc++.h>
using namespace std;

struct node{
	double num;
	char op;
	bool flag;//true表示操作数，false 表示操作符 
};

string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char, int> op;

void change(){//将中缀表达式转换成后缀表达式
	double num;
	node temp;
	for(int i=0; i<str.length();){
		if(str[i]>='0' && str[i]<='9'){//如果是数字
			temp.flag = true;
			temp.num = str[i++]-'0';
			while(i<str.length() && str[i]>='0' && str[i]<='9'){
				temp.num = temp.num*10+(str[i]-'0');
				i++;
			} 
			q.push(temp);
		}
		else{
			temp.flag = false;
			//只要op<当前栈顶，就把栈顶元素弹出到后缀变达式的队列中 
			while(!s.empty() && op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop(); 
			} 
			temp.op = str[i];
			s.push(temp);//把该操作符压入操作符栈中
			i++; 
		}
	} 
	while(!s.empty()){//如果操作符栈中还有操作符，就把他弹出到后缀表达式序列中
		 	q.push(s.top());
			s.pop(); 
	} 	
} 

//计算后缀表达式 
double Calculate(){
	double t1, t2;
	node cur, temp;
	while(!q.empty()){//只要后缀表达式队列非空
		cur = q.front();//cur记录队首元素
		q.pop();
		if(cur.flag == true) s.push(cur);//如果是操作数，直接压入栈 
		else{//如果是操作符 
			t2 = s.top().num;//弹出第二操作数
			s.pop();
			t1 = s.top().num;
			s.pop(); 
			temp.flag = true;// 临时记录操作数
			if(cur.op =='+') temp.num = t1+t2;
			else if(cur.op =='-') temp.num = t1-t2;
			else if(cur.op =='*') temp.num = t1*t2;
			else  temp.num = t1/t2;
			s.push(temp);
		} 
	} 
	return s.top().num;
} 

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while(getline(cin,str),str!="0"){
		for(string::iterator it=str.end(); it!=str.begin(); it--){
			if(*it==' ') str.erase(it);//把表达式中的空格全都去掉			 
		} 
		while(!s.empty()) s.pop();//初始化栈
		change();
		printf("%.2f\n", Calculate()) ;
	}
	return 0;
} 
