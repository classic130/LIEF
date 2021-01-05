/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_PE_SIGNATURE_RSA_INFO_H_
#define LIEF_PE_SIGNATURE_RSA_INFO_H_
#include <vector>
#include <ostream>

#include "LIEF/types.hpp"
#include "LIEF/visibility.h"

namespace LIEF {
namespace PE {
class x509;

class LIEF_API RsaInfo {
  friend class x509;

  public:
  using rsa_ctx_handle = void*;
  using bignum_wrapper_t = std::vector<uint8_t>;

  public:
  RsaInfo(const RsaInfo& other);
  RsaInfo(RsaInfo&& other);
  RsaInfo& operator=(RsaInfo other);

  bool has_public_key(void) const;
  bool has_private_key(void) const;

  bignum_wrapper_t N(void) const;
  bignum_wrapper_t E(void) const;

  bignum_wrapper_t D(void) const;
  bignum_wrapper_t P(void) const;
  bignum_wrapper_t Q(void) const;

  void swap(RsaInfo& other);
  operator bool() const;

  LIEF_API friend std::ostream& operator<<(std::ostream& os, const RsaInfo& info);

  ~RsaInfo(void);

  private:
  RsaInfo(void);
  RsaInfo(const rsa_ctx_handle ctx);
  rsa_ctx_handle ctx_;
};

}
}
#endif
