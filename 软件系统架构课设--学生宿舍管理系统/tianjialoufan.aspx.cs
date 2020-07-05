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

public partial class tianjialoufan : System.Web.UI.Page
{
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
            string sex;
            if (RadioButton1.Checked)
                sex = "男";
            else
                sex = "女";
            SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            scn.Open();
            SqlCommand scm = new SqlCommand("dbo.StoredProcedure2", scn);
            scm.CommandType = CommandType.StoredProcedure;

            SqlParameter sprocParams = null;
            sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox1.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@administrator", SqlDbType.VarChar, 10));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox2.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@flooramount", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox3.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@areaamount", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox4.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@buildingsex", SqlDbType.Char, 2));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = sex;
            scm.ExecuteNonQuery();
            Label2.Text = "录入成功^_^";
        }
        catch (Exception)
        {
            Label2.Text = "录入失败！！";
            throw;
        }
        
    }
    protected void TextBox2_TextChanged(object sender, EventArgs e)
    {

    }
}
