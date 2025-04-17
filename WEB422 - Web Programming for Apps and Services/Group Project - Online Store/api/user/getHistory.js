/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
const userService = require('../../server/userDbService');
const { authenticate } = require('../../server/authMiddleware');

module.exports = async (req, res) => {
	// Only allow GET requests
	if (req.method !== 'GET') {
		return res.status(405).json({ message: 'Method Not Allowed' });
	}

	authenticate(req, res, async () => {
		await userService.connect();
		const userId = req.user._id;

		if (!userId) {
			return res.status(400).json({ message: 'User ID is required' });
		}

		try {
			const user = await userService.User.findById(userId).exec();

			if (!user) {
				return res.status(404).json({ message: 'User not found' });
			}

			return res.status(200).json(user.searchHistory || []);
		} catch (err) {
			return res.status(500).json({ message: 'Database error: ' + err.message });
		}
	});
};
