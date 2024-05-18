const { toDateString, parseDateString } = require('./solutions');

// Returns true if two dates have same year, month, day (ignoring time)
function compareDates(a, b) {
  return (
    a.getFullYear() === b.getFullYear() &&
    a.getMonth() === b.getMonth() &&
    a.getDate() === b.getDate()
  );
}

describe('Problem 4 - toDateString() function', function () {
  test('a date is correctly converted to a date string in the YYYY/MM/DD format', function () {
    let date = new Date('December 10, 2023');
    let result = toDateString(date, 'YYYY/MM/DD');
    expect(result).toBe('2023/12/10');
  });

  test('a date is correctly converted to a date string in the DD/MM/YYYY format', function () {
    let date = new Date('December 10, 2023');
    let result = toDateString(date, 'DD/MM/YYYY');
    expect(result).toBe('10/12/2023');
  });

  test('a date is correctly converted to a date string in the MM/DD/YYYY format', function () {
    let date = new Date('December 10, 2023');
    let result = toDateString(date, 'MM/DD/YYYY');
    expect(result).toBe('12/10/2023');
  });

  test('an error is thrown if the format is unknown', function () {
    let date = new Date('December 10, 2023');
    expect(() => toDateString(date, 'M/D/Y')).toThrow();
  });

  test('a date is correctly converted to a date string with expected month and day', function () {
    let date = new Date('December 17, 2023');
    let result = toDateString(date, 'YYYY/MM/DD');
    expect(result).toBe('2023/12/17');
  });

  test('a date is correctly converted to a date string, with padded month', function () {
    let date = new Date('January 10, 2023');
    let result = toDateString(date, 'YYYY/MM/DD');
    expect(result).toBe('2023/01/10');
  });

  test('a date is correctly converted to a date string, with padded day', function () {
    let date = new Date('December 01, 2023');
    let result = toDateString(date, 'YYYY/MM/DD');
    expect(result).toBe('2023/12/01');
  });

  test('toDateString and parseDateString are reversible', function () {
    let date = new Date('December 01, 2023');
    let dateString = '2023/01/12';

    expect(compareDates(parseDateString(toDateString(date, 'YYYY/MM/DD')), date)).toBe(true);
    expect(toDateString(parseDateString(dateString), 'YYYY/MM/DD')).toBe(dateString);
  });

  test('an invalid date causes an error to be thrown', function () {
    expect(() => toDateString('invalid date')).toThrow();
  });
});
