import Link from 'next/link';

export default function Layout(props) {

  return (
    <>
      <div style={{ padding: "10px" }}>
        <h2>Online Shopping</h2>
        <Link href="/">Home</Link> | <Link href="/products">Products</Link> | <Link href="/cart">Shopping Cart</Link>
        <hr />
        {props.children}
      </div>
    </>
  )
}

