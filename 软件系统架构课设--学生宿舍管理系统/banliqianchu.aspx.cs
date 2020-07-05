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

public partial class banliqianchu : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    public void qianchu()
    {
        SqlConnection scnn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scnn.Open();
        SqlCommand scmm = new SqlCommand("goout", scnn);
        scmm.CommandType = CommandType.StoredProcedure;

        SqlParameter param1 = null;
        param1 = scmm.Parameters.Add(new SqlParameter("@studentid", SqlDbType.Int));
        param1.Direction = ParameterDirection.Input;
        param1.Value = DropDownList1.Text;
        param1 = scmm.Parameters.Add(new SqlParameter("@studentname", SqlDbType.NChar, 10));
        param1.Direction = ParameterDirection.Input;
        param1.Value = DropDownList2.Text;
        param1 = scmm.Parameters.Add(new SqlParameter("@outtime", SqlDbType.NChar, 10));
        param1.Direction = ParameterDirection.Input;
        param1.Value = TextBox4.Text;
        param1 = scmm.Parameters.Add(new SqlParameter("@reason", SqlDbType.VarChar, 50));
        param1.Direction = ParameterDirection.Input;
        param1.Value = TextBox3.Text;
        scmm.ExecuteNonQuery();
        Label2.Text += "成功放入到out表中";
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("deletestudent", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@studentid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList1.Text;
        scm.ExecuteNonQuery();
        Label2.Text = "迁出成功^_^";
        scn.Close();

        qianchu();
        }
        catch (Exception)
        {
            //Label2.Text = "迁出失败！！";
            throw;
        }
        
    }
}
