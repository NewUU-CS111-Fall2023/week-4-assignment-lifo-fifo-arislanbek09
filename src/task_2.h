/*
 * Author: Arislanbek Kalbaev
 * Date: November 3, 2023
 * Name: Arislanbek Kalbaev
*/

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

bool ifArrangeTrains(int n, vector<int> trainOrder) {
    stack<int> s;
    int currentCar = 1; // Expected next car number

    for (int i = 0; i < n; i++) {
        if (trainOrder[i] == currentCar) {
            currentCar++;
        } else {
            while (!s.empty() && s.top() == currentCar) {
                s.pop();
                currentCar++;
            }
            s.push(trainOrder[i]);
        }
    }

    while (!s.empty() && s.top() == currentCar) {
        s.pop();
        currentCar++;
    }

    return (currentCar == n + 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> trainOrder(n);
    for (int i = 0; i < n; i++)
        cin >> trainOrder[i];

    if (ifArrangeTrains(n, trainOrder))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
