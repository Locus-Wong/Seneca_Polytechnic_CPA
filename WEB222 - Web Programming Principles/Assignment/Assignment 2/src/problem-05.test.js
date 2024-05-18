/* eslint-disable jest/expect-expect */
const data = require('./data');
const { getObservationsByLocation } = require('./observations');

describe('Problem 05 - getObservationsByLocation() function', function () {
  function expectSuitableArray(value, expectedLength) {
    expect(Array.isArray(value)).toBe(true);
    expect(value.length).toBe(expectedLength);
  }

  test('missing options object returns same Array as original', function () {
    let results = getObservationsByLocation(data);
    expect(results).toEqual(data.results);
  });

  test('empty options object returns same Array as original', function () {
    let results = getObservationsByLocation(data, {});
    expect(results).toEqual(data.results);
  });

  test('lat and lng values return an Array of expected results', function () {
    let results = getObservationsByLocation(data, { lat: 43.798774894, lng: -79.3565522733 });
    expectSuitableArray(results, 1);
    results.forEach((result) => {
      expect(result.location).toBe('43.798774894,-79.3565522733');
    });
  });

  test('lat and lng with unknown value returns an empty Array', function () {
    let results = getObservationsByLocation(data, { lat: 43.66, lng: -79.39 });
    expectSuitableArray(results, 0);
  });

  test('min and max values return an Array of expected results', function () {
    let results = getObservationsByLocation(data, {
      lat: { min: 43, max: 44 },
      lng: { min: -80, max: -78 }
    });
    expectSuitableArray(results, 10);
    results.forEach((result) => {
      const latitude = parseFloat(result.location.split(',')[0]);
      expect(latitude).toBeGreaterThanOrEqual(43);
      expect(latitude).toBeLessThanOrEqual(44);

      const longitude = parseFloat(result.location.split(',')[1]);
      expect(longitude).toBeGreaterThanOrEqual(-80);
      expect(longitude).toBeLessThanOrEqual(-78);
    });
  });

  test('min and max values too close together return an empty Array', function () {
    let results = getObservationsByLocation(data, {
      lat: { min: 43.65, max: 43.65 },
      lng: { min: -79.38, max: -79.38 }
    });
    expectSuitableArray(results, 0);
  });
});
