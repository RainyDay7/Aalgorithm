//�򵥼�����
//��op�����ȼ�>ջ���Ĳ�������ѹ��
//��op�����ȼ�<ջ���Ĳ�����,����ջ����ֱ��op>ջ�� 

#include<bits/stdc++.h>
using namespace std;

struct node{
	double num;
	char op;
	bool flag;//true��ʾ��������false ��ʾ������ 
};

string str;
stack<node> s;//������ջ
queue<node> q;//��׺���ʽ����
map<char, int> op;

void change(){//����׺���ʽת���ɺ�׺���ʽ
	double num;
	node temp;
	for(int i=0; i<str.length();){
		if(str[i]>='0' && str[i]<='9'){//���������
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
			//ֻҪop<��ǰջ�����Ͱ�ջ��Ԫ�ص�������׺���ʽ�Ķ����� 
			while(!s.empty() && op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop(); 
			} 
			temp.op = str[i];
			s.push(temp);//�Ѹò�����ѹ�������ջ��
			i++; 
		}
	} 
	while(!s.empty()){//���������ջ�л��в��������Ͱ�����������׺���ʽ������
		 	q.push(s.top());
			s.pop(); 
	} 	
} 

//�����׺���ʽ 
double Calculate(){
	double t1, t2;
	node cur, temp;
	while(!q.empty()){//ֻҪ��׺���ʽ���зǿ�
		cur = q.front();//cur��¼����Ԫ��
		q.pop();
		if(cur.flag == true) s.push(cur);//����ǲ�������ֱ��ѹ��ջ 
		else{//����ǲ����� 
			t2 = s.top().num;//�����ڶ�������
			s.pop();
			t1 = s.top().num;
			s.pop(); 
			temp.flag = true;// ��ʱ��¼������
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
			if(*it==' ') str.erase(it);//�ѱ��ʽ�еĿո�ȫ��ȥ��			 
		} 
		while(!s.empty()) s.pop();//��ʼ��ջ
		change();
		printf("%.2f\n", Calculate()) ;
	}
	return 0;
} 
