
let vehicleData = [{
  "id": 1,
  "year": 1994,
  "make": "Suzuki",
  "model": "SJ",
  "vin": "JN8AZ2KR6CT544012"
}, {
  "id": 2,
  "year": 1999,
  "make": "Chrysler",
  "model": "300",
  "vin": "1B3CC5FB5AN648885"
}, {
  "id": 3,
  "year": 2005,
  "make": "BMW",
  "model": "X3",
  "vin": "JTHBP5C29E5152916"
}];

export default function handler(req, res) {
  const { method } = req;
  const { id } = req.query;

  switch (method) {
    case 'GET':
      let vehicleIndex = vehicleData.findIndex(v => v.id == id);
      // if a vehicleIndex was found, return the corresponding vehicle, else send a 404 error
      (vehicleIndex != -1) ? res.status(200).json(vehicleData[vehicleIndex]) : res.status(404).end();
    break;
    
    default:
      // send an error message back, indicating that the method is not supported by this route
      res.setHeader('Allow', ['GET']);
      res.status(405).end(`Method ${method} Not Allowed`);
  }
}

