#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1); // 使用 n + 1 来方便从 1 开始
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        // 双端队列存储可能的 j 值
        deque<int> q;
        
        // 从 j = 1 开始，j 的最大值为 n - i
        for (int j = 1; j + i <= n; ++j) {
            // 向队列添加可能的 j
            if (a[i] <= j) { // a[i] <= j
                while (!q.empty() && a[i + q.back()] < j) {
                    q.pop_back(); // 弹出不符合条件的 j
                }
                q.push_back(j); // 添加合法的 j
            }

            // 如果 j 有符合条件的值
            if (!q.empty() && j >= q.front() && j <= a[i + q.front()]) {
                cout << "1 " << q.front() << endl; // 输出第一个合适的 j
                break;
            }
        }

        if (q.empty() || !q.empty() && a[i + q.front()] < q.front()) {
            cout << "0" << endl; // 没有找到合法的 j
        }
    }

    return 0;
}
