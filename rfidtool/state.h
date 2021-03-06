#ifndef __STATE_INCLUDED_H__
#define __STATE_INCLUDED_H__

#include <Arduino.h>

struct StateMachine;

struct State {
  StateMachine* sm;

  virtual void enter() = 0;
  virtual void action() = 0;
  virtual void leave() = 0;

  void stateGoto(State* state);
};

struct NullState : public State {
  inline void enter() {}

  inline void action() {}

  inline void leave() {}
};

struct StateMachine {
  State* currentState;

  inline StateMachine() : currentState(NULL) {}
  void stateGoto(State* state);
  void stateAction();
};

#endif
