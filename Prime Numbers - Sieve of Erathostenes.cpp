#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Juan Carlos Juárez 
//Sieve of Erathostenes

int countPrimes(int n) {
        if(n<2) return 0;
        vector<int> primes;
        primes.resize(n);
        fill(primes.begin(), primes.end(), 1);
        int count=0;
        for(int i=2; i<n; i++){
            if(primes[i]){
                count++;
                for(int j=i+i; j<n; j+=i){
                    primes[j]=0;
                }
            }
        }
        return count;
    }

int main() {
  cout << countPrimes(100);
  return 0;
}