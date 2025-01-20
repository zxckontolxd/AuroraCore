#pragma once

#include "utils/logger/logger.h"

/*
 * MainLogger.h - Centralized logging system for the application
 *
 * This file defines the MainLogger class, which extends the Logger class to provide
 * a singleton-based, application-wide logging system. It is responsible for:
 *  - Managing and directing log messages across all modules in the application.
 *  - Supporting multiple log levels (Info, Warning, Error, Debug) for categorizing messages.
 *  - Allowing configuration of output streams for different log levels.
 *  - Providing a global interface for consistent logging throughout the application.
 *
 * Log Levels:
 *  - Info: For general informational messages that describe the normal functioning of the application.
 *  - Warning: For messages that indicate potential issues or non-critical problems.
 *  - Error: For messages that highlight significant problems requiring attention.
 *  - Debug: For detailed diagnostic messages useful during development.
 *
 * The MainLogger class ensures that all logging operations are unified and routed
 * through a single instance, simplifying the debugging and monitoring processes.
 *
 * Key Features:
 *  - Singleton pattern ensures a single instance accessible globally.
 *  - Flexible configuration of output streams for each log level.
 *  - Support for both global and level-specific logging outputs.
 *  - Integrated with the application's components for centralized log management.
 *
 * Usage:
 *  - Access the singleton instance using `MainLogger::getInstance()`.
 *  - Configure global and level-specific streams as needed.
 *  - Use the logging methods (e.g., `info()`, `warning()`, `error()`, `debug()`)
 *    to output messages based on their importance.
 *
 * The MainLogger class is a crucial component for managing log output across the
 * entire application, promoting consistency and ease of maintenance.
 */

class MainLogger : public Logger
{
private:
    static MainLogger *instance;

    MainLogger();

    MainLogger(const MainLogger&) = delete;
    MainLogger& operator=(const MainLogger&) = delete;
public:
    static MainLogger* get();
};
