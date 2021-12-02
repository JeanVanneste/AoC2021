#include <fstream>
#include <iostream>

#define DATA_FILE "2.data"

void exo1()
{
    int depth = 0;
    int horiz = 0;

    std::ifstream file(DATA_FILE);

    std::string instr;
    int unit;
    while (file >> instr >> unit)
    {
        if (instr == "forward")
            horiz += unit;
        else if (instr == "down")
            depth += unit;
        else if (instr == "up")
            depth -= unit;
    }

    std::cout << depth * horiz << std::endl;
}

void exo2()
{
    int depth = 0;
    int horiz = 0;
    int aim = 0;

    std::ifstream file(DATA_FILE);

    std::string instr;
    int unit;
    while (file >> instr >> unit)
    {
        if (instr == "forward")
        {
            horiz += unit;
            depth += aim * unit;
        }
        else if (instr == "down")
            aim += unit;
        else if (instr == "up")
            aim -= unit;
    }

    std::cout << depth * horiz << std::endl;
}

int main()
{
    exo2();
    return 0;
}