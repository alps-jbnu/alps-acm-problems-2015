#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX_LEN 100

string source;
string target;
int lcs_len[MAX_LEN + 1][MAX_LEN + 1];
pair<int, int> pre[MAX_LEN + 1][MAX_LEN + 1];

int main() {
    int cases;
    cin >> cases;
    for (int tc = 0; tc < cases; tc++) {
        cin >> source >> target;
        for (int i = 0; i <= source.size(); i++) {
            lcs_len[i][0] = 0;
            pre[i][0] = make_pair(0, 0);
        }
        for (int j = 0; j <= target.size(); j++) {
            lcs_len[0][j] = 0;
            pre[0][j] = make_pair(0, 0);
        }

        for (int i = 1; i <= source.size(); i++) {
            for (int j = 1; j <= target.size(); j++) {
                // LCS(i, j)를 계산한다.
                char s_ch = source[i - 1];
                char t_ch = target[j - 1];

                // 두 문자가 같은 경우,
                // LCS(i-1, j-1) + 1과 같음.
                if (s_ch == t_ch) {
                    lcs_len[i][j] = lcs_len[i - 1][j - 1] + 1;
                    pre[i][j] = make_pair(i - 1, j - 1);
                }
                // 두 문자가 다른 경우,
                else {
                    // LCS(i, j-1)과 LCS(i-1, j) 중 큰 쪽을 선택
                    // 같다면, 사전 순으로 빠른 문자가 있는 쪽을 선택
                    int lcs_from_s = lcs_len[i][j - 1];
                    int lcs_from_t = lcs_len[i - 1][j];
                    bool from_s;

                    if (lcs_from_s > lcs_from_t)
                        from_s = true;
                    else if (lcs_from_s < lcs_from_t)
                        from_s = false;
                    else 
                        if (s_ch < t_ch)
                            from_s = true;
                        else
                            from_s = false;

                    if (from_s) {
                        lcs_len[i][j] = lcs_from_s;
                        pre[i][j] = make_pair(i, j - 1);
                    } else {
                        lcs_len[i][j] = lcs_from_t;
                        pre[i][j] = make_pair(i - 1, j);
                    }
                }
            }
        }

        string trace;
        pair<int, int> pos = make_pair(source.size(), target.size());
        while (pos.first > 0 && pos.second > 0) {
            int i = pos.first;
            int j = pos.second;
            char s_ch = source[i - 1];
            char t_ch = target[j - 1];
            if (s_ch == t_ch)
                trace.push_back(s_ch);

            pos.first = pre[i][j].first;
            pos.second = pre[i][j].second;
        }
        reverse(trace.begin(), trace.end());

        int insertions = target.size() - trace.size();
        int deletions = source.size() - trace.size();
        cout << trace << ' ' << insertions << ' ' << deletions << endl;
    }
    return 0;
}
