using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Buoi5
{
    public partial class Form1 : Form
    {
        hocsinh hs = new hocsinh();
        public Form1()
        {
            InitializeComponent();
            DataTable table = hs.duLieuHocSinh();
            dataGridView1.DataSource = table;
        }
    }
}
