#include <cstdio>
#include <ctime>
#include <set>
#include <unordered_set>

using namespace std;


const int N = 1e7;
const int base = 1699, mod = 1000000007;

void set_test() {
    clock_t begin = clock();
    set<int> s;
    int curr_num = 0;
    for (int i = 0; i < N; ++i) {
        curr_num  = (curr_num + base) % mod;
        s.insert(curr_num);
    }
    printf("set: %.3lf seconds\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
    clock_t middle = clock();

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (s.find(i) != s.end())
            cnt++;
    }
    printf("set lookup: %.3lf seconds, elems found: %d\n",
           (double) (clock() - middle) / CLOCKS_PER_SEC, cnt);
}

void uset_test() {
    clock_t begin = clock();
    unordered_set<int> us;
    int curr_num = 0;
    for (int i = 0; i < N; ++i) {
        curr_num  = (curr_num + base) % mod;
        us.insert(curr_num);
    }
    printf("unordered set: %.3lf seconds\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
    clock_t middle = clock();

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (us.find(i) != us.end())
            cnt++;
    }
    printf("set lookup: %.3lf seconds, elems found: %d\n",
           (double) (clock() - middle) / CLOCKS_PER_SEC, cnt);
}

int main() {
    set_test();
    uset_test();
}
