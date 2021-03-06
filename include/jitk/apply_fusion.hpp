/*
This file is part of Bohrium and copyright (c) 2012 the Bohrium
team <http://www.bh107.org>.

Bohrium is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3
of the License, or (at your option) any later version.

Bohrium is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the
GNU Lesser General Public License along with Bohrium.

If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __BH_JITK_APPLY_FUSION_HPP
#define __BH_JITK_APPLY_FUSION_HPP

#include <iostream>
#include <chrono>

#include <bh_instruction.hpp>
#include <bh_config_parser.hpp>
#include <jitk/block.hpp>
#include <jitk/fuser.hpp>
#include <jitk/transformer.hpp>
#include <jitk/fuser_cache.hpp>
#include <jitk/statistics.hpp>

namespace bohrium {
namespace jitk {


// Apply the pre-fuser (i.e. fuse an instruction list to a block list specified by the name 'transformer_name'
std::vector<Block> apply_pre_fusion(const std::vector<bh_instruction*> &instr_list,
                                    const std::string &transformer_name);

// Apply the list of tranformers specified by the names in 'transformer_names'
// 'avoid_rank0_sweep' will avoid fusion of sweeped and non-sweeped blocks at the root level
void apply_transformers(std::vector<Block> &block_list, const std::vector<std::string> &transformer_names,
                        bool avoid_rank0_sweep);

// Create a block list based on 'instr_list' and what is in the 'config' and 'fcache'
// 'avoid_rank0_sweep' will avoid fusion of sweeped and non-sweeped blocks at the root level
std::vector<Block> get_block_list(const std::vector<bh_instruction*> &instr_list, const ConfigParser &config,
                                  FuseCache &fcache, Statistics &stat, bool avoid_rank0_sweep);

} // jitk
} // bohrium

#endif
