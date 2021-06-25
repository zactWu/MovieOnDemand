using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace movie_on_demand
{
    public class DateTimeUtils
    { 
        public static void Hello()
        {
            Console.WriteLine("Hello, this is datetime!");
        }

        public static string GetYear(string t)
        {
            var temp = t.Split('/');
            return temp[0];
        }

        public static string GetMonth(string t)
        {
            var temp = t.Split('/');
            return temp[1];
        }

        public static string GetDay(string t)
        {
            var temp = t.Split('/');
            return temp[2];
        }

        public static string GetHour(string t)
        {
            var temp = t.Split(' ')[1].Split(':');
            return temp[0];
        }

        public static string GetMinute(string t)
        {
            var temp = t.Split(' ')[1].Split(':');
            return temp[1];
        }

        public static string GetSecond(string t)
        {
            var temp = t.Split(' ')[1].Split(':');
            return temp[2];
        }

    }
}