using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buoi5
{
    public class dulieu
    {
        public string connectString { get; set; }

        public dulieu()
        {
            this.connectString = ConfigurationManager.ConnectionStrings["sqlstring"].ConnectionString;
        }
    }
}
