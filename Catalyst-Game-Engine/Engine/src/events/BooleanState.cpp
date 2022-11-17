#include "BooleanState.h"

namespace Events {
	

	BooleanState::BooleanState(bool _value, bool _changed, bool _rising, bool _falling) {
		value = _value;
		changed = _changed;
		rising = _rising;
		falling = _falling;
	}

	void BooleanStateTracker::updateValue(bool newValue) {
		if (value == newValue) {
			changed = false;
			rising = false;
			falling = false;
		}
		else if (value == false && newValue == true) {
			changed = true;
			rising = true;
			falling = false;
		}
		else if (value == true && newValue == false) {
			changed = false;
			rising = false;
			falling = false;
		}

		value = newValue;
	}

	BooleanState BooleanStateTracker::getState() {
		return BooleanState(value, changed, rising, falling);
	}

	bool BooleanStateTracker::getValue() { return value; }
	bool BooleanStateTracker::getChanged() { return changed; }
	bool BooleanStateTracker::getRising() { return rising; }
	bool BooleanStateTracker::getFalling() { return falling; }
	
}
