//
// Created by Quinn Koike on 14/03/2017.
//

#include <sstream>
#include <iostream>
#include <fstream>
#include <array>
#include "Log.h"

Log::Log() {
    startTime = getPrintableTime();
    fileName = getYear() + getMonth() + getDay() + "_" + getHour() + getMin() + ".txt";
}

std::string Log::getHour() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;
    std::stringstream h;
    h << hour;
    std::string time = h.str();
    return time;
}

std::string Log::getMin() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_min;
    std::stringstream m;
    m << hour;
    std::string minutes = m.str();
    return minutes;
}

std::string Log::getYear() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int yearNow = ltm->tm_year - 100;
    std::stringstream y;
    y << yearNow;
    std::string year = y.str();
    return year;
}

std::string Log::getDay() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int dayNow = ltm->tm_mday;
    std::stringstream d;
    d << dayNow;
    std::string day = d.str();
    return day;
}

std::string Log::getMonth() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int monthNow = ltm->tm_mon;
    std::stringstream m;
    m << (monthNow + 1);
    std::string month = m.str();
    return month;
}

std::string Log::translateMonth(std::string month) {
    if (month == "1"){
        return "Jan";
    } else if (month == "2"){
        return "Feb";
    } else if (month == "3"){
        return "Mar";
    } else if (month == "4"){
        return "Apr";
    } else if (month == "5"){
        return "May";
    } else if (month == "6"){
        return "Jun";
    } else if (month == "7"){
        return "Jul";
    } else if (month == "8"){
        return "Aug";
    } else if (month == "9"){
        return "Sep";
    } else if (month == "10"){
        return "Oct";
    } else if (month == "11"){
        return "Nov";
    } else if (month == "12"){
        return "Dec";
    } else {
        throw "Invalid months error";
    }
}

const std::string Log::getPrintableTime() {
    std::string time = getHour() + ":" + getMin() + " " + getDay() + "-" + translateMonth(getMonth()) + "-20" + getYear();
    return time;
}

void Log::endRound(int outcome) {
    rounds.push_back(outcome);
}

void Log::ioOut() {
    std::string started = "Game started at: " + startTime + "\n";
    std::string ended = "Game ended at: " + getPrintableTime() + "\n";
    std::array<int, 3> score = getTotalScore();
    int wins = score[0];
    int loses = score[1];
    long totalRounds = rounds.size();

    // String streams to cast from int to printable strings
    std::stringstream rc;
    std::stringstream r;
    std::stringstream w;
    std::stringstream l;
    r << totalRounds;
    w << wins;
    l << loses;
    std::ofstream logfile;

//  If the file exists because the program was started more than once, then append instead of overwriting the file.

    if (std::ifstream(fileName)){
        try {
            logfile.open(fileName, std::ios_base::app);
            logfile << "\n\n\n***************** NEW GAME STARTED WITHIN THE SAME MINUTE ********************\n\n\n";
        } catch (...){
            std::cout << "File exists. Error opening - Filename: " + fileName << std::endl;
        }
    } else {
        try {
            logfile.open (fileName);
        } catch(...){
            std::cout << "File does not exist. Error opening - Filename: " + fileName << std::endl;
        }
    }
    logfile << started + ended + "Rounds: " + r.str() + "\n" + "Wins: " + w.str() + "\n" + "Loses: " + l.str() + "\n\n" + "----" + "\n\n";
    for (int i = 0; i < rounds.size(); i++){
        rc << i;
        if (rounds[i] == 1){
            logfile << "Round " + rc.str() + ":" + " Won" + "\n";
        } else if (rounds[i] == 2) {
            logfile << "Round " + rc.str() + ":" + " Lost" "\n";
        } else {
            logfile << "Round " + rc.str() + ":" + " Draw" "\n";
        }
        rc.str("");
    }
    logfile.close();
}


const std::array<int, 3> Log::getTotalScore() {
    int wins = 0;
    int lose = 0;
    int draw = 0;
    for (int i = 0; i < rounds.size(); i++){
        if(rounds[i] == 1){
            wins += 1;
        } else if (rounds[i] == 2) {
            lose += 1;
        } else {
            draw += 1;
        }
    }
    std::array<int, 3> score = {wins, lose, draw};
    return score;
};
