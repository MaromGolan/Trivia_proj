using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace trivia
{
    class Message
    {
        public int type;
        public string message;
        
        public Message(int type, string message)
        {
            this.type = type;
            this.message = message;
        }
        public Message(Message m)
        {
            this.type = m.type;
            this.message= m.message;
        }

    }
}
