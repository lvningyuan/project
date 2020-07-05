<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tianjialoufan.aspx.cs" Inherits="tianjialoufan" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>添加楼房</title>
    <style type="text/css">
        .style1
        {
            width: 77%;
        }
        .style2
        {
            width: 187px;
        }
        .style3
        {
            width: 152px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 328px; width: 641px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" style="text-align: center" Text="统计楼房"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    宿舍楼楼号：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td style="text-align: left">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                        ControlToValidate="TextBox1" ErrorMessage="请输入数据!" style="text-align: left"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼楼管：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox2" runat="server" OnTextChanged="TextBox2_TextChanged"></asp:TextBox>
                </td>
                <td style="text-align: left">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                        ControlToValidate="TextBox2" ErrorMessage="请输入楼管"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼楼层：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
                <td style="text-align: left">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                        ControlToValidate="TextBox3" ErrorMessage="请输入楼层！"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼面积：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                </td>
                <td style="text-align: left">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
                        ControlToValidate="TextBox4" ErrorMessage="请输入数据！"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    宿舍楼性别：</td>
                <td class="style3">
                    <asp:RadioButton ID="RadioButton1" runat="server" Checked="True" 
                        GroupName="sex" Text="男" />
                    <asp:RadioButton ID="RadioButton2" runat="server" GroupName="sex" Text="女" />
                </td>
                <td>
                    &nbsp;</td>
            </tr>
        </table>
        <asp:Button ID="Button1" runat="server" Text="录入" onclick="Button1_Click" 
            PostBackUrl="~/tianjialoufan.aspx" style="height: 26px" 
             />
        <asp:Button ID="Button2" runat="server" Text="返回" />
    
        <br />
    
        <br />
        <asp:Label ID="Label2" runat="server" Font-Size="Large"></asp:Label>
    
    </div>
    </form>
</body>
</html>
