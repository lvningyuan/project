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

public partial class fangjiantongji : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("dormitorycount", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter nwparam = null;
        nwparam = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        nwparam.Direction = ParameterDirection.Input;
        nwparam.Value = DropDownList1.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
}
