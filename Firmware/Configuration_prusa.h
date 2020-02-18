#ifndef CONFIGURATION_PRUSA_H
#define CONFIGURATION_PRUSA_H

#include <limits.h>
#include "printers.h"
/*------------------------------------
 GENERAL SETTINGS
 *------------------------------------*/

// Printer revision
#define PRINTER_TYPE PRINTER_MK3S
#define PRINTER_NAME PRINTER_MK3S_NAME
#define PRINTER_MMU_TYPE PRINTER_MK3S_MMU2
#define PRINTER_MMU_NAME PRINTER_MK3S_MMU2_NAME
#define FILAMENT_SIZE "1_75mm_MK3"
#define NOZZLE_TYPE "E3Dv6full"

// Developer flag
#define DEVELOPER

// Printer name
#define CUSTOM_MENDEL_NAME "veloc1ty - MK3S"

// Electronics
#define MOTHERBOARD BOARD_EINSY_1_0a
#define STEEL_SHEET
#define HAS_SECOND_SERIAL_PORT

// PSU
#define PSU_Delta                                 // uncomment if DeltaElectronics PSU installed

// Uncomment the below for the E3D PT100 temperature sensor (with or without PT100 Amplifier)
//#define E3D_PT100_EXTRUDER_WITH_AMP
//#define E3D_PT100_EXTRUDER_NO_AMP
//#define E3D_PT100_BED_WITH_AMP
//#define E3D_PT100_BED_NO_AMP

// Extruder
#define BONDTECH_MK3S
//#define BONDTECH_MOSQUITO
//#define BONDTECH_MOSQUITO_MAGNUM

/*------------------------------------
 AXIS SETTINGS
 *------------------------------------*/

// Steps per unit {X,Y,Z,E}
//#define DEFAULT_AXIS_STEPS_PER_UNIT   {100,100,3200/8,140}
#define DEFAULT_AXIS_STEPS_PER_UNIT   {100,100,3200/8,415}
//#define DEFAULT_AXIS_STEPS_PER_UNIT   {100,100,3200/8,560}

// Endstop inverting
#define X_MIN_ENDSTOP_INVERTING 0 // set to 1 to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING 0 // set to 1 to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING 0 // set to 1 to invert the logic of the endstop.

// Direction inverting
#define INVERT_X_DIR 1    // for Mendel set to 0, for Orca set to 1
#define INVERT_Y_DIR 0    // for Mendel set to 1, for Orca set to 0
#define INVERT_Z_DIR 1     // for Mendel set to 0, for Orca set to 1
#define INVERT_E0_DIR 0   // for direct drive extruder v9 set to 1, for geared extruder set to 0
#define INVERT_E1_DIR 0    // for direct drive extruder v9 set to 1, for geared extruder set to 0
#define INVERT_E2_DIR 0   // for direct drive extruder v9 set to 1, for geared extruder set to 0

// Home position
#define MANUAL_X_HOME_POS 0
#define MANUAL_Y_HOME_POS -2.2
#define MANUAL_Z_HOME_POS 0.2

// Travel limits after homing
#define X_MAX_POS 255
#define X_MIN_POS 0
#define Y_MAX_POS 212.5
#define Y_MIN_POS -4 //orig -4
#define Z_MAX_POS 205
#define Z_MIN_POS 0.15

// Canceled home position
#define X_CANCEL_POS 50
#define Y_CANCEL_POS 190

//Pause print position
#define X_PAUSE_POS 50
#define Y_PAUSE_POS 190
#define Z_PAUSE_LIFT 20

#define NUM_AXIS 4 // The axis order in all axis related arrays is X, Y, Z, E
#define HOMING_FEEDRATE {3000, 3000, 800, 0}  // set the homing speeds (mm/min) // 3000 is also valid for stallGuard homing. Valid range: 2200 - 3000

//#define DEFAULT_Y_OFFSET    4.f // Default distance of Y_MIN_POS point from endstop, when the printer is not calibrated.
/**
 * [0,0] steel sheet print area point X coordinate in bed print area coordinates
 */
#define SHEET_PRINT_ZERO_REF_X 0.f
/**
 * [0,0] steel sheet print area point Y coordinate in bed print area coordinates
 */
#define SHEET_PRINT_ZERO_REF_Y -2.f

