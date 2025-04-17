import ComponentC from "./ComponentC";

export default function ComponentB(){
  console.log("Rendering Component B");
  return (
    <>
      Component B
      <ul>
        <li><ComponentC /></li>
      </ul>
    </>
  );
}