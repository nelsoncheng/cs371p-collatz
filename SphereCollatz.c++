// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <cmath>

const int MAX_CACHE = 100000;
int cache[MAX_CACHE] = {0};

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_cycle_length
// ------------

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
	int n_temp = n;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
		if(n < MAX_CACHE && n > 0){
			int temp = cache[n];
			if(temp > 0){
				c = c + temp;
				cache[n_temp] = c;
				return c;}
		}
		++c;	
	}
	if(n_temp < MAX_CACHE && n_temp > 0)
		cache[n_temp] = c;
	assert(c > 0);
    return c;}


// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    // <your code>
    int v = 1;
	int min = std::min(i,j);
	int max = std::max(i,j);
	int n_length;
	for(int n = min; n <= max; n++) {
		n_length = cycle_length(n);
		v = n_length > v ? n_length : v;
	}
    assert(v > 0);
    return v;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

int main () {
    using namespace std;
//  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    collatz_solve(cin, cout);
    return 0;}


