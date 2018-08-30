#ifndef __CLI__HPP__
#define __CLI__HPP__
#include "coreengine.hpp"
#include "frequencymap.hpp"
#include "utility.hpp"
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
    void print(search_result result);
    void RunWeb();
private:
    string get_dir();
    vector<string> files;
    CoreEngine engine;
};
void CliApp::print(search_result result) {
    if (result.size() <= 0) {
        cout << "Not found." << endl;
    } else {
        for (auto &it : result) {
			for (auto& m : it.first)
            cout << (*(it.second)) << ", dbindex: " << m.first << ": " << m.second << " results." << endl;
        }
    }
}
CliApp::CliApp(int argc, char **argv) {}
CliApp::CliApp(){}
CliApp::~CliApp() {}

int CliApp::run() {
    string dirname = get_dir();
    auto process = [this, &dirname]() {
        this->engine.populate(dirname);
    };

	cout << "**************************** " << endl;

    cout << "**Took " << profile(process) << "us to build search index." << endl;
    string query;
    search_result result;
    cout << "**Enter :q to stop at anytime.**" << endl;
    do {

        cout << "Enter search query: ";
        cin >> query;
        auto query_index = [this, &query, &result] () {
            result = this->engine.search(query);
        };
        cout << "**Took " << profile(query_index) << "us to query tree." << endl;
        print(result);

    } while (query != ":q");

    cout << "Exiting search engine...Done!" << endl;
    return 0;
}
void CliApp::RunWeb(){
    string dirname = get_dir();
    vector<string> res;
    auto process = [this, &dirname,&res]() {
        res = this->engine.populate(dirname);
    };
    cout << res.size() << endl;
    cout << "**Took " << profile(process) << "us to build search index." << endl;

}

search_result CliApp::SearchWeb(string query) {
    search_result result;
        cout << this->engine.i << endl;
        auto query_index = [this, &query, &result] () {
            result = this->engine.search(query);
        };
        cout << "**Took " << profile(query_index) << "us to query tree." << endl;    
    return result;
}

int CliApp::prueba(int n){
    return n;
}

string CliApp::get_dir() {
    string dirname;
    cout << "Enter directory: ";
    getline(cin, dirname);
    cout << "Processing directory at " << dirname << endl;
    return dirname;
}

#endif