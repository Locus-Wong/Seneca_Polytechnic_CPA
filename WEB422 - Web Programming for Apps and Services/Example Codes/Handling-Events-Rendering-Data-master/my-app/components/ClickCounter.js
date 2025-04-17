import { useState } from 'react';

export default function ClickCounter(props) {
  const [numClicks, setNumClicks] = useState(0);

  function increaseNumClicks(e) {
    // 'e' is the current event object
    setNumClicks((prevClicks) => prevClicks + 1);
  }

  return <button onClick={increaseNumClicks}>Clicks: {numClicks}</button>;
}