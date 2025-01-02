#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

struct Edge {
    int to;
    long long weight;
};

struct Train {
    int start;
    long long first_time;
    long long interval;
};

struct State {
    int node;
    long long time;
    int transfers;

    bool operator>(const State& other) const {
        return time > other.time; // ���ȶ����У���ʱ������
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ��ȡ����
    int n, m, k, s, t;
    cin >> n >> m >> s >> k >> t;
    s--; t--; // ����תΪ0-indexed

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long weight;
        cin >> u >> v >> weight;
        u--; v--; // ����תΪ0-indexed
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // �����
    }

    int num_trains;
    cin >> num_trains;
    vector<Train> trains(num_trains);
    for (int i = 0; i < num_trains; ++i) {
        cin >> trains[i].start >> trains[i].first_time >> trains[i].interval;
        trains[i].start--; // ��վ��תΪ0-indexed
    }

    // ��С����ʱ������
    vector<vector<long long>> min_time(n, vector<long long>(k + 1, INF));
    
    // ���ȶ��У��洢״̬ (����Ľڵ�, �����ʱ��, ���˴���)
    priority_queue<State, vector<State>, greater<State>> pq;

    // ��ʼ�����ȶ��У������г�����ʱ��
    for (const Train& train : trains) {
        if (train.start == s) {
            pq.push({s, train.first_time, 0});
            min_time[s][0] = train.first_time; // ֱ�Ӵ�������
        }
    }

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int node = current.node;
        long long time = current.time;
        int transfers = current.transfers;

        // �������Ŀ���
        if (node == t) {
            cout << time << endl;
            return 0;
        }

        // �ڵ�ǰվ�㻻��
        if (transfers < k) {
            for (const Train& train : trains) {
                if (train.start == node) {
                    // ����Ⱥ���һ���г���ʱ��
                    long long wait_time = max(0LL, train.first_time - time);
                    if (wait_time % train.interval != 0) {
                        wait_time += train.interval - (wait_time % train.interval);
                    }
                    long long departure_time = time + wait_time;
                    pq.push({node, departure_time, transfers + 1}); // ֱ���ڴ�վ̨��������
                }
            }
        }  
        // ����ͼ�ϵ��ƶ�
        for (const Edge& edge : graph[node]) {
            long long arrive_time = time + edge.weight;
            // ������С����ʱ��
            if (arrive_time < min_time[edge.to][transfers]) {
                min_time[edge.to][transfers] = arrive_time;
                pq.push({edge.to, arrive_time, transfers}); // �ӵ�ǰ�ڵ��ƶ����ߵ���һ��
            }
        }
    }

    // ����޽�
    cout << -1 << endl;
    return 0;
}		  
