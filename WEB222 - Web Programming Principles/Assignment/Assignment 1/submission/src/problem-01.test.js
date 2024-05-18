const { toCamelCase } = require('./solutions');

describe('Problem 1 - toCamelCase() function', function () {
  test('returns name unmodified if it needs no changes', function () {
    let result = toCamelCase('variable');
    expect(result).toBe('variable');
  });

  test('returns simple name in UpperCamelCase if requested', function () {
    let result = toCamelCase('variable', true);
    expect(result).toBe('Variable');
  });

  test('correctly converts variable-name to variableName', function () {
    let result = toCamelCase('variable-name');
    expect(result).toBe('variableName');
  });

  test('correctly converts variable-name to VariableName', function () {
    let result = toCamelCase('variable-name', true);
    expect(result).toBe('VariableName');
  });

  test('correctly deals with long kebab-case names', function () {
    let result = toCamelCase('variable-name-with-many-dashes');
    expect(result).toBe('variableNameWithManyDashes');
  });

  test('correctly deals with multiple - in a row', function () {
    let result = toCamelCase('variable---name-with-multiple-------------dashes');
    expect(result).toBe('variableNameWithMultipleDashes');
  });
});
