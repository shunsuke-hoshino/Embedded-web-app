#include "taskspi.h"

#include <gpio_num.h>
#include <task.h>

#define IMAGE_RAW_DATA_SIZE	(3840 * 2160 * 3)
#define IMAGE_STACK_AMOUNT	(4)

#define SPI_IOPORT_MOSI	(GPIO_NUM_23)
#define SPI_IOPORT_MISO	(GPIO_NUM_19)
#define SPI_IOPORT_SCLK	(GPIO_NUM_18)


/**
 * @brief Construct a new Spi Task:: Spi Task object
 * @author Yuki.S
 * @date 2025-09-28
 */
SpiTask::SpiTask()
{
	// Initialize SPI
	SPIDevice = SPI2_HOST;

	SPIInterface = spi_device_interface_config_t
	{
		.mode = 0,
		.clock_speed_hz = SPI_MASTER_FREQ_40M, // 1 MHz
		.spics_io_num = GPIO_NUM_5, // CS pin
		.queue_size = IMAGE_STACK_AMOUNT,
	};

	SPIConfig = spi_bus_config_t
	{
		.mosi_io_num = SPI_IOPORT_MOSI,
		.miso_io_num = SPI_IOPORT_MISO,
		.sclk_io_num = SPI_IOPORT_SCLK,
		.quadwp_io_num = -1,
		.quadhd_io_num = -1,
	};

	SPIControl = apispi::SpiControl(
		SPIDevice,
		&SPIInterface,
		&SPIConfig
	);
}