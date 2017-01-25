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
    std::vector<long long> first_cost; // Degree == 1
    std::vector<long long> current_cost; // Degree == 0
    std::vector<int> P; // Population
    std::vector<int> first_P; // Degree == 1
    std::vector<int> current_P; // Degree == 0
    std::vector<Edge> L; // Edge set array
    std::vector<int> in_degree;
    std::vector<int> out_degree;
    std::vector<int> index;
    std::queue<int> topological_queue; // Assist topological sorting

    void input();
    Edge& next(const int threshold);
    void generate_queue(const int threshold);
    void reset(Edge& edge, const int threshold);
    void iteration(std::vector<int>& P, std::vector<long long>& cost,
        const std::vector<int>& pre_P, const std::vector<long long>& pre_cost, const int threshold);
    void compute();
    template<typename T>
    void output(const std::vector<T>& data);

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
    std::cin >> this -> N;

    for (auto i = 0; i != this -> N; ++i){
        int tmp;

        std::cin >> tmp;
        this -> P.push_back(tmp);
    }

    this -> in_degree.resize(this -> N);
    this -> out_degree.resize(this -> N);
    for (auto i = 0; i != N - 1; ++i){
        int A;
        int B;
        int L;

        std::cin >> A >> B >> L;
        this -> L.push_back(Solution::Edge(A, B, L));
        this -> L.push_back(Solution::Edge(B, A, L));
        ++(this -> in_degree.at(A));
        ++(this -> out_degree.at(A));
        ++(this -> in_degree.at(B));
        ++(this -> out_degree.at(B));
    }

    this -> index.push_back(0);
    for (auto i:this -> in_degree){
        this -> index.push_back(this -> index.back() + i);
    }

    std::sort(this -> L.begin(), this -> L.end());
}

Solution::Edge& Solution::next(const int threshold){
    int i = this -> topological_queue.front();
    while (this -> out_degree.at(i) == 0){
        this -> topological_queue.pop();
        i = this -> topological_queue.front();
    }
    for (auto j = this -> index.at(i); j != this -> index.at(i + 1); ++j){
        if (this -> L.at(j).used == 0){
            return this -> L.at(j);
        }
    }
}

void Solution::generate_queue(const int threshold){
    for (auto i = 0; i != this -> N; ++i){
        if (this -> in_degree.at(i) == threshold && this -> out_degree.at(i) != 0){
            this -> topological_queue.push(i);
        }
    }
}

void Solution::reset(Solution::Edge& edge, const int threshold){
    edge.used = 1;
    --(this -> in_degree.at(edge.D));
    --(this -> out_degree.at(edge.S));
    if (this -> in_degree.at(edge.D) == threshold && this -> out_degree.at(edge.D) != 0){
        this -> topological_queue.push(edge.D);
    }
}

void Solution::iteration(std::vector<int>& P, std::vector<long long>& cost,
    const std::vector<int>& pre_P, const std::vector<long long>& pre_cost, const int threshold){
    /*
    std::cout << "D ";
    this -> output(this -> in_degree);
    std::cout << "  ";
    this -> output(this -> out_degree);
    std::cout << "P ";
    this -> output(P);
    std::cout << "C ";
    this -> output(cost);
    std::cout << "Pp";
    this -> output(pre_P);
    std::cout << "Pc";
    this -> output(pre_cost);
    */
    this -> generate_queue(threshold);
    for (auto i = 0; i != this -> N - 1; ++i){
        auto& next = this -> next(1);

        cost.at(next.D) += next.L * (P.at(next.S) - pre_P.at(next.D)) - next.L * pre_P.at(next.D)
                        + cost.at(next.S) - pre_cost.at(next.D); // subtract historical cost/Population from D to S in last iteration
        P.at(next.D) += P.at(next.S);
        this -> reset(next, threshold);
        /*
        std::cout << "S " << next.S << " D " << next.D << " L " << next.L << " P " << P.at(next.S)
            << " C " << cost.at(next.S) << " Pp " << pre_P.at(next.D) << " Pc " << pre_cost.at(next.D) << std::endl;
        std::cout << "D ";
        this -> output(this -> in_degree);
        std::cout << "  ";
        this -> output(this -> out_degree);
        std::cout << "P ";
        this -> output(P);
        std::cout << "C ";
        this -> output(cost);
        */
    }
}

void Solution::compute(){
    this -> first_cost.resize(this -> N, 0);
    this -> current_cost.resize(this -> N, 0);
    this -> current_P.resize(this -> N, 0);

    this -> first_P.assign(this -> P.begin(), this -> P.end());
    this -> iteration(this -> first_P, this -> first_cost, this -> current_P, this -> current_cost, 1);

    // std::cout << "second" << std::endl;
    this -> current_P.assign(this -> first_P.begin(), this -> first_P.end());
    this -> current_cost.assign(this -> first_cost.begin(), this -> first_cost.end());
    this -> iteration(this -> current_P, this -> current_cost, this -> first_P, this -> first_cost, 0);
}

template<typename T>
void Solution::output(const std::vector<T>& data){
    std::ostream_iterator<T> int_cout(std::cout, " ");

    std::copy(data.begin(), data.end(), int_cout);
    std::cout << std::endl;
}

Solution::Solution(){
    this -> input();

    this -> compute();
    this -> output(this -> current_cost);
}
