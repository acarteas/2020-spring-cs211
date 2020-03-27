using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public abstract class DecisionTreeQuestion
    {
        public string question = "";
        public abstract bool Evaluate(GameState state);
    }
}
