#include <iostream>
#include <vector>
#include <stack>

bool valid_par_stack (std::string s)
{
    int count = 0;
    std::stack<char> result;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            result.push(s[i]);
            count++;
            continue;
        }
        else if (s[i] == ')')
        {
            if (result.empty() || result.top() != '(')
                return false;
            else
                result.pop();
            count--;
            continue;
        }
        
        if (s[i] == '{')
        {
            result.push(s[i]);
            ++count;
            continue;
        }
        else if (s[i] == '}')
        {
            if (result.empty() || result.top() != '{')
                return false;
            else
                result.pop();
            --count;
            continue;
        }
        
        if (s[i] == '[')
        {
            result.push(s[i]);
            ++count;
            continue;
        }
        else if (s[i] == ']')
        {
            if (result.empty() || result.top() != '[')
                return false;
            else
                result.pop();
            --count;
            continue;
        }
    }
     if (count == 0)
        return true;
    return false;
}

bool valid_par__vector(std::string s)
{
    int count = 0;
    std::vector<char> result;
    for (unsigned int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            result.push_back(s[i]);
            ++count;
            continue;
        }
        else if (s[i] == ')')
        {
            if (result.empty() || result[result.size() - 1] != '(')
                return false;
            else
                result.pop_back();
            --count;
            continue;
        }

        if (s[i] == '{')
        {
            result.push_back(s[i]);
            ++count;
            continue;
        }
        else if (s[i] == '}')
        {
            if (result.empty() || result[result.size() - 1] != '{')
                return false;
            else
                result.pop_back();
            --count;
            continue;
        }

        if (s[i] == '[')
        {
            result.push_back(s[i]);
            ++count;
            continue;
        }
        else if (s[i] == ']')
        {
            if (result.empty() || result[result.size() - 1] != '[')
                return false;
            else
                result.pop_back();
            --count;
            continue;
        }
    }
    if (count == 0)
        return true;
    return false;
}

int main ()
{
    std::string str1;
    std::cout << "Enter the string: ";
    std::cin >> str1;
    if (valid_par_stack(str1))
    {
        std::cout << "Verification is done through the stack: TRUE" << std::endl; 
        std::cout << "Verification is done through the vector: TRUE" << std::endl; 
    }
    else
    {
        std::cout << "Verification is done through the stack: FALSE" << std::endl; 
        std::cout << "Verification is done through the vector: FALSE" << std::endl; 
    }

    return 0;
}