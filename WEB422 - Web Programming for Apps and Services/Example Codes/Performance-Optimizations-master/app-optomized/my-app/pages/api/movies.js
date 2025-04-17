
import getMovieData from "@/lib/movieData";

export default function handler(req, res) {
  const { method } = req; switch (method) {
    case 'GET':
      res.status(200).json(getMovieData());
      break;

    default:
      // send an error message back, indicating that the method is not supported by this route
      res.setHeader('Allow', ['GET']);
      res.status(405).end(`Method ${method} Not Allowed`);
  }
}

