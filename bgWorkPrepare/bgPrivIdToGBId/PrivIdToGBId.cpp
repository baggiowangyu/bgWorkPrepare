#include "stdafx.h"
#include "PrivIdToGBId.h"

PrivIdToGB28181Id::PrivIdToGB28181Id()
{

}

PrivIdToGB28181Id::~PrivIdToGB28181Id()
{

}

int PrivIdToGB28181Id::Init(enum CONVERT_TYPE t /* = USE_MEMORY */)
{
	int errCode = ERROR_NOT_SUPPORTED;

	convert_type_ = t;
	switch (convert_type_)
	{
	case USE_SQL:
		// 初始化SQLite3模块
		break;
	case USE_MEMORY:
		errCode = ERROR_SUCCESS;
		break;
	case USE_FILEMAPPING:
		// 初始化FileMapping
		break;
	default:
		break;
	}

	return errCode;
}

void PrivIdToGB28181Id::Uninit()
{

}

int PrivIdToGB28181Id::AddMapping(std::string priv_id, std::string gb_id)
{
	int errCode = ERROR_NOT_SUPPORTED;

	switch (convert_type_)
	{
	case USE_SQL:
		// 
		break;
	case USE_MEMORY:
		{
			// 
			std::pair<std::map<std::string, std::string>::iterator, bool> Insert_Pair = id_memory_mapping_.insert(std::pair<std::string, std::string>(priv_id, gb_id));
			if (Insert_Pair.second == true)
			{
				Insert_Pair = rid_memory_mapping_.insert(std::pair<std::string, std::string>(gb_id, priv_id));
				if (Insert_Pair.second == true)
					errCode = ERROR_SUCCESS;
			}
		}
		break;
	case USE_FILEMAPPING:
		// 
		break;
	default:
		break;
	}

	return errCode;
}

int PrivIdToGB28181Id::QueryGbId(std::string priv_id, std::string *gb_id)
{
	int errCode = ERROR_NOT_FOUND;

	switch (convert_type_)
	{
	case USE_SQL:
		// 
		break;
	case USE_MEMORY:
		{
			std::map<std::string, std::string>::iterator iter = id_memory_mapping_.find(priv_id);
			if (iter != id_memory_mapping_.end())
			{
				*gb_id = iter->second;
				errCode = ERROR_SUCCESS;
			}

			//// 这里还是以遍历的形式查找吧
			//std::map<std::string, std::string>::iterator iter;
			//for (iter = id_memory_mapping_.begin(); iter != id_memory_mapping_.end(); ++iter)
			//{
			//	if (iter->first.compare(priv_id) == 0)
			//	{
			//		*gb_id = iter->second;
			//		errCode = ERROR_SUCCESS;
			//		break;
			//	}
			//}
		}
		break;
	case USE_FILEMAPPING:
		// 
		break;
	default:
		break;
	}

	return errCode;
}

int PrivIdToGB28181Id::QueryPrivId(std::string gb_id, std::string *priv_id)
{
	int errCode = ERROR_NOT_FOUND;

	switch (convert_type_)
	{
	case USE_SQL:
		// 
		break;
	case USE_MEMORY:
		{
			std::map<std::string, std::string>::iterator iter = rid_memory_mapping_.find(gb_id);
			if (iter != rid_memory_mapping_.end())
			{
				*priv_id = iter->first;
				errCode = ERROR_SUCCESS;
			}

			//std::map<std::string, std::string>::iterator iter;
			//for (iter = id_memory_mapping_.begin(); iter != id_memory_mapping_.end(); ++iter)
			//{
			//	if (iter->second.compare(gb_id) == 0)
			//	{
			//		*priv_id = iter->first;
			//		errCode = ERROR_SUCCESS;
			//		break;
			//	}
			//}
		}
		break;
	case USE_FILEMAPPING:
		// 
		break;
	default:
		break;
	}

	return errCode;
}

int PrivIdToGB28181Id::CleanupMapping()
{
	int errCode = 0;

	id_memory_mapping_.clear();
	rid_memory_mapping_.clear();

	return errCode;
}