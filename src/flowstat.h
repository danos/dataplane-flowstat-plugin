/*
 * Flow stat pipeline feature node
 *
 * Copyright (c) 2021, SafePoint <info@safepoint.vn>.  All rights reserved.
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef FLOWSTAT_H
#define FLOWSTAT_H

#ifdef UNIT_TEST
#define FLOWSTAT_LOG "/tmp/flowstat_test.log"
#define LOG_ES_SESSION_INTERVAL 2
#else
#define FLOWSTAT_LOG "/var/log/flowstat.log"
#define LOG_ES_SESSION_INTERVAL 60
#endif

/* Used by unit-test */
void export_log(void);

#endif
