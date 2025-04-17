import ClickCounter from '@/components/ClickCounter';
import List from '@/components/List';
import Post from '@/components/Post';

// This function gets called at build time
export async function getStaticProps() {
  // Call an external API endpoint to get posts
  const res = await fetch('https://jsonplaceholder.typicode.com/posts/1');
  const data = await res.json();

  return { props: { staticPost: data } };
}

export default function Home(props) {
  return (
    <>
      <Post post={props.staticPost} />
      <hr />
      <List />
      <hr />
      <ClickCounter />
    </>
  );
}
