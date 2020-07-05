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

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("updatedormitory", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList1.Text;

        param = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList2.Text;

        param = scm.Parameters.Add(new SqlParameter("@telephonenum", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = TextBox1.Text;

        param = scm.Parameters.Add(new SqlParameter("kindid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList3.Text;

        scm.ExecuteNonQuery();
        Label2.Text = "更新成功^_^";
        }
        catch (Exception)
        {
            Label2.Text = "更新失败！！";
        }
    }
}
