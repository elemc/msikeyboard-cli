#include "MSIKeyboard.h"
#include <boost/program_options.hpp>
#include <vector>
#include <iostream>

using namespace std;
namespace po = boost::program_options;

struct options {
    bool help;
    string mode;
    vector<string> colors;
    //vector<string> rgbs;
};

void initProgramOptions(options *opts, int argc, char **argv);

int main(int argc, char **argv) {
    struct options opts;
    initProgramOptions(&opts, argc, argv);
    if ( opts.help )
        return 0;

    bool modified;

    MSIKeyboard keyboard;
    if ( opts.mode != "" ) {
        keyboard.SetMode(opts.mode);
        modified = true;
    }
    for ( string value : opts.colors) {
        keyboard.SetRegion(Region(std::move(value)));
        modified = true;
    }
    if ( modified )
        keyboard.Send();

    return 0;
}

void initProgramOptions(options *opts, int argc, char **argv) {
    po::options_description desc("Main options");
    desc.add_options()
            ("help,h", "produce this message")
            ("mode,m", po::value<string>(&opts->mode), "set mode")
            ("colors,c", po::value<vector<string>>(&opts->colors), "set colors, as example '<region name>:<color name>:<intensity name>'")
    ;
    po::variables_map vm;
    po::parsed_options parsed = po::command_line_parser(argc, argv).options(desc).allow_unregistered().run();
    po::store(parsed, vm);
    po::notify(vm);
    if ( argc == 1 || vm.count("help") > 0) {
        opts->help = true;
        cout << desc << endl;
    }
}