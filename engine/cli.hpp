#ifndef __CLI__HPP__
#define __CLI__HPP__
#include "coreengine.hpp"
#include "frequencymap.hpp"
#include<string>

using namespace std;

class CliApp {
public:
    CliApp();
    CliApp(int argc, char** argv);
    ~CliApp();
    int run();
    search_result SearchWeb(string);
    int prueba(int);
private:
    string get_dir();
    void print(search_result result);
    vector<string> files;
    CoreEngine engine;
};
#endif
