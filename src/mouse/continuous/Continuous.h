#pragma once

#include "../IMouseAlgorithm.h"

namespace continuous {

class Continuous : public IMouseAlgorithm {

public:
    std::string mouseFile() const;
    std::string interfaceType() const;
    void solve(int mazeWidth, int mazeHeight, char initialDirection, sim::MouseInterface* mouse);

private:
	//Thresholds for left and right sensors detecting side walls
#define hasLeftWall 800
#define hasRightWall 800

	//Seperate speeds for explore and solve (not currently implemented)
	int exploreSpeed = 240;
	int solveSpeed = 240;

	int leftBaseSpeed = exploreSpeed;
	int rightBaseSpeed = exploreSpeed;

	//Setpoint for left and right sensors detecting side walls
	const int rightWallDist = 2000;
	const int leftWallDist = 1900;

	// PID Constants
#define straightKp 3
#define turnKp 16
#define Kd 10

	/* Variables for interface between drive code and algorithm */
	volatile char movesBuffer[256];
	char bluetoothBuffer[5];
	volatile bool walls_global[3] = { false, false, false }; // Left, Front, Right
	volatile bool movesReady = false; // Set to true by algorithm, set to false by drive.
	volatile bool movesDoneAndWallsSet = false; // Set to true by drive, set to false by algorithm.
												/* End of variables for interface */

												//Max speed for acceleration
	const int maxSpeed = 500;

	bool currentMoveDone = false;
	bool firstMove = true;
	bool accelerate = true;
	bool solving = 1;
	int goalSpeed = 0;

	//RX and TX pins for software serial
	const int rxPin = 0;
	const int txPin = 16;


	volatile bool firstCell = true;
	volatile bool afterTurnAround = false;

	//Walls currently on left or right
	volatile bool rightValid = true;
	volatile bool leftValid = true;

	volatile bool haveSensorReading = false;

	//SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);

	//Current angle of the robot
	volatile float angle = 0.0;

	//Different move types
	volatile enum {
		NO = 0,
		FORWARD = 1,
		TURN_LEFT = 2,
		TURN_RIGHT = 3,
		TURN_AROUND = 4
	} moveType;

	int rightTicks = 0;
	int leftTicks = 0;
//	int rightBaseSpeed = 240;
//	int leftBaseSpeed = 240;
	volatile int leftSensor;
	volatile int rightSensor;
	volatile int rightMiddleValue;
	volatile int leftMiddleValue;
	volatile int leftFront;
	volatile int rightFront;
	int currentRightPWM = 0;
	int currentLeftPWM = 0;
	const int buttonPin = 24;
	const int LED = 11;
    bool wallRight();
    bool wallFront();
    bool wallLeft();
    void turnRight();
    void turnLeft();
	void moveForward();
	void forwardCorrection();
	void turnCorrection();
	void pivotTurnRight();
	void pivotTurnLeft();
	long long millis();
	void pivotTurnRight90();
	void wallFollow();
	void setSpeed(double left, double right);
	void turnAround();
	void readSensors();
    void correctErrors();
	float readGyro();
	void delay(int ms);
	void correction();
	float getAngle(float speedLeft, float speedRight);
    sim::MouseInterface* m_mouse;
};

} // namespace continuous
