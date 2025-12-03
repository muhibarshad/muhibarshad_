#include <iostream>
using namespace std;

const int MAX = 100; // Define maximum array size
int dp[MAX];         // Memoization array

// Fibonacci function with Memoization
int fibonacci(int n)
{
    if (n <= 1)
        return n; // Base case

    if (dp[n] != -1)
        return dp[n]; // Return cached result if available

    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2); // Store & return result
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Initialize memoization array with -1
    for (int i = 0; i < MAX; i++)
    {
        dp[i] = -1;
    }

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
