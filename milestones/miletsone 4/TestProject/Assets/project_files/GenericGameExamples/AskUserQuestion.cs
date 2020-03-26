using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public class AskUserQuestion : DecisionTreeQuestion
    {
        public override bool Evaluate(GameState state)
        {
            //Get User Input to ask them the result of the question here.
            return true;
        }

        public AskUserQuestion(string q)
        {
            this.question = q;
        }
    }
}