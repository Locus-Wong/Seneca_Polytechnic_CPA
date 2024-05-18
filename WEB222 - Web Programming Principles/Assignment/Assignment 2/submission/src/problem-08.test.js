const { extractSpeciesNames, extractSpeciesNames2 } = require('./observations');
const data = require('./data');
const result0 = data.results[0];
const result1 = data.results[1];

const testCases = (fn) => {
  test('should return a single result', () => {
    expect(fn({ results: [result0] })).toEqual(['Muskrat']);
  });

  test('extractSpeciesNames should not return duplicates', () => {
    expect(fn({ results: [result0, result0] })).toEqual(['Muskrat']);
  });

  test('extractSpeciesNames should deal properly with multiple values without duplicating', () => {
    expect(fn({ results: [result0, result0, result1, result1] })).toEqual([
      'Muskrat',
      'Cordia sebestena sebestena'
    ]);
  });

  test('extractSpeciesNames should work on real data', () => {
    expect(fn(data)).toEqual([
      'Muskrat',
      'Cordia sebestena sebestena',
      'Common Eastern Bumble Bee',
      "Angel's Trumpet",
      'Dryobates Woodpeckers',
      'American trumpet vine',
      'bittersweet nightshade',
      '香茶屬',
      '矮牽牛屬',
      '芹亞科'
    ]);
  });
};

describe('extractSpeciesNames()', () => {
  testCases(extractSpeciesNames);
});

describe('extractSpeciesNames2()', () => {
  testCases(extractSpeciesNames2);
});
