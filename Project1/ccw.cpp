#include <utility>
#include <iostream>
using namespace std;
#define pii pair<int, int>


// ccw
int ccw(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

// ���б���
bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {

    pii p1 = l1.first;
    pii p2 = l1.second;
    pii p3 = l2.first;
    pii p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 ����
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 ����

    // �� ������ ������ �� ����
    if (p1p2 == 0 && p3p4 == 0) {
        // �񱳸� �Ϲ�ȭ�ϱ� ���� �� ��ġ ����
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // �� ������ �������� �ִ��� Ȯ��
    }

    return p1p2 <= 0 && p3p4 <= 0;
