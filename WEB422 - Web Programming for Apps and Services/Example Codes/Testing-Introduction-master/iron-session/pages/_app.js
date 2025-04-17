import { SWRConfig } from "swr";
import fetchJson from "@/lib/fetchJson";

export default function App({ Component, pageProps }) {
  return (
    <SWRConfig
      value={{
        fetcher: fetchJson,
        onError: (err) => {
          console.error(err);
        },
      }}
    >
      <Component {...pageProps} />
    </SWRConfig>
  );
}


