using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    /// <summary>
    /// Example tree node that can be used 
    /// </summary>
    public class DecisionTreeNode
    {
        public DecisionTreeQuestion QuestionToAsk { get; set; }
        public DecisionTreeNode TrueResponseNode { get; set; }
        public DecisionTreeNode FalseResponseNode { get; set; }

        /// <summary>
        /// Because this is set programmatically, it is possible for this to be true and yet still have 
        /// children.  Be careful!
        /// </summary>
        public bool IsLeafNode { get; set; }

        public DecisionTreeNode EvaluateDecision(GameState state)
        {
            if(QuestionToAsk.Evaluate(state) == true)
            {
                return TrueResponseNode;
            }
            else
            {
                return FalseResponseNode;
            }
        }
    }
}
