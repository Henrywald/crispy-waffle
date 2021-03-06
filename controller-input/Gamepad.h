#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Windows.h>
#include <Xinput.h>

class Gamepad
{
public:
	// Function prototypes
	//---------------------//

	// Constructors
	Gamepad();
	Gamepad(int a_iIndex);

	void Update();       // Update gamepad state
	void RefreshState(); // Update button states for next frame

	// Thumbstick functions
	// - Return true if stick is inside deadzone, false if outside
	bool LStick_InDeadzone();
	bool RStick_InDeadzone();

	float LeftStick_X();  // Return X axis of left stick
	float LeftStick_Y();  // Return Y axis of left stick
	float RightStick_X(); // Return X axis of right stick
	float RightStick_Y(); // Return Y axis of right stick

	// Trigger functions
	float LeftTrigger();  // Return value of left trigger
	float RightTrigger(); // Return value of right trigger

	// Button functions
	// - 'Pressed' - Return true if pressed, false if not
	// - 'Down'    - Same as 'Pressed', but ONLY on current frame
	bool GetButtonPressed(int a_iButton);
	bool GetButtonDown(int a_iButton);

	// Utility functions
	XINPUT_STATE GetState(); // Return gamepad state
	int GetIndex();          // Return gamepad index
	bool Connected();        // Return true if gamepad is connected

	// Vibrate the gamepad (0.0f cancel, 1.0f max speed)
	void Rumble(float a_fLeftMotor = 0.0f, float a_fRightMotor = 0.0f);

private:
	// Member variables
	//---------------------//

	XINPUT_STATE m_State; // Current gamepad state
	int m_iGamepadIndex;  // Gamepad index (eg. 1,2,3,4)

	static const int ButtonCount = 14;    // Total gamepad buttons
	bool bPrev_ButtonStates[ButtonCount]; // Previous frame button states
	bool bButtonStates[ButtonCount];      // Current frame button states

	// Buttons pressed on current frame
	bool bGamepad_ButtonsDown[ButtonCount];
};

#endif // GAMEPAD_H