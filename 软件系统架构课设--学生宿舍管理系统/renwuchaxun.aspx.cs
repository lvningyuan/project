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

public partial class renwuchaxun : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("dbo.StoredProcedure11", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList1.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button9_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("name", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@name", SqlDbType.VarChar,10));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value =TextBox3.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button8_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("xuehao", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@studentid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = TextBox2.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button7_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("dbo.StoredProcedure8", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = TextBox1.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button6_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("classname", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@classname", SqlDbType.Char,10));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList4.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button5_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("major", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@major", SqlDbType.Char,10));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList3.Text;
        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
}
