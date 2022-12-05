#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


int main()
{
    const std::string locIn = "D:\\inFile.txt", locOut = "D:\\outFile.txt";
    std::ifstream ifile(locIn);
    std::ofstream ofile(locOut);

    try
    {
        if (!ifile.is_open())
            throw std::exception("File open error");
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }


    std::string tmp;
    char find;

    ifile.get(find);
    std::getline(ifile, tmp);
    while (ifile)
    {
        ofile << std::count(tmp.begin(), tmp.end(), find) << std::endl;
        ifile.get(find);
        std::getline(ifile, tmp);
    }

    return 0;
}