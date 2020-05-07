using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public class ScoreGreaterThanOneHundred : DecisionTreeQuestion
    {
        public override bool Evaluate(GameState state)
        {
            //Get User Input to ask them the result of the question here.
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
