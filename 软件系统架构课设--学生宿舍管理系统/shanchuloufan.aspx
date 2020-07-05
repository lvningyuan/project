<%@ Page Language="C#" AutoEventWireup="true" CodeFile="shanchuloufan.aspx.cs" Inherits="shanchuloufan" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>删除楼房</title>
    <style type="text/css">
        .style1
        {
            width: 72%;
        }
        .style2
        {
            width: 150px;
        }
        .style3
        {
            width: 172px;
        }
        .style4
        {
            color: #FF3300;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 332px; width: 658px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" Text="删除楼房"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    楼号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList1" runat="server" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [buildingid] FROM [building]"></asp:SqlDataSource>
                </td>
                <td>
                    <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="删除" />
                </td>
            </tr>
            <tr>
                <td class="style4" colspan="3">
                    请注意：若删除楼，则该楼中所有有关数据据都被删除！</td>
            </tr>
        </table>
    
        <asp:Label ID="Label2" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>
