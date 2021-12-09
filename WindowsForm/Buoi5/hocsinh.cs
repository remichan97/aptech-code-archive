using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Data.Sql;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buoi5
{
    
    public class hocsinh
    {
        dulieu Dulieu = new dulieu();
        public DataTable duLieuHocSinh()
        {
            /*khoi tao ket noi*/
            SqlConnection sql = new SqlConnection();
            sql.ConnectionString = Dulieu.connectString;

            /*kiem tra ket noi va mo ket noi*/
            if (sql.State == ConnectionState.Closed)
            {
                sql.Open();
            }

            SqlCommand cmd = new SqlCommand();
            cmd.Connection = sql;
            cmd.CommandText = "select*from HocSinh order by TenSinhVien";
            cmd.CommandType = CommandType.Text;

            /*thuc hien command*/

            SqlDataAdapter sqlData = new SqlDataAdapter(cmd);
            
            DataTable tableKQ = new DataTable();

            sqlData.Fill(tableKQ);

            return tableKQ;
        }

        
    }
}
