import Component3 from "./Component3";

export default function Component2(){
  console.log("Rendering Component 2");
  return (
    <>
      Component 2
      <ul>
        <li><Component3 /></li>
      </ul>
    </>
  );
}