#include <vector>
#include <algorithm>
#include "segmenttree.h"

#include<bits/stdc++.h>

template<typename Type, typename Operator>
class SegmentTree {
    std::vector<Type> tree;
    int _length;
    Type _default;
    Operator Operation = Operator();

    int left_child(int root) {
        return (root << 1) + 1;
    }
    int right_child(int root) {
        return (root << 1) + 2;
    }

    void _build(int root, int left, int right, const std::vector<Type>& input) {
        if (left == right) {
            tree.at(root) = input.at(left);
            return;
        }
        int mid = (left + right) >> 1;
        _build(left_child(root), left, mid, input);
        _build(right_child(root), mid + 1, right, input);
        tree.at(root) = Operation(tree.at(left_child(root)), tree.at(right_child(root)));
    }

    void _update(int root, int left, int right, int pos, const Type& value) {
        if (left == right) {
            tree.at(root) = value;
            return;
        }
        int mid = (left + right) >> 1;
        if (pos >= left && pos <= mid) {
            _update(left_child(root), left, mid, pos, value);
        }
        if (pos > mid && pos <= right) {
            _update(right_child(root), mid + 1, right, pos, value);
        }
        tree.at(root) = Operation(tree.at(left_child(root)), tree.at(right_child(root)));
    }

    int _query(int root, int tleft, int tright, int left, int right) {
        if (tleft >= left && tright <= right) {
//            std::cout << "Q root " << root << std::endl;
//            std::cout << "Q " << tleft << ' ' << tright << ' ' << left << ' ' << right << ' ' << tree.at(root) << std::endl;
            return tree.at(root);
        } else if (tleft > right || tright < left) {
//            std::cout << "Q root " << root << std::endl;
//            std::cout << "Q " << tleft << ' ' << tright << ' ' << left << ' ' << right << ' ' << "DEFAULT" << std::endl;
            return _default;
        } else {
            int mid = (tleft + tright) >> 1;
            Type ans = Operation(_query(left_child(root), tleft, mid, left, right), _query(right_child(root), mid + 1, tright, left, right));
//            std::cout << "Q root " << root << std::endl;
//            std::cout << "Q " << tleft << ' ' << mid << ' ' << tright << ' ' << left << ' ' << mid << ' ' << right << ' ' << ans << std::endl;
            return ans;
        }
    }
    
  public:
    SegmentTree() {}
    SegmentTree(const std::vector<Type>& input) {
        build(input);
    }

    void set_default(const Type& value) {
        _default = value;
    }

    void build(const std::vector<Type>& input) {
        _length = input.size();
        tree.assign((_length << 2) + 1, 0);
        _build(0, 0, input.size() - 1, input);
    }

    void update(int pos, const Type& value) {
        _update(0, 0, _length - 1, pos, value);
//        std::cout << "U " << pos << ' ' << value << std::endl;
//        std::ostream_iterator<int> int_cout(std::cout, " ");
//        std::copy(tree.begin(), tree.end(), int_cout);
//        std::cout << std::endl;
    }

    int query(int left, int right) {
//        std::cout << "Q " << left << ' ' << right << std::endl;
//        std::ostream_iterator<int> int_cout(std::cout, " ");
//        std::copy(tree.begin(), tree.end(), int_cout);
//        std::cout << std::endl;
        return _query(0, 0, _length - 1, left, right);
    }
};

template<typename T>
struct Min {
    T operator()(const T& lhs, const T& rhs) const {
        return std::min(lhs, rhs);
    }
};

SegmentTree<int, Min<int> > segment_tree;

void init(int N) {
    segment_tree.set_default(INT_MAX);
    std::vector<int> tmp(N, 0);
    segment_tree.build(tmp);
    return;
}

void update(int P, int V) {
    segment_tree.update(P, V);
    return;
}

int query(int A, int B) {
    return segment_tree.query(A, B);
}
