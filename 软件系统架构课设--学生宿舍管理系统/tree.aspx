<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tree.aspx.cs" Inherits="tree" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>TREE</title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="width: 1355px; height: 820px; clip: rect(auto, auto, auto, auto); overflow: hidden; font-size: 22px;" align="left">
    
        <asp:TreeView ID="TreeView1" runat="server" ShowLines="True" ExpandDepth="0" 
            onselectednodechanged="TreeView1_SelectedNodeChanged" Target="mainFrame" Height="112px" style="margin-bottom: 0px" Width="235px" NodeIndent="30">
            <Nodes>
                <asp:TreeNode Text="楼房管理" Value="楼房管理" SelectAction="Expand">
                    <asp:TreeNode Text="添加楼房" Value="添加楼房" NavigateUrl="~/tianjialoufan.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="修改楼房" Value="修改楼房" NavigateUrl="~/xiugailoufang.aspx"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/shanchuloufan.aspx" Text="删除楼房" Value="删除楼房">
                    </asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Text="房间管理" Value="房间管理" SelectAction="Expand">
                    <asp:TreeNode Text="房间录入" Value="房间录入" NavigateUrl="~/fangjianluru.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="房间信息修改" Value="房间信息修改" 
                        NavigateUrl="~/fanjianxinxixiugai.aspx"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/fangjianshanchu.aspx" Text="房间删除" Value="房间删除">
                    </asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Text="班级管理" Value="班级管理">
                    <asp:TreeNode NavigateUrl="~/banjiluru.aspx" Text="班级录入" Value="班级录入">
                    </asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/banjixinxixiugai.aspx" Text="班级信息修改" 
                        Value="班级信息修改"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/banjishanchu.aspx" Text="班级删除" Value="班级删除">
                    </asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Text="住宿管理" Value="住宿管理" SelectAction="Expand">
                    <asp:TreeNode Text="住宿情况查看" Value="住宿情况查看" 
                        NavigateUrl="~/zhusuqingkuangchakan.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="办理人员入住" Value="办理人员入住" 
                        NavigateUrl="~/banlirenyuanruzhu.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="办理迁出" Value="办理迁出" NavigateUrl="~/banliqianchu.aspx"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Text="信息查询" Value="信息查询" SelectAction="Expand">
                    <asp:TreeNode Text="人物查询" Value="人物查询" NavigateUrl="~/renwuchaxun.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="房间查询" Value="房间查询" NavigateUrl="~/fangjianchaxun.aspx"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Text="数据统计" Value="数据统计" SelectAction="Expand">
                    <asp:TreeNode Text="人物统计" Value="人物统计" NavigateUrl="~/renwutongji.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="房间统计" Value="房间统计" NavigateUrl="~/fangjiantongji.aspx"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Text="迁出记录" Value="迁出记录" SelectAction="Expand">
                    <asp:TreeNode Text="查看迁出信息" Value="查看迁出信息" 
                        NavigateUrl="~/chakanqianchuxinxi.aspx"></asp:TreeNode>
                    <asp:TreeNode Text="查看某人是否迁出" Value="查看某人是否迁出" 
                        NavigateUrl="~/chakanmourenshifouqianchu.aspx"></asp:TreeNode>
                </asp:TreeNode>
            </Nodes>
        </asp:TreeView>

    </div>
    </form>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;</p>
   
</body>
</html>
