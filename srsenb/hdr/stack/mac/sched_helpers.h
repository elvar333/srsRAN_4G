/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2020 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSLTE_SCHED_HELPERS_H
#define SRSLTE_SCHED_HELPERS_H

#include "srsenb/hdr/stack/mac/sched_common.h"
#include "srslte/common/logmap.h"
#include "srslte/interfaces/sched_interface.h"

namespace srsenb {

inline uint32_t aggr_level(uint32_t aggr_idx)
{
  return 1u << aggr_idx;
}

/// Obtain rvidx from nof retxs. This value is stored in DCI
inline uint32_t get_rvidx(uint32_t retx_idx)
{
  const static uint32_t rv_idx[4] = {0, 2, 3, 1};
  return rv_idx[retx_idx % 4];
}

/// Obtain nof retxs from rvidx.
inline uint32_t get_nof_retx(uint32_t rv_idx)
{
  const static uint32_t nof_retxs[4] = {0, 3, 1, 2};
  return nof_retxs[rv_idx % 4];
}

void log_dl_cc_results(srslte::log_ref log_h, uint32_t enb_cc_idx, const sched_interface::dl_sched_res_t& result);

/**
 * Generate possible CCE locations a user can use to allocate DCIs
 * @param regs Regs data for the given cell configuration
 * @param location Result of the CCE location computation.
 * @param cfi Number of control symbols used for the PDCCH
 * @param sf_idx subframe index specific to the tx TTI (relevant only for data and RAR transmissions)
 * @param rnti identity of the user (invalid RNTI for RAR and BC transmissions)
 */
void generate_cce_location(srslte_regs_t*   regs,
                           sched_dci_cce_t* location,
                           uint32_t         cfi,
                           uint32_t         sf_idx = 0,
                           uint16_t         rnti   = SRSLTE_INVALID_RNTI);

} // namespace srsenb

#endif // SRSLTE_SCHED_HELPERS_H
