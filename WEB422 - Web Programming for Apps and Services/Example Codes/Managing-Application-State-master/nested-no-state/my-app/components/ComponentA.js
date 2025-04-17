import ComponentB from "./ComponentB";

export default function ComponentA(){
  return (
    <>
      Component A
      <ul>
        <li><ComponentB /></li>
      </ul>
    </>
  );
}