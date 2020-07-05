<%@ Page Language="C#" AutoEventWireup="true" CodeFile="renwuchaxun.aspx.cs" Inherits="renwuchaxun" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>人物查询</title>
    <style type="text/css">
        .style1
        {
            width: 74%;
            height: 212px;
        }
        .style2
        {
            width: 169px;
        }
        .style3
        {
            width: 206px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 399px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" Text="人物查询"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    楼号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList1" runat="server" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid" Width="80px">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [buildingid] FROM [building]"></asp:SqlDataSource>
                </td>
                <td>
                    <asp:Button ID="Button3" runat="server" onclick="Button3_Click" Text="查询" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    专业：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList3" runat="server" Width="80px" 
                        DataSourceID="SqlDataSource3" DataTextField="major" DataValueField="major">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT DISTINCT major FROM class"></asp:SqlDataSource>
                </td>
                <td>
                    <asp:Button ID="Button5" runat="server" onclick="Button5_Click" Text="查询" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    班级：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList4" runat="server" Width="80px" 
                        DataSourceID="SqlDataSource2" DataTextField="classname" 
                        DataValueField="classname">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [classname] FROM [class]"></asp:SqlDataSource>
                </td>
                <td>
                    <asp:Button ID="Button6" runat="server" onclick="Button6_Click" Text="查询" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="Button7" runat="server" onclick="Button7_Click" Text="查询" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    学号：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="Button8" runat="server" onclick="Button8_Click" Text="查询" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    姓名：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="Button9" runat="server" onclick="Button9_Click" Text="查询" />
                </td>
            </tr>
        </table>
        <br />
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
    
    </div>
    </form>
</body>
</html>
