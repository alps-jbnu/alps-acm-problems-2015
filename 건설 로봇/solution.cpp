#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_LEN 5000
#define INF 987654321


/* 문제 입력 */

int nWorks;  // 작업 수
int nKinds;  // 기종 수

// isCapable[i][j]: 기종 j에 대한 작업 i의 수행 가능 여부
bool isCapable[MAX_LEN][MAX_LEN];


/* 그래프 노드 */

int src_num;  // 0: 소스 노드
int sink_num;  // 1: 싱크 노드
int w_num_first, w_num_last;  // 작업 1 ~ W에 대한 노드
int k_num_first, k_num_last;  // 기종 1 ~ K에 대한 노드
int max_num;  // 마지막 노드 번호


/* 플로우 네트워크 */

int flow[MAX_LEN][MAX_LEN];  // 현재 유량
int capacity[MAX_LEN][MAX_LEN];  // 유량 한계

void addEdge(int s, int t, int cap) {
    capacity[s][t] = cap;
}

int residualFlow(int s, int t) {
    return capacity[s][t] - flow[s][t];
}

void addFlow(int s, int t, int amount) {
    flow[s][t] += amount;
    flow[t][s] -= amount;
}


/* augment path */

bool pathFound;  // augment path 찾았는지 여부

// augment path 찾을 때, 이전 노드 기록
// -1: 미방문
// -2: 소스 노드
// 그 외: 이전 노드
int parent[MAX_LEN];

int minRes[MAX_LEN];  // augment path 찾을 때, path 중 최소 잔여 유량

void findAugmentPath() {
    pathFound = false;
    for (int i = 0; i <= max_num; i++) {
        parent[i] = -1;
        minRes[i] = INF;
    }
    parent[src_num] = -2;

    queue<int> q;
    q.push(src_num);
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int neighbor = 0; neighbor <= max_num; neighbor++) {
            if (parent[neighbor] == -1 && residualFlow(here, neighbor) > 0) {
                parent[neighbor] = here;
                minRes[neighbor] = min(minRes[neighbor], residualFlow(here, neighbor));
                if (neighbor == sink_num) {
                    pathFound = true;
                    return;
                } else
                    q.push(neighbor);
            }
        }
    }
}


int main() {
    int cases;
    cin >> cases;
    for (int tc = 0; tc < cases; tc++) {

        /* 입력 및 초기화 */

        // 그래프 노드 번호를 매긴다.
        src_num = 0;
        sink_num = 1;

        cin >> nWorks >> nKinds;

        w_num_first = 2;
        w_num_last = w_num_first + (nWorks - 1);

        k_num_first = w_num_last + 1;
        k_num_last = k_num_first + (nKinds - 1);

        max_num = k_num_last;

        cout << "src_num: " << src_num << endl;
        cout << "sink_num: " << sink_num << endl;
        cout << "w_num_first: " << w_num_first << endl;
        cout << "w_num_last: " << w_num_last << endl;
        cout << "k_num_first: " << k_num_first << endl;
        cout << "k_num_last: " << k_num_last << endl;

        // 플로우 네트워크 초기화
        for (int i = 0; i <= max_num; i++) {
            for (int j = 0; j <= max_num; j++) {
                capacity[i][j] = 0;
                flow[i][j] = 0;
            }
        }

        // 그래프 간선 추가
        for (int w_num = w_num_first; w_num <= w_num_last; w_num++) {
            int robot_limit;
            cin >> robot_limit;
            addEdge(w_num, sink_num, robot_limit);
        }

        for (int k_num = k_num_first; k_num <= k_num_last; k_num++) {
            int robot_cnt;
            cin >> robot_cnt;
            addEdge(src_num, k_num, robot_cnt);
            for (int w_num = w_num_first; w_num <= w_num_last; w_num++) {
                int c;
                cin >> c;
                if (c == 1)
                    addEdge(k_num, w_num, INF);
            }
        }


        /* 가능한 한 augument path를 찾아 flow를 늘린다. */

        while (true) {
            findAugmentPath();

            if (!pathFound)
                break;

            cout << "path found:";
            int amount = minRes[sink_num];
            int here = sink_num;
            while (here != src_num) {
                cout << ' ' << here;
                int pre = parent[here];
                addFlow(pre, here, amount);
                here = pre;
            }
            cout << endl;
        }


        /* 작업들로부터 싱크로 가는 간선을 조사하여, 정답을 출력한다. */

        for (int w_num = w_num_first; w_num <= w_num_last; w_num++) {
            int w_flow = flow[w_num][sink_num];
            cout << w_flow;
            if (w_num == w_num_last)
                cout << endl;
            else
                cout << ' ';
        }

    }
    return 0;
}