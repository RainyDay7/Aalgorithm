#include<bits/stdc++.h>
using namespace std;

//给出N哥正整数，再给出M个正整数，问这M个数中的每个数分别是否在这N个书中出现过 
//把输入的数作为数组的下标来对这个数的性质进行统计 
const int maxn = 100010;
bool hashTable[maxn] = {false};
int main(){
	int n,m,x;
	scnaf("%d%d",&n,&m);
	for(int i=0;i<n; i++){
		scanf("%d",&x);
		hashTable[x] = true;//数字x出现过 
	}
	for(int i=0;i<m; i++){
		scnaf("%d",&x);
		if(hashTable[x]==true)
			printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
} 
