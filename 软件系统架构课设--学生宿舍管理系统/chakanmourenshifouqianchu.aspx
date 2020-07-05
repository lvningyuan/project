<%@ Page Language="C#" AutoEventWireup="true" CodeFile="chakanmourenshifouqianchu.aspx.cs" Inherits="chakanmourenshifouqianchu" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>查看某人是否迁出</title>
    <style type="text/css">
        .style1
        {
            width: 55%;
        }
        .style2
        {
            width: 157px;
        }
        .style3
        {
            width: 179px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 429px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" Text="查看某人是否迁出"></asp:Label>
        <table class="style1">
            <tr>
                <td class="style2">
                    学号：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="查看" />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    姓名：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="Button2" runat="server" onclick="Button2_Click" Text="查看" />
                </td>
            </tr>
        </table>
    
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="studentid" HeaderText="学号" 
                    SortExpression="studentid" />
                <asp:BoundField DataField="studentname" HeaderText="姓名" 
                    SortExpression="studentname" />
                <asp:BoundField DataField="outtime" HeaderText="迁出时间" 
                    SortExpression="outtime" />
                <asp:BoundField DataField="reason" HeaderText="迁出原因" 
                    SortExpression="reason" />
            </Columns>
        </asp:GridView>
        <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" 
            DataSourceID="SqlDataSource2">
            <Columns>
                <asp:BoundField DataField="studentid" HeaderText="学号" 
                    SortExpression="studentid" />
                <asp:BoundField DataField="studentname" HeaderText="姓名" 
                    SortExpression="studentname" />
                <asp:BoundField DataField="outtime" HeaderText="迁出时间" 
                    SortExpression="outtime" />
                <asp:BoundField DataField="reason" HeaderText="迁出原因" SortExpression="reason" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT * FROM [out] WHERE ([studentname] = @studentname)">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox2" Name="studentname" 
                    PropertyName="Text" Type="String" />
            </SelectParameters>
        </asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT * FROM [out] WHERE ([studentid] = @studentid)">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="studentid" PropertyName="Text" 
                    Type="Int32" />
            </SelectParameters>
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
