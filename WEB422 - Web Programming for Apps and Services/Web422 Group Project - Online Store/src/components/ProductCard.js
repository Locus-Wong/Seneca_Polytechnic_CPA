/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faHeart } from '@fortawesome/free-regular-svg-icons';
import { useAtom } from 'jotai';
import { favouritesAtom } from '@/atoms/atoms';
import { readToken, isAuthenticated } from '../lib/authClient';
import { useRouter } from 'next/router';
import { updateFavourite } from '../lib/userService';

export default function ProductCard({ product }) {
	const [favourites, setFavourites] = useAtom(favouritesAtom);
	const router = useRouter();

	// Currency formatter
	const CADDollar = new Intl.NumberFormat('en-US', {
		style: 'currency',
		currency: 'USD',
	});

	// Truncate description Length
	const desc = product.description.length > 90 ? product.description.substring(0, 90) + '...' : product.description;

	async function update() {
		const token = readToken();

		let updatedFavourites;
		if (favourites.some((fav) => fav.id === product.id)) {
			updatedFavourites = favourites.filter((fav) => fav.id !== product.id);
			setFavourites(updatedFavourites);
		} else {
			updatedFavourites = [...favourites, product];
			setFavourites(updatedFavourites);
		}
		await updateFavourite(token._id, updatedFavourites); // Call the API route to update the favourite field
	}

	return (
		<div className='card m-0 product-card'>
			<div className='position-relative'>
				<img
					src={product.images[0]}
					className='card-img-top'
					style={{ height: '230px' }}
				/>
				<button
					className='btn btn-light rounded-circle position-absolute d-flex justify-content-center align-items-center bottom-0 end-0'
					onClick={async () => {
						if (isAuthenticated()) {
							await update();
						} else {
							router.push('/login');
						}
					}}
					style={{
						width: '50px',
						height: '50px',
						transform: 'translate(-10px, -10px)',
						backgroundColor: favourites.some((fav) => fav.id === product.id) ? 'pink' : 'white',
					}}>
					<FontAwesomeIcon
						icon={faHeart}
						size='2xl'
					/>
				</button>
			</div>
			<div className='card-body d-flex flex-column pt-2'>
				<div className='d-flex justify-content-between'>
					<span style={{ color: '#919191', fontStyle: 'italic' }}>{product.category.name}</span>
					<span className='product-text'>{CADDollar.format(product.price)}</span>
				</div>
				<span className='product-text'>{product.title}</span>
				<span className='mt-4 product-text'>{desc}</span>
			</div>
		</div>
	);
}
