#pragma once
//������
const int MSG_LOGIN = 0x01;//�ɿͻ��˷�����¼����
const int MSG_TLOGIN = 0x02;//�ɷ����У���˺����������ͻ��˵�¼
const int MSG_FLOGIN = 0x03;//�˺����벻��ȷ���ܾ��ͻ��˵�¼
const int MSG_SENDPERSON = 0x11;//���͵�����Ϣ
const int MSG_SENDGROUP = 0x12;//����Ⱥ��Ϣ
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
