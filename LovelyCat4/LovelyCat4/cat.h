#pragma once
#ifndef _DLL_DEMO_H_
#define _DLL_DEMO_H_
#ifdef DLLDEMO_EXPORTS
#define DLL_DEMO _declspec( dllexport )
#else
#define DLL_DEMO _declspec(dllimport)
#endif
extern int AutoCode;
int Cat_Initialize(char* json, int session);
void Cat_AppendLogs(int Code, char* msg);
/**
 * 配置插件信息
 * @return
 */
extern "C" DLL_DEMO int __stdcall  LoadingInfo(int lApiString);
/**
 * 软件启动，运行一次这里（还未登录，仅为软件启动时）
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventInit();
/**
 * 插件启用时，运行一次这里（启动完成后也会调用一次这里，便于初始化，其他时候，只有用户点击启用插件时才会调用）
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventEnable();

/**
 * 插件被停用/插件重载/插件卸载/软件退出，运行这里
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventStop();

/**
 *  新的账号登录成功/下线时，运行这里
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventLogin();

/**
 * 群消息事件（收到群消息时，运行这里）
 * @param robot_wxid	文本型, , 机器人账号id（就是这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param type	 整数型, , 1/文本消息 3/图片消息 34/语音消息  42/名片消息  43/视频 47/动态表情 48/地理位置  49/分享链接  2001/红包  2002/小程序  2003/群邀请 更多请参考sdk模块常量值
 * @param from_wxid 文本型, , 来源群id
 * @param from_name 文本型, , 来源群昵称
 * @param final_from_wxid 文本型, , 具体发消息的群成员id
 * @param final_from_name 文本型, , 具体发消息的群成员昵称
 * @param to_wxid 文本型, , 接收消息的人id，（一般是机器人收到了，也有可能是机器人发出的消息，别人收到了，那就是别人）
 * @param msg 文本型, , 消息内容
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventGroupMsg(
	char* robot_wxid,
	int type,
	char* from_wxid,
	char* from_name,
	char* final_from_wxid,
	char* final_from_name,
	char* to_wxid,
	char* msg
);

/**
 * 私聊消息事件（收到私聊消息时，运行这里）
 * @param robot_wxid	文本型, , 机器人账号id（就是这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param type	1/文本消息 3/图片消息 34/语音消息  42/名片消息  43/视频 47/动态表情 48/地理位置  49/分享链接  2001/红包  2002/小程序  2003/群邀请
 * @param from_wxid	文本型, , 来源用户ID
 * @param from_name	文本型, , 来源用户昵称
 * @param to_wxid	文本型, , 接收消息的人ID（一般都是机器人收到了，所以这里是机器人ID，如果是机器人发出的，这里就是对方的ID）
 * @param msg	文本型, , 消息内容
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventFriendMsg(
	char* robot_wxid,
	int type,
	char* from_wxid,
	char* from_name,
	char* to_wxid,
	char* msg
);

/**
 * 收到转账事件（收到好友转账时，运行这里）
 * @param robot_wxid	文本型, , 机器人账号ID（就是这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param from_wxid	文本型, , 来源用户ID
 * @param from_name	文本型, , 来源用户昵称
 * @param to_wxid	文本型, , 接收消息的人ID（一般都是机器人收到了，所以这里是机器人ID，如果是机器人发出的，也就是接收转账，这里就是对方的ID）
 * @param money	文本型, , 金额
 * @param json_msg	文本型, , 收到转账的详细JSON信息，具体JSON结构请查看日志
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventReceivedTransfer(
	char* robot_wxid,
	char* from_wxid,
	char* from_name,
	char* to_wxid,
	char* money,
	char* json_msg
);

/**
 * 面对面收款（二维码收款时，运行这里）
 * @param robot_wxid	收钱的人
 * @param pay_wxid	消息来源id
 * @param pay_name	消息来源昵称
 * @param money		金额
 * @param json_msg	更多详细的收款信息，具体JSON结构请查看日志
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventScanCashMoney(
	char* robot_wxid,
	char* pay_wxid,
	char* pay_name,
	char* money,
	char* json_msg
);

/*好友请求事件（插件3.0版本及以上）*/

/**
 * 好友请求事件（插件3.0版本及以上）
 * @param robot_wxid	机器人账号id（这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param from_wxid	陌生人用户id
 * @param from_name	陌生人用户昵称
 * @param to_wxid	忽略
 * @param json_msg	好友验证信息JSON对象（1/群内添加时，包含群id   2/名片推荐添加时，包含推荐人id及昵称  3/微信号、手机号搜索添加时），具体JSON结构请查看日志
 * @return
 */

extern "C" DLL_DEMO int __stdcall  EventFriendVerify(
	char* robot_wxid,
	char* from_wxid,
	char* from_name,
	char* to_wxid,
	char* json_msg
);


/**/
/**
 * 朋友变动事件（插件4.0版本及以上，当前为测试版，还未启用，留以备用）
 * @param robot_wxid
 * @param type
 * @param from_wxid	来源用户id
 * @param from_name	来源用户昵称
 * @param msg	消息内容
 * @return
 */

extern "C" DLL_DEMO int __stdcall  EventContactsChange(
	char* robot_wxid,
	int type,
	char* from_wxid,
	char* from_name,
	char* msg
);

/**
 *群成员增加事件（新人进群）
 * @param robot_wxid 机器人账号id（就是这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param from_wxid	来源群id
 * @param from_name	来源群名称
 * @param json_msg	新成员增加消息JSON对象，具体JSON结构请查看日志
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventGroupMemberAdd(
	char* robot_wxid,
	char* from_wxid,
	char* from_name,
	char* json_msg
);

/**
 * 群成员减少事件（群成员退出）
 * @param robot_wxid	机器人账号id（就是这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param from_wxid	来源群id
 * @param from_name	来源群名称
 * @param json_msg	退出人的id|退出人的昵称
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventGroupMemberDecrease(
	char* robot_wxid,
	char* from_wxid,
	char* from_name,
	char* json_msg
);

/**
 * 系统消息事件
 * @param robot_wxid	机器人账号id（就是这条消息是哪个机器人的，因为可能登录多个机器人）
 * @param type
 * @param json_msg
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventSysMsg(
	char* robot_wxid,
	int type,
	char* json_msg
);

/**
 * 打开插件菜单
 */
extern "C" DLL_DEMO void __stdcall Menu();







#endif