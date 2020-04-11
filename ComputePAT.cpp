//打表 
//1、在程序中一次性计算出所有需要用到的结果，之后的查询直接取到这些结果
//2、在程序B中分一次或多次计算出所有需要用到的结果，手工把结果写在程序A的数组中，然后在程序A中就可以直接用到这些结果
//3、对一些感觉不会做的题目，先用暴力程序计算小范围数据的结果，然后找规律

//PAT B1040/A1093　有几个pat
//eg APPAT 246 346所以输出2

//对一个确定位置的A来说，它形成的PAT等于左边的P*右边的T

const int maxn=100010;
const int mod=1000000007;
char str[maxn];
int leftNumP[maxn]={0};//每一位A左边含P的个数

int main(){
	gets(str);读入字符串 
	int len = strlen(str);
	for(int i=0; i<n; i++){
		if(i>0){//如果不是0号位 
			leftNumP[i] = leftNumP[i-1];//继承上一位的结果 
		}
		if (str[i]=='P'){
			leftNumP[i]++;
		} 
	} 
	int ans=0;
	int rightNumT=0;//ans为答案，rightNumT记录右边T的个数
	for(int i=len-1; i>=0; i--){//从右向左遍历字符串 
		if(str[i]=='T')//当前位是T
			rightNumT++;
		else if(str[i]=='A'){
			ans = (ans+leftNumP[i]*rightNumT)%mod;//累计乘积 
		} 
	} 
	printf("%d\n", ans);//输出结果
	return 0; 
} 
 
