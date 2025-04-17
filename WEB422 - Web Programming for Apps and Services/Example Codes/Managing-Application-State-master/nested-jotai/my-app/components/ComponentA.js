import ComponentB from "./ComponentB";

export default function ComponentA(){
  console.log("Rendering Component A");

  return (
    <>
      Component A
      <ul>
        <li><ComponentB /></li>
      </ul>
    </>
  );
}