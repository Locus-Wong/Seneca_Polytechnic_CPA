import { useAtom } from 'jotai';
import { cartListAtom } from '@/store';

export default function Cart() {

  const [cartList, setCartList] = useAtom(cartListAtom);

  return (
    <>
      <br />
      <ul>
      {cartList.map((product, index) =>(
        <li key={index}>
          <strong>{product.title}</strong>: {product.description}<br />
          <strong>${product.price.toFixed(2)}</strong>
          <br /><br />
        </li>
      ))}
      </ul>
      <hr />
      <ul><li><strong>Total: ${cartList.reduce( (total, prod) => total + prod.price, 0).toFixed(2)}</strong></li></ul>
    </>
  )
}
