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
//该源码下载自www.51aspx.com(５1ａSｐｘ．ｃｏｍ)

public partial class banjiluru : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
        SqlConnection scn =new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("inclass", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@classname", SqlDbType.VarChar,10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox1.Text;

        param = scm.Parameters.Add(new SqlParameter("@major", SqlDbType.Char, 10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox2.Text;

        param = scm.Parameters.Add(new SqlParameter("@instructor", SqlDbType.Char, 10));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox3.Text;

        scm.ExecuteNonQuery();
        Label2.Text = "录入成功^_^";
        }
        catch (Exception)
        {
            Label2.Text = "录入失败！！";
        }
    }
}
