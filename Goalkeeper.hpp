#ifndef _GOALKEEPER_
#define _GOALKEEPER_

#include "Player.hpp"
#include "Match.hpp"

class Goalkeeper : public Player {
private:
    int noSaves;
    int noGoalsLet;

public:
    // Constructor
    Goalkeeper(Team::Gender gender, std::string name, int age, Country* nationality) : Player( gender,name, age, nationality), noSaves(0), noGoalsLet(0) {}

    // Getter methods
    int getNoSaves() const {
        return noSaves;
    }

    int getNoGoalsLet() const {
        return noGoalsLet;
    }
    
    // Additional methods
    void makeSave() {
        noSaves++;
    }

    void letInGoal() {
        noGoalsLet++;
    }

    // Override methods
    void updateStats(Match* m) override {
        // Assuming getTeamTwo returns a list of players
       
        
        noSaves += rand() %10;
        int Awayplayer = 0;
        const std::list<Player*>& teamTwoPlayers = m->getTeamOne()->getPlayers();
     for (Player* p : teamTwoPlayers) {
        if (p->getName()==this->getName() ) {
            noGoalsLet = m->getGoalTwo();
            Awayplayer=1;
        }
     }
     if (Awayplayer==1){
        noGoalsLet=m->getGoalOne();
        }

    }

    void printStats() const override {
        Player::printStats();
        std::cout << "Atajadas realizadas: " << noSaves << std::endl;
        std::cout << "Goles permitidos: " << noGoalsLet << std::endl;
    }
    
};

#endif  // _GOALKEEPER_