#define DEFAULT_MAX_FEEDRATE                {200, 200, 12, 120}      // (mm/sec)   max feedrate (M203)
#define DEFAULT_MAX_FEEDRATE_SILENT         {100, 100, 12, 120}      // (mm/sec)   max feedrate (M203), silent mode

#define DEFAULT_MAX_ACCELERATION            {1000, 1000, 200, 5000}  // (mm/sec^2) max acceleration (M201)
#define DEFAULT_MAX_ACCELERATION_SILENT     {960, 960, 200, 5000}    // (mm/sec^2) max acceleration (M201), silent mode


#define DEFAULT_ACCELERATION          1250   // X, Y, Z and E max acceleration in mm/s^2 for printing moves (M204S)
#define DEFAULT_RETRACT_ACCELERATION  1250   // X, Y, Z and E max acceleration in mm/s^2 for retracts (M204T)

#define MANUAL_FEEDRATE {2700, 2700, 1000, 100}   // set the speeds for manual moves (mm/min)

//Silent mode limits
#define SILENT_MAX_ACCEL_XY      960ul  // max acceleration in silent mode in mm/s^2
#define SILENT_MAX_FEEDRATE_XY   100  // max feedrate in mm/s

//Normal mode limits
#define NORMAL_MAX_ACCEL_XY     2500ul  // max acceleration in normal mode in mm/s^2
#define NORMAL_MAX_FEEDRATE_XY   200  // max feedrate in mm/s

//number of bytes from end of the file to start check
#define END_FILE_SECTION 20000

#define Z_AXIS_ALWAYS_ON 1

//Crash detection
#define CRASHDET_TIMER 45 //seconds
#define CRASHDET_COUNTER_MAX 3

// New XYZ calibration
#define NEW_XYZCAL

// Watchdog support
#define WATCHDOG

// Power panic
#define UVLO_SUPPORT

// Fan check
#define FANCHECK

// Safety timer
#define SAFETYTIMER
#define DEFAULT_SAFETYTIMER_TIME_MINS 30
#define FARM_DEFAULT_SAFETYTIMER_TIME_ms (45*60*1000ul)

// Filament sensor
#define FILAMENT_SENSOR
#define IR_SENSOR

// Backlash -
//#define BACKLASH_X
//#define BACKLASH_Y


// Minimum ambient temperature limit to start triggering MINTEMP errors [C]
// this value is litlebit higher that real limit, because ambient termistor is on the board and is temperated from it,
// temperature inside the case is around 31C for ambient temperature 25C, when the printer is powered on long time and idle
// the real limit is 15C (same as MINTEMP limit), this is because 15C is end of scale for both used thermistors (bed, heater)
#define MINTEMP_MINAMBIENT      25
#define MINTEMP_MINAMBIENT_RAW  978

#define DEBUG_DCODE3

//#define DEBUG_BUILD
//#define DEBUG_SEC_LANG   //secondary language debug output at startup
//#define DEBUG_W25X20CL   //debug external spi flash
#ifdef DEBUG_BUILD
//#define _NO_ASM
#define DEBUG_DCODES //D codes
#define DEBUG_STACK_MONITOR        //Stack monitor in stepper ISR
//#define DEBUG_FSENSOR_LOG          //Reports fsensor status to serial
//#define DEBUG_CRASHDET_COUNTERS  //Display crash-detection counters on LCD
//#define DEBUG_RESUME_PRINT       //Resume/save print debug enable
//#define DEBUG_UVLO_AUTOMATIC_RECOVER // Power panic automatic recovery debug output
//#define DEBUG_DISABLE_XMINLIMIT  //x min limit ignored
//#define DEBUG_DISABLE_XMAXLIMIT  //x max limit ignored
//#define DEBUG_DISABLE_YMINLIMIT  //y min limit ignored
//#define DEBUG_DISABLE_YMAXLIMIT  //y max limit ignored
//#define DEBUG_DISABLE_ZMINLIMIT  //z min limit ignored
//#define DEBUG_DISABLE_ZMAXLIMIT  //z max limit ignored
#define DEBUG_DISABLE_STARTMSGS //no startup messages
//#define DEBUG_DISABLE_MINTEMP   //mintemp error ignored
//#define DEBUG_DISABLE_SWLIMITS  //sw limits ignored
//#define DEBUG_DISABLE_LCD_STATUS_LINE  //empty four lcd line
//#define DEBUG_DISABLE_PREVENT_EXTRUDER //cold extrusion and long extrusion allowed
//#define DEBUG_DISABLE_PRUSA_STATISTICS //disable prusa_statistics() mesages
//#define DEBUG_DISABLE_FORCE_SELFTEST //disable force selftest
//#define DEBUG_XSTEP_DUP_PIN 21   //duplicate x-step output to pin 21 (SCL on P3)
//#define DEBUG_YSTEP_DUP_PIN 21   //duplicate y-step output to pin 21 (SCL on P3)
//#define DEBUG_DISABLE_FANCHECK     //disable fan check (no ISR INT7, check disabled)
//#define DEBUG_DISABLE_FSENSORCHECK //disable fsensor check (no ISR INT7, check disabled)
#define DEBUG_DUMP_TO_2ND_SERIAL   //dump received characters to 2nd serial line
#define DEBUG_STEPPER_TIMER_MISSED // Stop on stepper timer overflow, beep and display a message.
#define PLANNER_DIAGNOSTICS // Show the planner queue status on printer display.
#define CMD_DIAGNOSTICS //Show cmd queue length on printer display
#endif /* DEBUG_BUILD */

