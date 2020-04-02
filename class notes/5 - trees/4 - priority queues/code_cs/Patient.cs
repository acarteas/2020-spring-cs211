using System;
using System.Collections.Generic;
using System.Text;

namespace code_cs
{
    public enum Severity { Low = 1, Medium, High, Extreme};

    public class Patient : IComparable<Patient>
    {
        public int Score
        {
            get
            {
                return (int)Severity * (Age + Health);
            }
        }

        public int Age { get; set; }
        public int Health { get; set; }
        public Severity Severity { get; set; }
        public string Name { get; set; }

        public int CompareTo(Patient obj)
        {
            Patient other = obj as Patient;

            //can only compare Patients
            if(other == null)
            {
                return 0;
            }
            if(Score > other.Score)
            {
                return -1;
            }
            if(Score == other.Score)
            {
                return 0;
            }
            return 1;
        }

        public static Patient GenerateRandomPatient(string[] names)
        {
            Random rng = new Random();
            Patient p = new Patient();
            p.Age = rng.Next(1, 100);
            p.Health = rng.Next(1, 100);
            p.Severity = (Severity)rng.Next(1, 4);
            p.Name = names[rng.Next(0, names.Length - 1)];
            return p;
        }
    }
}
