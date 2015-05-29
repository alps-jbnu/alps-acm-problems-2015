#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_LEN 5000
#define INF 987654321


/* ���� �Է� */

int nWorks;  // �۾� ��
int nKinds;  // ���� ��

// isCapable[i][j]: ���� j�� ���� �۾� i�� ���� ���� ����
bool isCapable[MAX_LEN][MAX_LEN];


/* �׷��� ��� */

int src_num;  // 0: �ҽ� ���
int sink_num;  // 1: ��ũ ���
int w_num_first, w_num_last;  // �۾� 1 ~ W�� ���� ���
int k_num_first, k_num_last;  // ���� 1 ~ K�� ���� ���
int max_num;  // ������ ��� ��ȣ


/* �÷ο� ��Ʈ��ũ */

int flow[MAX_LEN][MAX_LEN];  // ���� ����
int capacity[MAX_LEN][MAX_LEN];  // ���� �Ѱ�

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

bool pathFound;  // augment path ã�Ҵ��� ����

// augment path ã�� ��, ���� ��� ���
// -1: �̹湮
// -2: �ҽ� ���
// �� ��: ���� ���
int parent[MAX_LEN];

int minRes[MAX_LEN];  // augment path ã�� ��, path �� �ּ� �ܿ� ����

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

        /* �Է� �� �ʱ�ȭ */

        // �׷��� ��� ��ȣ�� �ű��.
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

        // �÷ο� ��Ʈ��ũ �ʱ�ȭ
        for (int i = 0; i <= max_num; i++) {
            for (int j = 0; j <= max_num; j++) {
                capacity[i][j] = 0;
                flow[i][j] = 0;
            }
        }

        // �׷��� ���� �߰�
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


        /* ������ �� augument path�� ã�� flow�� �ø���. */

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


        /* �۾���κ��� ��ũ�� ���� ������ �����Ͽ�, ������ ����Ѵ�. */

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