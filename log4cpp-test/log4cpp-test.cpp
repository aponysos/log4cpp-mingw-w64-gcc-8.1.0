// log4cpp-test.cpp : Defines the entry point for the console application.
//

#include "log4cpp/log4cpp.h"

#define PATTERN_STRING "%d [%5p]{%5t} %m%n"
#define LOG_FILE "log4cpp-test.log"
#define LOG_PRIORITY (log4cpp::Priority::DEBUG)

void init_log()
{
  log4cpp::Appender *appender = new log4cpp::FileAppender(
      "file", LOG_FILE);
  log4cpp::PatternLayout *layout = new log4cpp::PatternLayout();
  layout->setConversionPattern(PATTERN_STRING);
  appender->setLayout(layout);

  log4cpp::Appender *appender1 = new log4cpp::OstreamAppender(
      "console", &std::cout);
  appender1->setLayout(new log4cpp::BasicLayout());

  log4cpp::Category &root = log4cpp::Category::getRoot();
  root.setPriority(LOG_PRIORITY);
  root.addAppender(appender);
  root.addAppender(appender1);

  INFO_LOG() << "log file: " << LOG_FILE << ", priority: " << LOG_PRIORITY;
}

void test(int i1, int i2)
{
  TRACE_FUNC2(i1, i2);
}

int main()
{
  init_log();

  INFO_LOG() << "program begin";
  test(2, 3);
  INFO_LOG() << "program end";

  return 0;
}
