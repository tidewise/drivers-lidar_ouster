#include <iostream>

#include "ouster/client.h"
#include "ouster/impl/build.h"

using namespace std;

void usage(ostream& stream)
{
    stream << "Version: " << ouster::SDK_VERSION_FULL << " (" << ouster::BUILD_SYSTEM
           << ")"
           << "\n\nUsage: lidar_ouster_bin <sensor_hostname> <CMD>\n"
           << "    where:\n    CMD is one of the commands bellow:\n"
           << "\n"
           << "Available operating modes:\n"
           << "standby: sets the operational mode to STANDBY\n"
           << "normal: sets the operational mode to NORMAL SENSOR OPERATION.\n"
           << endl;
}

// Needs to receive IP and mode as arguments
int main(int argc, char* argv[])
{
    if (argc < 3) {
        usage(cerr);
        return EXIT_FAILURE;
    }

    const string sensor_hostname = argv[1];
    const string mode = argv[2];

    // Get the current config on the sensor
    ouster::sensor::sensor_config original_config;
    if (!ouster::sensor::get_config(sensor_hostname, original_config)) {
        cerr << "..error: could not connect to sensor!" << endl;
        return EXIT_FAILURE;
    }
    cout << "success! Got original config\nOriginal config of sensor:\n"
         << to_string(original_config) << endl;

    ouster::sensor::sensor_config config;
    if (mode == "standby") {
        config.operating_mode = ouster::sensor::OperatingMode::OPERATING_STANDBY;
    }
    else if (mode == "normal") {
        config.operating_mode = ouster::sensor::OperatingMode::OPERATING_NORMAL;
    }
    else {
        cerr << mode << " is not a valid operating mode." << endl;
        return EXIT_FAILURE;
    }

    // Configure sensor
    if (!ouster::sensor::set_config(sensor_hostname, config)) {
        cerr << "..error: could not connect to sensor" << endl;
        return EXIT_FAILURE;
    }
    else {
        cout << "Updated configuration: \n" << to_string(config) << endl;
    }

    // Get updated configuration
    if (!ouster::sensor::get_config(sensor_hostname, config)) {
        cerr << "..error: could not connect to sensor!" << endl;
        return EXIT_FAILURE;
    }
    cout << "success! Got updated config\nUpdated config of sensor:\n"
         << to_string(config) << endl;

    return EXIT_SUCCESS;
}
