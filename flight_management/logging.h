///
/// @file logging.h
/// @copyright Copyright (c) 2018 The TensorFlow Authors. All Rights Reserved.
///
///            Licensed under the Apache License, Version 2.0 (the "License");
///            you may not use this file except in compliance with the License.
///            You may obtain a copy of the License at
///
///                    http://www.apache.org/licenses/LICENSE-2.0
///
///            Unless required by applicable law or agreed to in writing, software
///            distributed under the License is distributed on an "AS IS" BASIS,
///            WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
///            See the License for the specific language governing permissions and
///            limitations under the License.
///
#ifndef FLIGHT_MANAGEMENT_LOGGING_H_
#define FLIGHT_MANAGEMENT_LOGGING_H_

#include <cstdint>
#include <iostream>
#include <sstream>

namespace fms
{
namespace logging
{
/// @brief Logging Wrapper to stdout and stderr
class LoggingWrapper
{
  public:
    /// @brief Log Severity Levels
    enum class LogSeverity : std::int32_t
    {
        INFO = 0,
        WARN = 1,
        ERROR = 2,
        FATAL = 3,
        DEBUG = 4,
    };

    /// @brief Constructor
    /// @param severity[in] - Logging Severity
    explicit LoggingWrapper(const LogSeverity& severity);

    /// @brief Constructor
    /// @param severity[in] - Logging Severity
    /// @param should_log[in] - Enable/Disable Logging
    explicit LoggingWrapper(const LogSeverity& severity, const bool should_log);

    /// @brief Destructor
    ~LoggingWrapper();

    /// @brief Provides Stream containing logged contents
    ///
    /// @return stream - string stream for logged contents
    std::stringstream& Stream();

  private:
    /// @brief Logged String Stream
    std::stringstream stream_;

    /// @brief Severity Level for Logging
    LogSeverity severity_;

    /// @brief Enable/Disable Logging
    bool should_log_;
};
}  // namespace logging
}  // namespace fms

/// @brief Log Stream with provided severity level
/// @param severity[in] - Severity Level (INFO, WARN, ERROR, FATAL)
#define LOG(severity) fms::logging::LoggingWrapper(fms::logging::LoggingWrapper::LogSeverity::severity).Stream()

/// @brief Checks for Assertion. If condition is false, Log FATAL Error and exit program.
/// @param condition[in] - condition to be evaluated
#define ASSERT_CHECK(condition) \
    fms::logging::LoggingWrapper(fms::logging::LoggingWrapper::LogSeverity::FATAL, (condition) ? false : true).Stream()

/// @brief Checks for Assertion for Comparision. If a and b are not same, Log FATAL Error and exit program.
/// @param a[in] - attribute a
/// @param b[in] - attribute b
#define ASSERT_CHECK_EQ(a, b) ASSERT_CHECK(a == b)

#endif  /// FLIGHT_MANAGEMENT_LOGGING_H_
