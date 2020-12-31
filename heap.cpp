// https://www.acwing.com/problem/content/840/
#include <iostream>
using namespace std;

const int N = 1e5 + 3;
int h[N]; 
int cnt; // 小顶堆，存储下标为：1~cnt

void down(int u){
    int t = u;
    if (2 * u <= cnt && h[2 * u] < h[t]) t = 2 * u;
    if (2 * u + 1 <= cnt && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if (t != u){
        swap(h[t], h[u]);
        down(t);
    }
}

void up(int u){
    while (u / 2 && h[u / 2] > h[u]){
        u >>= 1;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    cnt = n;
    for (int i = 1; i <= n; ++i){
        scanf("%d", &h[i]);
    }
    for (int i = n/2; i; --i) down(i);
    while (m--){
        printf("%d ", h[1]);
        h[1] = h[cnt--];
        down(1);
    }
    return 0;
}