import ComponentC from "./ComponentC";

export default function ComponentB(props){
  console.log("Rendering Component B");
  return (
    <>
      Component B
      <ul>
        <li><ComponentC setCount={props.setCount} /></li>
      </ul>
    </>
  );
}