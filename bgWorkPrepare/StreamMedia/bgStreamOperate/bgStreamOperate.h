#ifndef _STREAM_OPERATE_H_
#define _STREAM_OPERATE_H_

//////////////////////////////////////////////////////////////////////////
//
// 本接口用于处理视音频流的拉流转发
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