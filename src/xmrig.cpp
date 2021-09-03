/* XMRig
 * Copyright (c) 2018-2021 SChernykh   <https://github.com/SChernykh>
 * Copyright (c) 2016-2021 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "App.h"
#include "base/kernel/Entry.h"
#include "base/kernel/Process.h"
#include "core/config/usage.h"


#ifdef XMRIG_FEATURE_OPENCL
#   include "backend/opencl/wrappers/OclPlatform.h"
#endif


int main(int argc, char **argv)
{
    using namespace xmrig;

    Process process(argc, argv);

    {
        int rc = 0;
        auto entry = std::make_unique<Entry>(usage);

#       ifdef XMRIG_FEATURE_OPENCL
        entry->add(OclPlatform::printPlatforms);
#       endif

        if (entry->exec(rc)) {
            return rc;
        }
    }

    App app;

    return app.exec();
}
