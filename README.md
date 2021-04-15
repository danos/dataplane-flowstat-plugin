# DANOS Dataplane flowstat plugin

A plugin for dataplane allow viewing flow statistics.

# Tests
Setup and build test environment
```sh
meson build
ninja -C build
```
Run tests
```
cd build
meson test -v
```

## Architecture
```sh
      +------------+      +----------+      +--------------+
      |  Dataplane |  --> | wfcqueue |  --> | flowstat.log |
      +------------+      +----------+      +--------------+
                                                    |
                                                    v
      +------------+      +-------------+      +-----------+
      | op command |  --> | flowstat.db | <--  | flowstatd |
      +------------+      +-------------+      +-----------+
```
- Session info was collected by session watch, and stored in a wait free queue. 
- A thread dequeue session info from queue and flush to a log file (rotated by logrotate).
- A daemon called flowstatd will read log from log file then save statistics into a sqlite3 db `flowstat.db`.
- OP command will query statistics directly from `flowstat.db`.
- There 4 period time
  - now: statistics were calculated by session table of dataplane
  - 5m/1h/1d: statistics  from `flowstatd.db`
