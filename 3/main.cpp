#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>

#define DATA_FILE "3.data"

void exo1()
{
    std::ifstream file(DATA_FILE);

    std::vector<std::string> data;
    std::string code;

    while (file >> code)
    {
        data.push_back(code);
    }

    uint pos = 1;
    uint gamma = 0;
    uint epsilon = 0;
    while (!data.back().empty())
    {
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < data.size(); i++)
        {
            char &bit = data[i].back();
            bit == '0' ? zeros++ : ones++;
            data[i].pop_back();
        }
        zeros > ones ? epsilon += pos : gamma += pos;
        pos *= 2;
    }
    std::cout << gamma * epsilon << std::endl;
}

void exo2()
{
    std::ifstream file(DATA_FILE);

    std::vector<std::string> original_data;
    std::string code;

    while (file >> code)
    {
        original_data.push_back(code);
    }

    const std::size_t code_size = original_data.front().size();

    std::vector<std::string> oxygen, co2;
    oxygen = original_data;
    co2 = original_data;

    // oxygen
    uint pos = 0;
    while (oxygen.size() > 1)
    {
        uint zeros = 0;
        uint ones = 0;
        for (int i = 0; i < oxygen.size(); i++)
        {
            oxygen[i][pos] == '0' ? zeros++ : ones++;
        }
        char max;
        zeros > ones ? max = '0' : max = '1';
        std::vector<std::string> filtered_oxygen;
        for (int i = 0; i < oxygen.size(); i++)
        {
            if (oxygen[i][pos] == max)
            {
                filtered_oxygen.push_back(oxygen[i]);
            }
        }
        oxygen = filtered_oxygen;
        std::cout << "size: " << oxygen.size() << " pos: " << pos << std::endl;
        pos++;
    }

    // std::cout << oxygen[0] << std::endl;

    // std::cin.get();

    // co2
    pos = 0;
    while (co2.size() > 1)
    {
        uint zeros = 0;
        uint ones = 0;
        for (int i = 0; i < co2.size(); i++)
        {
            co2[i][pos] == '0' ? zeros++ : ones++;
        }
        char min;
        zeros <= ones ? min = '0' : min = '1';
        std::vector<std::string> filtered_co2;
        for (int i = 0; i < co2.size(); i++)
        {
            if (co2[i][pos] == min)
                filtered_co2.push_back(co2[i]);
        }
        co2 = filtered_co2;
        std::cout << "Size: " << co2.size() << " pos: " << pos << std::endl;
        pos++;
    }

    // std::cout << co2.front() << std::endl;
    // std::cin.get();

    uint oxygen_num = 0;
    uint co2_num = 0;
    pos = 1;
    while (!oxygen.front().empty())
    {
        if (oxygen.front().back() == '1')
            oxygen_num += pos;
        if (co2.front().back() == '1')
            co2_num += pos;

        oxygen[0].pop_back();
        co2[0].pop_back();
        pos *=2;
    }

    std::cout << "oxygen rate: " << oxygen_num << " co2 rate: " << co2_num << std::endl;

    std::cout << oxygen_num * co2_num << std::endl;
        
}

int main()
{
    exo2();

    return 0;
}