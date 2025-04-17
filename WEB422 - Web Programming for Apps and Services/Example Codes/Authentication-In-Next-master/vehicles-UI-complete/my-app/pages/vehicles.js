import { Card, Table } from "react-bootstrap";
import { getToken } from "@/lib/authenticate";

import useSWR from 'swr';
const fetcher = (url) => fetch(url, { headers: { Authorization: `JWT ${getToken()}` }}).then((res) => res.json());

export default function Vehicles() {

    const { data, error } = useSWR(`${process.env.NEXT_PUBLIC_API_URL}/vehicles`, fetcher);

    return (
      <>
        <Card bg="light">
          <Card.Body>
            <h2>Vehicles</h2>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum nec volutpat ante.
          </Card.Body>
        </Card>
        <br />
        <Table striped bordered>
          <thead>
            <tr>
              <th>Year</th>
              <th>Make</th>
              <th>Model</th>
              <th>Vin</th>
            </tr>
          </thead>
          <tbody>
            {data?.map(vehicle => (
              <tr key={vehicle.id} >
                <td>{vehicle.year}</td>
                <td>{vehicle.make}</td>
                <td>{vehicle.model}</td>
                <td>{vehicle.vin}</td>
              </tr>
            ))}

          </tbody>
        </Table>
      </>
    )
}
