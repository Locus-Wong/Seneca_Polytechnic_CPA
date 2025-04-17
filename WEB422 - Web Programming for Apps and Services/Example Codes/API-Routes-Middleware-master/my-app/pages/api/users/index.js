import { UserModel, mongooseConnect } from '@/lib/dbUtils';

export default async function handler(req, res) {
  const { name } = req.body;
  const { method } = req;

  try {
    await mongooseConnect();

    switch (method) {
      case 'GET':
        let users = await UserModel.find().exec();
        res.status(200).json(users);
        break;
      case 'POST':
        const newUser = new UserModel({ name: name });
        await newUser.save();
        res.status(200).json({ message: `User: ${name} Created` });
        break;
      default:
        res.setHeader('Allow', ['GET', 'POST']);
        res.status(405).end(`Method ${method} Not Allowed`);
    }
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
}