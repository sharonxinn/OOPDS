#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   // Create a vector of ints.
   vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };

   // Use a lambda expression to create a function object.
   auto isEven = [](int x) {return x % 2 == 0; };  //** */

   // Get the number of elements that even.
   int evenNums = count_if(v.begin(), v.end(), isEven);

   // Display the results.
   cout << "The vector contains " << evenNums << " even numbers.\n";
   return 0;
}

/*
What is a Lambda Expression?
A lambda expression in C++ is a concise way to define an anonymous function object (a "functor") inline, without needing a formal function declaration. It is commonly used for short, one-time operations.

Breakdown of the Given Code
cpp
auto isEven = [](int x) { return x % 2 == 0; };
This lambda expression defines a function that checks if an integer is even.

Components:
-Capture Clause ([])
Empty [] means the lambda does not capture any variables from the surrounding scope.
If variables were needed (e.g., [y]), they could be captured here.
-Parameter List ((int x))
The lambda takes one argument, an integer x.
Similar to function parameters.

-Body ({ return x % 2 == 0; })
The logic inside checks if x is even (x % 2 == 0).
Returns true if even, false otherwise.

-Return Type (Inferred)
The compiler deduces the return type (bool in this case).
Explicit return types can be specified with -> bool if needed.

-Assignment to auto isEven
The lambda is assigned to a variable isEven, making it reusable like a function.

How It Works
When called, isEven(x):
Computes x % 2 == 0.
Returns true if x is even, false otherwise.

Example Usage:
cout << isEven(4);  // Output: 1 (true)
cout << isEven(5);  // Output: 0 (false)

Why Use a Lambda Here?
-Conciseness
-Avoids writing a full function definition for a simple check.
-Locality
The logic is defined where it’s used, improving readability.
-Flexibility
-Can be passed directly to algorithms like std::find_if:
std::vector<int> v = {1, 2, 3, 4};
auto it = std::find_if(v.begin(), v.end(), isEven); // Finds 2
Key Takeaways
Syntax: [capture](parameters) { body }
-Use Case: Short, reusable predicates or operations.

Advantage: Saves boilerplate code compared to traditional function objects.

This lambda is functionally equivalent to:
bool isEvenFunction(int x) { return x % 2 == 0; }
*/