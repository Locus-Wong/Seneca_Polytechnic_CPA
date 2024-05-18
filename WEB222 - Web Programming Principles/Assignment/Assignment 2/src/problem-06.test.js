const data = require('./data');
const { getPlaceURLs } = require('./observations');

const places = (...ids) => ({ results: [{ place_ids: ids }] });

describe('Problem 06 - getPlaceURLs() function', function () {
  test('should return an Array', function () {
    let result = getPlaceURLs(places(1234));
    expect(Array.isArray(result)).toBe(true);
  });

  test('should include the expected URL', function () {
    let result = getPlaceURLs(places(45678));
    expect(result).toContain('https://www.inaturalist.org/observations?place_id=45678');
  });

  test('should work for multiple place_ids', function () {
    let result = getPlaceURLs(places(1, 2, 3));
    expect(result).toContain('https://www.inaturalist.org/observations?place_id=1');
    expect(result).toContain('https://www.inaturalist.org/observations?place_id=2');
    expect(result).toContain('https://www.inaturalist.org/observations?place_id=3');
  });

  test('should work for multiple results', function () {
    let results = getPlaceURLs(data);
    results.forEach(function (result) {
      expect(/https:\/\/www.inaturalist.org\/observations\?place_id=\d+/.test(result)).toBe(true);
    });
  });
});
