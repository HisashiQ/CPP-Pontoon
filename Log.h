//
// Created by Quinn Koike on 14/03/2017.
//

#ifndef PONTOON_LOG_H
#define PONTOON_LOG_H


#include <string>
#include <vector>

class Log {
public:
    Log();
    const std::string getPrintableTime();
    void endRound(int);
    void ioOut();

private:
    std::vector<int> rounds;
    std::string startTime;
    std::string fileName;

//  Helper methods to access each element of time
    std::string getHour();
    std::string getMin();
    std::string getDay();
    std::string getMonth();
    std::string getYear();

//  Turns numbered month to string i.e 2 = February
    std::string translateMonth(std::string);
    const std::array<int, 3> getTotalScore();
};


#endif //PONTOON_LOG_H
