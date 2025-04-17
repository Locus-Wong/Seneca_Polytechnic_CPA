export async function getStaticPaths() {
    return {
        paths: [
            { params: { id: "1" } },
            { params: { id: "2" } },
            { params: { id: "3" } },
            { params: { id: "4" } },
            { params: { id: "5" } }
        ], fallback: false
    }
}

export async function getStaticProps(context) {

    const res = await fetch(`https://jsonplaceholder.typicode.com/posts/${context.params.id}`)
    const data = await res.json()

    return { props: { post: data } }
}

export default function Post(props) {
    return <>
        <p><strong>User ID:</strong> {props.post.userId}</p>
        <p><strong>ID:</strong> {props.post.id}</p>
        <p><strong>Title:</strong> {props.post.title}</p>
        <p><strong>Body:</strong> {props.post.body}</p>
    </>
}