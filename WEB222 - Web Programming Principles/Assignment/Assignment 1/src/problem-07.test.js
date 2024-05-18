const { mimeTypeFromFilename } = require('./solutions');

describe('Problem 7 - mimeTypeFromFilename() function', function () {
  test('correct MIME type for TXT extension', function () {
    expect(mimeTypeFromFilename('doc.txt')).toEqual('text/plain');
  });

  test('correct MIME type for HTML extensions', function () {
    expect(mimeTypeFromFilename('index.html')).toEqual('text/html');
    expect(mimeTypeFromFilename('index.htm')).toEqual('text/html');
  });

  test('correct MIME type for CSS extension', function () {
    expect(mimeTypeFromFilename('styles.css')).toEqual('text/css');
  });

  test('correct MIME type for JS extension', function () {
    expect(mimeTypeFromFilename('script.js')).toEqual('application/javascript');
  });

  test('correct MIME type for JPEG extensions', function () {
    expect(mimeTypeFromFilename('photo.jpg')).toEqual('image/jpeg');
    expect(mimeTypeFromFilename('photo.jpeg')).toEqual('image/jpeg');
  });

  test('correct MIME type for PNG extension', function () {
    expect(mimeTypeFromFilename('photo.png')).toEqual('image/png');
  });

  test('correct MIME type for GIF extension', function () {
    expect(mimeTypeFromFilename('animation.gif')).toEqual('image/gif');
  });

  test('correct MIME type for BMP extension', function () {
    expect(mimeTypeFromFilename('graphic.bmp')).toEqual('image/bmp');
  });

  test('correct MIME type for SVG extension', function () {
    expect(mimeTypeFromFilename('chart.svg')).toEqual('image/svg+xml');
  });

  test('correct MIME type for JSON extension', function () {
    expect(mimeTypeFromFilename('data.json')).toEqual('application/json');
  });

  test('correct MIME type for XML extension', function () {
    expect(mimeTypeFromFilename('data.xml')).toEqual('application/xml');
  });

  test('correct MIME type for CSV extension', function () {
    expect(mimeTypeFromFilename('data.csv')).toEqual('text/csv');
  });

  test('correct MIME type for unknown extensions', function () {
    expect(mimeTypeFromFilename('file.exe')).toEqual('application/octet-stream');
    expect(mimeTypeFromFilename('library.dll')).toEqual('application/octet-stream');
  });

  test('absolute Unix file paths give correct MIME type', function () {
    expect(mimeTypeFromFilename('/public/site/www/cat.jpg')).toEqual('image/jpeg');
  });

  test('absolute Windows file paths give correct MIME type', function () {
    expect(mimeTypeFromFilename('C:\\Documents\\Seneca\\WEB222\\students.csv')).toEqual('text/csv');
  });

  test('spaces in path give correct MIME type', function () {
    expect(mimeTypeFromFilename('/this path/has quite a/few spaces/doc.txt')).toEqual('text/plain');
  });

  test('periods in path give correct MIME type', function () {
    expect(mimeTypeFromFilename('/this.path/has.quite.a/few.periods/dog.png')).toEqual('image/png');
  });

  test('relative path gives correct MIME type', function () {
    expect(mimeTypeFromFilename('../names.json')).toEqual('application/json');
  });

  test('filename with no extension should give unknown MIME type', function () {
    expect(mimeTypeFromFilename('/this/file/has/no/extension')).toEqual('application/octet-stream');
  });

  test('filename with unexpected extension should give unknown MIME type', function () {
    expect(mimeTypeFromFilename('/this/file/has/an/unknown/extension.cgi')).toEqual(
      'application/octet-stream'
    );
  });
});
