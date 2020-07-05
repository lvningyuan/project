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

public partial class fanjianguanli : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        try
        {
            SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            scn.Open();
            SqlCommand scm = new SqlCommand("dbo.StoredProcedure3", scn);
            scm.CommandType = CommandType.StoredProcedure;

            SqlParameter sprocParams = null;
            sprocParams = scm.Parameters.Add(new SqlParameter("@kindid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox4.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@standardamount", SqlDbType.Char,10));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox5.Text;
      
            sprocParams = scm.Parameters.Add(new SqlParameter("@standardfee", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox6.Text;
            scm.ExecuteNonQuery();
            Label3.Text = "录入成功^_^";
        }
        catch (Exception)
        {
            Label3.Text = "录入失败！！！";
        }
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
            SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            scn.Open();
            SqlCommand scm = new SqlCommand("dbo.StoredProcedure4", scn);
            scm.CommandType = CommandType.StoredProcedure;

            SqlParameter sprocParams = null;
            sprocParams = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox1.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList1.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@kindid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList2.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@telephonenum", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox3.Text;
            scm.ExecuteNonQuery();
            Label2.Text = "录入成功^_^";
        }
        catch (Exception)
        {
            Label2.Text = "录入失败！！！";
        }
    }
}
