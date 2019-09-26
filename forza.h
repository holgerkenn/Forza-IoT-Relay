#define s32 int
#define u32 unsigned int
#define f32 float
#define u16 unsigned short
#define s8 char
#define u8 unsigned char

typedef struct _telemetry
{
s32 IsRaceOn; // = 1 when race is on. = 0 when in menus/race stopped …
u32 TimestampMS; //Can overflow to 0 eventually
f32 EngineMaxRpm;
f32 EngineIdleRpm;
f32 CurrentEngineRpm;
f32 AccelerationX; //In the car's local space; X = right, Y = up, Z = forward
f32 AccelerationY;
f32 AccelerationZ;
f32 VelocityX; //In the car's local space; X = right, Y = up, Z = forward
f32 VelocityY;
f32 VelocityZ;
f32 AngularVelocityX; //In the car's local space; X = pitch, Y = yaw, Z = roll
f32 AngularVelocityY;
f32 AngularVelocityZ;
f32 Yaw;
f32 Pitch;
f32 Roll;
f32 NormalizedSuspensionTravelFrontLeft; // Suspension travel normalized: 0.0f = max stretch; 1.0 = max compression
f32 NormalizedSuspensionTravelFrontRight;
f32 NormalizedSuspensionTravelRearLeft;
f32 NormalizedSuspensionTravelRearRight;
f32 TireSlipRatioFrontLeft; // Tire normalized slip ratio, = 0 means 100% grip and |ratio| > 1.0 means loss of grip.
f32 TireSlipRatioFrontRight;
f32 TireSlipRatioRearLeft;
f32 TireSlipRatioRearRight;
f32 WheelRotationSpeedFrontLeft; // Wheel rotation speed radians/sec. 
f32 WheelRotationSpeedFrontRight;
f32 WheelRotationSpeedRearLeft;
f32 WheelRotationSpeedRearRight;
s32 WheelOnRumbleStripFrontLeft; // = 1 when wheel is on rumble strip, = 0 when off.
s32 WheelOnRumbleStripFrontRight;
s32 WheelOnRumbleStripRearLeft;
s32 WheelOnRumbleStripRearRight;
f32 WheelInPuddleDepthFrontLeft; // = from 0 to 1, where 1 is the deepest puddle
f32 WheelInPuddleDepthFrontRight;
f32 WheelInPuddleDepthRearLeft;
f32 WheelInPuddleDepthRearRight;
f32 SurfaceRumbleFrontLeft; // Non-dimensional surface rumble values passed to controller force feedback
f32 SurfaceRumbleFrontRight;
f32 SurfaceRumbleRearLeft;
f32 SurfaceRumbleRearRight;
f32 TireSlipAngleFrontLeft; // Tire normalized slip angle, = 0 means 100% grip and |angle| > 1.0 means loss of grip.
f32 TireSlipAngleFrontRight;
f32 TireSlipAngleRearLeft;
f32 TireSlipAngleRearRight;
f32 TireCombinedSlipFrontLeft; // Tire normalized combined slip, = 0 means 100% grip and |slip| > 1.0 means loss of grip.
f32 TireCombinedSlipFrontRight;
f32 TireCombinedSlipRearLeft;
f32 TireCombinedSlipRearRight;
f32 SuspensionTravelMetersFrontLeft; // Actual suspension travel in meters
f32 SuspensionTravelMetersFrontRight;
f32 SuspensionTravelMetersRearLeft;
f32 SuspensionTravelMetersRearRight;
// end of V1 aka sled data
u8 fh4_232;
u8 fh4_233;
u8 fh4_234;
u8 fh4_235;
u8 fh4_236;
u8 fh4_237;
u8 fh4_238;
u8 fh4_239;
u8 fh4_240;
u8 fh4_241;
u8 fh4_242;
u8 fh4_243;
// end of new FH4 data
s32 CarOrdinal; //Unique ID of the car make/model
s32 CarClass; //Between 0 (D -- worst cars) and 7 (X class -- best cars) inclusive 
s32 CarPerformanceIndex; //Between 100 (slowest car) and 999 (fastest car) inclusive
s32 DrivetrainType; //Corresponds to EDrivetrainType; 0 = FWD, 1 = RWD, 2 = AWD
s32 NumCylinders; //Number of cylinders in the engine
//Position (meters)
f32 PositionX;
f32 PositionY;
f32 PositionZ;
f32 Speed; // meters per second
f32 Power; // watts
f32 Torque; // newton meter
f32 TireTempFrontLeft;
f32 TireTempFrontRight;
f32 TireTempRearLeft;
f32 TireTempRearRight;
f32 Boost;
f32 Fuel;
f32 DistanceTraveled;
f32 BestLap;
f32 LastLap;
f32 CurrentLap;
f32 CurrentRaceTime;
u16 LapNumber;
u8 RacePosition;
u8 Accel;
u8 Brake;
u8 Clutch;
u8 HandBrake;
u8 Gear;
s8 Steer;
s8 NormalizedDrivingLine;
s8 NormalizedAIBrakeDifference;
u8 fh4_323;
} telemetry;


