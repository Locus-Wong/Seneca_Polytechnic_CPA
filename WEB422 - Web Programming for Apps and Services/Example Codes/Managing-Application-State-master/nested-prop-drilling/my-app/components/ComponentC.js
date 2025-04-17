export default function ComponentC(props){
  console.log("Rendering Component C");
  return (
    <>
      Component C<br />
      <button onClick={e => props.setCount(n => n + 1) }>Increase Value</button>
    </>
  );
}