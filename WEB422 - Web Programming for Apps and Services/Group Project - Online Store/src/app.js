/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
function getProducts() {
	return fetch('https://api.escuelajs.co/api/v1/products?offset=0&limit=50')
		.then((res) => res.json())
		.then((data) => {
			return data;
		});
}

function getCategories() {
	return fetch('https://api.escuelajs.co/api/v1/categories')
		.then((res) => res.json())
		.then((apiCategories) => {
			// Remove unwanted categories
			const filteredCategories = apiCategories.filter((category) => !['category_B', 'string'].includes(category.name));

			const transformedCategories = filteredCategories.map((category) => ({
				id: category.id,
				name: category.name,
				image: category.image,
			}));

			return transformedCategories;
		});
}

export { getProducts, getCategories };
