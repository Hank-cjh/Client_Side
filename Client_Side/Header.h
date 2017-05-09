#pragma once
//各类型
const int MSG_LOGIN = 0x01;//由客户端发出登录请求
const int MSG_TLOGIN = 0x02;//由服务端校对账号密码后，允许客户端登录
const int MSG_FLOGIN = 0x03;//账号密码不正确，拒绝客户端登录
const int MSG_SENDPERSON = 0x11;//发送单人信息
const int MSG_SENDGROUP = 0x12;//发送群消息
typedef struct HEADER
{
	int Type;
	int ContentLength;
	char FromUser[8];
	char ToUser[8];
	char GroupID[8];
}Header,*LPHeader;
//const int MSG_LOGIN = 0x01;
//const int MSG_SENDPERSON = 0x12;
//const int MSG_SENDGROUP = 0x22;
//const int MSG_PERSONINFO = 0x03;
//const int MSG_SIGNUP = 0x04;
//typedef struct HEADER
//{
//	int Type;
//	int ContentLength;
//	char FromUser[8];
//	char ToUser[8];
//	char GroupID[8];
//	char Account[8];
//	char Password[8];
//	BOOL logo;
//}Header, *LPHeader;
