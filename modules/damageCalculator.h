int damageCalculator(int attackStat, int defenceStat, int type1, int type2)
{ // type 1 is defender type 2 is attacker
    int damageMultiplier = 1;
    // TYPE DAMAGE
    
    // 1 = rock, 2 = paper, 3 = scissors
    switch (type1) // damage multipliers for all combinations of attaker and defender types
    {
    case 1: // rock defence
        switch (type2)
        {
        case 2: // paper attack
            damageMultiplier *= 2;
            break;
        case 3: // scissor attack
            damageMultiplier *= 0.5;
            break;
        }
        break;
    case 2: // paper defence
        switch (type2)
        {
        case 3: // scissor attack
            damageMultiplier *= 2;
            break;
        case 1: // rock attack
            damageMultiplier *= 0.5;
            break;
        }
        break;
    case 3: // scissor defence
        switch (type2)
        {
        case 1: // rock attack
            damageMultiplier *= 2;
            break;
        case 2: // paper attack
            damageMultiplier *= 0.5;
            break;
        }
        break;
    }
    // TYPE DAMAGE
    int damage = (attackStat / defenceStat) * damageMultiplier; // calculate damage
    if (damage == 0) { // if the damage is 0 then make it 1
        damage = 1;
    }

    return damage; // return the damge calculated

}