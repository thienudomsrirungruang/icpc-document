#include "../utilities/template.h"

#include "../../content/numerical/LinearRecurrence.h"

template<class F>
void gen(vector<ll>& v, int at, F f) {
	if (at == sz(v)) f();
	else {
		rep2(i,0,mod) {
			v[at] = i;
			gen(v, at+1, f);
		}
	}
}

int main() {
	rep2(n,1,5) {
		vector<ll> start(n);
		vector<ll> coef(n);
		int size = 10*n + 3;
		vector<ll> full(size);
		gen(start,0,[&]() {
			gen(coef,0,[&]() {
				for(auto &x:full) x = 0;
				rep2(i,0,n) full[i] = start[i];
				rep2(i,n,size) rep2(j,0,n) full[i] = (full[i] + coef[j] * full[i-1 - j]) % mod;
	// rep2(i,0,size) cerr << full[i] << ' '; cerr << endl;
	// rep2(i,0,n) cerr << coef[i] << ' '; cerr << endl;
	// LinearRec lr(start, coef);
	// rep2(i,0,size) { cerr << lr.Get(i) << ' '; } cerr << endl;
				rep2(i,0,size) {
					auto v = linearRec(start, coef, i);
	// cerr << v << ' ';
					assert(v == full[i]);
				}
	// cerr << endl;
	// cerr << endl;
			});
		});
	}
	cout<<"Tests passed!"<<endl;
}
