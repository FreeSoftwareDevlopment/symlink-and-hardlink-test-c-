#include "wapi.hpp"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

/** @name main function
 * @brief  Do some stuff
 * @param  argc Number of arguments
 * @param  argv Arguments
 * @retval return value
 */
///@{
int main(int argc, char* argv[]){
    const fs::path file = "helloworld.txt";

    #ifdef WIN32
    char* fpath = p();
    if(fpath != nullptr){
        fs::path xo(fpath);
        free(fpath);
    }
    #endif

    std::ofstream myfile(file);
    myfile << "HelloWorld" << std::endl;
    myfile.close();
    fs::create_hard_link(file, "hey.txt");
    fs::create_symlink(file, "helloworld2.txt");
    return 0;
}

///@}
