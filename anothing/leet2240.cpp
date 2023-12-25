
using namespace std;

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long res = 0;
    for(int i = 0; i * cost1 <= total; ++i){
        res += (total - i * cost1) / cost2 + 1;
    }
    return res;
}