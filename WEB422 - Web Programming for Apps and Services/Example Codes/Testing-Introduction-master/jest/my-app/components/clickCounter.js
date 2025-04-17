import {useState} from 'react'

export default function ClickCounter(){
  const [count, setCount] = useState(0);
  return <button onClick={()=>{setCount(count => count + 1)}}>Clicked {count} Times</button>
}