///
/// @file logging_tests.cpp
/// @brief Contains unit tests for Logging APIs.
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/logging.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace fms
{
namespace logging
{
namespace
{
/// @test Test Assert Check Macro
TEST(LoggingWrapperSpec, AssertionMacro) { EXPECT_EXIT(ASSERT_CHECK(false), ::testing::KilledBySignal(SIGABRT), ""); }

/// @test Test Assert Compare Macro
TEST(LoggingWrapperSpec, AssertionCompareMacro)
{
    EXPECT_EXIT(ASSERT_CHECK_EQ(1, 2), ::testing::KilledBySignal(SIGABRT), "");
}

/// @test Test Fatal logging
TEST(LoggingWrapperSpec, FatalLogging)
{
    auto unit = new LoggingWrapper(LoggingWrapper::LogSeverity::FATAL, true);
    unit->Stream() << "test";
    EXPECT_EXIT(delete unit, ::testing::KilledBySignal(SIGABRT), "");
}

/// @test Test logging wrapper when no logging enabled
TEST(LoggingWrapperSpec, NoLogging)
{
    ::testing::internal::CaptureStderr();
    ::testing::internal::CaptureStdout();
    LoggingWrapper(LoggingWrapper::LogSeverity::DEBUG, false).Stream() << "test";
    LoggingWrapper(LoggingWrapper::LogSeverity::INFO, false).Stream() << "test";
    LoggingWrapper(LoggingWrapper::LogSeverity::ERROR, false).Stream() << "test";
    LoggingWrapper(LoggingWrapper::LogSeverity::WARN, false).Stream() << "test";
    EXPECT_TRUE(::testing::internal::GetCapturedStdout().empty());
    EXPECT_TRUE(::testing::internal::GetCapturedStderr().empty());
}

/// @test Test logging on stdout
TEST(LoggingWrapperSpec, OnStandardOutput)
{
    ::testing::internal::CaptureStderr();
    ::testing::internal::CaptureStdout();
    LoggingWrapper(LoggingWrapper::LogSeverity::DEBUG, false).Stream() << "test";
    LoggingWrapper(LoggingWrapper::LogSeverity::INFO, true).Stream() << "test";
    LoggingWrapper(LoggingWrapper::LogSeverity::WARN, true).Stream() << "test";
    EXPECT_FALSE(::testing::internal::GetCapturedStdout().empty());
    EXPECT_TRUE(::testing::internal::GetCapturedStderr().empty());
}

/// @test Test logging on stderr
TEST(LoggingWrapperSpec, OnStandardError)
{
    ::testing::internal::CaptureStderr();
    ::testing::internal::CaptureStdout();
    LoggingWrapper(LoggingWrapper::LogSeverity::ERROR, true).Stream() << "test";
    EXPECT_TRUE(::testing::internal::GetCapturedStdout().empty());
    EXPECT_FALSE(::testing::internal::GetCapturedStderr().empty());
}
}  // namespace
}  // namespace logging
}  // namespace fms
