<%@ Page Language="C#" AutoEventWireup="true" CodeFile="banlirenyuanruzhu.aspx.cs" Inherits="banlirenyuanruzhu" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>办理人员入住</title>
    <style type="text/css">
        .style1
        {
            width: 60%;
        }
        .style2
        {
            width: 152px;
        }
        .style3
        {
            width: 108px;
        }
        .style4
        {
            width: 152px;
            height: 52px;
        }
        .style5
        {
            width: 108px;
            height: 52px;
        }
        .style6
        {
            height: 52px;
        }
        .style7
        {
            width: 152px;
            height: 11px;
        }
        .style8
        {
            width: 108px;
            height: 11px;
        }
        .style9
        {
            height: 11px;
        }
        .style10
        {
            width: 152px;
            height: 10px;
        }
        .style11
        {
            width: 108px;
            height: 10px;
        }
        .style12
        {
            height: 10px;
        }
        .style13
        {
            width: 152px;
            height: 33px;
        }
        .style14
        {
            width: 108px;
            height: 33px;
        }
        .style15
        {
            height: 33px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 539px; text-align: center">
    
        <asp:Label ID="Label1" runat="server" Text="办理人员入住"></asp:Label>
        <br />
        <table class="style1">
            <tr>
                <td class="style2">
                    学号：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="RequireFieldValidator1" runat="server" 
                        ControlToValidate="TextBox1" ErrorMessage="不能为空！！"></asp:RequiredFieldValidator></td>
            </tr>
            <tr>
                <td class="style2">
                    姓名：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    性别：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList4" runat="server" AutoPostBack="True">
                    </asp:DropDownList>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    年龄：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style13">
                    班级：</td>
                <td class="style14">
                    <asp:DropDownList ID="DropDownList5" runat="server" 
                        DataSourceID="SqlDataSource3" DataTextField="classname" 
                        DataValueField="classname" AutoPostBack="True">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [classname] FROM [class]"></asp:SqlDataSource>
                    <asp:DropDownList ID="DropDownList6" runat="server" 
                        DataSourceID="SqlDataSource4" DataTextField="classid" DataValueField="classid">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource4" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        SelectCommand="SELECT [classid] FROM [class] WHERE ([classname] = @classname)">
                        <SelectParameters>
                            <asp:ControlParameter ControlID="DropDownList5" Name="classname" 
                                PropertyName="SelectedValue" Type="String" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                </td>
                <td class="style15">
                    </td>
            </tr>
            <tr>
                <td class="style2">
                    入住日期：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                        ControlToValidate="TextBox5" ErrorMessage="日期格式(1999-01-01)" 
                        ValidationExpression="^\d{4}-((0[1-9])|(1[0-2]))-((0[1-9])|([1-2][0-9])|(3[0-1]))$" ></asp:RegularExpressionValidator></td>
            </tr>
            <tr>
                <td class="style10">
                    楼号：</td>
                <td class="style11">
                    <asp:DropDownList ID="DropDownList1" runat="server" 
                        DataSourceID="SqlDataSource1" DataTextField="buildingid" 
                        DataValueField="buildingid" AutoPostBack="True">
                    </asp:DropDownList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                        
                        SelectCommand="SELECT [buildingid], [buildingsex] FROM [building] WHERE ([buildingsex] = @buildingsex)">
                        <SelectParameters>
                            <asp:ControlParameter ControlID="DropDownList4" Name="buildingsex" 
                                PropertyName="SelectedValue" Type="String" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                </td>
                <td class="style12">
                    </td>
            </tr>
            <tr>
                <td class="style2">
                    房间号：</td>
                <td class="style3">
                    <asp:DropDownList ID="DropDownList2" runat="server" 
                        DataSourceID="SqlDataSource2" DataTextField="dormitoryid" 
                        DataValueField="dormitoryid" AutoPostBack="True" 
                        onselectedindexchanged="Button2_Click">
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
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style7">
                    该房间最大床号：</td>
                <td class="style8">
                    <asp:DropDownList ID="DropDownList8" runat="server" 
                        DataTextField="standardamount">
                    </asp:DropDownList>
                </td>
                <td class="style9">
                    </td>
            </tr>
            <tr>
                <td class="style4">
                    床号：</td>
                <td class="style5">
                    <asp:TextBox ID="TextBox7" runat="server"></asp:TextBox>
                </td>
                <td class="style6">
                    &nbsp;</td>
            </tr>
            <tr>
                <td class="style2">
                    年制：</td>
                <td class="style3">
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                </td>
                <td>
                    &nbsp;</td>
            </tr>
        </table>
    
        <asp:Button ID="Button1" runat="server" Text="入住" onclick="Button1_Click" 
            style="height: 26px" />
    
        <br />
        <asp:Label ID="Label2" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>
