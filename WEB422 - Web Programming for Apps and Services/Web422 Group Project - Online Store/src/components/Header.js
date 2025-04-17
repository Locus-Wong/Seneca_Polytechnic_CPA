/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
export default function Header({
	title,
}) {
	return (
		<div
			className='
				container-fluid 
				d-flex 
				justify-content-center 
				align-items-center
				py-5'
			style={{ background: 'rgb(37, 41, 45)' }}>
			<h1 style={{ color: '#FFFFFF' }}>{title}</h1>
		</div>
	);
}
