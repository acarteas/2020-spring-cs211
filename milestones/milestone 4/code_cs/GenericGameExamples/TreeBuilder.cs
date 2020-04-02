using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public class TreeBuilder
    {
        /// <summary>
        /// Grabs all tree nodes from the file.  The resulting list will have to be post processed into an actual
        /// tree using recursion with another function.
        /// </summary>
        public List<DecisionTreeNode> BuildTree()
        {
            //Reflection required assembly name to instantiate objects
            var assemblyPrefix = typeof(DecisionTreeQuestion).Assembly.FullName.Split(',')[0];
            List<DecisionTreeNode> nodes = new List<DecisionTreeNode>();

            string[] lines = System.IO.File.ReadAllLines("GameTree.txt");
            foreach (var line in lines)
            {
                DecisionTreeNode node = new DecisionTreeNode();
                string className = line;

                //leaf node
                if(line.Length > 0 && line[0] == '*')
                {
                    //take out asterisk
                    className = line.Substring(1);

                    //mark as leaf node
                    node.IsLeafNode = true;
                }

                //attach evaluator function to this node
                className = assemblyPrefix + "." + className;
                var type = Type.GetType(className);
                var question = (DecisionTreeQuestion)Activator.CreateInstance(type);
                node.QuestionToAsk = question;
                nodes.Add(node);
            }
            return nodes;
        }
    }
}
