#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_data {
	int			id;
	std::string	name;
} t_data;

class	Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& variant);
		Serializer& operator=(const Serializer& other);
	public:
		static uintptr_t serialize(t_data &data);
		t_data *deserialize(uintptr_t value);
};
