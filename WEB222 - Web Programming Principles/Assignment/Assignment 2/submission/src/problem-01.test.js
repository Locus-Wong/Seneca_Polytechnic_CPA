const data = require('./data');
const { results } = data;
const { speciesCoordinates, speciesCoordinates2, speciesCoordinates3 } = require('./observations');

// "Muskrat" observed at coordinates (43.79248394,-79.33852796)
const formatRegEx = /^"[^"]+" observed at coordinates \(-?\d+(\.\d+)?,-?\d+(\.\d+)?\)$/i;

function runTestCases(fn, fnName, regex = formatRegEx) {
  const originalLog = console.log;

  afterEach(() => {
    console.log = originalLog;
  });

  test(`${fnName}() should call console.log() once per case`, function () {
    let called = 0;
    const mockedLog = () => (called += 1);
    console.log = mockedLog;

    fn(data);
    expect(called).toBe(results.length);
  });

  test(`${fnName}() should log correct format of all cases`, function () {
    let consoleOutput = [];
    const mockedLog = (output) => consoleOutput.push(output);
    console.log = mockedLog;

    fn(data);

    expect(consoleOutput.length).toBe(results.length);
    consoleOutput.forEach((output) =>
      expect(output).toEqual(
        // We expect a string like '"Muskrat" observed at coordinates (43.79248394, -79.33852796)"'
        expect.stringMatching(regex)
      )
    );
  });
}

describe('Problem 01 Part 1 - speciesCoordinates() function with for loop', function () {
  runTestCases(speciesCoordinates, 'speciesCoordinates');
});

describe('Problem 01 Part 2 - speciesCoordinates2() function with .forEach()', function () {
  runTestCases(speciesCoordinates2, 'speciesCoordinates2');
});

describe('Problem 01 Part 3 - speciesCoordinates3() function with for-of', function () {
  // "Muskrat" observed at coordinates (43.79248394, -79.33852796)
  const formatRegEx = /^"[^"]+" observed at coordinates \(-?\d+(\.\d+)?, -?\d+(\.\d+)?\)$/i;
  runTestCases(speciesCoordinates3, 'speciesCoordinates3', formatRegEx);
});
