#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int start;
    int end;
} Segmento;

struct compareSegmento {
	bool operator()(const Segmento s1, const Segmento s2) {
        if(s1.start < s2.start) return true;
        if(s1.start > s2.start) return false;
        return s1.end > s2.end;
	}
};

int coberturaMinima(vector<Segmento> v, int m) {
    int end = 0;        // Posição final do segmento
    int segCount = 0;   // Contagem de segmentos
    int tmpEnd = 0;     // Posição final de um segmeto do meio
    int aux = 0;        // Guardar a posição do segmeto do meio
    while (end < m) {
        for(unsigned int i = aux; i < v.size(); i++) {
            if(v[i].start <= end) {
                if(v[i].end > tmpEnd) {
                    aux = i;
                    tmpEnd = v[i].end;
                }
            }
        }
        end = tmpEnd;
        segCount++;
    }
    return segCount;
}

int main() {
    int m, n;   // Tamanho do segmento a cobrir, Quantidade de segmentos 
    scanf("%d %d", &m, &n);

    vector<Segmento> seg(n);
    for(int i = 0; i < n; i++) {
        cin >> seg[i].start;
        cin >> seg[i].end;
    }

    sort(seg.begin(), seg.end(), compareSegmento());

    printf("%d\n", coberturaMinima(seg,m));
}