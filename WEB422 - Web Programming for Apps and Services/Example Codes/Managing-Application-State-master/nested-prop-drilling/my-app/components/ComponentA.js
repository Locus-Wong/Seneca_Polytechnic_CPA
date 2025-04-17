import ComponentB from "./ComponentB";

export default function ComponentA(props){
  console.log("Rendering Component A");
  return (
    <>
      Component A
      <ul>
        <li><ComponentB setCount={props.setCount} /></li>
      </ul>
    </>
  );
}