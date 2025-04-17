import { useState } from 'react';

export default function SimpleForm() {

    const [userName, setUserName] = useState("Homer Simpson");

    function submitForm(e) {
        e.preventDefault();
        console.log(`form submitted - userName: ${userName} `);
    }

    return (
        <form onSubmit={submitForm}>
            User Name: <input value={userName} onChange={e => setUserName(e.target.value)} /><br /><br />
            <button type="submit">Update User Name</button>
        </form>
    );
}