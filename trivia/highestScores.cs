using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace trivia
{
    public partial class highestScores : Form
    {
        private string lastPage { set; get; }
        public highestScores(string lastPage)
        {
            InitializeComponent();
            this.lastPage = lastPage;   
        }
        private void highestScores_Load(object sender, EventArgs e)
        {

        }
    }
}
