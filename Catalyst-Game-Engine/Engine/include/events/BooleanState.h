#pragma once

namespace Events {

	struct BooleanState {
		bool value = false;

		bool changed = false;
		bool rising = false;
		bool falling = false;

		BooleanState(bool value, bool changed, bool rising, bool falling);
	};

	class BooleanStateTracker {
	private:
		bool value = false;

		bool changed = false;
		bool rising = false;
		bool falling = false;

	public:
		void updateValue(bool newValue);

		BooleanState getState();

		bool getValue();
		bool getChanged();
		bool getRising();
		bool getFalling();
	};
}