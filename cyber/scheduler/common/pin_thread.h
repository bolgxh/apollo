/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CYBER_SCHEDULER_COMMON_PIN_THREAD_H_
#define CYBER_SCHEDULER_COMMON_PIN_THREAD_H_

#include <string>
#include <thread>
#include <vector>

#include "cyber/common/log.h"

namespace apollo {
namespace cyber {
namespace scheduler {

void ParseCpuset(const std::string& str, std::vector<int>* cpuset);

void SetSchedAffinity(std::thread* thread,
                      const std::vector<int>& cpus,
                      const std::string& affinity,
                      int cpu_id = -1);

void SetSchedPolicy(std::thread* thread,
                    std::string spolicy,
                    int sched_priority,
                    pid_t tid = -1);

}  // namespace scheduler
}  // namespace cyber
}  // namespace apollo

#endif  // CYBER_SCHEDULER_COMMON_PIN_THREAD_H_
