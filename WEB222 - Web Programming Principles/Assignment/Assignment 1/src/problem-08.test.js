const { buildApiEndpoint } = require('./solutions');

describe('Problem 8 - buildApiEndpoint() function', function () {
  test('correct values produce an expected endpoint', function () {
    let endpoint = buildApiEndpoint('users', '123', 'John Doe');
    expect(endpoint).toEqual('/users/123/John%20Doe');
  });

  test('extraData values are properly encoded in endpoint', function () {
    let endpoint = buildApiEndpoint('products', '456', 'Special: Limited Edition');
    expect(endpoint).toEqual('/products/456/Special%3A%20Limited%20Edition');
  });

  test('extraData is optional', function () {
    let endpoint = buildApiEndpoint('users', '123');
    expect(endpoint).toEqual('/users/123');
  });

  test('missing or empty resourceType or resourceId throw', function () {
    expect(() => buildApiEndpoint()).toThrow();
    expect(() => buildApiEndpoint('users')).toThrow();
    expect(() => buildApiEndpoint('', '123', 'John Doe')).toThrow();
    expect(() => buildApiEndpoint('users', '', 'John Doe')).toThrow();
    expect(() => buildApiEndpoint('users', '123', '')).toThrow();
  });

  test('extraData can be left out', function () {
    let endpoint = buildApiEndpoint('users', '123');
    expect(endpoint).toEqual('/users/123');
  });

  test('resourceId can be a number', function () {
    let endpoint = buildApiEndpoint('users', 123, 'John Doe');
    expect(endpoint).toEqual('/users/123/John%20Doe');
  });

  test('resourceId can be a string containing a number', function () {
    let endpoint = buildApiEndpoint('users', '123', 'John Doe');
    expect(endpoint).toEqual('/users/123/John%20Doe');
  });
});
