/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:31:31 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/27 11:31:33 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int		printError(std::string err)
{
	std::cerr << err << std::endl;
	return (1);
}

int	printError(std::string err, std::ifstream &file)
{
	std::cerr << err << std::endl;
	file.close();
	return (1);
}

int	searchAndReplace(const char *filename, const std::string &search, const std::string &replace)
{
	std::string		newFileName;
	std::string		buffer;
	std::ifstream	infile(filename);

	if (!infile)
		return (printError("Error: could not open file ", infile));
	getline(infile, buffer, '\0');
	if (buffer.empty())
		return (printError("Error: buffer empty."));
	newFileName = filename;
	std::ofstream	outfile(newFileName.append(".replace").c_str(), std::ios_base::out);
	if (!outfile)
		return (printError("Error: couldn't create the outfile", infile));
	for (size_t pos = buffer.find(search); pos != std::string::npos; pos = buffer.find(search, pos + replace.length()))
	{
		buffer.erase(pos, search.length());
		buffer.insert(pos, replace);
	}
	outfile << buffer;
	infile.close();
	outfile.close();
	return (0);
}
int main(int argc, char **argv)
{
    std::string     search;
    std::string     replace;

	if (argc != 4)
		return (printError("Usage: <filename> <string to find> <string to replace>"));
	search = argv[2];
	replace = argv[3];
	if (search.empty())
		return (printError("Error: no string to find bro"));
	return (searchAndReplace(argv[1], search, replace));
}
