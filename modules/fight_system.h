#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

class fight_system: Sprite{

   public:
      fight_system(){
      # from the first round
         Turn_num = 1;
         level_fight_value = level;
         exp_fight_value = exp;
         attack_fight_value = attack;
         HP_fight_value = HP;
      }

      enemy(){

      }




      
   private:
   # The number of turns during the game battle
      int Turn_num; 
   # The value of the change (consumption) during the battle on game
      int level_fight_value;
      int exp_fight_value;
      int attack_fight_value;
      int HP_fight_value;
};

