#ifndef _STREAM_OPERATE_H_
#define _STREAM_OPERATE_H_

//////////////////////////////////////////////////////////////////////////
//
// ���ӿ����ڴ�������Ƶ��������ת��
//
//////////////////////////////////////////////////////////////////////////

class bgStreamOperateNotifer
{
public:
	virtual int WorkingStateNotify() = 0;
};

class bgStreamOperate
{
public:
	bgStreamOperate(bgStreamOperateNotifer *notifer);
	~bgStreamOperate();

public:
	int Delay
	
};

#endif//_STREAM_OPERATE_H_