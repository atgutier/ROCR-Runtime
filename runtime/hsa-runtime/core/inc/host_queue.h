////////////////////////////////////////////////////////////////////////////////
//
// The University of Illinois/NCSA
// Open Source License (NCSA)
//
// Copyright (c) 2014-2015, Advanced Micro Devices, Inc. All rights reserved.
//
// Developed by:
//
//                 AMD Research and AMD HSA Software Development
//
//                 Advanced Micro Devices, Inc.
//
//                 www.amd.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal with the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
//  - Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimers.
//  - Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimers in
//    the documentation and/or other materials provided with the distribution.
//  - Neither the names of Advanced Micro Devices, Inc,
//    nor the names of its contributors may be used to endorse or promote
//    products derived from this Software without specific prior written
//    permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS WITH THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef HSA_RUNTIME_CORE_INC_HOST_QUEUE_H_
#define HSA_RUNTIME_CORE_INC_HOST_QUEUE_H_

#include "core/inc/memory_region.h"
#include "core/inc/queue.h"
#include "core/inc/runtime.h"
#include "core/inc/signal.h"

namespace core {
class HostQueue : public Queue {
 public:
  HostQueue(hsa_region_t region, uint32_t ring_size, hsa_queue_type_t type,
            uint32_t features, hsa_signal_t doorbell_signal);

  ~HostQueue();

  hsa_status_t Inactivate() { return HSA_STATUS_SUCCESS; }

  uint64_t LoadReadIndexAcquire() {
    return atomic::Load(&amd_queue_.read_dispatch_id,
                        std::memory_order_acquire);
  }

  uint64_t LoadReadIndexRelaxed() {
    return atomic::Load(&amd_queue_.read_dispatch_id,
                        std::memory_order_relaxed);
  }

  uint64_t LoadWriteIndexAcquire() {
    return atomic::Load(&amd_queue_.write_dispatch_id,
                        std::memory_order_acquire);
  }

  uint64_t LoadWriteIndexRelaxed() {
    return atomic::Load(&amd_queue_.write_dispatch_id,
                        std::memory_order_relaxed);
  }

  void StoreReadIndexRelaxed(uint64_t value) {
    atomic::Store(&amd_queue_.read_dispatch_id, value,
                  std::memory_order_relaxed);
  }

  void StoreReadIndexRelease(uint64_t value) {
    atomic::Store(&amd_queue_.read_dispatch_id, value,
                  std::memory_order_release);
  }

  void StoreWriteIndexRelaxed(uint64_t value) {
    atomic::Store(&amd_queue_.write_dispatch_id, value,
                  std::memory_order_relaxed);
  }

  void StoreWriteIndexRelease(uint64_t value) {
    atomic::Store(&amd_queue_.write_dispatch_id, value,
                  std::memory_order_release);
  }

  uint64_t CasWriteIndexAcqRel(uint64_t expected, uint64_t value) {
    return atomic::Cas(&amd_queue_.write_dispatch_id, value, expected,
                       std::memory_order_acq_rel);
  }

  uint64_t CasWriteIndexAcquire(uint64_t expected, uint64_t value) {
    return atomic::Cas(&amd_queue_.write_dispatch_id, value, expected,
                       std::memory_order_acquire);
  }

  uint64_t CasWriteIndexRelaxed(uint64_t expected, uint64_t value) {
    return atomic::Cas(&amd_queue_.write_dispatch_id, value, expected,
                       std::memory_order_relaxed);
  }

  uint64_t CasWriteIndexRelease(uint64_t expected, uint64_t value) {
    return atomic::Cas(&amd_queue_.write_dispatch_id, value, expected,
                       std::memory_order_release);
  }

  uint64_t AddWriteIndexAcqRel(uint64_t value) {
    return atomic::Add(&amd_queue_.write_dispatch_id, value,
                       std::memory_order_acq_rel);
  }

  uint64_t AddWriteIndexAcquire(uint64_t value) {
    return atomic::Add(&amd_queue_.write_dispatch_id, value,
                       std::memory_order_acquire);
  }

  uint64_t AddWriteIndexRelaxed(uint64_t value) {
    return atomic::Add(&amd_queue_.write_dispatch_id, value,
                       std::memory_order_relaxed);
  }

  uint64_t AddWriteIndexRelease(uint64_t value) {
    return atomic::Add(&amd_queue_.write_dispatch_id, value,
                       std::memory_order_release);
  }

  hsa_status_t SetCUMasking(const uint32_t num_cu_mask_count,
                            const uint32_t* cu_mask) {
    return HSA_STATUS_ERROR;
  }

  bool active() const { return active_; }

  void* operator new(size_t size) {
    return _aligned_malloc(size, HSA_QUEUE_ALIGN_BYTES);
  }

  void* operator new(size_t size, void* ptr) { return ptr; }

  void operator delete(void* ptr) { _aligned_free(ptr); }

  void operator delete(void*, void*) {}

 private:
  static const size_t kRingAlignment = 256;
  const uint32_t size_;
  bool active_;
  void* ring_;

  DISALLOW_COPY_AND_ASSIGN(HostQueue);
};
}  // namespace core
#endif  // header guard