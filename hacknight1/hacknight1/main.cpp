
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[])
{
    int input = 0, inputRoot = 0;
    
    cout << "Enter n: ";
    cin >> input;
    
    // Calculate square root of input
    inputRoot = (int)sqrt(input) + 1;
    
    if(input < 2)
        cout << "Prime numbers cannot be less than 2" << endl;
    else
    {
        cout<< "Finding prime numbers from 1 to " << input << " with the Sieve of Atkins..." << endl;
    
        bool *primes = new bool[input+1];
        
        for(int i=1; i<input+1; i++)
            primes[i] = false;
        
        primes[2] = true;
        primes[3] = true;
        
        // Sieve of Atkin
        for(int x=1; x<=inputRoot; x++)
            for(int y=1; y<inputRoot; y++)
            {
                int n = (4*x*x)+(y*y);
                if (n <= input && (n % 12 == 1 || n % 12 == 5))
                    primes[n] ^= true;
                n = (3*x*x)+(y*y);
                if (n <= input && n % 12 == 7)
                    primes[n] ^= true;
                n = (3*x*x)-(y*y);
                if (x > y && n <= input && n % 12 == 11)
                    primes[n] ^= true;
            }
        
        for (int i = 5; i <= inputRoot; i++)
            if (primes[i])
                for (int j = i*i; j < input; j += i*i)
                    primes[j] = false;
        
        for(int i=2; i<(input+1); i++)
            if(primes[i])
                cout << i << endl;
        
    }
    
    return 0;
}
