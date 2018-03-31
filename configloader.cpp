// Copyright [2018] <lv7777>
// g++ configloader.cpp -l jansson
#include<jansson.h>
#include <dirent.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int parseDic(const char *dir, string fname) {
    // cout<<string(dir)+"/"+fname<<endl;
    string fullpath = string(dir)+"/"+fname;
    ifstream ifs(fullpath.c_str());
    string line;
        if (ifs.fail()) {
        cerr << "失敗" << endl;
        return -1;
    }
    while (getline(ifs, line)) {
        cout << "[" << line << "]" << endl;
    }
    return 0;
}

int main() {
    json_t *config;
    json_t *version;
    const char *dir;
    json_error_t err;
    config = json_load_file("mio_config.json", 0, &err);
    if (config != NULL) {
        version = json_object_get(config, "config_version");
        printf("version:%s\n", json_string_value(version));
        dir = json_string_value(json_object_get(config, "mio_dirs"));
        DIR* dp = opendir(dir);
        struct dirent *dent = NULL;
        while (true) {
            dent = readdir(dp);
            if (dent == NULL) {
                break;
            }
            string fName = dent->d_name;
            // XXX(lv777): dirty hack 4 struct validate
            if (fName.size()-fName.rfind(".dic") == 4 &&
                fName.find(".dic") != string::npos) {
                cout<< (fName.size()-fName.rfind(".dic")) <<endl;
                cout<< fName <<endl;
                parseDic(dir, fName);
            }
        }
        closedir(dp);
    }
    json_decref(config);
    json_decref(version);
}
