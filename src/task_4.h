/*
 * Author: Arislanbek Kalbaev
 * Date: November 3, 2023
 * Name: Arislanbek Kalbaev
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<stack<int>> stacks(N);
    vector<int> containers(N + 1);

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int type;
            cin >> type;
            stacks[i].push(type);
            containers[type] = i;
        }
    }

    bool impossible = false;

    for (int type = 1; type <= N; type++) {
        if (containers[type] != 0) {

            int from = containers[type];
            int to = 0;

            stacks[to].push(stacks[from].top());
            stacks[from].pop();
            containers[type] = to;

            cout << from + 1 << " " << to + 1 << endl;
        }


        while (!stacks[0].empty() && stacks[0].top() != type) {
            int currentStack = containers[stacks[0].top()];
            int to = currentStack + 1;

            if (to >= N) {
                impossible = true;
                break;
            }

            stacks[to].push(stacks[0].top());
            stacks[0].pop();
            containers[stacks[to].top()] = to;

            cout << 1 << " " << to + 1 << endl;
        }

        if (impossible) {
            break;
        }
    }

    if (impossible) {
        cout << 0 << endl;
    }

    return 0;
}
