#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ALL(x) (x).begin(), x.end()

const int inf = 1e9;
const int maxn = 1e5 + 10;

ll a[maxn];
ll b[maxn];
int T, n, m, x;

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 1; i <= n; i++) scanf("%lld", a + i);
    for(int i = 1; i <= m; i++) scanf("%lld", b + i);

    for(int i = 1; i <= n; i++) a[i] += a[i-1];
    for(int i = 1; i <= m; i++) b[i] += b[i-1];

    int res = 0;
    for(int i = 0, j = m; i <= n && a[i] <= x; i++) {
      while(a[i] + b[j] > x && j >= 1)
        j --;
      res = max(res, i + j);
    }
    printf("%d\n", res);
  }
  return 0;
}
