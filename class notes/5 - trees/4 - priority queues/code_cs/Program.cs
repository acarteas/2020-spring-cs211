using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Caching;

namespace code_cs
{
    class Program
    {
        static string[] GetNames()
        {
            var names = File.ReadAllLines("first_names.txt");
            return names;
        }

        static void Main(string[] args)
        {
            var names = GetNames();
            List<Patient> patients = new List<Patient>();
            for(int i = 0; i < 1000; i++)
            {
                patients.Add(Patient.GenerateRandomPatient(names));
            }

            PriortyQueue<Patient> toServe = new PriortyQueue<Patient>(patients);
            for(int i = 0; i < 10; i++)
            {
                System.Console.WriteLine("{0} is saved!", toServe.GetFirst().Name);
                toServe.Dequeue();
            }
            System.Console.WriteLine("Unfortunately, everyone else died :(");

        }

    }
}
