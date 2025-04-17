import Component2 from "./Component2";

export default function Component1(props) {
  console.log("Rendering Component 1");
  return (
    <>
      Component 1
      <ul>
        <li><Component2 count={props.count} /></li>
      </ul>
    </>

  );
}