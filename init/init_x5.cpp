/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"


#define CHUNK 2048 /* read 2048 bytes at a time */

int check_cmdline(const char param[]) {

    char buf[CHUNK];
    FILE *file;
    size_t nread;
    file = fopen("/proc/cmdline", "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
                /* fwrite(buf, 1, nread, stdout); */
                char delims[] = " ";
                char *word = NULL;
                word = strtok(buf, delims);

                while(word != NULL) {
                        if (!strcmp(param,word)) {
                                fclose(file);
                                return 1;
                        }
                        word = strtok(NULL, delims);
                }
        }
    }	
    fclose(file);
    return 0;
}

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char serial[PROP_VALUE_MAX];
    //char device[PROP_VALUE_MAX];
    //char devicename[PROP_VALUE_MAX];

    property_get("ro.boot.serialno", serial);
    property_set("ro.product.model", "LG-LS740");
    property_set("ro.product.device", "x5");
    property_set("ro.nfc.port", "I2C");
    property_set("ro.build.description", "x5_spr_us-user 5.0.2 LRX22G.A1423481010 15040202274a7 release-keys");
    property_set("ro.build.fingerprint", "lge/x5_spr_us/x5:5.0.2/LRX22G.A1423481010/15040202274a7:user/release-keys");
    property_set("persist.radio.multisim.config", "");
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ro.telephony.ril_class", "LgeX5RIL");
}
