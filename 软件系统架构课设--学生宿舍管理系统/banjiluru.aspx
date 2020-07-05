<%@ Page Language="C#" AutoEventWireup="true" CodeFile="banjiluru.aspx.cs" Inherits="banjiluru" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>班级录入</title>
    <style type="text/css">
        .style1
        {
            width: 58%;
        }
        .style2
        {
            width: 326px;
        }
        .style3
        {
            width: 90px;
        }
        .style4
        {
            width: 41px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 219px; text-align: center; width: 606px">
    
        <asp:Label ID="Label1" runat="server" Text="班级录入"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style3">
                    班级：</td>
                <td class="style4">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td class="style2">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                        ControlToValidate="TextBox1" ErrorMessage="班级不能为空！！"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    专业：</td>
                <td class="style4">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
                <td class="style2">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                        ControlToValidate="TextBox2" ErrorMessage="专业不能为空！！"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    导员：</td>
                <td class="style4">
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
                <td class="style2">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                        ControlToValidate="TextBox3" ErrorMessage="导员不能为空！！"></asp:RequiredFieldValidator>
                </td>
            </tr>
        </table>
        <asp:Label ID="Label2" runat="server"></asp:Label>
        <br />
        <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="录入" />
    
    </div>
    </form>
</body>
</html>
