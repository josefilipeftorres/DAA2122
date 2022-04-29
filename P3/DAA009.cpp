#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct DNA
{
    char letter;
    int freq;
    int firstAppearance;
};

//  true se elemento "p1" for menor que elemento "p2"
//  false se elemento "p1" for maior ou igual ao elemento "p2"
struct compareDNA
{
    bool operator()(const DNA l1, const DNA l2)
    {
        if(l1.freq > l2.freq) return true;
        if(l1.freq < l2.freq) return false;
        if(l1.firstAppearance <= l2.firstAppearance) return true;
        return false;
    }
};

int main()
{
    vector<DNA> letter(26);
    for (int i = 0; i < 26; i++)
    {
        letter[i].letter = 'A' + i;
        letter[i].freq = 0;
    }

    string s; cin >> s;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        int pos = s[i] - 'A';
        if(letter[pos].freq == 0) letter[pos].firstAppearance = i;
        letter[pos].freq++;
    }
    
    sort(letter.begin(),letter.end(),compareDNA());

    for (unsigned int i = 0; i < letter.size(); i++)
    {
        if(letter[i].freq == 0) break;
        printf("%c %d\n", letter[i].letter, letter[i].freq);
    }
    return 0;
}