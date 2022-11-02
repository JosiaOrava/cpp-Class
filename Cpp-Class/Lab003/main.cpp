#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<double> askNumbers()
{
    std::cout << "Give number: " << std::endl;
    std::vector<double> tmp;
    double x;
    while(true)
    {
        std::cin >> x;
        if(x < 0)
        {
            break;
        }
        tmp.push_back(x);
    }
    return tmp;
}

std::vector<double> sort(std::vector<double> vector)
{
    double left = 0, right = 0, tmp = 0;
    
    for(int i = 0; i < vector.size(); i++)
    {
        for (int j = 0; j < vector.size() - i; j++)
        {
            left = vector[j];
            right = vector[j+1];
            if(left > right)
            {
                tmp = right;
                right = left;
                left = tmp;
                vector[j] = left;
                vector[j+1] = right;
                
            }
        }
    }
        
    return vector;
}

int main()
{
    std::vector<double> vec, sorted;
    vec = askNumbers();
    sorted = sort(vec);
    for(int i = 0; i<sorted.size(); i++)
    {
        std::cout << sorted[i] << std::endl;
    }

    return 0;
}