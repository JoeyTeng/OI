// parade

#include<bits/stdc++.h>

class Solution{
    private:

    struct Edge{
        Edge(int S, int D, int L);

        // friend int operator<(const Edge& x, const Edge& y);

        int S; // Start point
        int D; // Destination
        int L; // Length
        int used;
    };

    int N;
    int total_cost;
    std::vector<int> P; // Population
    std::vector<Edge> L; //Edge set array
    std::vector<int> degree;
    std::vector<int> index;

    void input();
    Edge& find(Edge edge);
    int cost(Edge edge);
    Edge& next();
    void reset(Edge& edge);
    void compute();
    void output();

    public:

    Solution();
};

int main(){
    Solution();

    return 0;
}

Solution::Edge::Edge(int S, int D, int L){
    this -> S = S;
    this -> D = D;
    this -> L = L;
    this -> used = 0;
}

template<typename T>
int operator<(const T& x, const T& y){
    if (x.S < y.S){
        return 1;
    } else if (y.S < x.S){
        return 0;
    } else if (x.D < y.D){
        return 1;
    } else {
        return 0;
    }
}

void Solution::input(){
    std::cin >> N;

    for (auto i = 0; i != N; ++i){
        int tmp;

        std::cin >> tmp;
        this -> P.push_back(tmp);
    }

    this -> degree.resize(N);
    for (auto i = 0; i != N - 1; ++i){
        int A;
        int B;
        int L;

        std::cin >> A >> B >> L;
        this -> L.push_back(Solution::Edge(A, B, L));
        this -> L.push_back(Solution::Edge(B, A, L));
        ++(this -> degree.at(A));
        ++(this -> degree.at(B));
    }

    this -> index.push_back(0);
    for (auto i:this -> degree){
        this -> index.push_back(this -> index.back() + i);
    }

    std::sort(this -> L.begin(), this -> L.end());
}

Solution::Edge& Solution::find(Solution::Edge edge){
    return *std::upper_bound(this -> L.begin(), this -> L.end(), edge);
}

int Solution::cost(Solution::Edge edge){
    return this -> P.at(edge.S) * edge.L; // People in city S move to city D
}

Solution::Edge& Solution::next(){
    int min_cost = INT_MAX;
    int index = 0;

    for (auto i = 0; i != N; ++i){
        if (this -> degree.at(i) == 1){
            for (auto j = this -> index.at(i); j != this -> index.at(i + 1); ++i){
                if (this -> L.at(j).used == 0
                 && this -> cost(this -> L.at(j)) < min_cost){
                    index = j;
                    min_cost = this -> cost(this -> L.at(j));
                }
            }
        }
    }
    return this -> L.at(index);
}

void Solution::reset(Solution::Edge& edge){
    edge.used = 1;
    this -> find(Solution::Edge(edge.D, edge.S, edge.L)).used = 1;
    --(this -> degree.at(edge.S));
    --(this -> degree.at(edge.D));
}

void Solution::compute(){
    int S;
    for (auto i = 0; i != N - 1; ++i){
        auto& next = this -> next();

        this -> total_cost += next.L * this -> P.at(next.S);
        this -> P.at(next.D) += this -> P.at(next.S);
        this -> P.at(next.S) = 0;
        this -> reset(next);
        S = next.S;
    }
}

void Solution::output(){
}

Solution::Solution(){
    this -> total_cost = 0;

    this -> input();
    this -> compute();
    this -> output();
}
