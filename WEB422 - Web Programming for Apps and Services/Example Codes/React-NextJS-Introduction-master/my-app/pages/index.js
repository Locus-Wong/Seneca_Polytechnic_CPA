import Clock from "@/components/Clock";
import Hello from "@/components/Hello";

export default function Home() {
  return (
    <>
    <Hello />  
    <Hello fName="Bart" lName="Simpson" />  
    <Clock locale="en-CA" />
    </>
  )
}