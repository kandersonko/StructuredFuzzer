PROGRAM AutomatedConveyorControl
VAR
    itemType : INT;               // Type of item on the conveyor (1 for fragile, 2 for standard, 3 for heavy)
    conveyorSpeed : REAL;         // Conveyor belt speed (in meters per second)
    emergencyStopActivated : BOOL;// Flag indicating if emergency stop is activated
END_VAR

// Dummy function for sensor reading
PROCEDURE GetItemType() : INT; BEGIN END_PROCEDURE;
PROCEDURE ActivateEmergencyStop(); BEGIN END_PROCEDURE;
PROCEDURE DeactivateEmergencyStop(); BEGIN END_PROCEDURE;
PROCEDURE SetConveyorSpeed(speed : REAL); BEGIN END_PROCEDURE;

// Main logic
itemType := GetItemType();

// Logical Bug: Incorrect conveyor speed settings for different item types
CASE itemType OF
    1: // Fragile items
        conveyorSpeed := 0.5; // Slow speed for fragile items
    2: // Standard items
        conveyorSpeed := 1.5; // Medium speed for standard items
    3: // Heavy items
        // Bug: Too fast for heavy items, might cause damage
        conveyorSpeed := 2.0; // High speed for heavy items
    ELSE
        // In case of an unrecognized item type, activate emergency stop
        ActivateEmergencyStop();
        emergencyStopActivated := TRUE;
        conveyorSpeed := 0.0;
END_CASE

SetConveyorSpeed(conveyorSpeed);

IF NOT emergencyStopActivated THEN
    DeactivateEmergencyStop();
END_IF
END_PROGRAM
