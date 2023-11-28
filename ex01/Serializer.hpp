#pragma once

#include "Data.hpp"

class	Data;

class	Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& serializer);
		~Serializer(void);

		Serializer& operator=(const Serializer& serializer);

		virtual void	makeAbstract(void) const = 0;
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
