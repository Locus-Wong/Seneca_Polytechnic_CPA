import { createMocks } from 'node-mocks-http';
import handler from '../pages/api/vehicles/[id]';

describe('/api/vehicles/[id] Route', () => {
  test('returns a vehicle for a specified ID', async () => {
    const { req, res } = createMocks({
      method: 'GET',
      query: {
        id: '1',
      },
    });

    await handler(req, res);

    expect(res._getStatusCode()).toBe(200);
    expect(JSON.parse(res._getData())).toEqual(
      expect.objectContaining({
        id: 1,
      }),
    );
  });

  test('returns 404 when vehicle id not found', async () => {
    const { req, res } = createMocks({
      method: 'GET',
      query: {
        id: 'abc',
      },
    });

    await handler(req, res);
    expect(res._getStatusCode()).toBe(404);
  });
});