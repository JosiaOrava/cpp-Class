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
        if(input == "stop" || input == "STOP")
        {
            break;
        }
        tmpS.push_back(input);
    }
    return tmpS;
}

// FOR EXERCISE A
std::vector<double> sort(std::vector<double> vector)
{
    std::sort(vector.begin(), vector.end());
        
    return vector;
}

// FOR EXERCISE B
void backwards(std::vector<std::string> &vec)
{
    
    // reversing words
    for (int i = 0; i < vec.size(); i++)
    {
        std::reverse(vec[i].begin(), vec[i].end());
    }
    // alphabetical order and reversing whole vec
    std::sort(vec.begin(), vec.end());
    std::reverse(vec.begin(), vec.end());
}

void exerciseA()
{
    std::vector<double> vec, sorted;
    vec = askNumbers();
    //sorted = sort(vec);
    sort(vec.begin(), vec.end());
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