#ifndef _TASKSPI_H
#define _TASKSPI_H

#pragma once

#include "apispi.h"

class SpiTask final
{
public:
    SpiTask();
    ~SpiTask();
private:
    apispi::SpiControl SPIControl;

    spi_host_device_t SPIDevice;

    spi_device_interface_config_t SPIInterface;

	spi_bus_config_t SPIConfig;
};

#endif // _TASKSPI_H