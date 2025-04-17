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
	// Only allow DELETE requests
	if (req.method !== 'DELETE') {
		return res.status(405).json({ message: 'Method Not Allowed' });
	}

	authenticate(req, res, async () => {
		await userService.connect();
		const { historyId } = req.body;
		const userId = req.user._id;

		if (!userId) {
			return res.status(400).json({ message: 'User ID is required' });
		}

		if (!historyId) {
			return res.status(400).json({ message: 'History ID is required' });
		}

		try {
			const updatedUser = await userService.User.findByIdAndUpdate(
				userId,
				{ $pull: { searchHistory: { _id: historyId } } },
				{ new: true }
			).exec();

			if (!updatedUser) {
				return res.status(404).json({ message: 'User not found' });
			}

			return res.json({
				message: 'Search history entry removed successfully',
				history: updatedUser.searchHistory,
			});
		} catch (err) {
			return res.status(500).json({ message: 'Database error: ' + err.message });
		}
	});
};
