//A1089  Insert or Merge
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N],changed[N]; //由于先进行插入排序再进行归并排序 先用origin保存原数组 
int n; // 元素个数

// 判断两个数组是否相同
bool isSame(int a[], int b[])
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i]) return false;
	} 
	return true;
}

//输出 
void showArray(int a[])
{
	for(int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if(i < n - 1) printf(" ");
	}
	printf("\n");
}

// 插入排序
bool insertSort()
{
	bool flag = false; //是否是使用了插入排序
	//进行n-1轮 
	for(int i = 1; i < n; i++)
	{
		if(i != 1 && isSame(tempOri, changed))
		{
			flag = true;
		}
		//插入排序 
		int temp = tempOri[i]; // 保存 待插入的值 
		int j = i; // i之前是排序好的数
		while(j > 0 && tempOri[j - 1] > temp)// 从前面的有序数组查找待放位置（从后往前） 
		{
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true) return true; 
	}
	return false;
}

//归并排序 
void mergeSort()
{
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2)
	{
		//归并排序某个过程的结构和目标序列相同 
		if(step != 2 && isSame(tempOri, changed)) flag = true;
		for(int i = 0; i < n; i += step) 
			sort(tempOri + i, tempOri + min(i + step, n));
		if(flag == true)
		{
			showArray(tempOri);
			return;
		}
	}
}
int main(){
	scanf("%d", &n);
	//输入 
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0; i < n; i++) scanf("%d", &changed[i]);
	
	if(insertSort())
	{
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else
	{
		printf("MergeSort\n");
		//恢复原数组
		for(int i = 0; i < n; i++) tempOri[i] = origin[i];
		mergeSort();
	}
	return 0;
}