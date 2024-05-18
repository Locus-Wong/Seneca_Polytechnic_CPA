const data = require('./data');
let result0 = data.results[0];
const {
  transformObservation,
  transformObservations,
  transformObservations2
} = require('./observations');

const isUrl = (url) => {
  try {
    new URL(url);
    return true;
  } catch (err) {
    return false;
  }
};

describe('Problem 03 - transformObservation(), transformObservations(), transformObservations2() functions', function () {
  describe('Problem 03 - transformObservation() function', function () {
    let sample;

    beforeEach(() => {
      // Clone the object for each test (so we can make changes)
      sample = Object.assign({}, result0);
    });

    test('should return an Object', function () {
      let result = transformObservation(sample);
      expect(typeof result).toBe('object');
    });

    test('should return an Object containing an id property', function () {
      let result = transformObservation(sample);
      expect(result.id).toBe(sample.id);
    });

    test('should return an Object containing a name property', function () {
      sample.name = 'Muskrat';
      let result = transformObservation(sample);
      expect(result.name).toBe('muskrat');
    });

    test('should return an Object containing an isExtinct property', function () {
      sample.conservation_status = { status_name: 'extinct in the wild' };
      expect(transformObservation(sample).isExtinct).toBe(true);

      sample.conservation_status = { status_name: 'least concern' };
      expect(transformObservation(sample).isExtinct).toBe(false);

      delete sample.conservation_status;
      expect(transformObservation(sample).isExtinct).toBe(false);
    });

    test('should return an Object containing an observer property', function () {
      sample.user = { login_exact: 'hsmith' };
      let result = transformObservation(sample);
      expect(result.observer).toBe('hsmith@inaturalist.com');
    });

    test('should return an Object containing an images Array of URLs and copyright details', function () {
      let result = transformObservation(sample);
      expect(Array.isArray(result.images)).toBe(true);
      expect(result.images.length).toBe(1);
      let image = result.images[0];
      expect(typeof image.url).toBe('string');
      expect(isUrl(image.url)).toBe(true);
      expect(typeof image.copyright).toBe('string');
    });

    test('should return an Object containing an images Array of multiple URLs and copyright details', function () {
      const photo = sample.photos[0];
      sample.photos = [photo, photo, photo];

      let result = transformObservation(sample);
      expect(Array.isArray(result.images)).toBe(true);
      expect(result.images.length).toBe(3);

      result.images.forEach((image) => {
        expect(typeof image.url).toBe('string');
        expect(isUrl(image.url)).toBe(true);
        expect(typeof image.copyright).toBe('string');
      });
    });
  });

  describe('transformObservations() function', function () {
    let sample, samples, sampleData;

    beforeEach(() => {
      sample = Object.assign({}, result0);
      samples = [sample, sample];
      sampleData = { results: samples };
    });

    test('should return an Array', function () {
      let result = transformObservations(sampleData);
      expect(Array.isArray(result)).toBe(true);
    });

    test('should return a new Array', function () {
      let result = transformObservations(sampleData);
      expect(result).not.toBe(samples);
    });

    test('should return an Array with the same number of elements', function () {
      let result = transformObservations(sampleData);
      expect(result.length).toBe(samples.length);
    });

    test('should return an Array of Objects', function () {
      let result = transformObservations(sampleData);
      result.forEach((o) => expect(typeof o).toBe('object'));
    });

    test('should return an Array with Objects containing an id property', function () {
      let result = transformObservations(sampleData);
      expect(result[0].id).toBe(sample.id);
      expect(result[1].id).toBe(sample.id);
    });

    test('should return an Object containing a name property', function () {
      let result = transformObservations(sampleData);
      expect(result[0].name).toBe('muskrat');
      expect(result[0].name).toBe('muskrat');
    });

    test('should return an Object containing an isExtinct property', function () {
      let result = transformObservations(sampleData);
      expect(result[0].isExtinct).toBe(false);
      expect(result[1].isExtinct).toBe(false);
    });

    test('should return an Object containing an observer property', function () {
      let result = transformObservations(sampleData);
      expect(result[0].observer).toBe('dridgen@inaturalist.com');
      expect(result[1].observer).toBe('dridgen@inaturalist.com');
    });

    test('should return an Object containing an images Array', function () {
      let results = transformObservations(sampleData);
      expect(Array.isArray(results[0].images)).toBe(true);
      expect(results[0].images.length).toBe(1);

      results.forEach((result) =>
        result.images.forEach((image) => {
          expect(image.url).toBe(
            'https://static.inaturalist.org/photos/109762131/square.jpg?1610308133'
          );
          expect(image.copyright).toBe('(c) dridgen, some rights reserved (CC BY-NC)');
        })
      );
    });

    test('real-world data should behave the same way as test data', function () {
      expect(transformObservations(data)).toEqual([
        {
          id: 67868131,
          name: 'muskrat',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/109762131/square.jpg?1610308133',
              copyright: '(c) dridgen, some rights reserved (CC BY-NC)'
            }
          ],
          observer: 'dridgen@inaturalist.com'
        },
        {
          id: 66528178,
          name: 'cordia sebestena sebestena',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/107267018/square.jpeg?1607882195',
              copyright: '(c) Mohammed Master, all rights reserved'
            }
          ],
          observer: 'mohammedmaster@inaturalist.com'
        },
        {
          id: 61770700,
          name: 'common eastern bumble bee',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/98884441/square.jpg?1601901356',
              copyright: '(c) johnnyrehabb, some rights reserved (CC BY-NC)'
            }
          ],
          observer: 'johnnyrehabb@inaturalist.com'
        },
        {
          id: 61472666,
          name: "angel's trumpet",
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/98374594/square.jpeg?1601643792',
              copyright: '(c) Monica Yeung, all rights reserved'
            }
          ],
          observer: 'monicayeung@inaturalist.com'
        },
        {
          id: 61307088,
          name: 'dryobates woodpeckers',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/98089550/square.jpeg?1601480884',
              copyright: '(c) Holly, some rights reserved (CC BY-NC)'
            },
            {
              url: 'https://static.inaturalist.org/photos/98089568/square.jpeg?1601480892',
              copyright: '(c) Holly, some rights reserved (CC BY-NC)'
            },
            {
              url: 'https://static.inaturalist.org/photos/98097088/square.jpeg?1601483871',
              copyright: '(c) Holly, some rights reserved (CC BY-NC)'
            }
          ],
          observer: 'h-easton@inaturalist.com'
        },
        {
          id: 60706122,
          name: 'american trumpet vine',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/97090180/square.jpeg?1601038974',
              copyright: '(c) Monica Yeung, all rights reserved'
            }
          ],
          observer: 'monicayeung@inaturalist.com'
        },
        {
          id: 60671346,
          name: 'bittersweet nightshade',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/97031452/square.jpeg?1600996784',
              copyright: '(c) Karen C, all rights reserved'
            }
          ],
          observer: 'kareberry@inaturalist.com'
        },
        {
          id: 60021049,
          name: '香茶屬',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/95944256/square.jpeg?1600471203',
              copyright: '(c) xinjie lin, all rights reserved'
            },
            {
              url: 'https://static.inaturalist.org/photos/95944271/square.jpeg?1600471210',
              copyright: '(c) xinjie lin, all rights reserved'
            }
          ],
          observer: 'xinjielin@inaturalist.com'
        },
        {
          id: 60020978,
          name: '矮牽牛屬',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/95944070/square.jpeg?1600471140',
              copyright: '(c) xinjie lin, all rights reserved'
            }
          ],
          observer: 'xinjielin@inaturalist.com'
        },
        {
          id: 60004808,
          name: '芹亞科',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/95916480/square.jpeg?1600460651',
              copyright: '(c) xinjie lin, all rights reserved'
            },
            {
              url: 'https://static.inaturalist.org/photos/95916500/square.jpeg?1600460656',
              copyright: '(c) xinjie lin, all rights reserved'
            }
          ],
          observer: 'xinjielin@inaturalist.com'
        }
      ]);
    });
  });

  describe('transformObservations2() function', function () {
    let sample, samples, sampleData;

    beforeEach(() => {
      sample = Object.assign({}, result0);
      samples = [sample, sample];
      sampleData = { results: samples };
    });

    test('should return an Array', function () {
      let result = transformObservations2(sampleData);
      expect(Array.isArray(result)).toBe(true);
    });

    test('should return a new Array', function () {
      let result = transformObservations2(sampleData);
      expect(result).not.toBe(samples);
    });

    test('should return an Array with the same number of elements', function () {
      let result = transformObservations2(sampleData);
      expect(result.length).toBe(samples.length);
    });

    test('should return an Array of Objects', function () {
      let result = transformObservations2(sampleData);
      result.forEach((o) => expect(typeof o).toBe('object'));
    });

    test('should return an Array with Objects containing an id property', function () {
      let result = transformObservations2(sampleData);
      expect(result[0].id).toBe(sample.id);
      expect(result[1].id).toBe(sample.id);
    });

    test('should return an Object containing a name property', function () {
      let result = transformObservations2(sampleData);
      expect(result[0].name).toBe('muskrat');
      expect(result[0].name).toBe('muskrat');
    });

    test('should return an Object containing an isExtinct property', function () {
      let result = transformObservations2(sampleData);
      expect(result[0].isExtinct).toBe(false);
      expect(result[1].isExtinct).toBe(false);
    });

    test('should return an Object containing an observer property', function () {
      let result = transformObservations2(sampleData);
      expect(result[0].observer).toBe('dridgen@inaturalist.com');
      expect(result[1].observer).toBe('dridgen@inaturalist.com');
    });

    test('should return an Object containing an images Array', function () {
      let results = transformObservations2(sampleData);
      expect(Array.isArray(results[0].images)).toBe(true);
      expect(results[0].images.length).toBe(1);

      results.forEach((result) =>
        result.images.forEach((image) => {
          expect(image.url).toBe(
            'https://static.inaturalist.org/photos/109762131/square.jpg?1610308133'
          );
          expect(image.copyright).toBe('(c) dridgen, some rights reserved (CC BY-NC)');
        })
      );
    });

    test('real-world data should behave the same way as test data', function () {
      expect(transformObservations2(data)).toEqual([
        {
          id: 67868131,
          name: 'muskrat',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/109762131/square.jpg?1610308133',
              copyright: '(c) dridgen, some rights reserved (CC BY-NC)'
            }
          ],
          observer: 'dridgen@inaturalist.com'
        },
        {
          id: 66528178,
          name: 'cordia sebestena sebestena',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/107267018/square.jpeg?1607882195',
              copyright: '(c) Mohammed Master, all rights reserved'
            }
          ],
          observer: 'mohammedmaster@inaturalist.com'
        },
        {
          id: 61770700,
          name: 'common eastern bumble bee',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/98884441/square.jpg?1601901356',
              copyright: '(c) johnnyrehabb, some rights reserved (CC BY-NC)'
            }
          ],
          observer: 'johnnyrehabb@inaturalist.com'
        },
        {
          id: 61472666,
          name: "angel's trumpet",
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/98374594/square.jpeg?1601643792',
              copyright: '(c) Monica Yeung, all rights reserved'
            }
          ],
          observer: 'monicayeung@inaturalist.com'
        },
        {
          id: 61307088,
          name: 'dryobates woodpeckers',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/98089550/square.jpeg?1601480884',
              copyright: '(c) Holly, some rights reserved (CC BY-NC)'
            },
            {
              url: 'https://static.inaturalist.org/photos/98089568/square.jpeg?1601480892',
              copyright: '(c) Holly, some rights reserved (CC BY-NC)'
            },
            {
              url: 'https://static.inaturalist.org/photos/98097088/square.jpeg?1601483871',
              copyright: '(c) Holly, some rights reserved (CC BY-NC)'
            }
          ],
          observer: 'h-easton@inaturalist.com'
        },
        {
          id: 60706122,
          name: 'american trumpet vine',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/97090180/square.jpeg?1601038974',
              copyright: '(c) Monica Yeung, all rights reserved'
            }
          ],
          observer: 'monicayeung@inaturalist.com'
        },
        {
          id: 60671346,
          name: 'bittersweet nightshade',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/97031452/square.jpeg?1600996784',
              copyright: '(c) Karen C, all rights reserved'
            }
          ],
          observer: 'kareberry@inaturalist.com'
        },
        {
          id: 60021049,
          name: '香茶屬',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/95944256/square.jpeg?1600471203',
              copyright: '(c) xinjie lin, all rights reserved'
            },
            {
              url: 'https://static.inaturalist.org/photos/95944271/square.jpeg?1600471210',
              copyright: '(c) xinjie lin, all rights reserved'
            }
          ],
          observer: 'xinjielin@inaturalist.com'
        },
        {
          id: 60020978,
          name: '矮牽牛屬',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/95944070/square.jpeg?1600471140',
              copyright: '(c) xinjie lin, all rights reserved'
            }
          ],
          observer: 'xinjielin@inaturalist.com'
        },
        {
          id: 60004808,
          name: '芹亞科',
          isExtinct: false,
          images: [
            {
              url: 'https://static.inaturalist.org/photos/95916480/square.jpeg?1600460651',
              copyright: '(c) xinjie lin, all rights reserved'
            },
            {
              url: 'https://static.inaturalist.org/photos/95916500/square.jpeg?1600460656',
              copyright: '(c) xinjie lin, all rights reserved'
            }
          ],
          observer: 'xinjielin@inaturalist.com'
        }
      ]);
    });
  });
});
