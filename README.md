# EE599 Homework 3 - Sam Bruner

> Can be used in Visual Studio Code


### Run main:

You can run this using `blaze`:

```bash
bazel run src/main:main
```

### Run Tests:

You can run unit tests using [`blaze`](installing-bazel):

```bash
bazel test tests:tests
```

### Concerns:
testing::internal::GetCapturedStdout() causes seg fault when called in bazel test. As a result, validation of void functions that rely on cout to determine validity must be done in main file.

### Credit

EE355 Course Notes on Linkedlists