<%@ Page Language="C#" AutoEventWireup="true" CodeFile="fanjianxinxixiugai.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>房间信息修改</title>
    <style type="text/css">
        .style1
        {
            width: 55%;
        }
        .style2
        {
            width: 308px;
            text-align: center;
        }
        .style3
        {
            width: 87px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 404px; text-align: center; width: 607px;">
    
        <br />
        <asp:Label ID="Label1" runat="server" Text="房间信息修改"></asp:Label>
        <table class="style1">
            <tr>
                <td class="style3">
                    楼号：</td>
                <td class="style2">
                    <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [buildingid] FROM [building]"></asp:SqlDataSource>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    宿舍号：</td>
                <td class="style2">
                    <asp:DropDownList ID="DropDownList2" runat="server" 
                        DataSourceID="SqlDataSource2" DataTextField="dormitoryid" 
                        DataValueField="dormitoryid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [dormitoryid] FROM [dormitory] WHERE ([buildingid] = @buildingid)">
                        <SelectParameters>
                            <asp:ControlParameter ControlID="DropDownList1" Name="buildingid" 
                                PropertyName="SelectedValue" Type="Int32" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    电话：</td>
                <td class="style2">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    等级：</td>
                <td class="style2">
                    <asp:DropDownList ID="DropDownList3" runat="server" 
                        DataSourceID="SqlDataSource3" DataTextField="kindid" DataValueField="kindid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [kindid] FROM [dormitorykind]"></asp:SqlDataSource>
                </td>
            </tr>
            <tr>
                <td class="style3">
                    &nbsp;</td>
                <td class="style2">
                    &nbsp;</td>
            </tr>
        </table>
        <asp:Label ID="Label2" runat="server"></asp:Label>
        <br />
        <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="修改" />
    
    </div>
    </form>
</body>
</html>
