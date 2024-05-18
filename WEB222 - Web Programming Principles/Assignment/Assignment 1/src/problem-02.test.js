const { createLinkTag } = require('./solutions');

describe('Problem 2 - createLinkTag() function', function () {
  test('correct <link> tag for stylesheet link, stripping double-quotes where appropriate', function () {
    let rel = 'stylesheet';
    let href = 'styles.css';
    let result = createLinkTag(rel, href);
    expect(result).toBe('<link rel=stylesheet href=styles.css>');
  });

  test('leading whitespace is removed before using values', function () {
    let rel = '  stylesheet';
    let href = '                  styles.css';
    let result = createLinkTag(rel, href);
    expect(result).toBe('<link rel=stylesheet href=styles.css>');
  });

  test('trailing whitespace is removed before using values', function () {
    let rel = 'stylesheet ';
    let href = 'styles.css                             ';
    let result = createLinkTag(rel, href);
    expect(result).toBe('<link rel=stylesheet href=styles.css>');
  });

  test('double-quotes around value are not optional when the value includes a space', function () {
    let rel = 'rel with space';
    let href = 'href with space';
    let result = createLinkTag(rel, href);
    expect(result).toBe('<link rel="rel with space" href="href with space">');
  });

  test('double-quotes around value are not optional when the value includes tab', function () {
    let rel = 'rel\twith\ttab';
    let href = 'href\twith\ttab\t';
    let result = createLinkTag(rel, href);
    expect(result).toBe('<link rel="rel\twith\ttab" href="href\twith\ttab">');
  });
});
