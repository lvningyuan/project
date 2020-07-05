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

public partial class renwutongji : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("classcount", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter sprocParams = null;
        sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        sprocParams.Direction = ParameterDirection.Input;
        sprocParams.Value = DropDownList1.Text;

        sprocParams = scm.Parameters.Add(new SqlParameter("@classname", SqlDbType.Char,10));
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
        SqlConnection scn=new SqlConnection (ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("buildingstudentnum", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList5.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        SqlConnection scn=new SqlConnection (ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("classstudentnum", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@classname", SqlDbType.Char,10));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList3.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
    protected void Button4_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("majorstudentnum", scn);
        scm.CommandType = CommandType.StoredProcedure;

        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@major", SqlDbType.Char, 10));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList4.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
}
