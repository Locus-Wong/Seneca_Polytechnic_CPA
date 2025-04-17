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

export default function AdrianAboutCard() {
	return (
		<div className='card p-5 about-card'>
			<div className='card-body'>
				<h3 className='card-title'>Adrian Curammeng</h3>
				<p className='card-text'>Part creative, part programmer, full goof.</p>
				<p className='card-text'>
					I am a web developer currently studying at Seneca Polytechnic. I am proficient in designing UIs, working in
					terminal environments, and starting,
					<s> but maybe not finishing</s> many personal projects.
				</p>
				<div className='container d-flex p-0 mb-3 gap-5'>
					<div>
						<span>Skills:</span>
						<ul className='card-text'>
							<li>Next.js</li>
							<li>Node.js</li>
							<li>Bootstrap</li>
							<li>Figma</li>
						</ul>
					</div>
					<div>
						<span>Hobbies:</span>
						<ul className='card-text'>
							<li>Music</li>
							<li>Baseball</li>
							<li>Walking</li>
							<li>Cleaning</li>
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
						<a
							target='_blank'
							href='mailto:acurammeng@myseneca.ca'>
							acurammeng@myseneca.ca
						</a>
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
							href='https://www.linkedin.com/in/adrians-sky/'>
							Adrian Curammeng
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
							href='https://github.com/adrians-sky'>
							adrians-sky
						</a>
					</li>
				</ul>
			</div>
		</div>
	);
}
