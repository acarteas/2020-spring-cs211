using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using code_cs;

public class GuessingGame : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("hello world");
        TreeBuilder builder = new TreeBuilder();
        var nodes = builder.BuildTree();

        /* nodes is now a list of all the questions read in from the file
         * Need to use the reverse tree traversal method and build up a tree
         * out of DecisionTreeNodes*/
        DecisionTreeNode rootNode = new DecisionTreeNode();
        rootNode.QuestionToAsk = nodes[0].QuestionToAsk;
        rootNode.IsLeafNode = nodes[0].IsLeafNode;

        rootNode.TrueResponseNode = null;
        rootNode.FalseResponseNode = null;

    }

    // Update is called once per frame
    void Update()
    {
        /* Step 1
         *Until we reach a leaf node:
            Output the value of the node (i.e. next question to ask, "e.g. does it have fur?")
                If the user's response is "yes", pull the next question from the right child
                If the user's response is "no", pull the next question from the left child */





        /* Step 2
         * Once at a leaf node:
           Read the value of the leaf node, which should be a question (e.g. "is it a dog?")
            If the answer is yes, output that you win and that the game is over
            If the answer is no:
                Ask the user for the correct answer (e.g. "cat")
             Ask the user for a new question, "What is a question that I can use to differentiate between my guess and your answer" (example response, "does it purr?")
                Remember the question and the answer, restructure tree accordingly
         */




        /* Step 3
         * You want to save this tree the user has built.
         * Use a Traversal Method (the same one you used to read the file above)
         * To save each node in the tree into a new list, using that traversals order.
         * 
         * Then write that list to your save file "AnimalGame.txt" line by line.
         */

    }
}
