import { Container, Row, Col, Card, Accordion } from 'react-bootstrap';
import { useState, useEffect } from 'react';
import Head from 'next/head';
import StarRating from '@/components/StarRating';
import useSWR from 'swr';
import _ from 'lodash';

import styles from '@/styles/Home.module.css'

const fetcher = (url) => fetch(url).then((res) => res.json());

export default function Home() {

  const { data, error } = useSWR(`/api/movies`, fetcher);
  const [searchText, setSearchText] = useState("");
  const [filteredResults, setFilteredResults] = useState();

   function filterResults(data, searchText) {
    setFilteredResults(_.filter(data, movie => movie.title.toLowerCase().includes(searchText.toLowerCase())));
  }

  useEffect(() => {
    if(data && searchText)
      filterResults(data, searchText);
    else if(data && searchText == "")
      setFilteredResults(data)
  }, [data, searchText])

  return (
    <>
      <Head>
        <title>Film Collection</title>
        <meta name="description" content="Personal Collection of Films" />
        <link rel="icon" href="/favicon.ico" />
      </Head>
      <Container className="mt-4">
        <Row>
          <Col>
            <Card bg="light">
              <Card.Body>
                <Col></Col>
                <h2>Film Collection</h2>
              </Card.Body>

              <Container>
                <Row>
                  <Col>
                    <input placeholder="search by Title" className='form-control' type="text" name="search" value={searchText} onChange={e => setSearchText(e.target.value)} />
                  </Col>
                </Row>
              </Container><br />
            </Card>

            <img src="theatre-bkrd.jpg" alt="theatre background" className={styles.headerImage} />
            <Accordion className="mt-4">
              {filteredResults?.map(movie => (
                <Accordion.Item key={movie.id} eventKey={movie.id}>
                  <Accordion.Header><strong>{movie.title}</strong>&nbsp;- {movie.genre}</Accordion.Header>
                  <Accordion.Body>
                    <strong>Rating:</strong> <StarRating rating={movie.rating} /><br /><br />
                    <strong>Plot Summary</strong><br />{movie.plot_summary}
                  </Accordion.Body>
                </Accordion.Item>
              ))}
            </Accordion>
          </Col>
        </Row>
      </Container>
    </>
  )
}
