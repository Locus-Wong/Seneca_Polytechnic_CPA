export default function Component3(props){
  console.log("Rendering Component 3");
  return (
  <>
    Component 3<br />
    <strong>Value: {props.count}</strong>
  </>
  );
}