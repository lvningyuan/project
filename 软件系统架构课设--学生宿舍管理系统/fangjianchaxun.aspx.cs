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

public partial class fangjianchaxun : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            ArrayList arry = new ArrayList();
            arry.Add("男");
            arry.Add("女");
            DropDownList3.DataSource = arry;
            DropDownList3.DataBind();
        }
    }
    protected void Button4_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("dormitoryid", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList1.Text;

        sprocParams = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList2.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("telephonenum", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@telephonenum", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = TextBox2.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("peoplenum", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@peoplenum", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = TextBox3.Text;

        sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList4.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
}
