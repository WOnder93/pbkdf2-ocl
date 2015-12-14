/*
 * Copyright (C) 2015, Ondrej Mosnacek <omosnacek@gmail.com>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation: either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBPBKDF2_COMPUTE_TESTS_PBKDF2TESTVECTOR_H
#define LIBPBKDF2_COMPUTE_TESTS_PBKDF2TESTVECTOR_H

#include <cstdlib>
#include <vector>
#include <string>

#include "pbkdf2parameters.h"

namespace libpbkdf2 {
namespace compute {
namespace tests {

class PBKDF2TestVector
{
private:
    PBKDF2Parameters params;

    const void *dk;

public:
    const PBKDF2Parameters &getParams() const { return params; }

    const void *getDerivedKeyData() const { return dk; }

    PBKDF2TestVector() { }
    PBKDF2TestVector(
            const PBKDF2Parameters &params,
            const void *dk) :
        params(params), dk(dk) { }

    static const std::vector<PBKDF2TestVector> &getStandardVectors(std::string hashSpec);
};

} // namespace tests
} // namespace compute
} // namespace libpbkdf2

#endif // LIBPBKDF2_COMPUTE_TESTS_PBKDF2TESTVECTOR_H
