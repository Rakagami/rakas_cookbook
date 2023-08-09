#include <CLI/CLI.hpp>
#include <iostream>

void printAdd(float num1, float num2)
{
    printf("num1 + num2 = %f + %f = %f\n", num1, num2, num1 + num2);
}

int main(int argc, char** argv)
{
    CLI::App app { "Adder App" };

    float num1 { 0.0 };
    float num2 { 0.0 };
    bool verbose { false };
    app.add_option("num1", num1)->required();
    app.add_option("num2", num2)->required();
    app.add_flag("-v,--verbose", verbose, "add verbosity");
    CLI11_PARSE(app, argc, argv);

    printAdd(num1, num2);

    if (verbose) {
        printf("This is verbose output");
    }
}
