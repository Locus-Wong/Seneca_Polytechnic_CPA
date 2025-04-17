import ClickCounter from "../components/clickCounter";
import "@testing-library/jest-dom";
import userEvent from "@testing-library/user-event";
import { render } from "@testing-library/react";

describe("ClickCounter Component", () => {
  test("increase count by 1 when clicked", async ()=>{
    const user = userEvent.setup();
    const {container} = render(<ClickCounter />);

    //attempt to fetch the "button" element
    const button = container.querySelector('button');

    // ensure there the "button" element exists
    expect(button).toBeTruthy();

    // ensure that the "button" text contains "0" to start
    expect(button.innerHTML).toContain("0");  

    // simulate a button click event
    await user.click(button);

    // ensure that the "button" context contains "1" after the event
    expect(button.innerHTML).toContain("1");
  }); 
});