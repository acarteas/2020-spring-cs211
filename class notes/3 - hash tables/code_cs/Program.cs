using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace code_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            List<PrintJob> jobs = new List<PrintJob>();
            foreach(var item in File.ReadLines("printer_log.csv"))
            {
                List<string> pieces = item.Split(',').ToList();
                if(pieces.Count == 4)
                {
                    try 
                    {
                        PrintJob job = new PrintJob();
                        job.Date = DateTime.Parse(pieces[0]);
                        job.Page = Int32.Parse(pieces[1]);
                        job.UserId = Int32.Parse(pieces[2]);
                        job.PrinterId = Int32.Parse(pieces[3]);
                        jobs.Add(job);
                    }
                    catch(Exception ex)
                    {

                    }
                    
                }
            }

            //in C# a HT is called a dictionary
            Dictionary<DateTime, int> dates = new Dictionary<DateTime, int>();
            foreach(var job in jobs)
            {
                if(dates.ContainsKey(job.Date) == false)
                {
                    dates.Add(job.Date, 0);
                }
                dates[job.Date] += job.Page;
            }
            DateTime max_date = DateTime.MinValue;
            int max_pages = -1;
            foreach(var kvp in dates)
            {
                if(kvp.Value > max_pages)
                {
                    max_pages = kvp.Value;
                    max_date = kvp.Key;
                }
            }
            Console.WriteLine("pages: " + max_pages + " date: " + max_date);
        }
    }
}
