#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int n{ 0 }, result{ 0 };
int date[1500001];
int cost[1500001];
int calc[1500001];

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> date[i] >> cost[i];
    }

    for (int i = 0; i <= n; ++i)
    {
        result = max(result, calc[i]);

        if (i + date[i] > n) continue;
        calc[i + date[i]] = max(calc[i + date[i]], result + cost[i]); //calc[i] + cost[i]가 아님에 주의
    }

    cout << result;

    return 0;
}
