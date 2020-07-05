<%@ Page Language="C#" AutoEventWireup="true" CodeFile="chakanqianchuxinxi.aspx.cs" Inherits="chakanqianchuxinxi" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>查看迁出信息</title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 485px; text-align: center;">
    
        <br />
        <asp:Label ID="Label1" runat="server" Text="迁出信息"></asp:Label>
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
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            
            
            SelectCommand="SELECT [studentid], [studentname], [outtime], [reason] FROM [out]">
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
