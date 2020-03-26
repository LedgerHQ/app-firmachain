/*******************************************************************************
*   (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#include <gmock/gmock.h>
#include <zxmacros.h>
#include <bech32.h>

namespace {
    TEST(BECH32, hex_to_address) {
        char addr_out[100];
        const char *hrp = "zx";

        uint8_t data1[] = {1, 3, 5};
        uint8_t data2[] = {1, 3, 5, 7, 9, 11, 13};

        bech32EncodeFromBytes(addr_out, hrp, data1, sizeof(data1));
        std::cout << addr_out << std::endl;
        ASSERT_STREQ("zx1qypse825ac", addr_out);

        bech32EncodeFromBytes(addr_out, hrp, data2, sizeof(data2));
        std::cout << addr_out << std::endl;
        ASSERT_STREQ("zx1qyps2pcfpvx20dk22", addr_out);
    }
}
