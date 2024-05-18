const { normalizeTime } = require('./solutions');

/**
 * 1. "01:30:00 PM"
 * 2. "13:30:00"
 *
 * In the first case, the values are followed by `AM` or `PM`. In the second, the values
 * are in 24-hour format.
 *
 * Valid Hour values are positive integers between 1 and 12 for AM/PM format and 0 and 23 for 24-hour format.
 *
 * Valid Minute and Second values are positive integers between 0 and 59.
 *
 * Parse the value and return a new string in the following form:
 *
 * "(hours, minutes, seconds)"
 */

describe('Problem 5 - normalizeTime() function', function () {
  test('a valid time in the form h:m:s AM/PM is returned as expected', function () {
    let time = '01:30:00 PM';
    expect(normalizeTime(time)).toBe('(13, 30, 0)');
  });

  test('a valid time in the form H:M:S is returned as expected', function () {
    let time = '13:30:00';
    expect(normalizeTime(time)).toBe('(13, 30, 0)');
  });

  test('an invalid time in the form h:m:s AM/PM is returned as null', function () {
    let time = '13:30:00 PM';
    expect(normalizeTime(time)).toBe(null);
  });

  test('an invalid time in the form H:M:S is returned as null', function () {
    let time = '24:30:00';
    expect(normalizeTime(time)).toBe(null);
  });

  test('a time with invalid minute value is returned as null', function () {
    let time = '01:60:00 PM';
    expect(normalizeTime(time)).toBe(null);
    time = '13:60:00';
    expect(normalizeTime(time)).toBe(null);
  });

  test('a time with invalid second value is returned as null', function () {
    let time = '01:30:60 PM';
    expect(normalizeTime(time)).toBe(null);
    time = '13:30:60';
    expect(normalizeTime(time)).toBe(null);
  });
});
