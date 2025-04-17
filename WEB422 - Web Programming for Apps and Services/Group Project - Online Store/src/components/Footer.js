/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/
import Link from 'next/link';

export default function Footer() {
	return (
		<div
			className='container-fluid 
					  d-flex 
				  	  flex-column 
					  justify-content-center 
					  align-items-center
					  py-4'
			style={{ height: '180px', background: 'rgb(33, 37, 41)' }}>
			<div
				className='d-flex justify-content-center align-items-center'
				style={{
					width: '200px',
					height: '80px',
					background: '#919191',
				}}>
				<span>Website Logo</span>
			</div>
			<div className='d-flex gap-3'>
				<Link
					href='/contact'
					className='footer-link'>
					Contact Page
				</Link>
				<Link
					href='/about'
					className='footer-link'>
					About Page
				</Link>
			</div>
		</div>
	);
}
