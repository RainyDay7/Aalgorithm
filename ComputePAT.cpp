//��� 
//1���ڳ�����һ���Լ����������Ҫ�õ��Ľ����֮��Ĳ�ѯֱ��ȡ����Щ���
//2���ڳ���B�з�һ�λ��μ����������Ҫ�õ��Ľ�����ֹ��ѽ��д�ڳ���A�������У�Ȼ���ڳ���A�оͿ���ֱ���õ���Щ���
//3����һЩ�о�����������Ŀ�����ñ����������С��Χ���ݵĽ����Ȼ���ҹ���

//PAT B1040/A1093���м���pat
//eg APPAT 246 346�������2

//��һ��ȷ��λ�õ�A��˵�����γɵ�PAT������ߵ�P*�ұߵ�T

const int maxn=100010;
const int mod=1000000007;
char str[maxn];
int leftNumP[maxn]={0};//ÿһλA��ߺ�P�ĸ���

int main(){
	gets(str);�����ַ��� 
	int len = strlen(str);
	for(int i=0; i<n; i++){
		if(i>0){//�������0��λ 
			leftNumP[i] = leftNumP[i-1];//�̳���һλ�Ľ�� 
		}
		if (str[i]=='P'){
			leftNumP[i]++;
		} 
	} 
	int ans=0;
	int rightNumT=0;//ansΪ�𰸣�rightNumT��¼�ұ�T�ĸ���
	for(int i=len-1; i>=0; i--){//������������ַ��� 
		if(str[i]=='T')//��ǰλ��T
			rightNumT++;
		else if(str[i]=='A'){
			ans = (ans+leftNumP[i]*rightNumT)%mod;//�ۼƳ˻� 
		} 
	} 
	printf("%d\n", ans);//������
	return 0; 
} 
 
