/*
    This header file provides some usefull template functions to use std::vector objects.
    Copyright (C) 2018  BBlackJack07

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef MY_VECTOR_FUNCS
#define MY_VECTOR_FUNCS

#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <random>
#include <iostream>
#include <iterator>

template<typename T>
std::vector<T>& operator<<(std::vector<T>& vec, std::ifstream& doc)
{
    /*
        Use the operator << to read a std::ifstream and write his content in an std::vector<T>.
    */

	T line {};

	while(getline(doc, line))
	{
		vec.push_back(line);
	}
	return vec;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec)
{
    /*
        Use the operator << to write the content of a std::vector<T> in a std::ostream.
    */

    for(auto i = vec.begin(); i != vec.end(); i++)
        out << *i << "\n";
    return out;
}

template<class Iterator>
std::ostream& pprint(std::ostream& out, Iterator begin, Iterator end, std::string sep)
{
    /*
        This function take four argument : std::ostream& out, Iterator begin (begin of your std::vector), Iterator end (end of your std::vector), std::string sep (text to write between each elements of your std::vector)
        It write each element between begin and end in a std::ostream (out) and return out.
    */

	if(begin > end)
	{
		for(Iterator i { begin }; i != end; i--)
		{
			if (i == end)
				out << *i << std::endl;
			else
				out << *i << sep;
		}
	}

	else
	{
		for(Iterator i { begin }; i != end; i++)
		{
			if (i == end-1)
				out << *i << std::endl;
			else
				out << *i << sep;
		}
	}
	return out;
}

template<typename T>
T getRandom(std::vector<T> vec)
{
    /*
        This function take one argument : std::vector<T> vec
        It return a random element of vec.
    */

	std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dis(0,vec.size()-1);
	return vec[dis(engine)];
}

#endif //MY_VECTOR_FUNCS
