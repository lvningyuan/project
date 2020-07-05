<%@ Page Language="C#" AutoEventWireup="true" CodeFile="fangjiantongji.aspx.cs" Inherits="fangjiantongji" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>房间统计</title>
    <style type="text/css">
        .style1
        {
            width: 47%;
        }
        .style2
        {
            width: 211px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 326px; text-align: center; width: 535px;">
    
        <asp:Label ID="Label1" runat="server" Text="房间统计"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    楼号：</td>
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
            </table>
        <br />
        <asp:Button ID="Button1" runat="server" Text="统计" onclick="Button1_Click" />
    
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
        <br />
    
    </div>
    </form>
</body>
</html>
