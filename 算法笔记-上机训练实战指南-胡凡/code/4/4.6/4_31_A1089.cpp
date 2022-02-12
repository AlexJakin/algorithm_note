//A1089  Insert or Merge
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N],changed[N]; //�����Ƚ��в��������ٽ��й鲢���� ����origin����ԭ���� 
int n; // Ԫ�ظ���

// �ж����������Ƿ���ͬ
bool isSame(int a[], int b[])
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i]) return false;
	} 
	return true;
}

//��� 
void showArray(int a[])
{
	for(int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if(i < n - 1) printf(" ");
	}
	printf("\n");
}

// ��������
bool insertSort()
{
	bool flag = false; //�Ƿ���ʹ���˲�������
	//����n-1�� 
	for(int i = 1; i < n; i++)
	{
		if(i != 1 && isSame(tempOri, changed))
		{
			flag = true;
		}
		//�������� 
		int temp = tempOri[i]; // ���� �������ֵ 
		int j = i; // i֮ǰ������õ���
		while(j > 0 && tempOri[j - 1] > temp)// ��ǰ�������������Ҵ���λ�ã��Ӻ���ǰ�� 
		{
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true) return true; 
	}
	return false;
}

//�鲢���� 
void mergeSort()
{
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2)
	{
		//�鲢����ĳ�����̵Ľṹ��Ŀ��������ͬ 
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
	//���� 
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
		//�ָ�ԭ����
		for(int i = 0; i < n; i++) tempOri[i] = origin[i];
		mergeSort();
	}
	return 0;
}