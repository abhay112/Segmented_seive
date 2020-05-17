#include<bits/stdc++.h>
using namespace std;
#define max 100001
typedef long long  ll;
vector<int>* seive(){
	
	bool p[max];
	for(int i = 0; i < max; i++)
		p[i] = true;
	for(int i = 2; i*i < max; i++){
		if(p[i]){
			for(int j = i*i; j < max; j +=i)
				p[j] = false;
		}
	}
	vector<int> *primes = new vector<int>();
	primes->push_back(2);
	for(int i = 3; i < max; i+=2){
		if(p[i])
			primes -> push_back(i);
	}
	return primes;
}
void print_prime(ll l, ll r, vector<int> * &primes){
	bool isP[r-l+1];
	for(int i = 0; i <= r-l; i++){
		isP[i] = true;
	}
	for(int i = 0; primes->at(i)*(ll)primes->at(i) <=r; i++){
		
		int current_prime = primes -> at(i);

		ll base = (l/current_prime)*current_prime;
		if(base < l)
			base = base + current_prime;

		for(ll j = base; j <= r; j+= current_prime){
			isP[j-l] = false;
		}
		if(base == current_prime)
			isP[base - l] = true;

	}
	for(int i = 0; i <= r-l; i++){
		if(isP[i] == true)
			cout << i+l<< endl;
	}
}
int main(){
	vector<int> *primes = seive();
	int t; cin >> t;
	while(t--){
		ll l,r; cin >> l >> r;
		print_prime(l,r,primes);
	}
}