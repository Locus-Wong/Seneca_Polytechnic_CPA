import { StarFill } from 'react-bootstrap-icons';
import { Star } from 'react-bootstrap-icons';

export default function StarRating({ rating }) {

  let ratingInt = +rating

  return (
    <>
      {[...Array(ratingInt)].map((e, i) => <StarFill key={i} />)}
      {[...Array(5 - ratingInt)].map((e, i) => <Star key={i} />)}
    </>
  );
}