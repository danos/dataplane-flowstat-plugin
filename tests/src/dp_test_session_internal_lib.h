/*
 * Copyright (c) 2021, SafePoint <info@safepoint.vn>. All rights reserved.
 * Copyright (c) 2018-2020, AT&T Intellectual Property. All rights reserved.
 * Copyright (c) 2015 by Brocade Communications Systems, Inc.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Whole dataplane test npf session library
 */

#ifndef __DP_TEST_SESSION_INTERNAL_LIB_H__
#define __DP_TEST_SESSION_INTERNAL_LIB_H__

void _dp_test_session_gc(const char *file, int line);
#define dp_test_session_gc() \
	_dp_test_session_gc(__FILE__, __LINE__)

#endif  /* __DP_TEST_SESSION_LIB_H__ */

