/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
const mongoose = require('mongoose');
const dotenv = require('dotenv');

// Load environment variables
dotenv.config();

let messageSchema = new mongoose.Schema({
	name: {
		type: String,
		required: true,
	},
	email: {
		type: String,
		required: true,
	},
	message: {
		type: String,
	},
});

// Initialise Message variable
let Message = mongoose.models.Message || mongoose.model('Message', messageSchema);

export default async function handler(req, res) {
	if (req.method !== 'POST') {
		return res.status(405).json({ message: 'Method Not Allowed' });
	}

	// Initialise Message variabel
	if (!Message) {
		Message = mongoose.model('Message', messageSchema);
	}

	// Connect to MongoDB database
	await mongoose.connect(process.env.MONGODB_URI, {
		bufferCommands: false, // Disable mongoose buffering
		maxPoolSize: 10, // Optimize for serverless
	});

	// Add User to database
	const newMessage = await Message.create(req.body);

	res.status(200).json({ message: 'OK' });
}
