/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faEnvelope } from '@fortawesome/free-regular-svg-icons';
import { faLocationDot } from '@fortawesome/free-solid-svg-icons';
import { faLinkedin, faGithub } from '@fortawesome/free-brands-svg-icons';

export default function LocusAboutCard() {
	return (
		<div className='card p-5 about-card'>
			<div className='card-body'>
				<h2 className='card-title'>Locus Wong</h2>
				<p className='card-text'>
					Hi everyone, I am an enthusiastic web/mobile app developer. Feel free to reach out if there's an opportunity
					to work together or if you have any questions.
				</p>
				<div className='container d-flex p-0 mb-3 gap-5'>
					<div>
						<span>Skills:</span>
						<ul className='card-text'>
							<li>React</li>
							<li>ExpressJS</li>
							<li>NodeJS</li>
							<li>MongoDB</li>
						</ul>
					</div>
					<div>
						<span>Hobbies:</span>
						<ul className='card-text'>
							<li>Movies</li>
							<li>Anime</li>
							<li>Videogames</li>
							<li>Boardgames</li>
						</ul>
					</div>
				</div>
				<h5>Contact</h5>
				<ul className='card-text p-0'>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faEnvelope}
							size='lg'
							className='me-2 contact-logo'
						/>
						twwong9@myseneca.ca
					</li>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faLocationDot}
							size='lg'
							className='me-2 contact-logo'
						/>
						Toronto, ON
					</li>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faLinkedin}
							size='lg'
							className='me-2 contact-logo'
						/>
						<a
							target='_blank'
							href='https://www.linkedin.com/in/tsz-wa-wong-8201b3210?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BrvaskB%2BWQ26zVfqR%2BPueOQ%3D%3D'>
							Locus Wong
						</a>
					</li>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faGithub}
							size='lg'
							className='me-2 contact-logo'
						/>
						<a
							target='_blank'
							href='https://github.com/Locus-Wong'>
							locus-wong
						</a>
					</li>
				</ul>
			</div>
		</div>
	);
}
