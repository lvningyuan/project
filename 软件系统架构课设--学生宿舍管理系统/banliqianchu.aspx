<%@ Page Language="C#" AutoEventWireup="true" CodeFile="banliqianchu.aspx.cs" Inherits="banliqianchu" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>办理迁出</title>
    <style type="text/css">
        .style1
        {
            width: 67%;
        }
        .style2
        {
            width: 177px;
        }
        .style3
        {
            width: 309px;
            text-align: left;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 445px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" style="text-align: center" Text="办理迁出："></asp:Label>
        <table class="style1">
            <tr>
                <td class="style2">
                    学号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
                        DataSourceID="SqlDataSource1" DataTextField="studentid" 
                        DataValueField="studentid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [studentid] FROM [studdent]"></asp:SqlDataSource>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    姓名：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList2" runat="server" 
                        DataSourceID="SqlDataSource2" DataTextField="studentname" 
                        DataValueField="studentname">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [studentname] FROM [studdent] WHERE ([studentid] = @studentid)">
                        <SelectParameters>
                            <asp:ControlParameter ControlID="DropDownList1" Name="studentid" 
                                PropertyName="SelectedValue" Type="Int32" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    迁出时间：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                        ControlToValidate="TextBox4" ErrorMessage="日期格式(1999-01-01)" 
                        ValidationExpression="^\d{4}-((0[1-9])|(1[0-2]))-((0[1-9])|([1-2][0-9])|(3[0-1]))$" ></asp:RegularExpressionValidator>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    原因：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox3" runat="server" style="text-align: left" 
                        Width="293px"></asp:TextBox>
                </td>
                <td>
        <asp:Button ID="Button1" runat="server" Text="迁出" onclick="Button1_Click" />
                </td>
            </tr>
        </table>
    
        <asp:Label ID="Label2" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>
