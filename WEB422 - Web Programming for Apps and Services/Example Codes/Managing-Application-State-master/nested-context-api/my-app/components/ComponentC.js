import { useContext } from "react";
import { SetCountContext } from "@/pages/_app";

export default function ComponentC(){
  console.log("Rendering Component C");

  const setCount = useContext(SetCountContext);  

  return (
    <>
      Component C<br />
      <button onClick={e => setCount(n => n + 1) }>Increase Value</button>
    </>
  );
}