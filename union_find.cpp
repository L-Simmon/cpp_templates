// 例题：LC399(除法求值，带边权的并查集)，LC1202(交换字符串中的元素)

#include<iostream>
using namespace std;

const int N = 1e5 + 1;
int p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int union_(int x, int y){
    p[find(x)] = find(y);
}

int main(){
    // 初始化
    int n = 10;
    for (int i = 0; i < n; ++i) p[i] = i;

    return 0;
}