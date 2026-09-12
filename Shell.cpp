#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

vector<string> history_list;

vector<string> parse(const string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (ss >> token) tokens.push_back(token);
    return tokens;
}

int main() {
    string line;

    while (true) {
        cout << "$";
        cout.flush();

        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        vector<string> args = parse(line);

        // 1. Comando Interno: exit [n]
        if (args[0] == "exit") {
            int code = (args.size() > 1) ? stoi(args[1]) : 0;
            exit(code);
        }

        // 2. Comando Interno: pwd[cite: 1]
        if (args[0] == "pwd") {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))) cout << cwd << endl;
            continue;
        }

        // 3. Comando Interno: cd [dir][cite: 1]
        if (args[0] == "cd") {
            string dir = (args.size() > 1) ? args[1] : getenv("HOME");
            if (chdir(dir.c_str()) != 0) cout << "cd: erro ao mudar de diretório" << endl;
            continue;
        }

        // 4. Comando Interno: history [-c][cite: 1]
        if (args[0] == "history") {
            if (args.size() > 1 && args[1] == "-c") {
                history_list.clear();
            } else {
                int total = history_list.size();
                int limit = min(total, 10);
                for (int i = 0; i < limit; i++) {
                    cout << i << " " << history_list[total - 1 - i] << endl;
                }
            }
            continue;
        }

        history_list.push_back(line);

        cout << "Command not found: " << args[0] << endl;
    }

    return 0;
}