Just a simple cpp stopwatch. Not trying to be anything else. Has a lap-timer.

```
#include "stopwatch.cpp" // Simple does it.

...

auto sw = Stopwatch();

... doing things ...

sw.s_elapsed_lap("Some description"); 
```

Notably, `Stopwatch::s_elapsed_lap("description")` logs to `cout` with `name="description"` for log grepability. The next lap will be counted from instantiation or latest call to `s_elapsed_lap(...)`.