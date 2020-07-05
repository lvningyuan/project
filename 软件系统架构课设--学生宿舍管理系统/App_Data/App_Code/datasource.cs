using System;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using System.Data.SqlClient;
/// <summary>
///datasource 的摘要说明
/// </summary>
//该源码下载自www.51aspx.com(５１AｓPｘ．ｃｏｍ)

public class datasource
{
    private string ConnString;
    private SqlConnection SqlCon;
    private SqlCommand SqlCmd;
    private SqlDataAdapter sda;
    private SqlDataReader sdr;
    private DataSet ds;
    public datasource()
    {
        SqlCon=new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
       // SqlCon.Open();
        SqlCmd = new SqlCommand();
        sda = new SqlDataAdapter();
        ds = new DataSet();
    }
    public DataSet find()
    {
        sda.SelectCommand = new SqlCommand("select * from name", SqlCon);
        sda.Fill(ds);
        return ds;
    }
    public void updata(int ID, string MyName)
    {
        SqlCmd.CommandText = "update [name] set [MyName]='" + MyName + "' where [ID]= '" + ID + "'";
        //SqlCmd.CommandText="update [name] set [MyName]=MyName where [ID]=ID";
        SqlCmd.Connection = SqlCon;
        SqlCon.Open();
        SqlCmd.ExecuteNonQuery();
    }
    public void delete(int ID)
    {
        SqlCmd.CommandText = "delete from [name] where [ID]=ID";
        SqlCmd.Connection = SqlCon;
        SqlCon.Open();
        SqlCmd.ExecuteNonQuery();
    }
}
