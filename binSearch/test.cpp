#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

// 查找某个指定值x
int binSearch(int x, vector<int>& vc) {
    cout << "=== bin search ===" << endl;
    int ret = -1;
    if (vc.empty()) {
        return ret;
    }

    int left = 0;
    int right = vc.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (x == vc[mid]) {
            ret = mid;
            break;
        } else if (x > vc[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ret;
}

// 查找第一个 >= x的数
int lowerBound(int x, vector<int>& vc) {
    cout << "=== lower_bound ===" << endl;
    int ret = -1;
    if (vc.empty()) {
        return ret;
    }

    int left = 0;
    int right = vc.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (vc[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    ret = left;
    return ret;
}

// 查找第一个 > x的数
int upperBound(int x, vector<int>& vc) {
    cout << "=== upper_bound ===" << endl;
    int ret = -1;
    if (vc.empty()) {
        return ret;
    }

    int left = 0;
    int right = vc.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (vc[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    ret = left;
    return ret;
}

void printResult(int x) {
    if (x == -1) {
        cout << "search FAILED, res = " << x << endl;
    } else {
        cout << "search SUCCESS, res = " << x << endl;
    }
}

void test(int& x, const char c, vector<int>& vc) {
    typedef int(*search_type)(int, vector<int>&);
    search_type func;
    switch (c) {
        case 'b' : func = binSearch; break;
        case 'l' : func = lowerBound; break;
        case 'u' : func = upperBound; break;
    }

    printResult(func(x, vc));
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "---please search num---" << endl;
        return 0;
    }
    int x = atoi(argv[1]);
    char c = argv[2][0];
    cout << "x = " << x << endl;
    vector<int> vc = {-10, -7, -6, -5, -2, 0, 1,
                     1, 3, 8, 10, 28, 36, 67, 67};
    
    test(x, c, vc);

    return 0;
}