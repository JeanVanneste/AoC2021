#include "utilities.hpp"

void exo1()
{
    std::vector<int> depths = load_data("1.data");

    int increase = 0;
    for (int i = 1; i < depths.size(); i++)
    {
        if (depths[i] > depths[i - 1])
        {
            increase++;
        }
    }

    std::cout << increase << std::endl;
}

void exo2()
{
    std::vector<int> depths = load_data("1.data");

    int increase = 0;
    int last_sum = depths[0] + depths[1] + depths[2];
    for (int i = 3; i < depths.size(); i++)
    {
        int window = depths[i] + depths[i - 1] + depths[i - 2];
        if (window > last_sum)
        {
            increase++;
        }
        last_sum = window;
    }

    std::cout << increase << std::endl;
}

int main()
{
    exo2();
}