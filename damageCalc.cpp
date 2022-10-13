int damageCalculator(int attackStat, int defenceStat, int type1, int type2)
{ // type 1 is defender type 2 is attacker
    damageMultiplier = 1;
        // TYPE DAMAGE

    switch (type1) // 1 = rock, 2 = paper, 3 = scissors
    {
    case 1:
        switch (type2)
        {
        case 2:
            damageMultiplier *= 2;
            break;
        case 3:
            damageMultiplier *= 0.5;
            break;
        }
        break;
    case 2:
        switch (type2)
        {
        case 3:
            damageMultiplier *= 2;
            break;
        case 1:
            damageMultiplier *= 0.5;
            break;
        }
        break;
    case 3:
        switch (type2)
        {
        case 1:
            damageMultiplier *= 2;
            break;
        case 2:
            damageMultiplier *= 0.5;
            break;
        }
        break;
    }
        // TYPE DAMAGE

    return (attackStat/defenceStat)*damageMultiplier;

}