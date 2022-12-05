// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform_message.hpp"

#include <utility>

namespace flutter {

PlatformMessage::PlatformMessage(std::string channel,
                                 fml::MallocMapping data,
                                 fml::RefPtr<PlatformMessageResponse> response)
    : channel_(std::move(channel)),
      data_(std::move(data)),
      hasData_(true),
      response_(std::move(response)) {}
PlatformMessage::PlatformMessage(std::string channel,
                                 fml::RefPtr<PlatformMessageResponse> response)
    : channel_(std::move(channel)),
      data_(),
      hasData_(false),
      response_(std::move(response)) {}

PlatformMessage::~PlatformMessage() = default;

}  // namespace flutter
