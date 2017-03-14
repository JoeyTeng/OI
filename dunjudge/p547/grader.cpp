#include "segmenttree.h"
using namespace std;

static int N, Q;

int main() {
    scanf("%d%d", &N, &Q);
    init(N);
    for ( int i = 0; i < Q; i++ ) {
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);
        if ( A == 1 ) update(B, C);
        else printf("%d\n", query(B, C));
    }
    return 0;
}
