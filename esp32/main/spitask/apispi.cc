#include "apispi.h"

using namespace apispi;

SpiControl::SpiControl(
	spi_host_device_t deviceId,
	spi_device_interface_config_t* deviceConfig, 
	spi_bus_config_t* busConfig)
: DeviceId(deviceId),
  DeviceConfig(*deviceConfig)
{
	ESP_ERROR_CHECK(
		spi_bus_initialize(
			DeviceId,
			busConfig,
			SPI_DMA_CH_AUTO)
	);

	BusHandle = spi_device_handle_t();

	Transaction.length = SPI_BUFF_SIZE_TX;

	Transaction.rx_buffer =
		new uint8_t (SPI_BUFF_SIZE_RX);

	Transaction.tx_buffer =
		new uint8_t (SPI_BUFF_SIZE_TX);
}

SpiControl::~SpiControl()
{
	spi_bus_remove_device(BusHandle);

	spi_bus_free(DeviceId);

	delete (
		Transaction.rx_buffer,
		Transaction.tx_buffer);
}

bool SpiControl::Open()
{
	return (
		spi_bus_add_device(
			DeviceId,
			&DeviceConfig,
			&BusHandle
		) == ESP_OK);
}

int SpiControl::Send(uint8_t *, int)
{
}

int SpiControl::Receive(uint8_t *buffer)
{
	spi_device_transmit(
		BusHandle,
		&Transaction
	);
}