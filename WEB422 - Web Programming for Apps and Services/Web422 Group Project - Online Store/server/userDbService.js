/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
const mongoose = require('mongoose');
const dotenv = require('dotenv'); // to load environment variables from a .env file
dotenv.config(); // Load environment variables from .env file

let mongoDBConnectionString = process.env.MONGODB_URI;

let Schema = mongoose.Schema;

let userSchema = new Schema({
	userName: {
		type: String,
		unique: true,
		required: true,
	},
	password: {
		type: String,
		required: true,
	},
	email: {
		type: String,
		unique: true,
		required: true,
	},
	favourite: [
		{
			id: Number,
			title: String,
			slug: String,
			price: Number,
			description: String,
			category: {
				id: Number,
				name: String,
				slug: String,
				image: String,
				creationAt: Date,
				updatedAt: Date,
			},
			images: [String],
			creationAt: Date,
			updatedAt: Date,
		},
	],
	searchHistory: [
		{
			query: String,
			timestamp: { type: Date, default: Date.now },
		},
	],
});

// Initialize the User variable as null
let User = null;

// Improve connection for serverless environment
let cachedConnection = null;

// connect(): Establishes a connection to the MongoDB database.
module.exports.connect = async function () {
	if (cachedConnection) {
		return Promise.resolve(cachedConnection);
	}

	return mongoose
		.connect(mongoDBConnectionString, {
			useNewUrlParser: true,
			useUnifiedTopology: true,
			bufferCommands: false, // Disable mongoose buffering
			maxPoolSize: 10, // Optimize for serverless
		})
		.then((connection) => {
			cachedConnection = connection;
			User = mongoose.model('users', userSchema); // Initialize User model globally
			module.exports.User = User; // Export the User model
			console.log('MongoDB Connected');
			return connection;
		})
		.catch((err) => {
			console.error('MongoDB Connection Error:', err);
			throw err;
		});
};
