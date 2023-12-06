PROGRAM AutomatedTrafficControl
VAR
    currentTime : INT;              // Current time in hours (24-hour format)
    trafficCondition : INT;         // Traffic condition (1 for low, 2 for moderate, 3 for high)
    trafficLightState : STRING;     // State of the traffic lights ("Red", "Green", "Yellow")
END_VAR

// Dummy functions for simulation
PROCEDURE GetCurrentTime() : INT; BEGIN END_PROCEDURE;
PROCEDURE GetTrafficCondition() : INT; BEGIN END_PROCEDURE;
PROCEDURE SetTrafficLightState(state : STRING); BEGIN END_PROCEDURE;

// Main logic
currentTime := GetCurrentTime();
trafficCondition := GetTrafficCondition();

// Logical Bug: Incorrect handling of traffic light states in case statement
CASE currentTime OF
    0..5: // Late night
        trafficLightState := 'Yellow';
    6..9: // Morning rush hour
        IF trafficCondition = 3 THEN
            trafficLightState := 'Green';
        ELSE
            trafficLightState := 'Red';
        END_IF
    10..15: // Day time
        trafficLightState := 'Green';
    16..19: // Evening rush hour
        // Bug: Red light during high traffic in the evening rush hour
        IF trafficCondition = 3 THEN
            trafficLightState := 'Red';
        ELSE
            trafficLightState := 'Green';
        END_IF
    20..23: // Night
        trafficLightState := 'Yellow';
END_CASE

SetTrafficLightState(trafficLightState);
END_PROGRAM
