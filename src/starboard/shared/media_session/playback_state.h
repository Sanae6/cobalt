// Copyright 2017 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef STARBOARD_SHARED_MEDIA_SESSION_PLAYBACK_STATE_H_
#define STARBOARD_SHARED_MEDIA_SESSION_PLAYBACK_STATE_H_

namespace starboard {
namespace shared {
namespace media_session {

enum PlaybackState { kPlaying = 0, kPaused = 1, kNone = 2 };

void UpdateActiveSessionPlatformPlaybackState(PlaybackState state);

}  // namespace media_session
}  // namespace shared
}  // namespace starboard

#endif  // STARBOARD_SHARED_MEDIA_SESSION_PLAYBACK_STATE_H_