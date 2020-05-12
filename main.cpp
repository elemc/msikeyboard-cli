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
    vector<string> RGBs;
};

void initProgramOptions(options *opts, int argc, char **argv);

int main(int argc, char **argv) {
    struct options opts;
    initProgramOptions(&opts, argc, argv);
    if ( opts.help )
        return 0;

    bool modified;

    MSIKeyboard keyboard;

    // set mode
    if ( !opts.mode.empty() ) {
        keyboard.SetMode(opts.mode);
        modified = true;
    }

    // set colors by names
    for ( string value : opts.colors) {
        keyboard.SetRegion(Region(std::move(value)));
        modified = true;
    }

    // set colors by RGB value
    for (string value : opts.RGBs) {
        keyboard.SetRegion(Region(std::move(value)));
        modified = true;
    }
    if ( modified )
        keyboard.Send();

    return 0;
}

void initProgramOptions(options *opts, int argc, char **argv) {
    string modeHelp = "set mode (" + MSIKeyboard::GetModes() + ")";
    string colorsHelp = "set colors, as example '<region name>:<color name>:<intensity name>'. Regions: " +
            MSIKeyboard::GetRegions() +
            ". Colors: " + MSIKeyboard::GetColors() +
            ". Intensities: " + MSIKeyboard::GetIntensities() + ".";
    string rgbHelp = "set colors, as example '<region name>:<R>:<G>:<B>'. Regions: " +
                        MSIKeyboard::GetRegions() + ".";
    po::options_description desc("Main options");
    desc.add_options()
            ("help,h", "produce this message")
            ("mode,m", po::value<string>(&opts->mode), modeHelp.c_str())
            ("colors,c", po::value<vector<string>>(&opts->colors), colorsHelp.c_str())
            ("rgb", po::value<vector<string>>(&opts->RGBs), rgbHelp.c_str())
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