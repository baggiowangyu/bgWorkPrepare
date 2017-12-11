#ifndef _PRIVID_TO_GBID_H_
#define _PRIVID_TO_GBID_H_

#include <string>
#include <map>
#include <Windows.h>

class PrivIdToGB28181Id
{
public:
	enum CONVERT_TYPE
	{
		USE_SQL,
		USE_MEMORY,
		USE_FILEMAPPING
	};

public:
	PrivIdToGB28181Id();
	~PrivIdToGB28181Id();

public:
	int Init(enum CONVERT_TYPE t = USE_MEMORY);
	void Uninit();

public:
	int AddMapping(std::string priv_id, std::string gb_id);
	int QueryPrivId(std::string gb_id, std::string *priv_id);
	int QueryGbId(std::string priv_id, std::string *gb_id);
	int CleanupMapping();

private:
	enum CONVERT_TYPE convert_type_;
	std::map<std::string, std::string> id_memory_mapping_;
	std::map<std::string, std::string> rid_memory_mapping_;
};

#endif//_PRIVID_TO_GBID_H_
