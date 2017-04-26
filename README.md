# Unit Tests

Verify that code, when executed, does what you expect.

## Should

**Optimize for the Reader** Even more so than for production code.

**Run fast** Developer use is inversly proportional to time spent waiting for
feedback

**Be self-verifying** Don't use printed output to verify test, code the
pass/fail into the test itself.

**Observably correct** Keep each test small, test a single behavior at a time.

**Orthagonal with eachother** Coupled tests will break the test run
sporadically, and lead to turning failing tests off.

**One (or a few related) assert(s) per test** Keep tests simple and clean to
read.

## Will

**Promote Reusable Components** Code design will shift to the interfaces of
components, not the details.

**Help Prevent Regressions** Acts as a safety net to prevent new bugs being
introduced when you come back to a unit six months later and have forgotten the
assumptions you were using.

**Catch Common errors** Fenceposting (off-by-one), bad/wrong assumptions, etc.

## Does Not

**Catch all bugs** Bugs will be found in the integration between units, less
likely within a unit with unit testing.

**Replace Integration/System level Testing** Complements the system test groups
effort, and gives better confidence in the code before passing a binary to
another team, but doesn't replace the verification effort done at higher levels.

