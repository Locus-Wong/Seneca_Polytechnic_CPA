import { Container, Navbar, Nav } from "react-bootstrap";
import Link from 'next/link';
import { useRouter } from "next/router";
import { readToken, removeToken } from "@/lib/authenticate";

export default function Navigation(props) {

  const router = useRouter();
  let token = readToken();

  function logout() {
    removeToken();
    router.push("/");
  }

  return (
    <Navbar bg="light" expand="lg">
      <Container>
        <Link href="/" passHref legacyBehavior><Navbar.Brand >Vehicles UI {token && <>- Welcome {token.userName}</>}</Navbar.Brand></Link>
        <Navbar.Toggle aria-controls="basic-navbar-nav" />
        <Navbar.Collapse id="basic-navbar-nav">
          <Nav className="me-auto">
            <Link href="/" passHref legacyBehavior ><Nav.Link>Home</Nav.Link></Link>
            {token && <Link href="/vehicles" passHref legacyBehavior><Nav.Link>Vehicles</Nav.Link></Link>}
          </Nav>
          <Nav className="ml-auto">
            {!token && <Link href="/login" passHref legacyBehavior><Nav.Link>Login</Nav.Link></Link>}
            {token && <Nav.Link onClick={logout}>Logout</Nav.Link>}
          </Nav>
        </Navbar.Collapse>
      </Container>
    </Navbar>
  );
}