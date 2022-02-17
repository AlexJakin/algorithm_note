// A1059 Counting Ones
// 当前处理到k位，left为第k位的高位所表示的数 now是第k位 right低位所表示的数 
//对于个位数： left*a个
//对于十位数（因为该位是要统计的数） ：left * a + right + 1
//其他：(left+1)*a 
#include <stdio.h>

int main(){
	// a是某一位的数 统计a的数量 
	int n, a = 1, ans = 0;
	int left, now, right;
	scanf("%d", &n);
	// 从个位数开始遍历 
	while(n/a != 0)
	{
		left = n / (a * 10);//高k位 
		now = n / a % 10;
		right = n % a;
		
		if(now == 0) ans += left * a; // 个位 
		else if(now == 1) ans += left * a + right + 1; // 十位数（因为十位数是a） 
		else ans += (left + 1) * a; // 其他 
		a *= 10; 
	}
	printf("%d\n", ans);
	return 0;
}