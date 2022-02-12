// A1038 Recover the Smallest Number
// ������С�� ���ַ���ƴ������ 
//���ﲻ��ֱ��ʹ������+ƴ�ӵķ�������{'12', '112'} ʵ����С����Ϊ11212 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
string str[maxn];

//ƴ�Ӻ��a+b С�� b+a ��a��ǰ�� 
bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	string ans;// ����ַ��� 
	for(int i = 0; i < n; i++)
	{
		ans += str[i];
	}
	while(ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());//ȥ��ǰ��0 
	}
	if(ans.size() == 0) cout << 0;
	else cout << ans; 
	return 0;
} 