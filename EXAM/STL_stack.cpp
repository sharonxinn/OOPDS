const int MAX=8;
int count;

//Define an STL stack
stack<int, vector<int>>iStack;

for (count=0;count<MAX; count++)
{
    iStack.push(count);
}

iStack.size();

for (count=0;count<MAX; count++)
{
    iStack.pop(count);
}
