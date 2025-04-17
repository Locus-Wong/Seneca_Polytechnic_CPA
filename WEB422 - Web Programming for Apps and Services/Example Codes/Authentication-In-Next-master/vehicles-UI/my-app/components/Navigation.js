import { Container, Navbar, Nav } from "react-bootstrap";
import Link from 'next/link';

export default function Navigation(props) {

  return (
    <Navbar bg="light" expand="lg">
      <Container>
        <Link href="/" passHref legacyBehavior><Navbar.Brand >Vehicles UI</Navbar.Brand></Link>
        <Navbar.Toggle aria-controls="basic-navbar-nav" />
        <Navbar.Collapse id="basic-navbar-nav">
          <Nav className="me-auto">
            <Link href="/" passHref legacyBehavior><Nav.Link >Home</Nav.Link></Link>
            <Link href="/vehicles" passHref legacyBehavior><Nav.Link>Vehicles</Nav.Link></Link>
          </Nav>
        </Navbar.Collapse>
      </Container>
    </Navbar>
  );
}