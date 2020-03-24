using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public class ScoreGreaterThanOneHundred : DecisionTreeQuestion
    {
        public bool Evaluate(GameState state)
        {
            if(state.Score > 100)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
