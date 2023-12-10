// main.cpp

#include "Outfielder.hpp"
#include "Goalkeeper.hpp"
#include "Player.hpp"
#include "Match.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "Country.hpp"

int main() {
    // Create countries
    Country* spain = new Country("Spain");
    Country* england = new Country("England");
    Country* germany = new Country("Germany");

    // Create outfielders
    Outfielder* bellingham = new Outfielder(false, "Bellingham", 23, england);
    Outfielder* kross = new Outfielder(false, "Kross", 32, germany);
    Outfielder* kepa = new Outfielder(false, "Kepa", 27, spain);
    
    Outfielder* lamine = new Outfielder(false, "Lamine", 21, spain);
    Outfielder* terStegen = new Outfielder(false, "Ter Stegen", 29, germany);
    Outfielder* gavi = new Outfielder(false, "Gavi", 18, spain);

    // Create teams and add outfielders
    Team* madrid = new Team("Madrid", spain, Team::Gender::MALE);
    madrid->addPlayer(bellingham);
    madrid->addPlayer(kross);
    madrid->addPlayer(kepa);

    Team* barca = new Team("Barça", spain, Team::Gender::MALE);
    barca->addPlayer(lamine);
    barca->addPlayer(terStegen);
    barca->addPlayer(gavi);

    // Create and simulate a match
    Match* match = new Match(madrid, barca);
    match->simulateMatch();
    match->printMatch();

    // Update statistics of each player
    for (Player* player : madrid->getPlayers()) {
        player->updateStats(match);
    }

    for (Player* player : barca->getPlayers()) {
        player->updateStats(match);
    }

    // Print statistics of each player
    for (Player* player : madrid->getPlayers()) {
        player->printStats();
        std::cout << std::endl;
    }

    for (Player* player : barca->getPlayers()) {
        player->printStats();
        std::cout << std::endl;
    }

    // Note: Memory cleanup is omitted in this example for simplicity

    return 0;
}
