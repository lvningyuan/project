<%@ Page Language="C#" AutoEventWireup="true" CodeFile="renwutongji.aspx.cs" Inherits="renwutongji" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>人物统计</title>
    <style type="text/css">
        .style1
        {
            width: 47%;
        }
        .style2
        {
            width: 149px;
        }
        .style3
        {
            width: 153px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 390px; text-align: center; width: 592px;">
    
        <asp:Label ID="Label1" runat="server" style="text-align: center" Text="人物统计"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    楼号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList5" runat="server" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid">
                    </asp:DropDownList>
                </td>
                <td>
                    <asp:Button ID="Button3" runat="server" onclick="Button3_Click" Text="统计" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    &nbsp;</td>
                <td class="style3">
                    &nbsp;</td>
                <td>
                    &nbsp;</td>
            </tr>
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
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    班级：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList2" runat="server" 
                        DataSourceID="SqlDataSource2" DataTextField="classname" 
                        DataValueField="classname">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [classname] FROM [class]"></asp:SqlDataSource>
                </td>
                <td>
        <asp:Button ID="Button1" runat="server" Text="统计" onclick="Button1_Click" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    &nbsp;</td>
                <td class="style3">
                    &nbsp;</td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    班级：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList3" runat="server" 
                        DataSourceID="SqlDataSource2" DataTextField="classname" 
                        DataValueField="classname">
                    </asp:DropDownList>
                </td>
                <td>
                    <asp:Button ID="Button2" runat="server" onclick="Button2_Click" Text="统计" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    &nbsp;</td>
                <td class="style3">
                    &nbsp;</td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    专业：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList4" runat="server" 
                        DataSourceID="SqlDataSource3" DataTextField="major" DataValueField="major">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT DISTINCT major FROM class"></asp:SqlDataSource>
                </td>
                <td>
                    <asp:Button ID="Button4" runat="server" onclick="Button4_Click" Text="统计" />
                </td>
            </tr>
        </table>
    
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
    
    </div>
    </form>
</body>
</html>
