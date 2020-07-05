using System;
using System.Collections;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using System.Data.SqlClient;

public partial class banjixinxixiugai : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection scn=new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("updateclass", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@classnamee", SqlDbType.VarChar, 10));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList1.Text;

        param = scm.Parameters.Add(new SqlParameter("@classname", SqlDbType.VarChar,10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox1.Text;

        param = scm.Parameters.Add(new SqlParameter("@major", SqlDbType.Char,10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox2.Text;

        param = scm.Parameters.Add(new SqlParameter("@instructor", SqlDbType.Char,10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox3.Text;

        param = scm.Parameters.Add(new SqlParameter("@classmoniter", SqlDbType.Char,10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox4.Text;
        scm.ExecuteNonQuery();
        Label2.Text = "修改成功^_^";
    }
}
