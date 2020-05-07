using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    /// <summary>
    /// Example class that can be used if you go the guessing game route
    /// </summary>
    public class AnimalNode
    {
        public string Content { get; set; }
        public AnimalNode YesNode { get; set; }
        public AnimalNode NoNode { get; set; }
        public bool IsLeafNode
        {
            get
            {
                return YesNode == null && NoNode == null;
            }
        }
    }
}