//#define FSENSOR_QUALITY


#define LINEARITY_CORRECTION
#define TMC2130_LINEARITY_CORRECTION
#define TMC2130_LINEARITY_CORRECTION_XYZ
#define TMC2130_VARIABLE_RESOLUTION



/*------------------------------------
 TMC2130 default settings
 *------------------------------------*/

#define TMC2130_FCLK 12000000       // fclk = 12MHz

#define TMC2130_USTEPS_XY   16        // microstep resolution for XY axes
#define TMC2130_USTEPS_Z    16        // microstep resolution for Z axis
#define TMC2130_USTEPS_E    16        // microstep resolution for E axis
#define TMC2130_INTPOL_XY   1         // extrapolate 256 for XY axes
#define TMC2130_INTPOL_Z    1         // extrapolate 256 for Z axis
#define TMC2130_INTPOL_E    1         // extrapolate 256 for E axis

#define TMC2130_PWM_GRAD_X  2         // PWMCONF
#define TMC2130_PWM_AMPL_X  230       // PWMCONF
#define TMC2130_PWM_AUTO_X  1         // PWMCONF
#define TMC2130_PWM_FREQ_X  2         // PWMCONF

#define TMC2130_PWM_GRAD_Y  2         // PWMCONF
#define TMC2130_PWM_AMPL_Y  235       // PWMCONF
#define TMC2130_PWM_AUTO_Y  1         // PWMCONF
#define TMC2130_PWM_FREQ_Y  2         // PWMCONF

#define TMC2130_PWM_GRAD_Z  4         // PWMCONF
#define TMC2130_PWM_AMPL_Z  200       // PWMCONF
#define TMC2130_PWM_AUTO_Z  1         // PWMCONF
#define TMC2130_PWM_FREQ_Z  2         // PWMCONF

#define TMC2130_PWM_GRAD_E  4         // PWMCONF
#define TMC2130_PWM_AMPL_E  240       // PWMCONF
#define TMC2130_PWM_AUTO_E  1         // PWMCONF
#define TMC2130_PWM_FREQ_E  2         // PWMCONF

#define TMC2130_TOFF_XYZ    3         // CHOPCONF // fchop = 27.778kHz
#define TMC2130_TOFF_E      3         // CHOPCONF // fchop = 27.778kHz
//#define TMC2130_TOFF_E      4         // CHOPCONF // fchop = 21.429kHz
//#define TMC2130_TOFF_E      5         // CHOPCONF // fchop = 17.442kHz

//#define TMC2130_STEALTH_E // Extruder stealthChop mode
//#define TMC2130_CNSTOFF_E // Extruder constant-off-time mode (similar to MK2)

//#define TMC2130_PWM_DIV   683         // PWM frequency divider (1024, 683, 512, 410)
#define TMC2130_PWM_DIV   512         // PWM frequency divider (1024, 683, 512, 410)
#define TMC2130_PWM_CLK   (2 * TMC2130_FCLK / TMC2130_PWM_DIV) // PWM frequency (23.4kHz, 35.1kHz, 46.9kHz, 58.5kHz for 12MHz fclk)

