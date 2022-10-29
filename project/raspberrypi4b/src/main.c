/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      main.c
 * @brief     main source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2022-10-31
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2022/10/31  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_aht20_basic.h"
#include "driver_aht20_read_test.h"
#include <math.h>
#include <stdlib.h>

/**
 * @brief     aht20 full function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *             - 0 success
 *             - 1 run failed
 *             - 5 param is invalid
 * @note      none
 */
uint8_t aht20(uint8_t argc, char **argv)
{
    if (argc == 1)
    {
        goto help;
    }
    else if (argc == 2)
    {
        if (strcmp("-i", argv[1]) == 0)
        {
            aht20_info_t info;
            
            /* print aht20 information */
            aht20_info(&info);
            aht20_interface_debug_print("aht20: chip is %s.\n", info.chip_name);
            aht20_interface_debug_print("aht20: manufacturer is %s.\n", info.manufacturer_name);
            aht20_interface_debug_print("aht20: interface is %s.\n", info.interface);
            aht20_interface_debug_print("aht20: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
            aht20_interface_debug_print("aht20: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
            aht20_interface_debug_print("aht20: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
            aht20_interface_debug_print("aht20: max current is %0.2fmA.\n", info.max_current_ma);
            aht20_interface_debug_print("aht20: max temperature is %0.1fC.\n", info.temperature_max);
            aht20_interface_debug_print("aht20: min temperature is %0.1fC.\n", info.temperature_min);
            
            return 0;
        }
        else if (strcmp("-p", argv[1]) == 0)
        {
            /* print pin connection */
            aht20_interface_debug_print("aht20: SCL connected to GPIO3(BCM).\n");
            aht20_interface_debug_print("aht20: SDA connected to GPIO2(BCM).\n");
            
            return 0;
        }
        else if (strcmp("-h", argv[1]) == 0)
        {
            help:
            
            aht20_interface_debug_print("aht20 -h\n\tshow aht20 help.\n");
            aht20_interface_debug_print("aht20 -i\n\tshow aht20 chip and driver information.\n");
            aht20_interface_debug_print("aht20 -p\n\tshow aht20 pin connections of the current board.\n");
            aht20_interface_debug_print("aht20 -t read <times>\n\trun aht20 read test.times means test times.\n");
            aht20_interface_debug_print("aht20 -c read <times>\n\trun aht20 read function.times means test times.\n");
            
            return 0;
        }
        /* param is invalid */
        else
        {
            return 5;
        }
    }
    else if (argc == 4)
    {
        /* run test */
        if (strcmp("-t", argv[1]) == 0)
        {
             /* read test */
            if (strcmp("read", argv[2]) == 0)
            {
                /* run read test */
                if (aht20_read_test(atoi(argv[3])) != 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            /* param is invalid */
            else
            {
                return 5;
            }
        }
        /* run common */
        else if (strcmp("-c", argv[1]) == 0)
        {
             /* basic read */
            if (strcmp("read", argv[2]) == 0)
            {
                uint8_t res;
                uint32_t times;
                uint32_t i;
                float temperature;
                uint8_t humidity;
                
                res = aht20_basic_init();
                if (res != 0)
                {
                    return 1;
                }
                times = atoi(argv[3]);
                for (i = 0; i < times; i++)
                {
                    aht20_interface_delay_ms(2000);
                    res = aht20_basic_read((float *)&temperature, (uint8_t *)&humidity);
                    if (res != 0)
                    {
                        (void)aht20_basic_deinit();
                        
                        return 1;
                    }
                    aht20_interface_debug_print("aht20: %d/%d.\n", (uint32_t)(i+1), (uint32_t)times);
                    aht20_interface_debug_print("aht20: temperature is %0.2fC.\n", temperature);
                    aht20_interface_debug_print("aht20: humidity is %d%%.\n", humidity); 
                }
                (void)aht20_basic_deinit();
                
                return 0;
            }
            /* param is invalid */
            else
            {
                return 5;
            }
        }
        /* param is invalid */
        else
        {
            return 5;
        }
    }
    /* param is invalid */
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = aht20(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        aht20_interface_debug_print("aht20: run failed.\n");
    }
    else if (res == 5)
    {
        aht20_interface_debug_print("aht20: param is invalid.\n");
    }
    else
    {
        aht20_interface_debug_print("aht20: unknow status code.\n");
    }

    return 0;
}
