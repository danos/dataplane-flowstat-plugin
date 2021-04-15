# SPDX-License-Identifier: LGPL-2.1-only
# Copyright (c) 2021, SafePoint <info@safepoint.vn>. All rights reserved.
# Copyright (c) 2020, AT&T Intellectual Property. All rights reserved.

project('vyatta-flowstat-plugin', ['c', 'cpp'],
        default_options: [
                'debug=true',
                'optimization=3',
                'werror=true',
                'warning_level=2',
                'c_std=gnu11',
                'b_lto=true'
        ]
)

cc = meson.get_compiler('c')

add_project_arguments(
        '-D_GNU_SOURCE',
        cc.get_supported_arguments([
                '-Wno-deprecated-declarations',
                '-Wno-stringop-overflow',
                '-Wno-stringop-truncation',
                '-Wno-format-truncation'
        ]),
        language: 'c'
)

with_tests = get_option('with_tests').enabled()

check_dep = dependency('check', required: with_tests)
dp_dep = dependency('vyatta-dataplane-dev', required: true)
dl_dep = cc.find_library('dl', required : true)
dpdk_dep = dependency('libdpdk', version: '>= 19.11')
proto_c_dep = dependency('libprotobuf-c', version: '>= 1.0.0')
threads_dep = dependency('threads')
urcu_cds_dep = dependency('liburcu-cds', version: '>= 0.8.0')
urcu_dep = dependency('liburcu', version: '>= 0.8.0')
urcu_qsbr_dep = dependency('liburcu-qsbr', version: '>= 0.8.0')

subdir('protobuf')

flowstat_plugin_sources = files(
        'src/flowstat.c'
)

flowstat_plugin = shared_module('flowstat_plugin',
        sources: [flowstat_plugin_sources, flowstat_generated_protobuf_c],
        dependencies: [dp_dep, dl_dep, dpdk_dep, proto_c_dep, threads_dep, urcu_cds_dep, urcu_dep, urcu_qsbr_dep],
        include_directories: [],
        name_prefix: '',
        install: true,
        install_dir: get_option('prefix') / get_option('libdir') / 'vyatta-dataplane' / 'pipeline' / 'plugins'
)

flowstat_plugin_dep = declare_dependency(
        include_directories: [include_directories('src')],
        sources: [flowstat_plugin_sources, flowstat_generated_protobuf_c]
)

subdir('tests')
