#include "utilities.hpp"

std::vector<int> load_data(std::string filename)
{
    std::vector<int> data;
    std::ifstream file;

    file.open(filename, std::ios::out);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            data.push_back(stoi(line));
        }

        file.close();
        return data;
    }
    else
    {
        printf("error\n");
    }

    return {};
}