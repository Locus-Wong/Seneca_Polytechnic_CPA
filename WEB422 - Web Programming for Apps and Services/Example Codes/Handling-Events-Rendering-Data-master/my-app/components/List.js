import { useState } from 'react';

export default function List(props) {
    const [users, setUsers] = useState([
        { user: 'fred', active: false, age: 40 },
        { user: 'pebbles', active: false, age: 1 },
        { user: 'barney', active: true, age: 36 },
    ]);

    return (
        <>
            <div>{users[0].active && <p>{users[0].user} is Active!</p>}</div>
            <hr />
            <div>
                {users[0].active ? <p>{users[0].user} is Active!</p> : <p>{users[0].user} is Inactive!</p>}
            </div>
            <hr />
            <table>
                <thead>
                    <tr>
                        <th>User</th>
                        <th>Active</th>
                        <th>Age</th>
                    </tr>
                </thead>
                <tbody>
                {users.map((user, index) => (
                    <tr key={index}>
                        <td>{user.user}</td>
                        <td>{user.active ? 'yes' : 'no'}</td>
                        <td>{user.age}</td>
                    </tr>
                ))}
                </tbody>
            </table>
        </>
    );
}