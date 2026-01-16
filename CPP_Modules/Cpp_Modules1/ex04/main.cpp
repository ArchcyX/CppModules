/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:46:19 by alermi            #+#    #+#             */
/*   Updated: 2025/10/30 20:46:20 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string getInput(const std::string &consoleMessage)
{
	std::string input;

	std::cout << consoleMessage;
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
			std::cout << "\nEOF (CTRL+D) algılandı. Tekrar deneyebilirsin.\n";
		else
			std::cout << "\nGirdi hatası oluştu. Tekrar dene.\n";
		input = "";
	}
	return input;
}

std::string changeWord(std::string src, std::string target, std::string replace)
{
    std::string dst;
    size_t		pos;
    size_t		found;

	pos = 0;
    while ((found = src.find(target, pos)) != std::string::npos)
    {
        dst.append(src, pos, found - pos);
        dst += replace;
        pos = found + target.length();
    }
    dst.append(src, pos, src.length() - pos);
    return (dst);
}

int replaceFile(std::string fileName, std::string strSrc, std::string strDst)
{
	std::string		line;
    std::ifstream	fileSrc(fileName);
    std::ofstream	fileDst(fileName + ".replace");

    if (!fileSrc.is_open() || !fileDst.is_open())
    {
        std::cout << "Error File Not Created" << std::endl;
        return (0);
    }
	while (getline(fileSrc, line))
	{
		line = changeWord(line, strSrc, strDst);
		fileDst << line << std::endl;
	}
    return (1);
}


int main(void)
{
	std::string fileName;
	std::string strOne;
	std::string strTwo;

	while (true)
	{
		fileName = getInput("file Name : ");
		if (fileName.empty())
		{
			std::cout << "Error EOF detected" << std::endl; 
			return (0);
		}
		std::cout << "fileName: " << fileName << std::endl;

		strOne = getInput("string One : ");
		if (strOne.empty())
		{
			std::cout << "Error EOF detected" << std::endl; 
			return (0);
		}
		std::cout << "stringOne: " << strOne << std::endl;
		strTwo = getInput("string Two : ");
		if (strTwo.empty())
		{
			std::cout << "Error EOF detected" << std::endl; 
			return (0);
		}
		std::cout << "stringTwo: " << strTwo << std::endl;
		if (!replaceFile(fileName, strOne, strTwo))
			return (0);
	}
	return 0;
}

