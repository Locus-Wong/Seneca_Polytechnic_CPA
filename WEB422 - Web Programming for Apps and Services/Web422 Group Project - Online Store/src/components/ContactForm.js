/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/
import { useForm } from 'react-hook-form';
import { useRouter } from 'next/router';

export default function ContactForm() {
	const {
		register,
		handleSubmit,
		formState: { errors },
	} = useForm();

	const router = useRouter();

	// Save Form Data
	const onSubmit = async (data) => {
		// Extract fields from data
		let { email, message, name } = data;

		fetch('api/sendMessage', {
			method: 'POST',
			body: JSON.stringify({ name: name, email: email, message: message }),
			headers: { 'content-type': 'application/json' },
		})
			.then(() => {
				alert('Message successfully sent. Thank you for your feedback!');
				router.push('/');
			})
			.catch((err) => {
				console.log(err);
			});
	};

	return (
		<div
			className='mx-auto my-5'
			style={{ width: '650px' }}>
			<form
				className='d-flex flex-column gap-3'
				onSubmit={handleSubmit(onSubmit)}>
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
						htmlFor='messageField'
						className='form-label'>
						Message
					</label>
					<textarea
						{...register('message')}
						className='form-control input-field'
						id='messageField'></textarea>
				</div>
				<button
					className='btn btn-dark form-submit'
					type='submit'>
					Submit
				</button>
			</form>
		</div>
	);
}
