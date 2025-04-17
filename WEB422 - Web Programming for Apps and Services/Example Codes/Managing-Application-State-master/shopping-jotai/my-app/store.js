import { atom } from "jotai";
async function defaultValues(){

  const results =[]

  // Fetch Product 1

  const prod1Result = await fetch("https://dummyjson.com/products/1");
  const prod1 = await prod1Result.json();

  results.push(prod1);

  // Fetch Product 2

  const prod2Result = await fetch("https://dummyjson.com/products/2");
  const prod2 = await prod2Result.json();

  results.push(prod2);

  return results;
}

export const cartListAtom = atom(defaultValues());

