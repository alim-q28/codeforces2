#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 100000;
int a[N], b[N], st[N], st2[N], uf[N];

int find(int x)
{
  while (uf[x] != x)
    uf[x] = uf[uf[x]], x = uf[x];
  return x;
}

int main()
{
  int n = ri(), m = 0, m2 = 0;
  REP(i, n) {
    uf[i] = i;
    a[i] = ri();
    while (m && a[st[m-1]] >= a[i])
      m--;
    if (m)
      b[i] = b[find(st[m-1]+1)] + 1;
    st[m++] = i;
    while (m2 && b[st2[m2-1]] <= b[i])
      uf[st2[--m2]] = i;
    st2[m2++] = i;
  }
  printf("%d\n", *max_element(b, b+n));
}
