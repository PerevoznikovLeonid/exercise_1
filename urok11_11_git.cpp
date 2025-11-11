#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> parse_file(const string& path) {
    ifstream file;
    file.open(path);

    vector<string> result;

    if (!file.is_open()) {
        cerr << "File could not be opened" << endl;
        return result;
    }

    string line;
    while (getline(file, line)) {
        result.push_back(line);
    }

    file.close();

    return result;
}

struct Full_name {
    string family;
    string name;
};

vector<Full_name> organize_file(vector<string> source) {
    vector<Full_name> result;

    for (string item : source)
    {
        auto delim = item.find('|');
        string family = item.substr(0, delim);
        string name = item.substr(delim + 1);
        Full_name full_name;
        full_name.family = family;
        full_name.name = name;
        result.push_back(full_name);
    }

    return result;
}

void write_results(const string& path, vector<Full_name> source)
{
    ofstream file;
    file.open(path);
    if (file.is_open())
    {
        for (Full_name item : source)
        {
            file << item.family << endl;
        }
    }
    else
    {
        cerr << "File could not be written" << endl;
        return;
    }
    file.close();
}

int main()
{
    string data_path = "C:\\Programming\\urok11_11\\name_data.txt";
    string result_path = "C:\\Programming\\urok11_11\\families.txt";

    vector<string> lines = parse_file(data_path);
    vector<Full_name> full_names = organize_file(lines);
    write_results(result_path, full_names);
}

