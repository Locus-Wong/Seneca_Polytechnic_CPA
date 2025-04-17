import '@/styles/globals.css'
import Layout from '@/components/Layout';
import { cartListAtom } from '@/store';

export async function getStaticProps(context) {

  const res = await fetch(`https://dummyjson.com/products/${context.params.id}`)
  const data = await res.json()

  return { props: { staticProduct: data } }
}

export default function App({ Component, pageProps }) {

  return (
    <>
        <Layout>
          <Component {...pageProps} />
        </Layout>
    </>
  )
}