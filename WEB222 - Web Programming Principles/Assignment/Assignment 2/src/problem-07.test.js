const data = require('./data');
const result0 = data.results[0];
const result1 = data.results[1];
const { getSpeciesObservations } = require('./observations');

describe('Problem 07 - getSpeciesObservations() function', function () {
  let samples, sampleData;

  beforeEach(() => {
    samples = [result0, result1];
    sampleData = { results: samples };
  });

  test('should return an Object with the right properties', function () {
    let result = getSpeciesObservations(sampleData);
    expect(typeof result === 'object').toBe(true);
    expect(typeof result['Ondatra zibethicus'] === 'number').toBe(true);
    expect(result['Ondatra zibethicus']).toBe(1);
  });

  test('should return an Object with correct count properties', function () {
    let result = getSpeciesObservations(sampleData);
    expect(result).toEqual({ 'Ondatra zibethicus': 1, 'Cordia sebestena sebestena': 1 });
  });

  test('should return an Object with correct counts for multiple species', function () {
    let result = getSpeciesObservations({ results: [result0, result1, result0, result0, result1] });
    expect(result).toEqual({ 'Ondatra zibethicus': 3, 'Cordia sebestena sebestena': 2 });
  });

  test('real-data should produce the expected counts Object', function () {
    let result = getSpeciesObservations(data);
    expect(result).toEqual({
      'Ondatra zibethicus': 1,
      'Cordia sebestena sebestena': 1,
      'Bombus impatiens': 1,
      'Brugmansia arborea': 1,
      Dryobates: 1,
      'Campsis radicans': 1,
      'Solanum dulcamara': 1,
      Plectranthus: 1,
      Petunia: 1,
      Apioideae: 1
    });
  });
});
