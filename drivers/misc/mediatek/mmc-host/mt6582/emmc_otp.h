/*
* Copyright (C) 2011-2014 MediaTek Inc.
* 
* This program is free software: you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 2 as published by the Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EMMC_OTP_H
#define EMMC_OTP_H


#define OTP_MAGIC_NUM           0x4E3AF28B

struct emmc_otp_config
{
    u32 (* read)         (u32 blkno, void *BufferPtr);
    u32 (* write)        (u32 blkno, void *BufferPtr);
    u32 (* query_length) (u32 *Length);
};

struct otp_ctl
{
    unsigned int QLength;
    unsigned int Offset;
    unsigned int Length;
    char *BufferPtr;
    unsigned int status;
};


#define EMMC_OTP_START_ADDRESS   (0xc0000000)  /* just for debug */

#define EMMC_HOST_NUM            0
#define EMMC_OTP_MAGIC           'k'

/* EMMC OTP IO control number */
#define EMMC_OTP_GET_LENGTH    _IOW(EMMC_OTP_MAGIC, 1, int)
#define EMMC_OTP_READ          _IOW(EMMC_OTP_MAGIC, 2, int)
#define EMMC_OTP_WRITE         _IOW(EMMC_OTP_MAGIC, 3, int)

#define FS_EMMC_OTP_READ         0
#define FS_EMMC_OTP_WRITE        1

/* EMMC OTP Error codes */
#define OTP_SUCCESS                   0
#define OTP_ERROR_OVERSCOPE          -1
#define OTP_ERROR_TIMEOUT            -2
#define OTP_ERROR_BUSY               -3
#define OTP_ERROR_NOMEM              -4
#define OTP_ERROR_RESET              -5

#endif /* end of EMMC_OTP_H */
