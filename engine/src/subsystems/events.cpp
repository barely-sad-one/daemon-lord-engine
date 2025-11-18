#include "subsystems/events.h"

namespace Lord::subsystem {


void EventBus::fire(u16 code, void* sender, void* context) {
  auto& self = get();
  u64 size = self.m_events[code].size();
  if (size == 0) return;

  for (const auto& event : self.m_events[code] ) {
    event->invoke(sender, context);
  }
}

}
