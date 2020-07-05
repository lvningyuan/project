<%@ Page Language="C#" AutoEventWireup="true" CodeFile="xiugailoufang.aspx.cs" Inherits="xiugailoufang" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>修改楼房</title>
    <style type="text/css">
        .style1
        {
            width: 52%;
        }
        .style2
        {
            width: 161px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 382px; text-align: center; width: 558px;">
    
        <br />
        <asp:Label ID="Label1" runat="server" Text="修改楼房"></asp:Label>
        <table class="style1">
            <tr>
                <td class="style2">
                    宿舍楼楼号：</td>
                <td>
                    <asp:DropDownList ID="DropDownList1" runat="server" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [buildingid] FROM [building]"></asp:SqlDataSource>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼楼管：</td>
                <td>
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼层数：</td>
                <td style="text-align: center">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼面积：</td>
                <td>
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
            </tr>
        </table>
        <asp:Label ID="Label2" runat="server"></asp:Label>
        <br />
        <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="更新" />
    
    </div>
    </form>
</body>
</html>
