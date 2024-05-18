const { formatTimes } = require('./solutions');

describe('Problem 6 - formatTimes()', function () {
  test('a single time is valid', function () {
    let result = formatTimes('4:26:24 PM');
    expect(result).toBe('[(16, 26, 24)]');
  });

  test('valid times of the form h:m:s should be formatted correctly in a list', function () {
    let result = formatTimes('1:16:24', '1:16:25', '1:16:26');
    expect(result).toBe('[(1, 16, 24), (1, 16, 25), (1, 16, 26)]');
  });

  test('valid times of the form h:m:s AM/PM should be formatted correctly in a list', function () {
    let result = formatTimes('4:16:24 PM', '4:16:25 AM');
    expect(result).toBe('[(16, 16, 24), (4, 16, 25)]');
  });

  test('invalid times are skipped', function () {
    let result = formatTimes('4:16:24', '60:60:60', '100:100:100', '4:16:25 AM');
    expect(result).toBe('[(4, 16, 24), (4, 16, 25)]');
  });

  test('if all values are invalid, an empty list is returned', function () {
    let result = formatTimes('60:60:60', '100:100:100');
    expect(result).toBe('[]');
  });
});
