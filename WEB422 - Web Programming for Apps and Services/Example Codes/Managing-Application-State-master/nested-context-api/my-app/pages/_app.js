import '@/styles/globals.css';
import { useState, createContext } from 'react';

export const CountContext = createContext();
export const SetCountContext = createContext();

export default function App({ Component, pageProps }) {
  const [count, setCount] = useState(0);

  return (
    <>
      <CountContext.Provider value={count}>
        <SetCountContext.Provider value={setCount}>
          <Component {...pageProps} />
        </SetCountContext.Provider>
      </CountContext.Provider>
    </>
  );
}