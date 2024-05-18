const data = require('./data');
const { getObservationsByTaxa } = require('./observations');

describe('Problem 04 - getObservationsByTaxa() function', function () {
  test('if an unknown taxon name is passed, empty list is returned', function () {
    expect(getObservationsByTaxa(data, 'Unknown')).toEqual([]);
  });

  test('if a single, known taxon name is passed, the full Object should be returned', function () {
    let taxonName = 'Plantae';
    let result0 = data.results[1];

    expect(result0.taxon.iconic_taxon_name).toBe(taxonName);
    let result = getObservationsByTaxa({ results: [result0] }, taxonName);
    expect(result).toEqual([result0]);
  });

  test('if multiple known taxon names are passed, an Array of the full Objects should be returned', function () {
    let taxonName0 = 'Plantae';
    let result0 = data.results[1];
    expect(result0.taxon.iconic_taxon_name).toBe(taxonName0);

    let taxonName1 = 'Insecta';
    let result1 = data.results[2];
    expect(result1.taxon.iconic_taxon_name).toBe(taxonName1);

    let result = getObservationsByTaxa(data, taxonName0, taxonName1);
    expect(Array.isArray(result)).toBe(true);
    expect(result.length).toBe(8);
    expect(result).toContain(result0);
    expect(result).toContain(result1);
  });

  test('if some known and some unknown taxon names are passed, an Array of the known Objects should be returned', function () {
    let taxonName0 = 'Plantae';
    let result0 = data.results[1];
    expect(result0.taxon.iconic_taxon_name).toBe(taxonName0);

    let taxonName1 = 'Unknown';

    let result = getObservationsByTaxa(data, taxonName0, taxonName1);
    expect(Array.isArray(result)).toBe(true);
    expect(result.length).toBe(7);
    expect(result).toContain(result0);
  });
});
