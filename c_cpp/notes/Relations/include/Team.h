#ifndef TEAM_H
#define TEAM_H
#include <iostream>
using namespace std;
class Player{
    //---
};

class Team
{
    private:
        std::vector<Player * > players;
    public:
        Team() {
        }
        void addPlayer(Player * p){
            players.push_back(p);
        }
        void paly(){
            /*for(auto : palyers){
                player.play()
            }*/

        }

        ~Team() {
            //clear vector
            players.clear();
            //Loop Vector delete pointer pointer
        }

    protected:


};

#endif // TEAM_H
