const data = require('./data');
const { observationsByQualityGrade, observationsByQualityGrades } = require('./observations');

describe('Problem 02 - observationsByQualityGrade()', function () {
  test('should throw if qualityGrade is not one of the expected values', function () {
    // undefined
    expect(() => observationsByQualityGrade(data)).toThrow();
    // number
    expect(() => observationsByQualityGrade(data, 3)).toThrow();
    // boolean
    expect(() => observationsByQualityGrade(data, true)).toThrow();
    // unknown string
    expect(() => observationsByQualityGrade(data, 'unknown')).toThrow();
    // spelling mistake string
    expect(() => observationsByQualityGrade(data, 'researh')).toThrow();
  });

  test('should include the expected objects for a qualityGrade = research', function () {
    const research = observationsByQualityGrade(data, 'research');

    expect(research.length).toBe(2);
    research.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe('research');
    });
  });

  test('should include the expected objects for a qualityGrade = RESEARCH', function () {
    const research = observationsByQualityGrade(data, 'RESEARCH');

    expect(research.length).toBe(2);
    research.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe('research');
    });
  });

  test('should include the expected objects for a qualityGrade = casUal', function () {
    const research = observationsByQualityGrade(data, 'casUal');

    expect(research.length).toBe(4);
    research.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe('casual');
    });
  });

  test('should include the expected objects for a qualityGrade = needs_id', function () {
    const research = observationsByQualityGrade(data, 'needs_id');

    expect(research.length).toBe(2);
    research.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe('needs_id');
    });
  });

  test('should include the expected objects for a qualityGrade = null', function () {
    const research = observationsByQualityGrade(data, null);

    expect(research.length).toBe(2);
    research.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe(null);
    });
  });

  test('should return expected Array if data contains strings and null', function () {
    const mixedResults = {
      results: [
        { quality_grade: 'research' },
        { quality_grade: null },
        { quality_grade: 'casual' },
        { quality_grade: 'research' },
        { quality_grade: 'needs_id' }
      ]
    };
    const research = observationsByQualityGrade(mixedResults, 'research');
    expect(research.length).toBe(2);
    research.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe('research');
    });
  });
});

describe('Problem 02 Part 2 - observationsByQualityGrades()', function () {
  test('should return an array of observations for multiple qualityGrade values', function () {
    const qualityGrades = ['research', 'casual', 'needs_id', null];
    const observations = observationsByQualityGrades(data, ...qualityGrades);

    expect(Array.isArray(observations)).toBe(true);
    expect(observations.length).toBe(10);
    observations.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(qualityGrades.includes(observation.quality_grade)).toBe(true);
    });
  });

  test('should throw if an invalid qualityGrade value is included', function () {
    const qualityGrades = ['research', 'casual', 'unknown'];
    expect(() => observationsByQualityGrades(data, ...qualityGrades)).toThrow();
  });

  test('should return an array of observations for a single qualityGrade value', function () {
    const observations = observationsByQualityGrades(data, 'research');

    expect(Array.isArray(observations)).toBe(true);
    expect(observations.length).toBe(2);
    observations.forEach((observation) => {
      expect(typeof observation).toBe('object');
      expect(observation.quality_grade).toBe('research');
    });
  });
});
