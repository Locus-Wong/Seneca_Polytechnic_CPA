import Link from 'next/link';
import { useAtom } from 'jotai';
import { cartListAtom } from '@/store';

export async function getStaticPaths() {

  let pathList = [];

  // pre-render and support product/1 through product/30 only
  for (let i = 1; i <= 30; i++) {
    pathList.push({ params: { id: i.toString() } })
  }

  return {
    paths: pathList,
    fallback: false
  }
}

export async function getStaticProps(context) {

  const res = await fetch(`https://dummyjson.com/products/${context.params.id}`)
  const data = await res.json()

  return { props: { staticProduct: data } }
}

export default function Product(props) {

  const { staticProduct } = props;

  const [cartList, setCartList] = useAtom(cartListAtom);

  function addToCart(product){

    setCartList([...cartList, product])
  }


  return (
    <>
     <h3>{staticProduct.title}</h3>
        <img src={staticProduct.images[0]} /><br /><br />
        {staticProduct.description}<br /><br />
        <strong>Brand:</strong> {staticProduct.brand}<br />
        <strong>Rating:</strong> {staticProduct.rating} / 5<br />
        <strong>Stock:</strong> {staticProduct.stock}<br /><br />
        <strong>${staticProduct.price.toFixed(2)}</strong><br /><br />
        <Link href="/products"><button>Back to Product List</button></Link>&nbsp;&nbsp;<button onClick={e=>addToCart(staticProduct)}>Add to Cart</button>
    </>
  );
}
