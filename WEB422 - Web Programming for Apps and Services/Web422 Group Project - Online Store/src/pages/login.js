/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/
import Link from 'next/link';
import { useForm } from 'react-hook-form';
import { useAtom } from 'jotai';
import { authenticateUser, readToken } from 'lib/authClient';
import { getFavourites } from 'lib/userService';
import { useRouter } from 'next/router';
import { favouritesAtom } from '@/atoms/atoms';

export default function Login() {
	const {
		register,
		handleSubmit,
		formState: { errors },
	} = useForm();

	const router = useRouter();

	const [, setFavourites] = useAtom(favouritesAtom);

	// Login User
	const onSubmit = async (data) => {
		try {
			const authenticationSuccess = await authenticateUser(data.email, data.password);
			if (!authenticationSuccess) {
				alert('Authentication failed. Please log in manually.'); // Provide feedback to the user.
				return;
			} else {
				const token = readToken();
				const favourites = await getFavourites();
				setFavourites(favourites.favourites);
				router.push('/');
			}
		} catch (error) {
			console.error('Error during login:', error);
		}
	};

	return (
		<div
			className='d-flex 
						align-items-center 
						min-vh-100
						account-page'>
			<div
				className='row px-5'
				style={{ width: '100%', height: 'fix-content' }}>
				<div
					className='col-4 
								d-flex 
								align-items-center 
								justify-content-center
								rounded-start
								account-img'></div>
				<div className='col px-5 py-5 rounded-end account-card'>
					<h2 style={{ color: '#FFFFFF' }}>Log In</h2>
					<form
						className='account-form'
						onSubmit={handleSubmit(onSubmit)}>
						<div>
							<label
								htmlFor='emailField'
								className='form-label'>
								Email<span style={{ color: '#DD0000' }}>*</span>
								{errors.email && <span className='form-warning'>Email is required!</span>}
							</label>
							<input
								{...register('email', { required: true })}
								type='email'
								className='form-control input-field'
								id='emailField'
							/>
						</div>
						<div>
							<label
								htmlFor='passwordField'
								className='form-label'>
								Password<span style={{ color: '#DD0000' }}>*</span>
								{errors.password && <span className='form-warning'>Password is required!</span>}
							</label>
							<input
								{...register('password', { required: true })}
								type='password'
								className='form-control input-field'
								id='passwordField'
							/>
						</div>
						<div className='my-3 d-flex gap-3 justify-content-center'>
							<button
								className='btn btn-dark form-submit'
								type='submit'>
								Log In
							</button>
							<Link
								className='btn btn-light'
								href='/register'>
								Sign In
							</Link>
						</div>
					</form>
				</div>
			</div>
		</div>
	);
}
