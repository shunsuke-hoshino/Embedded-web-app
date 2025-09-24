#ifndef _APISPI_H
#define _APISPI_H

#pragma once

#include <spi_common.h>
#include <spi_master.h>

namespace apispi
{
	#define SPI_BUFF_SIZE_RX	(3840 * 2160)

	#define SPI_BUFF_SIZE_TX	(8)

	class SpiControl
	{
	public:
		SpiControl(
			spi_host_device_t,
			spi_device_interface_config_t*,
			spi_bus_config_t*);
		
		SpiControl() = default;

		~SpiControl();

		bool Open();

		int Send(uint8_t *, int);

		int Receive(uint8_t *);
	
	private:
		spi_host_device_t	DeviceId;

		spi_device_interface_config_t
							DeviceConfig;

		spi_device_handle_t	BusHandle;

		spi_transaction_t	Transaction;
		
	};
};

#endif // _APISPI_H