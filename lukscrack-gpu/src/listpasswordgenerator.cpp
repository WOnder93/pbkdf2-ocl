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

#include "listpasswordgenerator.h"

namespace lukscrack {

bool ListPasswordGenerator::nextPassword(const char *&pwData, std::size_t &pwLength)
{
    if (stream->eof()) {
        return false;
    }
    passwordBuffer.clear();
    while (true) {
        char c;
        try {
            stream->get(c);
        } catch (const std::ios_base::failure &) {
            if (stream->eof()) {
                break;
            }
            throw;
        }
        if (c == '\n') {
            break;
        }
        passwordBuffer.push_back(c);
    }
    pwData = passwordBuffer.data();
    pwLength = passwordBuffer.size();
    return true;
}

} // namespace lukscrack
