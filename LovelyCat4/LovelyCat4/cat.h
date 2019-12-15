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
 * ���ò����Ϣ
 * @return
 */
extern "C" DLL_DEMO int __stdcall  LoadingInfo(int lApiString);
/**
 * �������������һ�������δ��¼����Ϊ�������ʱ��
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventInit();
/**
 * �������ʱ������һ�����������ɺ�Ҳ�����һ��������ڳ�ʼ��������ʱ��ֻ���û�������ò��ʱ�Ż���ã�
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventEnable();

/**
 * �����ͣ��/�������/���ж��/����˳�����������
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventStop();

/**
 *  �µ��˺ŵ�¼�ɹ�/����ʱ����������
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventLogin();

/**
 * Ⱥ��Ϣ�¼����յ�Ⱥ��Ϣʱ���������
 * @param robot_wxid	�ı���, , �������˺�id������������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
 * @param type	 ������, , 1/�ı���Ϣ 3/ͼƬ��Ϣ 34/������Ϣ  42/��Ƭ��Ϣ  43/��Ƶ 47/��̬���� 48/����λ��  49/��������  2001/���  2002/С����  2003/Ⱥ���� ������ο�sdkģ�鳣��ֵ
 * @param from_wxid �ı���, , ��ԴȺid
 * @param from_name �ı���, , ��ԴȺ�ǳ�
 * @param final_from_wxid �ı���, , ���巢��Ϣ��Ⱥ��Աid
 * @param final_from_name �ı���, , ���巢��Ϣ��Ⱥ��Ա�ǳ�
 * @param to_wxid �ı���, , ������Ϣ����id����һ���ǻ������յ��ˣ�Ҳ�п����ǻ����˷�������Ϣ�������յ��ˣ��Ǿ��Ǳ��ˣ�
 * @param msg �ı���, , ��Ϣ����
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
 * ˽����Ϣ�¼����յ�˽����Ϣʱ���������
 * @param robot_wxid	�ı���, , �������˺�id������������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
 * @param type	1/�ı���Ϣ 3/ͼƬ��Ϣ 34/������Ϣ  42/��Ƭ��Ϣ  43/��Ƶ 47/��̬���� 48/����λ��  49/��������  2001/���  2002/С����  2003/Ⱥ����
 * @param from_wxid	�ı���, , ��Դ�û�ID
 * @param from_name	�ı���, , ��Դ�û��ǳ�
 * @param to_wxid	�ı���, , ������Ϣ����ID��һ�㶼�ǻ������յ��ˣ����������ǻ�����ID������ǻ����˷����ģ�������ǶԷ���ID��
 * @param msg	�ı���, , ��Ϣ����
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
 * �յ�ת���¼����յ�����ת��ʱ���������
 * @param robot_wxid	�ı���, , �������˺�ID������������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
 * @param from_wxid	�ı���, , ��Դ�û�ID
 * @param from_name	�ı���, , ��Դ�û��ǳ�
 * @param to_wxid	�ı���, , ������Ϣ����ID��һ�㶼�ǻ������յ��ˣ����������ǻ�����ID������ǻ����˷����ģ�Ҳ���ǽ���ת�ˣ�������ǶԷ���ID��
 * @param money	�ı���, , ���
 * @param json_msg	�ı���, , �յ�ת�˵���ϸJSON��Ϣ������JSON�ṹ��鿴��־
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
 * ������տ��ά���տ�ʱ���������
 * @param robot_wxid	��Ǯ����
 * @param pay_wxid	��Ϣ��Դid
 * @param pay_name	��Ϣ��Դ�ǳ�
 * @param money		���
 * @param json_msg	������ϸ���տ���Ϣ������JSON�ṹ��鿴��־
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventScanCashMoney(
	char* robot_wxid,
	char* pay_wxid,
	char* pay_name,
	char* money,
	char* json_msg
);

/*���������¼������3.0�汾�����ϣ�*/

/**
 * ���������¼������3.0�汾�����ϣ�
 * @param robot_wxid	�������˺�id��������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
 * @param from_wxid	İ�����û�id
 * @param from_name	İ�����û��ǳ�
 * @param to_wxid	����
 * @param json_msg	������֤��ϢJSON����1/Ⱥ�����ʱ������Ⱥid   2/��Ƭ�Ƽ����ʱ�������Ƽ���id���ǳ�  3/΢�źš��ֻ����������ʱ��������JSON�ṹ��鿴��־
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
 * ���ѱ䶯�¼������4.0�汾�����ϣ���ǰΪ���԰棬��δ���ã����Ա��ã�
 * @param robot_wxid
 * @param type
 * @param from_wxid	��Դ�û�id
 * @param from_name	��Դ�û��ǳ�
 * @param msg	��Ϣ����
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
 *Ⱥ��Ա�����¼������˽�Ⱥ��
 * @param robot_wxid �������˺�id������������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
 * @param from_wxid	��ԴȺid
 * @param from_name	��ԴȺ����
 * @param json_msg	�³�Ա������ϢJSON���󣬾���JSON�ṹ��鿴��־
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventGroupMemberAdd(
	char* robot_wxid,
	char* from_wxid,
	char* from_name,
	char* json_msg
);

/**
 * Ⱥ��Ա�����¼���Ⱥ��Ա�˳���
 * @param robot_wxid	�������˺�id������������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
 * @param from_wxid	��ԴȺid
 * @param from_name	��ԴȺ����
 * @param json_msg	�˳��˵�id|�˳��˵��ǳ�
 * @return
 */
extern "C" DLL_DEMO int __stdcall  EventGroupMemberDecrease(
	char* robot_wxid,
	char* from_wxid,
	char* from_name,
	char* json_msg
);

/**
 * ϵͳ��Ϣ�¼�
 * @param robot_wxid	�������˺�id������������Ϣ���ĸ������˵ģ���Ϊ���ܵ�¼��������ˣ�
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
 * �򿪲���˵�
 */
extern "C" DLL_DEMO void __stdcall Menu();







#endif