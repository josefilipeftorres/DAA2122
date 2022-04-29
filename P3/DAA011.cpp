#include <iostream>
#include <vector>
using namespace std;

bool condition(vector<int> v, int m, int q)
{
    int sum = 0, partitionCount = 1;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if(sum > m)
        {
            sum = 0;
            partitionCount++;
            i--;
        }
        if(partitionCount > q) return false;
    }
    return true;
}

int bsearch(int low, int high, vector<int> v, int question)
{
    while (low < high)
    {
        int middle = low + (high-low)/2;
        if(condition(v,middle,question) == true) high = middle;
        else low = middle+1;
    }
    if(condition(v,low,question) == false) return -1;
    return low;
}

int main()
{
    int n; cin >> n;     // Quantidade de distâncias
    vector<int> dist(n); // Distâncias
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> dist[i];
        maxSum += dist[i];
    }

    int question; cin >> question; // Quantidade de perguntas
    for (int i = 0; i < question; i++)
    {
        int qi; cin >> qi;
        printf("%d\n",bsearch(0, maxSum, dist, question));
    }
    return 0;
}