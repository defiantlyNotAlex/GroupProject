#ifndef PLAYERTURN_H
#define PLAYERTURN_H

#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

class player_turn{

   public:
      player_turn(){
       // Count the Turns of player
         player_Turn = 0;
         enemy_Turn = 0;
      }
      
      int player_Turning(int HP){
        // if HP more than 0, the player continue fight
        for (int i=0; HP>0; i++){
          player_Turn = player_Turn+1;
          // When the player turns number more than enemy turns, than for loop break.
          if (player_Turn==enemy_Turn+1){
             break;
          }
        }
        // return to player turns number and output text
        return player_Turn;
        std::cout << player_Turn << std::endl; 
      }

   private:
    // The number of turns during the game battle
      int player_Turn;
      int enemy_Turn;

};