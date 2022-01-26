#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

//将b进制的a转化为十进制
int gets(string s, int b)
{
    int res = 0 ;
    //秦九昭算法
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
    //用一个哈希表来存储第一个集合
    unordered_set <int> S;
    
    //得到a的所有可能集合S
    for (auto &c : a)
    {
        // 把a的每一位都换一下
        c ^= 1;
        //把a的所有可能放入S集合
        S.insert(gets(a, 2));
        // 把a恢复为原来的数
        c ^= 1;
    }
    
    //查看b的所有可能是否存在与S中，因为此题必有唯一解 所以肯定有一个交集
    for(auto &c : b)
    {
        //保存好c 后面要恢复原状 注意这里的t是ascii表示
        auto tmp = c;
        //三进制有 0 1 2三种可能 
        //这里的i表示0~2的ascii
        for(int i = '0'; i < '3'; i++)
        {
            
            //如果和原来相同 不改变 
            //（****）注意这里不能使用c 因为在for循环的时候c是不断在改变的（注意看下面第二句代码） t是我们原先保存的不会被改变
            if ( tmp == i) continue;
            c = i;
            //若存在一个解 则输出 由于只存在唯一解 可直接返回
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