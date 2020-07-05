<%@ Page Language="C#" AutoEventWireup="true" CodeFile="fangjianchaxun.aspx.cs" Inherits="fangjianchaxun" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>房间查询</title>
    <style type="text/css">
        .style1
        {
            width: 61%;
        }
        .style2
        {
            width: 156px;
        }
        .style3
        {
            width: 172px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 386px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" style="text-align: center" Text="房间查询"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    楼号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList1" runat="server" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid" AutoPostBack="True">
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
                    房间号：</td>
                <td class="style3">
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
                <td>
                    <asp:Button ID="Button4" runat="server" onclick="Button4_Click" Text="查询" />
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
                    电话号：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:Button ID="Button3" runat="server" onclick="Button3_Click" Text="查询" />
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
                    性别：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList3" runat="server" AutoPostBack="True">
                    </asp:DropDownList>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    楼号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList4" runat="server" 
                        DataSourceID="SqlDataSource3" DataTextField="buildingid" 
                        DataValueField="buildingid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [buildingid] FROM [building] WHERE ([buildingsex] = @buildingsex)">
                        <SelectParameters>
                            <asp:ControlParameter ControlID="DropDownList3" Name="buildingsex" 
                                PropertyName="SelectedValue" Type="String" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    空缺人数：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
                <td>
        <asp:Button ID="Button1" runat="server" Text="查询" onclick="Button1_Click" />
                </td>
            </tr>
            </table>
        <br />
        <asp:GridView ID="GridView1" runat="server">
        </asp:GridView>
    
    </div>
    </form>
</body>
</html>
