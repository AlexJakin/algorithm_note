#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

//��b���Ƶ�aת��Ϊʮ����
int gets(string s, int b)
{
    int res = 0 ;
    //�ؾ����㷨
    for(int i = 0; i < s.size(); i ++)
    {
        res = res * b + s[i] - '0';
    }
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b; 
    //��һ����ϣ�����洢��һ������
    unordered_set <int> S;
    
    //�õ�a�����п��ܼ���S
    for (auto &c : a)
    {
        // ��a��ÿһλ����һ��
        c ^= 1;
        //��a�����п��ܷ���S����
        S.insert(gets(a, 2));
        // ��a�ָ�Ϊԭ������
        c ^= 1;
    }
    
    //�鿴b�����п����Ƿ������S�У���Ϊ�������Ψһ�� ���Կ϶���һ������
    for(auto &c : b)
    {
        //�����c ����Ҫ�ָ�ԭ״ ע�������t��ascii��ʾ
        auto tmp = c;
        //�������� 0 1 2���ֿ��� 
        //�����i��ʾ0~2��ascii
        for(int i = '0'; i < '3'; i++)
        {
            
            //�����ԭ����ͬ ���ı� 
            //��****��ע�����ﲻ��ʹ��c ��Ϊ��forѭ����ʱ��c�ǲ����ڸı�ģ�ע�⿴����ڶ�����룩 t������ԭ�ȱ���Ĳ��ᱻ�ı�
            if ( tmp == i) continue;
            c = i;
            //������һ���� ����� ����ֻ����Ψһ�� ��ֱ�ӷ���
            if(S.count(gets(b, 3)))
            {
                cout << gets(b,3) << endl;
                return 0;
            }
        }
        c = tmp;
    }
    return 0;
}