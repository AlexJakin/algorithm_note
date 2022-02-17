// B1003 我要通过 
#include <stdio.h>
#include <cstring> 

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	// T次 
	while(T--)
	{
		char str[110];
		scanf("%s", str);
		int len = strlen(str);
		// P的个数  T的个数
		int num_p = 0, num_t = 0, other = 0;
		// P的位置 T的位置 
		int loc_p = -1, loc_t = -1;
		for(int i = 0; i < len; i++)
		{
			if(str[i] == 'P')
			{
				num_p++; loc_p = i;
			}
			else if(str[i] == 'T')
			{
				num_t++; loc_t = i;
			}
			else if(str[i] != 'A')
				other++;
		}
		//  如果P的个数不为1 或者T的个数不为1
		// 或者存在除PAT外的字符 或者P和T之间没有字符
		if((num_p != 1) || (num_t != 1) || (other != 0) || (loc_t - loc_p <= 1))
		{
			printf("NO\n"); continue;
		}
		
		int x = loc_p, y = loc_t - loc_p, z = len - loc_t - 1;
		if(z - x * (y - 1) == x) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}