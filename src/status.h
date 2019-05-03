// status.h
//
// Copyright (c) 2019 Kristofer Berggren
// All rights reserved.
//
// nmail is distributed under the MIT license, see LICENSE for details.

#pragma once

#include <cstdint>
#include <string>

struct StatusUpdate
{
  uint32_t SetFlags = 0;
  uint32_t ClearFlags = 0;
};

class Status
{
public:
  enum Flag
  {
    FlagNone = 0,
    FlagConnecting = (1 << 0),
    FlagFetching = (1 << 1),
    FlagSending = (1 << 2),
    FlagPrefetching = (1 << 3),
    FlagMoving = (1 << 4),
    FlagDeleting = (1 << 5),
    FlagUpdatingFlags = (1 << 6),
    FlagConnected = (1 << 7),
    FlagOffline = (1 << 8),
    FlagIdle = (1 << 9),
    FlagMax = FlagIdle,
  };

  Status();
  virtual ~Status();

  void Update(const StatusUpdate& p_StatusUpdate);
  bool IsSet(const Flag& p_Flag);
  std::string ToString();
  
private:
  uint32_t m_Flags = 0;
};
