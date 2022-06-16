#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    std::ifstream reading_file;
    reading_file.open("./log3.txt", std::ios::in);
    std::string reading_line_buffer;
    vector<string> V;
    while(!reading_file.eof()) {
        // read by line
        std::getline(reading_file, reading_line_buffer);

        //std::cout << reading_line_buffer << std::endl;
        V.emplace_back(reading_line_buffer);
        // read by delimiter on reading "one" line
        const char delimiter = ' ';
        std::string separated_string_buffer;
        std::istringstream line_separater(reading_line_buffer);
        std::getline(line_separater, separated_string_buffer, delimiter);

        //std::cout << separated_string_buffer << std::endl;
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::shuffle(V.begin(), V.end(), engine);
    for(auto s : V) {
        cout << s << endl;
    }
}