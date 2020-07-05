<%@ Page Language="C#" AutoEventWireup="true" CodeFile="zhusuqingkuangchakan.aspx.cs" Inherits="zhusuqingkuangchakan" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>住宿情况查看</title>
    <style type="text/css">
        .style1
        {
            width: 52%;
            height: 28px;
            margin-left: 112px;
        }
        .style2
        {
            width: 180px;
            height: 8px;
        }
        .style3
        {
            height: 8px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 324px; text-align: center; width: 539px;">
    
        <asp:Label ID="Label1" runat="server" Text="住宿情况查看"></asp:Label>
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
            </tr>
        </table>
        <asp:Button ID="Button2" runat="server" Text="查看未住满的房间" 
            onclick="Button2_Click" />
        <asp:Button ID="Button1" runat="server" Text="查看住满的房间" 
            onclick="Button1_Click" />
    
        <br />
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
    
    </div>
    </form>
</body>
</html>
