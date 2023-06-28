using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace trivia
{
    public class room
    {
        public string RoomName { get; set; }
        public int TimePerQuestion { get; set; }
        public int NumberOfPlayers { get; set; }
        public user[] ingame;
        public bool started;

        public room(string n, int t, int num, user u)
        {
            this.RoomName = n;
            this.TimePerQuestion = t;
            this.NumberOfPlayers = num;
            this.ingame = new user[NumberOfPlayers];
            ingame[0] = u;
            started = false;
        }
        public void AddUser(user u)
        {
            for(int i = 0; i < this.ingame.Length; i++)
            {
                if(ingame[i] == null)
                {
                    ingame[i] = u;
                    break;
                }
            }
        }

    }
}
