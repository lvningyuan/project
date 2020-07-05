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

public partial class fangjianshanchu : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
        SqlConnection scn=new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("deletedormitory2", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList1.Text;

        param = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList2.Text;
        scm.ExecuteNonQuery();
        Label2.Text = "删除成功^_^";
        }
        catch (Exception)
        {
            Label2.Text = "删除失败！！";
        }
    }
}
