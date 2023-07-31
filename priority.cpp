#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of process\n";
    cin >> n;
    vector<pair<int, pair<int, int>>> p;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter priority for process " << i + 1 << endl;
        int k;
        cin >> k;
        cout << "Enter bursttime" << endl;
        int b;
        cin >> b;
        p.push_back({k, {b, i + 1}});
    }
    sort(p.begin(), p.end());
    int total = 0;
    printf("Process\tPriority\tBurst-Time\tTurnaround\tWaiting-Time\t\n");
    for (int i = 0; i < n; i++)
    {
        int process = p[i].second.second;
        int b = p[i].second.first;
        total += b;
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process, p[i].first, b, total, total - b);
    }

    return 0;
}