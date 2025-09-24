#include "taskspi.h"

#include <task.h>

SpiTask::SpiTask()
{
	// Initialize SPI
	SPIDevice = SPI2_HOST;
	SPIInterface = spi_device_interface_config_t();
	SPIConfig = spi_bus_config_t();

	SPIControl = apispi::SpiControl(
		SPIDevice,
		&SPIInterface,
		&SPIConfig
	);
}