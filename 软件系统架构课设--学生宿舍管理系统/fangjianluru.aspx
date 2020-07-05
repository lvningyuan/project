<%@ Page Language="C#" AutoEventWireup="true" CodeFile="fangjianluru.aspx.cs" Inherits="fanjianguanli" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>房间录入</title>
    <style type="text/css">
        .style1
        {
            width: 79%;
            height: 188px;
        }
        .style2
        {
            width: 185px;
        }
        .style3
        {
            width: 179px;
        }
        .style4
        {
            width: 67%;
        }
        .style5
        {
            width: 144px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 474px; text-align: center; width: 670px">
    
        <asp:Label ID="Label1" runat="server" Text="房间信息录入"></asp:Label>
        <br />
        <br />
        <table class="style4">
            <tr>
                <td class="style3">
                    宿舍等级：</td>
                <td class="style5">
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style3">
                    费用：</td>
                <td class="style5">
                    <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style3">
                    标准人数：</td>
                <td class="style5">
                    <asp:TextBox ID="TextBox6" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
        </table>
        <asp:Button ID="Button3" runat="server" onclick="Button3_Click" Text="录入" />
        <br />
        <asp:Label ID="Label3" runat="server"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style3">
                    楼房号：</td>
                <td class="style2">
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
                <td class="style3">
                    房间号：</td>
                <td class="style2">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style3">
                    宿舍等级：</td>
                <td class="style2">
                    <asp:DropDownList ID="DropDownList2" runat="server" 
                        DataSourceID="SqlDataSource2" DataTextField="kindid" DataValueField="kindid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [kindid] FROM [dormitorykind]"></asp:SqlDataSource>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style3">
                    电话号码：</td>
                <td class="style2">
                    <asp:TextBox ID="TextBox3" runat="server" Height="22px"></asp:TextBox>
                </td>
                <td>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                        ControlToValidate="TextBox3" ErrorMessage="请输入7位电话号码！" 
                        ValidationExpression="\d{7}"></asp:RegularExpressionValidator>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    &nbsp;</td>
                <td class="style2">
                    &nbsp;</td>
                <td>
                    &nbsp;</td>
            </tr>
        </table>
        <br />
        <asp:Button ID="Button1" runat="server" Text="录入" onclick="Button1_Click" />
    
        <br />
        <asp:Label ID="Label2" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>
