using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace trivia
{
   public class user
    {
        public string Username { get; set; }
        public string Password { get; set; }
        public string Email { get; set; }

        public static List<user> users;
        public user(string u, string p, string e)
        {
            this.Email = e;
            this.Password = p;
            this.Username = u;
            users.Add(this);
        }
        public user()
        {

        }
    }
}
