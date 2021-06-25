using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;

namespace movie_on_demand
{
    public class Encoder
    {
        private static string TimeSample = "2020/6/8 16:58:55";

        public static string MD5Encoder(string s)
        {

            MD5 md = MD5.Create();
            string encoded = "";

            byte[] bytes = md.ComputeHash(System.Text.Encoding.UTF8.GetBytes(s));

            foreach (byte b in bytes)
            {

                encoded += b.ToString();

            }
            return encoded;
        }
    }
}