#ifndef _PLAYER_
#define _PLAYER_

#include "Country.hpp"

// Forward declaration
class Match;

class Player {
protected:
    std::string name;
    int age;
    Country* nationality; // Changed to pointer type
    bool female;

public:
    Player(bool f,std::string n, int a, Country* c) {
        female=f;
        name=n;
        age=a;
        nationality=c;

    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    Country* getNationality() const {
        return nationality;
    }
    bool isFemale(){
        return female;
    }

    virtual void updateStats(Match* m) = 0;
    virtual void printStats() const = 0;


    virtual ~Player() {} // Virtual destructor
};




#endif  // _PLAYER_

