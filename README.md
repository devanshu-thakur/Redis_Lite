# Redis-Lite

A lightweight, persistent in-memory Key-Value store built in C++ inspired by Redis architecture.

## Overview

Redis-Lite stores records directly in RAM for rapid lookups and mutates an **Append-Only File (`data.txt` / AOF)** in real time. On startup, the engine sequentially replays logged transactions to restore memory state seamlessly without data loss.

## Features

- **In-Memory Storage:** Fast key-value updates and lookups using standard hash/map storage.
- **Append-Only Persistence (AOF):** Every `set` and `del` mutation logs directly to disk in O(1) time.
- **Crash Recovery:** Automatically rebuilds active keys on startup by replaying the operation log.
- **Interactive CLI:** Direct command-line prompt for database interaction.

## Supported Commands

| Command | Description | Example |
| `set <key> <val>` | Insert or overwrite a key-value record | `set name Devanshu` |
| `get <key>` | Fetch the value associated with a key | `get name` |
| `del <key>` | Logically remove a record | `del name` |
| `exit` | Terminate the CLI session | `exit` |

## Build & Run

Ensure you have a C++ compiler (`g++` or `clang++`):

```bash
# Compile
g++ -std=c++17 main.cpp -o redis_lite

# Run
./redis_lite
```

## Example Usage

```text
==== Redis-Lite CLI Engine ====
db> set user:1 Devanshu
OK
db> get user:1
Devanshu
db> set score 100
OK
db> del user:1
OK
db> get user:1
(nil)
db> exit
```

## Roadmap

- [ ] Low-level raw pointer table implementation (zero standard-library containers).
- [ ] In-place character pointer tokenization (`char*` instead of `std::string`).
- [ ] AOF Log Compaction to compress historical updates.