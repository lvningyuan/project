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
using System.Collections;
using System.Data.SqlClient;
public partial class banlirenyuanruzhu : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            ArrayList arry = new ArrayList();
            arry.Add("男");
            arry.Add("女");
            DropDownList4.DataSource = arry;
            DropDownList4.DataBind();
        }
        else
        {
            
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
            SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
            scn.Open();
            SqlCommand scm = new SqlCommand("dbo.StoredProcedure1", scn);
            scm.CommandType = CommandType.StoredProcedure;

            SqlParameter sprocParams = null;
            sprocParams = scm.Parameters.Add(new SqlParameter("@studentid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox1.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@studentname", SqlDbType.VarChar, 10));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox2.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList1.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList2.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@bedid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox7.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@studentsex", SqlDbType.Char, 2));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList4.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@studentage", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox4.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@stayingtime", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox3.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@classname", SqlDbType.Char, 10));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList5.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@intime", SqlDbType.Char, 10));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = TextBox5.Text;

            sprocParams = scm.Parameters.Add(new SqlParameter("@classid", SqlDbType.Int));
            sprocParams.Direction = ParameterDirection.Input;
            sprocParams.Value = DropDownList6.Text;
            if (scm.ExecuteNonQuery() > 0)
                Label2.Text = "录入成功^_^";
            else
                Label2.Text = "录入失败！！";
        }
        catch (Exception)
        {
            Label2.Text = "录入失败！！";
        }
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        SqlConnection scn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
        scn.Open();
        SqlCommand scm = new SqlCommand("standardamount", scn);
        scm.CommandType = CommandType.StoredProcedure;
        SqlParameter param = null;
        param = scm.Parameters.Add(new SqlParameter("@buildingid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList1.Text;

        param = scm.Parameters.Add(new SqlParameter("@dormitoryid", SqlDbType.Int));
        param.Direction = ParameterDirection.Input;
        param.Value = DropDownList2.Text;

        SqlDataAdapter sda = new SqlDataAdapter(scm);
        DataSet ds = new DataSet();
        sda.Fill(ds);
        DropDownList8.DataSource = ds;
        DropDownList8.DataBind();
    }
}
