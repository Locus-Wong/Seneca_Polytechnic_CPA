import ProductBox from "@/components/ProductBox";

export async function getStaticProps() {
  const res = await fetch('https://dummyjson.com/products');
  const data = await res.json();
  return { props: { staticProducts: data.products } };
}

export default function Products(props) {
  const { staticProducts } = props;
  return (
    <div style={{ flexWrap: "wrap", display: "flex" }}>
      {staticProducts.map(prod => (
          <ProductBox key={prod.id} product={prod} />
      ))}
    </div>

  )
}
