import Component1 from "@/components/Component1";
import ComponentA from "@/components/ComponentA";

export default function Home() {
  console.log("Rendering Home");
  return (
    <>
      <ul>
        <li><Component1 /><br /></li>
        <li><ComponentA /></li>
      </ul>
    </>
  )
}
