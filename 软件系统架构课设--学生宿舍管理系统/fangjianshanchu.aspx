<%@ Page Language="C#" AutoEventWireup="true" CodeFile="fangjianshanchu.aspx.cs" Inherits="fangjianshanchu" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>房间删除</title>
    <style type="text/css">
        .style1
        {
            width: 62%;
        }
        .style2
        {
        }
        .style3
        {
            color: #CC6600;
        }
        .style4
        {
            color: #FF0000;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 251px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" Text="房间删除"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    楼号：</td>
                <td>
                    <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [buildingid] FROM [dormitory]"></asp:SqlDataSource>
                </td>
            </tr>
            <tr>
                <td class="style2">
                    房间号：</td>
                <td>
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
                <td class="style2" colspan="2">
                    <span class="style4">请注意：若删除房间，则该房间中所有有关数据据都被删除</span><span class="style3">！</span></td>
            </tr>
        </table>
        <asp:Label ID="Label2" runat="server"></asp:Label>
        <br />
        <asp:Button ID="Button1" runat="server" onclick="Button1_Click" Text="删除" />
    
    </div>
    </form>
</body>
</html>
