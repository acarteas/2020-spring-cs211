using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public class PlayerIsDead : DecisionTreeQuestion
    {
        public bool Evaluate(GameState state)
        {
            if(state.Health == 0)
            {
                return true;
            }
            return false;
        }
    }
}
