import Link  from 'next/link';
import { useRouter } from 'next/router';


export default function Layout(props) {

    const router = useRouter();

    return (
        <>
            <h1>Pages / Routing in Next.js</h1>
            <Link href="/">Home</Link> | <Link href="/about">About</Link> | <Link href="/dashboard">Dashboard</Link> | <Link href="/dashboard/preferences">Dashboard Preferences</Link> | <Link href="/products?page=1&category=stationary">Products (query parameters)</Link> | <Link href="/products">Products (no query parameters)</Link> | <Link href="/product/5">Product 5</Link> | <Link href="/product/6">Product 6</Link> | <Link href="/post/4">Post 4</Link> | <Link href="/post/5">Post 5</Link>
            <hr />
            <br />
            {props.children}
            <br />
            <hr />
            <button onClick={()=>{router.push("/")}}>Back Home</button>
        </>
    )
}