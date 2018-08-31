#ifndef __CLI__HPP__
#define __CLI__HPP__
#include<string>
#include "coreengine.hpp"
#include "frequencymap.hpp"

class CliApp {
public:
    CliApp();
    CliApp(int argc, char** argv);
    ~CliApp();
    int run();
    search_result SearchWeb(std::string);
	void sortMap(const std::map<int, int>& freqs, search_result& result);
    int prueba(int);
    void RunWeb();
private:
	std::string get_dir();
    void print(const std::map<int, int>& freqs, const double time);
	std::vector<std::string> files;
    CoreEngine engine;
};
#endif
