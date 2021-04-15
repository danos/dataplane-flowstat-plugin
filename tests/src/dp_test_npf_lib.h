/*
 * Copyright (c) 2021, SafePoint <info@safepoint.vn>. All rights reserved.
 * Copyright (c) 2017-2020, AT&T Intellectual Property.  All rights reserved.
 * Copyright (c) 2015 by Brocade Communications Systems, Inc.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Whole dataplane test npf library
 */

#ifndef __DP_TEST_NPF_LIB_H__
#define __DP_TEST_NPF_LIB_H__

#include <stdint.h>
#include <stdbool.h>

#include "dp_test/dp_test_firewall_lib.h"

/*
 * Defines for backward compatibility.
 */
#define dp_test_npf_rule_t	dp_test_fw_rule_t
#define dp_test_npf_ruleset_t	dp_test_fw_ruleset_t

void
_dp_test_npf_cmd_fmt(bool print, const char *file, int line,
		     const char *fmt_str, ...)
	__attribute__((__format__(printf, 4, 5)));

#define dp_test_npf_cmd_fmt(print, fmt_str, ...)	\
	_dp_test_npf_cmd_fmt(print, __FILE__, __LINE__, \
			     fmt_str, ##__VA_ARGS__)

#define dp_test_npf_fw_add(rs, debug)					\
	_dp_test_fw_ruleset_add(rs, "fw", debug,			\
				 true, __FILE__, __LINE__)

#define dp_test_npf_fw_del(fw, debug)				\
	_dp_test_fw_ruleset_del(fw, "fw", debug,		\
				 true, __FILE__, __LINE__)

#endif
