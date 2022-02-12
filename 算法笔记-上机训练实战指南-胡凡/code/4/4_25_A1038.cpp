// A1038 Recover the Smallest Number
// 生成最小数 （字符串拼接排序） 
//这里不能直接使用排序+拼接的方法比如{'12', '112'} 实际最小的数为11212 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
string str[maxn];

//拼接后的a+b 小于 b+a 把a排前面 
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
	string ans;// 结果字符串 
	for(int i = 0; i < n; i++)
	{
		ans += str[i];
	}
	while(ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());//去掉前导0 
	}
	if(ans.size() == 0) cout << 0;
	else cout << ans; 
	return 0;
} 