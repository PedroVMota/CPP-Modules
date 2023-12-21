#include "replace.hpp"

void replace_content(std::string &content, const std::string &to_find, const std::string &to_replace)
{
	size_t pos = content.find(to_find);

	while(pos != std::string::npos)
	{
		content.erase(pos, to_find.length());
		content.insert(pos, to_replace);
		pos = content.find(to_find, pos + to_replace.length());
	}
}