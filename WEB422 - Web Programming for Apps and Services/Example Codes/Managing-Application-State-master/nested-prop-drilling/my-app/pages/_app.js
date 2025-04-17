import '@/styles/globals.css'
import {useState} from 'react'

export default function App({ Component, pageProps }) {
  const [count, setCount] = useState(0);
  return <Component {...pageProps} count={count} setCount={setCount} />
}