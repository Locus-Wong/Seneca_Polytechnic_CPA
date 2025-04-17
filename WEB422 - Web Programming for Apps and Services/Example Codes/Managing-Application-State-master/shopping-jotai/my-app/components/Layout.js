import Link from 'next/link';
import { useAtom } from 'jotai';
import { cartListAtom } from '@/store';

export default function Layout(props) {

  const [cartList, setCartList] = useAtom(cartListAtom);

  return (
    <>
      <div style={{ padding: "10px" }}>
        <h2>Online Shopping</h2>
        <Link href="/">Home</Link> | <Link href="/products">Products</Link> | <Link href="/cart">Shopping Cart <span>({cartList.length})</span></Link>
        <hr />
        {props.children}
      </div>
    </>
  )
}
