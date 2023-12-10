// In the Outfielder.hpp file
#ifndef _OUTFIELDER_
#define _OUTFIELDER_

#include "Player.hpp"
#include "Match.hpp"
#include <iostream>
#include <random>  // Include the necessary header for random number generation


class Outfielder : public Player {
private:
    int noGoals;
    int noAssists;
    int noShoots;
    int noPasses;
    int noTackles;
    

public:
    Outfielder(bool gender, std::string name, int age, Country* nationality)
        : Player(gender,name, age, nationality), noGoals(0), noAssists(0), noShoots(0), noPasses(0), noTackles(0) {}

    int getNoGoals() const {
        return noGoals;
    }

    int getNoAssists() const {
        return noAssists;
    }

    int getNoShoots() const {
        return noShoots;
    }

    int getNoPasses() const {
        return noPasses;
    }

    int getNoTackles() const {
        return noTackles;
    }

    void updateStats(Match* m) override {
        Player::updateStats(m);

        // Assuming getTeamTwo returns a list of players
        const std::list<Player*>& teamTwoPlayers = m->getScorersTwo();
        
        for (const Player* p : teamTwoPlayers) {
            if (p->getName() == this->getName()) {
                this->noGoals +=1;
            }
        }
        const std::list<Player*>& teamOnePlayers = m->getScorersOne();
        
        for (const Player* p : teamOnePlayers) {
            if (p->getName() == this->getName()) {
                this->noGoals +=1;
            }
        }
        

        noAssists +=std::rand() %2;
        noTackles += std::rand() %10;
        noPasses += std::rand() %30;
        noShoots += std::rand() %5;
    }


    void printStats() const override {
        Player::printStats();
        std::cout << "Goles marcados: " << noGoals << std::endl;
        std::cout << "Asistencias realizadas: " << noAssists << std::endl;
        std::cout << "Entradas realizadas: " << noTackles << std::endl;
        std::cout << "Pases realizados: " << noPasses << std::endl;
        std::cout << "Tiros realizados: " << noShoots << std::endl;
    }
};

#endif  // _OUTFIELDER_