#define TMC2130_TPWMTHRS  0         // TPWMTHRS - Sets the switching speed threshold based on TSTEP from stealthChop to spreadCycle mode
#define TMC2130_THIGH     0         // THIGH - unused

//#define TMC2130_TCOOLTHRS_X 450       // TCOOLTHRS - coolstep treshold
//#define TMC2130_TCOOLTHRS_Y 450       // TCOOLTHRS - coolstep treshold
#define TMC2130_TCOOLTHRS_X 430       // TCOOLTHRS - coolstep treshold
#define TMC2130_TCOOLTHRS_Y 430       // TCOOLTHRS - coolstep treshold
#define TMC2130_TCOOLTHRS_Z 500       // TCOOLTHRS - coolstep treshold
#define TMC2130_TCOOLTHRS_E 500       // TCOOLTHRS - coolstep treshold

#define TMC2130_SG_HOMING       1     // stallguard homing
#define TMC2130_SG_THRS_X       3     // stallguard sensitivity for X axis
#define TMC2130_SG_THRS_Y       3     // stallguard sensitivity for Y axis
#define TMC2130_SG_THRS_Z       4     // stallguard sensitivity for Z axis
#define TMC2130_SG_THRS_E       3     // stallguard sensitivity for E axis

//new settings is possible for vsense = 1, running current value > 31 set vsense to zero and shift both currents by 1 bit right (Z axis only)
#define TMC2130_CURRENTS_H {16, 20, 35, 30}  // default holding currents for all axes
#define TMC2130_CURRENTS_R {16, 20, 35, 30}  // default running currents for all axes
#define TMC2130_UNLOAD_CURRENT_R 12			 // lowe current for M600 to protect filament sensor

#define TMC2130_STEALTH_Z

//#define TMC2130_SERVICE_CODES_M910_M918

//#define TMC2130_DEBUG
//#define TMC2130_DEBUG_WR
//#define TMC2130_DEBUG_RD


/*------------------------------------
 EXTRUDER SETTINGS
 *------------------------------------*/

// Mintemps
#define HEATER_0_MINTEMP 15
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define HEATER_MINTEMP_DELAY 15000                // [ms] ! if changed, check maximal allowed value @ ShortTimer
#if HEATER_MINTEMP_DELAY>USHRT_MAX
#error "Check maximal allowed value @ ShortTimer (see HEATER_MINTEMP_DELAY definition)"
#endif
#define BED_MINTEMP 15
#define BED_MINTEMP_DELAY 50000                   // [ms] ! if changed, check maximal allowed value @ ShortTimer
#if BED_MINTEMP_DELAY>USHRT_MAX
#error "Check maximal allowed value @ ShortTimer (see BED_MINTEMP_DELAY definition)"
#endif

// Maxtemps
#if defined(E3D_PT100_EXTRUDER_WITH_AMP) || defined(E3D_PT100_EXTRUDER_NO_AMP)
#define HEATER_0_MAXTEMP 410
#else
#define HEATER_0_MAXTEMP 305
#endif
#define HEATER_1_MAXTEMP 305
#define HEATER_2_MAXTEMP 305
#define BED_MAXTEMP 125

#if defined(E3D_PT100_EXTRUDER_WITH_AMP) || defined(E3D_PT100_EXTRUDER_NO_AMP)
// Define PID constants for extruder with PT100
#define  DEFAULT_Kp 21.70
#define  DEFAULT_Ki 1.60
#define  DEFAULT_Kd 73.76
#else
// Define PID constants for extruder
//#define  DEFAULT_Kp 40.925
//#define  DEFAULT_Ki 4.875
//#define  DEFAULT_Kd 86.085
#define  DEFAULT_Kp 16.13
#define  DEFAULT_Ki 1.1625
#define  DEFAULT_Kd 56.23
#endif

// Extrude mintemp
#define EXTRUDE_MINTEMP 175

// Extruder cooling fans
#define EXTRUDER_0_AUTO_FAN_PIN   8
#define EXTRUDER_1_AUTO_FAN_PIN   -1
#define EXTRUDER_2_AUTO_FAN_PIN   -1
#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED   255  // == full speed



/*------------------------------------
 LOAD/UNLOAD FILAMENT SETTINGS
 *------------------------------------*/

