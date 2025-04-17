import ComponentC from "./ComponentC";

export default function ComponentB(){
  return (
    <>
      Component B
      <ul>
        <li><ComponentC /></li>
      </ul>
    </>
  );
}