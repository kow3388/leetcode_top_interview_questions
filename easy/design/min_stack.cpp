#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    public:
        MinStack()
        {
            stack = {};
            stack_min = {};
        }
        void push(int val)
        {
            stack.push_back(val);
            if(stack_min.empty() or val <= stack_min.back())
                stack_min.push_back(val);
            else
                stack_min.push_back(stack_min.back());
        }
        void pop()
        {
            stack.pop_back();
            stack_min.pop_back();
        }
        int top()
        {
            return stack.back();
        }
        int getMin()
        {
            return stack_min.back();
        }
    private:
        vector<int> stack;
        vector<int> stack_min;
};

int main()
{
    MinStack *tmp = new MinStack();

    //cout << tmp->getMin() << endl;
    tmp->push(-2);
    tmp->push(0);
    tmp->push(-3);
    cout << tmp->getMin() << endl;
    tmp->pop();
    cout << tmp->top() << endl;
    cout << tmp->getMin() << endl;

    return 0;
}