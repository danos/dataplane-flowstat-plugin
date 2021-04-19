# SPDX-License-Identifier: LGPL-2.1-only
# Copyright (c) 2021, SafePoint <info@safepoint.vn>. All rights reserved.
# Copyright (c) 2020-2021, AT&T Intellectual Property. All rights reserved.

flowstat_test_plugin_sources = files(
        'src/dp_test_pipeline_flowstat.c',
)

flowstat_test_plugin = shared_module('flowstat_test',
        sources: [
                flowstat_test_plugin_sources,
        ],
        include_directories: [
                include_directories('src'),
        ],
        dependencies: [dp_dep, dpdk_dep, flowstat_plugin_dep],
        c_args: [
                '-DUNIT_TEST',
                '-Wno-unused-function'
        ]
)

# Only files that declare a CK test suite (using DP_DECL_TEST_SUITE())
# These will be iterated over using CK_RUN_SUITE for testing
# Everything else belongs in test_lib_sources above
check_tests = [
        'dp_test_pipeline_flowstat.c'
]

dataplane_test = find_program('dataplane_test')

lcore_number = 0
cores_available = run_command('nproc').stdout().to_int()

foreach suite : check_tests
        suite_env = ['CK_RUN_SUITE=@0@'.format(suite), 'CK_XML_LOG_FILE_NAME=test_@0@.xml'.format(suite)]
        test(suite, dataplane_test,
                depends: [flowstat_plugin, flowstat_test_plugin],
                workdir: meson.current_build_dir(),
                args: ['-l @0@'.format(lcore_number), '-d0', '-E'],
                env: suite_env,
                timeout: 120
        )

        lcore_number += 1
        if (lcore_number >= cores_available)
                lcore_number = 0
	endif

endforeach
