//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_TRIGGER_SCRIPTTRIGGER_HPP
#define HEADER_SUPERTUX_TRIGGER_SCRIPTTRIGGER_HPP

#include "trigger/trigger_base.hpp"

class ReaderMapping;
class Writer;

class ScriptTrigger : public TriggerBase
{
public:
  ScriptTrigger(const ReaderMapping& reader);
  ScriptTrigger(const Vector& pos, const std::string& script);
  std::string get_class() const {
    return "scripttrigger";
  }

  bool has_variable_size() const {
    return true;
  }

  virtual ObjectSettings get_settings();
  virtual void after_editor_set();

  void write(Writer& writer);
  void event(Player& player, EventType type);
  void draw(DrawingContext& context);

private:
  EventType triggerevent;
  std::string script;
  Vector new_size;
  bool must_activate;
  bool oneshot;
  int runcount;
};

#endif

/* EOF */
