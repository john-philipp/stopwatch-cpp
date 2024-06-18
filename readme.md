Just a simple cpp stopwatch. Not trying to be anything else. Has a lap-timer. Logs to cout by default. But you can set your own logger taking `const std::string& str`.

```
#include "stopwatch.cpp" // Simple does it.

...

auto sw = Stopwatch();

// And maybe ...
sw.setLogFunction([this](const std::string &str) {
  // Just a ros2 logging example.
  RCLCPP_INFO(get_logger(), str.c_str());
});

// Or simply ...
auto sw = Stopwatch([this](const std::string &str) {
  // Just a ros2 logging example.
  RCLCPP_INFO(get_logger(), str.c_str());
});

... doing some things ...

sw.elapsedLap("Some description"); 
```

Notably, `elapsedLap("description")` logs with `name="description"` for log grepability. The next lap will be counted from instantiation or latest call to either `elapsedLap()` or `reset()`.

You can also get the total time via `elapsedTotal()`. Totals don't count from latest invocation. Instead manually reset using `reset()`.