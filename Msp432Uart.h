/**
 * @file Msp432Uart.h
 * @author Aniket Sedhai (aniketsedhai@gmail.com)
 * @brief This file defines Uart for Msp432 family.
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MSP432_UART_H
#define MSP432_UART_H

/* ====================================================================================================================
 * INCLUDES
 * ====================================================================================================================
 */

#include "HwAbstractionLayerUartInterface.h"

/* ====================================================================================================================
 * PUBLIC DEFINES
 * ====================================================================================================================
 */

/* MSP432 UART Interfaces supported on this platform*/
#define MSP432_UART_INTERFACE_SERIAL_COMM_1     (1U)
#define MSP432_UART_INTERFACE_SERIAL_COMM_2     (2U)
#define MSP432_UART_INTERFACE_SERIAL_COMM_3     (3U)
#define MSP432_UART_INTERFACE_SERIAL_COMM_MAX_COUNT     (1 + MSP432_UART_INTERFACE_SERIAL_COMM_3)

/* ====================================================================================================================
 * CLASS DECLARATION
 * ====================================================================================================================
 */

class Msp432Uart: public HwAbstractionLayerUartInterface
{
    public:

    /**
     * @brief Get the instance object.
     * 
     * @param intf_id - the interface id for the singleton to retrive
     * @return Msp432Uart* - instance of the class
     */
    static Msp432Uart* get_instance(uint32_t intf_id);

    /**
     * @brief Initialize a UART interface
     * 
     * @param[in] baud_rate - baud rate to initialize the UART
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e - returns zero upon success, 
     * non-zero upon failure
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_init(
        uint32_t baud_rate,
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Check if the associated interface is initialized.
     * 
     * @return true - is initialized
     * @return false - is not initialized
     */
    bool hal_uart_is_initialized(void);

    /**
     * @brief Check if the UART is enabled to receive bytes.
     * 
     * @return true - is enabled
     * @return false - is not enabled
     */
    bool hal_uart_is_rx_enabled(void);

    /**
     * @brief Check if the UART is enabled to transmit bytes.
     * 
     * @return true - is enabled
     * @return false - is not enabled
     */
    bool hal_uart_is_tx_enabled(void);

    /**
     * @brief Enable both receive and transmit via UART interface.
     * 
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e - returns zero upon success and non zero upon failure.
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_enable_both_rx_tx(
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Enable receive capability via UART interface.
     * 
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e 
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_enable_rx(
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Enable transmit capability via UART interface.
     * 
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e 
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_enable_tx(
        int32_t* ret_platform_specific_status_p);


    /**
     * @brief Disable both receive and transmit via UART interface.
     * 
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e 
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_disable_both_rx_tx(
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Disable receive via UART interface.
     * 
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e 
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_disable_rx(
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Disable transmit via UART interface.
     * 
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e 
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_disable_tx(
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Transmit bytes via UART interface by writing the bytes on the UART transmit buffer.
     * 
     * @param[in] input_bytes_p - pointer to the input data
     * @param[in] num_of_bytes - number of bytes that needs to be written to the transmit buffer
     * @param[out] ret_platform_specific_status_p - pointer to set the platform specific status, can be NULL
     * @return HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e 
     */
    HwAbstractionLayerUartInterfaceNamespace::hal_uart_status_e hal_uart_transmit(
        const uint8_t* input_bytes_p,
        uint32_t num_of_bytes,
        int32_t* ret_platform_specific_status_p);

    /**
     * @brief Destroy the Msp 432 Uart object
     * 
     */
    ~Msp432Uart(){};

    protected:
        //none

    private:

    /**
     * @brief Construct a new Msp 432 Uart object
     * 
     * @param[in] interface_id - the interface id to instantiate
     */
    Msp432Uart(uint32_t interface_id);
};

#endif /*MSP432_UART_H*/