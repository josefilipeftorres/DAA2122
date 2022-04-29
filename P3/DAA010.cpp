#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<int> sums(vector<int> v)
{
    vector<int> sum;    
    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = i+1; j < v.size(); j++)
        {
            sum.push_back(v[i] + v[j]);
        }
    }
    // Sentinelas
    sum.push_back(INT_MAX); 
    sum.push_back(INT_MIN);
    return sum;
}

void bsearch(int low, int high, vector<int> v, int question)
{
    while (low < high)
    {   
        int middle = low + (high-low)/2;
        if(question <= v[middle]) high = middle;
        else low = middle+1;
    }
    int distHigh = abs(v[low] - question);
    int distLow  = abs(question - v[low-1]);

    if(distHigh < distLow) printf("%d\n", v[low]);
    else if(distHigh > distLow) printf("%d\n", v[low-1]);
    else printf("%d %d\n", v[low-1], v[low]);
}

int main()
{
    int n; cin >> n;    // Tamanho do conjunto de números
    vector<int> v(n);   // Conjunto 
    
    for (int i = 0; i < n; i++) cin >> v[i];
    
    v = sums(v);
    sort(v.begin(), v.end());

    int q; cin >> q;    // Quantidade de perguntas
    for (int i = 0; i < q; i++)
    {
        int qi; cin >> qi;
        bsearch(0, v.size()-1, v, qi);
    }
    return 0;
}