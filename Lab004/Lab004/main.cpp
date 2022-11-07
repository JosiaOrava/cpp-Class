#include <iostream>
#include <string>
#include <iomanip>

class Time
{
    private:
            int hour, min;
    public:
            void read(std::string s);
            bool lessThan(Time t);
            Time subtract(Time t);
            void display();
};

void Time::read(std::string s)
{   
    std::cout << s << std::endl;
    std::cout << "Give hours" << std::endl;
    std::cin >> hour;
    std::cout << "Give minutes" << std::endl;
    std::cin >> min;
}

bool Time::lessThan(Time t)
{
    int t1Hour = hour;
    int t1Min = min;
    int t2Hour = t.hour;
    int t2Min = t.min;
    if(t1Hour < t2Hour || (t1Hour == t2Hour && t1Min < t2Min))
    {
        return true;
    } 
    return false;
}

void Time::display()
{
    std::cout << std::setiosflags(std::ios::right); std::cout << std::setfill('0') << std::setw(2) << hour;
    std::cout << ":" << std::setfill('0') << std::setw(2) << min << std::endl;
}

Time Time::subtract(Time t)
{
    Time diff;
    int diffMin, t1Min, t2Min;

    t1Min = hour * 60 + min;
    t2Min = t.hour * 60 + t.min;
    diffMin = t1Min - t2Min;
    diff.hour = diffMin / 60;
    diff.min = diffMin % 60;
    return diff;
}

int main() {
    Time time1, time2, duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2)) 
    {
        duration = time2.subtract(time1);
        std::cout << "Starting time was ";
        time1.display();
    } else 
    {
        duration = time1.subtract(time2);
        std::cout << "Starting time was ";
        time2.display();
    }
    std::cout << "Duration was ";
    duration.display();
    return 0;
}

