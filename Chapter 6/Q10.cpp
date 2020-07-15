#include "std_lib_facilities.h"
#include <stdexcept>

int factorial(int val)
{
    int total = 1;
    for (; val > 1; val--)
    {
        int prevTotal = total;
        total *= val;
        if (total / val != prevTotal)
        {
            throw overflow_error("Overflow Error in Factorial Calculation");
        }

    }
    return total;
}

int permutations(int a, int b)
{
    return factorial(a) / factorial(a - b);
}

int combinations(int a, int b)
{
    return permutations(a, b) / factorial(b);
}

int main()
{
    int a = 0, b = 0;
    int pms = 0;
    int cms = 0;

    cout << "Please enter two numbers:\n";
    
    while (cin >> a >> b)
    {
        try 
        {
            pms = permutations(a, b);
            cms = combinations(a, b);
        }
        catch (std::overflow_error e)
        {
            cout << "\nWarning: " << e.what() << '\n';
        }

        cout << "Permutations: " << pms << '\n';
        cout << "Combinations: " << cms << '\n';
        cout << "Please enter two numbers or type quit to exit\n";
    }

}

