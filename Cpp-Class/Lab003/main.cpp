#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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
std::vector<std::string> askInput(){
    std::cout << "Give strings:" << std::endl;
    std::vector<std::string> tmpS;
    std::string input;
    while(true)
    {
        std::cin >> input;
        if(input == "stop")
        {
            break;
        }
        tmpS.push_back(input);
    }
    return tmpS;
}

std::vector<double> sort(std::vector<double> vector)
{
    double left = 0, right = 0, tmp = 0;
    for(int i = 0; i < vector.size()-1; i++)
    {
        for (int j = 0; j < vector.size() -1 - i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                tmp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = tmp;
            }
        }
    }
        
    return vector;
}

void backwards(std::vector<std::string> &vec)
{
    std::string tmp;
    // reversing the whole vector
    std::reverse(vec.begin(), vec.end());
    // reversing words
    for (int i = 0; i < vec.size(); i++)
    {
        std::reverse(vec[i].begin(), vec[i].end());
    }
    
}

void exerciseA()
{
    std::vector<double> vec, sorted;
    vec = askNumbers();
    sorted = sort(vec);
    for(int i = 0; i<sorted.size(); i++)
    {
        std::cout << std::fixed << std::setprecision(3) << sorted[i] << std::endl;
    }
}

void exerciseB()
{
    std::vector<std::string> vec;
    vec = askInput();
    std::cout << "Original:" << std::endl;
    for(int i = 0; i<vec.size(); i++){
        std::cout << i+1 << ". " <<vec[i] << std::endl;
    }
    backwards(vec);
    std::cout << "\nReversed:" << std::endl;
    for(int i = 0; i<vec.size(); i++){
        std::cout << i+1 << ". " << vec[i] << std::endl;
    }

}

int main()
{
    int input;
    while(true){
        std::cout << "Exercise A (1) | Exercise B (2) | Stop (3)" << std::endl;
        std::cin >> input;
        if(input == 1)
        {
            exerciseA();
        } else if(input == 2)
        {
            exerciseB();
        } else if(input == 3)
        {
            break;
        } else
        {
            std::cout << "Give proper number." << std::endl;
        }
    }

    return 0;
}