// bgPrivIdToGBId.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "PrivIdToGBId.h"

#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 3)
		return 0;

	TCHAR sz_element_count[4096] = {0};
	_tcscpy_s(sz_element_count, 4096, argv[1]);

	TCHAR sz_test_count[4096] = {0};
	_tcscpy_s(sz_test_count, 4096, argv[2]);

	int element_count = _ttoi(sz_element_count);
	int test_count = _ttoi(sz_test_count);

	PrivIdToGB28181Id p2g;
	int errCode = p2g.Init();

	
	for (int c = 0; c < test_count; ++c)
	{
		std::cout<<"==================��ʼ���� "<<element_count<<" �豸IDӳ��=================="<<std::endl;
		// ���˽��ID�����IDӳ��
		DWORD start_tick = GetTickCount();
		for (int index = 0; index < element_count; ++index)
		{
			char priv[9] = {0};
			sprintf_s(priv, 9, "%08d", index);

			char gb[21] = {0};
			sprintf_s(gb, 21, "%020d", index);

			errCode = p2g.AddMapping(priv, gb);
			if (errCode != ERROR_SUCCESS)
				std::cout<<"Add mapping failed! priv : "<<priv<<", gb : "<<gb<<std::endl;
		}
		DWORD end_tick = GetTickCount();
		std::cout<<element_count<<" ���豸IDӳ���ʱ "<<end_tick - start_tick<<" ���룬ƽ��"<<(end_tick - start_tick) / element_count<<" �������һ����"<<std::endl;

		std::cout<<"==================��ʼ���Ը���˽��ID�����ID=================="<<std::endl;
		// ����˽��ID�����ID
		start_tick = GetTickCount();
		for (int index = 0; index < element_count; ++index)
		{
			char priv[9] = {0};
			sprintf_s(priv, 9, "%08d", index);

			std::string gbcode;
			errCode = p2g.QueryGbId(priv, &gbcode);
			if (errCode != 0)
			{
				std::cout<<"Query gb id failed! priv : "<<priv<<std::endl;
				continue;
			}

			//std::cout<<"Query gb id! priv : "<<priv<<", gb : "<<gbcode.c_str()<<std::endl;
		}
		end_tick = GetTickCount();
		std::cout<<element_count<<" ���豸 ����˽��ID�����ID ��ѯ��ʱ "<<end_tick - start_tick<<" ���룬ƽ��"<<(end_tick - start_tick) / element_count<<" ����鵽һ��ӳ��ID��"<<std::endl;

		std::cout<<"==================��ʼ���Ը��ݹ���ID��˽��ID=================="<<std::endl;
		// ���ݹ���ID��˽��ID
		start_tick = GetTickCount();
		for (int index = 0; index < element_count; ++index)
		{
			char gb[21] = {0};
			sprintf_s(gb, 21, "%020d", index);

			std::string privcode;
			errCode = p2g.QueryPrivId(gb, &privcode);
			if (errCode != 0)
			{
				std::cout<<"Query priv id failed! gb : "<<gb<<std::endl;
				continue;
			}

			//std::cout<<"Query priv id! gb : "<<gb<<", priv : "<<privcode.c_str()<<std::endl;
		}
		end_tick = GetTickCount();
		std::cout<<element_count<<" ���豸 ����˽��ID�����ID ��ѯ��ʱ "<<end_tick - start_tick<<" ���룬ƽ��"<<(end_tick - start_tick) / element_count<<" ����鵽һ��ӳ��ID"<<std::endl;

		std::cout<<"==================��ʼ�������ӳ���ϵ=================="<<std::endl;
		// ���
		start_tick = GetTickCount();
		p2g.CleanupMapping();
		end_tick = GetTickCount();
		std::cout<<element_count<<" ���豸 ��� ��ʱ "<<end_tick - start_tick<<" ����"<<std::endl;

		element_count *= 10;
	}

	system("pause");
	return 0;
}

