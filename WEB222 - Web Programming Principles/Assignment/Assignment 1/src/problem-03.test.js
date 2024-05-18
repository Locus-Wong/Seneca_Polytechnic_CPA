const { parseDateString } = require('./solutions');

describe('Problem 3 - parseDateString() function', function () {
  // Checks that a date uses the given year, month, day values
  function assertDate(d, year, month, day) {
    return d && d.getFullYear() === year && d.getMonth() === month - 1 && d.getDate() === day;
  }

  test('not passing a date string throws an Error', function () {
    // null
    expect(() => parseDateString(null)).toThrow();
    // undefined
    expect(() => parseDateString()).toThrow();
    // empty string
    expect(() => parseDateString('')).toThrow();
  });

  test('passing an invalid date string format throws an Error', function () {
    // 2-digit year
    expect(() => parseDateString('20/03/12')).toThrow();
    // 1-digit month
    expect(() => parseDateString('2020/3/12')).toThrow();
    // using spaces vs. slashes
    expect(() => parseDateString('2020 03 12')).toThrow();
    // using dashes vs slashes
    expect(() => parseDateString('2020-03-12')).toThrow();
    // string, but not a date string
    expect(() => parseDateString('invalid string')).toThrow();
  });

  test('thrown error uses a proper Error object and message', function () {
    const message = 'invalid date string, expected a `YYYY/MM/DD` or `DD/MM/YYYY` formatted string';
    const error = new Error(message);
    expect(() => parseDateString()).toThrow(error);
  });

  test('passing a valid YYYY/MM/DD date string results in correct date object', function () {
    let result = parseDateString('2023/01/15');
    expect(assertDate(result, 2023, 1, 15)).toBe(true);
  });

  test('passing a valid DD/MM/YYYY date string results in correct date object', function () {
    let result = parseDateString('15/01/2023');
    expect(assertDate(result, 2023, 1, 15)).toBe(true);
  });
});
