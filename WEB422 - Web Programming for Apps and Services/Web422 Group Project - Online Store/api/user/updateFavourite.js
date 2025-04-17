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
	// Only allow PUT requests
	if (req.method !== 'PUT') {
		return res.status(405).json({ message: 'Method Not Allowed' });
	}

	authenticate(req, res, async () => {
		await userService.connect();
		const { favourites } = req.body;
		const userId = req.user._id;

		if (!userId) {
			return res.status(400).json({ message: 'User ID is required' });
		}

		if (!Array.isArray(favourites)) {
			return res.status(400).json({ message: 'Invalid request payload. favourites array is required.' });
		}

		try {
			let parsedFavourites;
			try {
				if (typeof favourites === 'string') {
					parsedFavourites = JSON.parse(favourites);
				} else if (Array.isArray(favourites)) {
					parsedFavourites = favourites;
				} else {
					throw new Error('Favourites must be an array or a JSON string representing an array');
				}
				if (!Array.isArray(parsedFavourites)) {
					throw new Error('Favourites must be an array');
				}
			} catch (err) {
				return res.status(400).json({ message: 'Invalid favourites format: ' + err.message });
			}

			const updatedUser = await userService.User.findByIdAndUpdate(
				userId,
				{ $set: { favourite: parsedFavourites } },
				{ new: true }
			).exec();

			if (!updatedUser) {
				return res.status(404).json({ message: 'User not found' });
			}

			return res.status(200).json({
				message: 'Favourites updated successfully',
				user: updatedUser,
			});
		} catch (err) {
			return res.status(500).json({ message: 'Database error: ' + err.message });
		}
	});
};
