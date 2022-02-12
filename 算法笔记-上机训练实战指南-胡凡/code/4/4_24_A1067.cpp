// A1067 Sort with swap(0,*)
// 0必须参与交换 每步都能让非零的数回归本位
// 如果0在第i位 找到数字i的位置 让0和i进行交换
// ps 这里使用 每个数字的索引数组 即pos数组 
#include <stdio.h>

//或者也有不用指针的方法交换两个数 
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
const int maxn = 100010;
int pos[maxn]; // pos存放每个数的当前编号 

int main(){
	int n, ans = 0; // ans是交换次数 
	scanf("%d", &n);
	//nums存放不在目标位的数量 num为当前数 
	int nums = n - 1, num;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		pos[num] = i;  // 如果num和i相同说明该数在目标位置上 
		// 除0外在本位上的数
		if(num == i && num != 0) nums--;
	}
	
	// 处理
	int k = 1; // k存放除0外当前不在本位上的最小的数
	while(nums > 0)//直到所有数都回到原位 
	{
		//如果0在当前位 选择最小不在当前位的数与0交换
		//保持用0交换的必要条件 
		if(pos[0] == 0)
		{
			while(k < n)
			{
				// 找到一个不在本位上的数 
				if(pos[k] != k)
				{
					swap(pos[0], pos[k]);
					ans++;
					break; 
				}
				k++;
			}
		}
		//0不在本位 
		while(pos[0] != 0)
		{
			// 0所在位置的索引数 和 该索引数的位置互换 使得索引数回到目标位置
			// 即num = i 
			swap(pos[0], pos[pos[0]]);
			ans++;
			nums--;
		}
	} 
	printf("%d\n", ans);
	return 0;
}