#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1); // ʹ�� n + 1 ������� 1 ��ʼ
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        // ˫�˶��д洢���ܵ� j ֵ
        deque<int> q;
        
        // �� j = 1 ��ʼ��j �����ֵΪ n - i
        for (int j = 1; j + i <= n; ++j) {
            // �������ӿ��ܵ� j
            if (a[i] <= j) { // a[i] <= j
                while (!q.empty() && a[i + q.back()] < j) {
                    q.pop_back(); // ���������������� j
                }
                q.push_back(j); // ��ӺϷ��� j
            }

            // ��� j �з���������ֵ
            if (!q.empty() && j >= q.front() && j <= a[i + q.front()]) {
                cout << "1 " << q.front() << endl; // �����һ�����ʵ� j
                break;
            }
        }

        if (q.empty() || !q.empty() && a[i + q.front()] < q.front()) {
            cout << "0" << endl; // û���ҵ��Ϸ��� j
        }
    }

    return 0;
}
