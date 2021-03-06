/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "android.hardware.gnss@2.1-service"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include "v2_1/GnssTemplate.h"

using ::android::OK;
using ::android::sp;
using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::joinRpcThreadpool;
using ::android::hardware::gnss::common::implementation::GnssTemplate;
using ::android::hardware::gnss::V2_1::IGnss;

int main(int /* argc */, char* /* argv */[]) {
    sp<IGnss> gnss = new GnssTemplate<IGnss>();
    configureRpcThreadpool(1, true /* will join */);
    if (gnss->registerAsService() != OK) {
        ALOGE("Could not register gnss 2.1 service.");
        return 1;
    }
    joinRpcThreadpool();

    ALOGE("Service exited!");
    return 1;
}