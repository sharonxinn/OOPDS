#include <iostream>
using namespace std;

class MathStack: public IntStack
{
    public:
    MathStack(int s): IntStack(S){}

    void add();
    void sub();
}

void MathStack::add()
{
    int num,sum;
    pop(sum);
    pop(num);

    sum+=num;
    push(sum);
}

void MathStack::sub()
{
    int num, diff;
    pop(diff); //remove
    pop(num);

    diff-=num;
    push(diff) //push into
}

int main()
{
    MathStack stack(5);

    stack.push(5);
    stack.push(7);

    stack.add();

    stack.push(5);
    stack.push(7);

    stack.sub();
    return 0;
}