// Load filament commands
#define LOAD_FILAMENT_0 "M83"
#define LOAD_FILAMENT_1 "G1 E80 F400"
#define LOAD_FILAMENT_2 "G1 E40 F100"

// Unload filament commands
#define UNLOAD_FILAMENT_0 "M83"
#define UNLOAD_FILAMENT_1 "G1 E-95 F7000"

/*------------------------------------
 CHANGE FILAMENT SETTINGS
 *------------------------------------*/

// Filament change configuration
#define FILAMENTCHANGEENABLE
#ifdef FILAMENTCHANGEENABLE
#define FILAMENTCHANGE_XPOS 211
#define FILAMENTCHANGE_YPOS 0
#define FILAMENTCHANGE_ZADD 2
#define FILAMENTCHANGE_FIRSTRETRACT -2
#define FILAMENTCHANGE_FINALRETRACT -95

#define FILAMENTCHANGE_FIRSTFEED 80 //E distance in mm for fast filament loading sequence used used in filament change (M600)
#define FILAMENTCHANGE_FINALFEED 25 //E distance in mm for slow filament loading sequence used used in filament change (M600) and filament load (M701)
#define FILAMENTCHANGE_RECFEED 5

#define FILAMENTCHANGE_XYFEED 50
#define FILAMENTCHANGE_EFEED_FIRST 20 // feedrate in mm/s for fast filament loading sequence used in filament change (M600)
#define FILAMENTCHANGE_EFEED_FINAL 3.3f // feedrate in mm/s for slow filament loading sequence used in filament change (M600) and filament load (M701)
//#define FILAMENTCHANGE_RFEED 400
#define FILAMENTCHANGE_RFEED 7000 / 60
#define FILAMENTCHANGE_EXFEED 2
#define FILAMENTCHANGE_ZFEED 15

#endif

/*------------------------------------
 ADDITIONAL FEATURES SETTINGS
 *------------------------------------*/

// Define Prusa filament runout sensor
//#define FILAMENT_RUNOUT_SUPPORT

#ifdef FILAMENT_RUNOUT_SUPPORT
#define FILAMENT_RUNOUT_SENSOR 1
#endif

// temperature runaway
#define TEMP_RUNAWAY_BED_HYSTERESIS 5
#define TEMP_RUNAWAY_BED_TIMEOUT 360

#define TEMP_RUNAWAY_EXTRUDER_HYSTERESIS 15
#define TEMP_RUNAWAY_EXTRUDER_TIMEOUT 45

/*------------------------------------
 MOTOR CURRENT SETTINGS
 *------------------------------------*/

// Motor Current settings for Einsy/tmc = 0..63
#define MOTOR_CURRENT_PWM_RANGE 63

/*------------------------------------
 BED SETTINGS
 *------------------------------------*/

// Define Mesh Bed Leveling system to enable it
#define MESH_BED_LEVELING
#ifdef MESH_BED_LEVELING

#define MBL_Z_STEP 0.01

// Mesh definitions
#define MESH_MIN_X 24
#define MESH_MAX_X 228
#define MESH_MIN_Y 6
#define MESH_MAX_Y 210

// Mesh upsample definition
#define MESH_NUM_X_POINTS 7
#define MESH_NUM_Y_POINTS 7
// Mesh measure definition
#define MESH_MEAS_NUM_X_POINTS 3
#define MESH_MEAS_NUM_Y_POINTS 3

// Maximum bed level correction value
#define BED_ADJUSTMENT_UM_MAX 100

#define MESH_HOME_Z_CALIB 0.2
#define MESH_HOME_Z_SEARCH 5.0f           // Z lift for homing, mesh bed leveling etc.

#define X_PROBE_OFFSET_FROM_EXTRUDER 23     // Z probe to nozzle X offset: -left  +right
#define Y_PROBE_OFFSET_FROM_EXTRUDER 5     // Z probe to nozzle Y offset: -front +behind
#define Z_PROBE_OFFSET_FROM_EXTRUDER -0.4  // Z probe to nozzle Z offset: -below (always!)
#endif

// Bed Temperature Control
// Select PID or bang-bang with PIDTEMPBED. If bang-bang, BED_LIMIT_SWITCHING will enable hysteresis
//
// Uncomment this to enable PID on the bed. It uses the same frequency PWM as the extruder.
// If your PID_dT above is the d
