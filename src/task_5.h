/*
 * Author: Arislanbek Kalbaev
 * Date: November 3, 2023
 * Name: Arislanbek Kalbaev
*/

#include <iostream>
using namespace std;

void Hanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        cout << "Move disk 1 from " << from_peg << " to " << to_peg << endl;
        return;
    }
    Hanoi(n - 1, from_peg, aux_peg, to_peg);
    cout << "Move disk " << n << " from " << from_peg << " to " << to_peg << endl;
    Hanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main() {
    int no = 8;
    Hanoi(no, 'A', 'C', 'B');
    return 0;
}
