using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using code_cs;
using System;
using UnityEngine.UI;
using System.IO;

public class GuessingGame : MonoBehaviour
{
    DecisionTreeNode rootNode;
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("hello world");
        TreeBuilder builder = new TreeBuilder();
        var nodes = builder.BuildTree();
       // nodes.ToArray;
        DecisionTreeNode[] nodeArray = nodes.ToArray();



        /* nodes is now a list of all the questions read in from the file
         * Need to use the reverse tree traversal method and build up a tree
         * out of DecisionTreeNodes*/
        rootNode = new DecisionTreeNode();
        rootNode.QuestionToAsk = nodes[0].QuestionToAsk;
        rootNode.IsLeafNode = nodes[0].IsLeafNode;

        rootNode.TrueResponseNode = null;
        rootNode.FalseResponseNode = null;
        BuildTree(rootNode, nodeArray, 1);
        Debug.Log("hello world");
        IsThisYourChoice(rootNode, null, false);

    }

    void TakeValue(DecisionTreeNode node, DecisionTreeNode[] values, int offset)
    {
        if(node.FalseResponseNode == null)
        {
            node.FalseResponseNode = values[offset];
        }
        else
        {
            node.TrueResponseNode = values[offset];
        }
        return;
    }
   void BuildTree(DecisionTreeNode node, DecisionTreeNode[] values, int offset)
    {
        if(!node.IsLeafNode)
        {
            TakeValue(node, values, offset);
            //if(!node.FalseResponseNode.IsLeafNode)
            //{
                BuildTree(node.FalseResponseNode, values, offset + 1);
           // }
           

        }
        else
        {
            TakeValue(node, values, offset);
            return;
        }
    }

    public void YbuttonPressed()
    {
        Debug.Log("You Pressed Yes");
    }

    public void NbuttonPressed()
    {
        Debug.Log("You Pressed No");
    }

    public void IsThisYourChoice(DecisionTreeNode node, DecisionTreeNode parentNode, bool lastAnswer)
    {
        if (!node.IsLeafNode)
        {
            //ask the user the y or n question
            string ask = node.QuestionToAsk.question;
            Debug.Log(ask);
            // while(!Input.GetKeyDown(KeyCode.Y) && !Input.GetKeyDown(KeyCode.N))
         //  {
            if (Input.GetKeyDown(KeyCode.Y))
            {
                Debug.Log("You Pressed Y for Yes!");
                IsThisYourChoice(node.TrueResponseNode, node, true);
            }
            else if (Input.GetKeyDown(KeyCode.N))
            {
                Debug.Log("You Pressed N for No!");
                IsThisYourChoice(node.FalseResponseNode, node, false);
            }
               
       // }

        }
        else
        {
            string ask = node.QuestionToAsk.question;
            Debug.Log(ask);
            if (Input.GetKeyDown(KeyCode.Y))
            {
                Debug.Log("You Pressed Y for Yes!");
                Debug.Log("You Win, and the Game is Over. Congratulations!!!");
             
            }
            else if (Input.GetKeyDown(KeyCode.N))
            {
                Debug.Log("You Pressed N for No!");
                Debug.Log("What is the Answer?");
                string userInput = Console.ReadLine();
                Debug.Log("What is a question that could differentiate this question from the last?");
                string newQuestion = Console.ReadLine();
                DecisionTreeNode newQuestionNode = new DecisionTreeNode();
                newQuestionNode.IsLeafNode = false;
                newQuestionNode.QuestionToAsk.question = newQuestion;
                DecisionTreeNode newLeafNode = new DecisionTreeNode();
                newLeafNode.IsLeafNode = true;
                newLeafNode.QuestionToAsk.question = userInput;


                newQuestionNode.FalseResponseNode = node;
                newQuestionNode.TrueResponseNode = newLeafNode;
              
               
                if(lastAnswer == true)
                {
                    parentNode.TrueResponseNode = newQuestionNode;
                }
                else
                {
                    parentNode.FalseResponseNode = newQuestionNode;
                }


            }

        }
    }
    
    void SaveValue(DecisionTreeNode value)
    {
        string path = Application.dataPath + "/NewTree.txt";
        //create file
        if(!File.Exists(path))
        {
            File.WriteAllText(path, value.QuestionToAsk.question);
        }
        else
        {
            File.AppendAllText(path, value.QuestionToAsk.question);
        }
    }

    //preorder traversal to save the tree
    void SaveTree(DecisionTreeNode node)
    {
        SaveValue(node);
        SaveTree(node.FalseResponseNode);
        SaveTree(node.TrueResponseNode);

            

        
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
