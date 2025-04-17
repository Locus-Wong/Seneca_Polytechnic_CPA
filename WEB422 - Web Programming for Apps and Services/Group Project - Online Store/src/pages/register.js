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
import { registerUser, authenticateUser } from 'lib/authClient';
import { useRouter } from 'next/router';

export default function Register() {
	const {
		register,
		handleSubmit,
		formState: { errors },
	} = useForm();

	const router = useRouter();

	// Create User
	const onSubmit = async (data) => {
		try {
			// Attempt to register the user
			const registrationSuccess = await registerUser(data.name, data.password, data.email);
			if (!registrationSuccess) {
				alert('Registration failed. Please try again.'); // Provide feedback to the user
				return;
			}

			// Attempt to authenticate the user after successful registration
			const authenticationSuccess = await authenticateUser(data.email, data.password);
			if (!authenticationSuccess) {
				alert('Authentication failed. Please log in manually.'); // Provide feedback to the user
				return;
			}

			// Redirect to the home page on success
			router.push('/');
		} catch (error) {
			// Handle unexpected errors
			console.error('Error during registration or authentication:', error);
			alert('An unexpected error occurred. Please try again later.');
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
					<h2 style={{ color: '#FFFFFF' }}>Create Account</h2>
					<form onSubmit={handleSubmit(onSubmit)}>
						<div>
							<label
								htmlFor='nameField'
								className='form-label'>
								Name<span style={{ color: '#DD0000' }}>*</span>
								{errors.name && <span className='form-warning'>Name is required!</span>}
							</label>
							<input
								{...register('name', { required: true })}
								type='text'
								className='form-control input-field'
								id='nameField'
							/>
						</div>
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
								Sign Up
							</button>
							<Link
								className='btn btn-light'
								href='/login'>
								Log In
							</Link>
						</div>
					</form>
				</div>
			</div>
		</div>
	);
}
