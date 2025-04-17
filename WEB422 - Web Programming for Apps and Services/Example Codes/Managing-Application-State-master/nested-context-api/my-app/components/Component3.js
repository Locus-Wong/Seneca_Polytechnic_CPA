import { useContext } from "react";
import { CountContext } from "@/pages/_app";

export default function Component3() {
  console.log("Rendering Component 3");

  const count = useContext(CountContext);  
  
  return (
    <>
      Component 3<br />
      <strong>Value: {count}</strong>
    </>
  );
}