#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<double, double> > polygraph;
    for (int i = 0; i < N; i++)
    {
        double pos_x, pos_y;
        cin >> pos_x >> pos_y;
        polygraph.push_back(make_pair(pos_x, pos_y));
    }
    polygraph.push_back(polygraph[0]);
    double area = 0;
    for (int i = 0; i < N + 1; i++)
    {
        area += (polygraph[i].first * polygraph[(i + 1) % (N + 1)].second - polygraph[(i + 1) % (N + 1)].first * polygraph[i].second);
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(area / 2) << "\n";
    return 0;
}