import {Container, Row, Col} from 'react-bootstrap';
import Navigation from './Navigation';

export default function Layout(props){
  return (
    <>
    <Navigation /><br />
      <Container>
        <Row>
          <Col>
            {props.children}
          </Col>
        </Row>
      </Container>
    </>
  );
}