using System;
using System.Collections.Generic;

namespace code_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            //in C#, Vectors are called Lists
            List<int> numbers = new List<int>();

            //add numbers
            for(int i = 0; i < 100; i++)
            {
                numbers.Add(i);  //same as push_back
            }

            //Pattern for READ
            for(int i = 0; i < numbers.Count; i++)
            {
                Console.WriteLine(numbers[i].ToString());
            }
            foreach(var number in numbers)
            {
                Console.WriteLine(number);
            }
        }
    }
}
