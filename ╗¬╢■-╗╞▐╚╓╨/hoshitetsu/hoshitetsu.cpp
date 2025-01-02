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
        return time > other.time; // 优先队列中，按时间升序
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读取输入
    int n, m, k, s, t;
    cin >> n >> m >> s >> k >> t;
    s--; t--; // 将点转为0-indexed

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long weight;
        cin >> u >> v >> weight;
        u--; v--; // 将点转为0-indexed
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // 无向边
    }

    int num_trains;
    cin >> num_trains;
    vector<Train> trains(num_trains);
    for (int i = 0; i < num_trains; ++i) {
        cin >> trains[i].start >> trains[i].first_time >> trains[i].interval;
        trains[i].start--; // 将站点转为0-indexed
    }

    // 最小到达时间数组
    vector<vector<long long>> min_time(n, vector<long long>(k + 1, INF));
    
    // 优先队列，存储状态 (到达的节点, 到达的时间, 换乘次数)
    priority_queue<State, vector<State>, greater<State>> pq;

    // 初始化优先队列，所有列车出发时刻
    for (const Train& train : trains) {
        if (train.start == s) {
            pq.push({s, train.first_time, 0});
            min_time[s][0] = train.first_time; // 直接从起点出发
        }
    }

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int node = current.node;
        long long time = current.time;
        int transfers = current.transfers;

        // 如果到达目标点
        if (node == t) {
            cout << time << endl;
            return 0;
        }

        // 在当前站点换乘
        if (transfers < k) {
            for (const Train& train : trains) {
                if (train.start == node) {
                    // 计算等候下一班列车的时间
                    long long wait_time = max(0LL, train.first_time - time);
                    if (wait_time % train.interval != 0) {
                        wait_time += train.interval - (wait_time % train.interval);
                    }
                    long long departure_time = time + wait_time;
                    pq.push({node, departure_time, transfers + 1}); // 直接在此站台继续逗留
                }
            }
        }  
        // 继续图上的移动
        for (const Edge& edge : graph[node]) {
            long long arrive_time = time + edge.weight;
            // 更新最小到达时间
            if (arrive_time < min_time[edge.to][transfers]) {
                min_time[edge.to][transfers] = arrive_time;
                pq.push({edge.to, arrive_time, transfers}); // 从当前节点移动到边的另一端
            }
        }
    }

    // 如果无解
    cout << -1 << endl;
    return 0;
}		  
