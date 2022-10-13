#ifndef ENEMYTURN_H
#define ENEMYTURN_H

#include "Enemy.h"
#include "PlayerTurn.h"
#include <iostream>

using namespace std;

// Use playerturn.h assignment in here.
class enemy_turn: public player_turn {

   public:
      enemy_turn(){
       // Add a count variable for enemyturn
       Enemy_Turn_num = enemy_Turn;
      }
      
      int enemy_Turning(int HP){
        // if HP more than 0, the enemy continue fight
        for (int i=0; HP>0; i++){
          Enemy_Turn_num = Enemy_Turn_num+1;
          // Stop when the enemy and the player have the same number of turns
          if (Enemy_Turn_num == player_Turn){
             break;
          }
        }
        // get num
        enemy_Turn = Enemy_Turn_num;
        // Returns enemy_Turn of playerturn class.
        return enemy_Turn;
      }
      ~enemy_turn() {}

   private:
    // The number of turns during the game battle
      int Enemy_Turn_num;

};

#endif