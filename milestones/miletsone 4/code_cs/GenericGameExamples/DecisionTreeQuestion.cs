using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public interface DecisionTreeQuestion
    {
        bool Evaluate(GameState state);
    }
}
