#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > slideshow;
vector<vector<int>> pics;
vector<bool> horizontal; //True if it is horizontal
vector<int> vertical;
vector<int> pos;
int ind[100000];
int leftalone;
map<string, int> tags;
ifstream in;
ofstream out;

inline double randd()
{
    return (double)rand() / RAND_MAX;
}

int CalculateSingleScore(const vector<int> & picA, const vector<int> & picB) {
    set<int> A(picA.begin(), picA.end());
    set<int> B(picB.begin(), picB.end());
    set<int> cross;

    for (auto a : A) {
        auto pos = B.find(a);
        if (pos != B.end()) {
            cross.insert(a);
        }
    }
    return min(min(A.size() - cross.size(), B.size() - cross.size()), cross.size());
}

int cal(pair<int,int> a, pair<int,int> b) {
    vector<int> A, B;
    A = pics[a.first];
    B = pics[b.first];
    if (a.second != -1) for (auto t:pics[a.second]) A.push_back(t);
    if (b.second != -1) for (auto t:pics[b.second]) B.push_back(t);
    return CalculateSingleScore(A, B);
}

int modu(int x) {
    int ret = 0;
    if (x) ret += cal(slideshow[x - 1], slideshow[x]);
    if (x < slideshow.size() - 1) ret += cal(slideshow[x], slideshow[x + 1]);
    return ret;
}

void input() {
    int N;
    in.open("b.txt");
    in >> N;
    string H(1, 'H');
    leftalone = -1;
    for (int i = 0; i < N; ++i) {
        string tmp;
        vector<int> current_tags;

        in >> tmp;
        if (tmp == H) {
            horizontal.push_back(true);
            slideshow.emplace_back(i, -1);
        } else {
            if (leftalone == -1) {
                leftalone = i;
            } else {
                horizontal.push_back(false);
                horizontal.push_back(false);
                ind[leftalone]=vertical.size();
                vertical.push_back(leftalone);
                ind[i]=vertical.size();
                vertical.push_back(i);
                pos.push_back(slideshow.size());
                pos.push_back(slideshow.size());
                slideshow.emplace_back(leftalone, i);
                leftalone = -1;
            }
        }

        int ttmp;
        in >> ttmp;
        for (int j = 0; j < ttmp; ++j) {
            in >> tmp;
            auto it = tags.find(tmp);

            if (it != tags.end()) {
                current_tags.push_back(it->second);
            } else {
                tags.insert(make_pair(tmp, tags.size()));
                current_tags.push_back(tags.size() - 1);
            }
        }
        pics.push_back(current_tags);
    }
}


int main() {
    input();
    double T = 100, TM = 1e-4, c = 0.995;
    int n = slideshow.size(), m = vertical.size();
    while (T > TM) {
        printf("%lf\n", T);
        for (int i = 1; i <= max(10, n / 2); i++) {
            int x = rand() % n, y = rand() % n;
            double now = modu(x) + modu(y);
            swap(slideshow[x], slideshow[y]);
            double td = modu(x) + modu(y), p = randd();
            if (td >= now || exp((td - now) / T) > p) {
                if (slideshow[x].second!=-1)
                {
                    pos[ind[slideshow[x].first]]=x;
                    pos[ind[slideshow[x].second]]=x;
                }
                if (slideshow[y].second!=-1)
                {
                    pos[ind[slideshow[y].first]]=y;
                    pos[ind[slideshow[y].second]]=y;
                }
                //printf("%.5lf %.5lf\n",exp((td - now) / T), p);
                //if (++cnt>=(n<<3)) break;
                continue;
            }
            swap(slideshow[x], slideshow[y]);
        }
        puts("F1");
        if (m)
            for (int i = 1; i <= max(10, m / 4); i++) {
                int x = rand() % m, y = rand() % m;
                if (pos[x] == pos[y]) continue;
                double now = modu(pos[x]) + modu(pos[y]);
                if (slideshow[pos[x]].second == vertical[x]) swap(slideshow[pos[x]].first, slideshow[pos[x]].second);
                if (slideshow[pos[y]].second == vertical[y]) swap(slideshow[pos[y]].first, slideshow[pos[y]].second);
                if (slideshow[pos[x]].first!=vertical[x]||slideshow[pos[y]].first!=vertical[y]) {
                    printf("%d",i);
                    puts("SCREW");
                    return 0;
                }
                swap(slideshow[pos[x]].first, slideshow[pos[y]].first);
                double td = modu(pos[x]) + modu(pos[y]), p = randd();
                if (td >= now || exp((td - now) / T) > p) {
                    swap(pos[x], pos[y]);
                    continue;
                }
                swap(slideshow[pos[x]].first, slideshow[pos[y]].first);
            }
        puts("F2");
        if (leftalone != -1) {
            for (int i = 1; i <= max(10, m / 8); i++) {
                int x = rand() % m;
                double now = modu(pos[x]);
                if (slideshow[pos[x]].second == vertical[x]) swap(slideshow[pos[x]].first, slideshow[pos[x]].second);
                slideshow[pos[x]].first = leftalone;
                double td = modu(pos[x]), p = randd();
                if (td >= now || exp((td - now) / T) > p) {
                    vertical[x] = leftalone;
                    ind[leftalone] = x;
                    continue;
                }
                slideshow[pos[x]].first = vertical[x];
            }

        }
        T *= c;
    }
    out.open("ans_b.txt");
    out << slideshow.size() << '\n';
    for (auto p:slideshow) {
        if (p.second == -1) out << p.first << '\n';
        else out << p.first << ' ' << p.second << '\n';
    }
    out.close();
    return 0;
}