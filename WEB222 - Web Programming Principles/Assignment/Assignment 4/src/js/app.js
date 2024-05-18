/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Tsz Wa Wong
 *      Student ID: 152181228
 *      Date:       7 Mar 2024
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

function generateArtistButtons(artists) {
  const menu = document.querySelector("#menu");
  artists.forEach(function (artist) {
    if (artist.name === artists[0].name) {
      // Display the first artist's top 5 songs by default
      const header = document.getElementById("selected-artist"); // select the h2 element with id selected-artist
      header.textContent = "Top 5 Songs Most Streamed by " + artist.name + " ";
      const Wikipedia = document.createElement("a");
      Wikipedia.href = artist.urls[0].url; // set the href attribute of the anchor to the artist's Instagram URL
      Wikipedia.textContent = "(Wikipedia,";
      header.appendChild(Wikipedia); // append the anchor to the header
      const Instagram = document.createElement("a");
      Instagram.href = artist.urls[1].url; // set the href attribute of the anchor to the artist's Instagram URL
      Instagram.textContent = " Instagram)";
      header.appendChild(Instagram); // append the anchor to the header
      generateSongsTable(artist.artistId);
    }

    const artistButton = document.createElement("button"); // create a button element
    artistButton.textContent = artist.name; // set button text to artist name
    artistButton.addEventListener("click", () => {
      const header = document.getElementById("selected-artist"); // select the h2 element with id selected-artist
      header.textContent = "Top 5 Songs Most Streamed by " + artist.name + " ";
      const Wikipedia = document.createElement("a");
      Wikipedia.href = artist.urls[0].url; // set the href attribute of the anchor to the artist's Instagram URL
      Wikipedia.textContent = "(Wikipedia,";
      header.appendChild(Wikipedia); // append the anchor to the header
      const Instagram = document.createElement("a");
      Instagram.href = artist.urls[1].url; // set the href attribute of the anchor to the artist's Instagram URL
      Instagram.textContent = " Instagram)";
      header.appendChild(Instagram); // append the anchor to the header
      generateSongsTable(artist.artistId);
    });

    menu.appendChild(artistButton);
  });
}

function generateSongsTable(artistId) {
  const thead = document.querySelector("thead");
  const tbody = document.getElementById("songs");
  let songsByArtist = songs.filter((song) => song.artistId === artistId); // get the array of songs by the artist

  thead.innerHTML = ""; // clear the table head
  tbody.innerHTML = ""; // clear the table body

  const thead_tr = document.createElement("tr");
  thead.appendChild(thead_tr);

  const Title = document.createElement("td");
  Title.textContent = "Name of the song";
  const Year = document.createElement("td");
  Year.textContent = "Year of release";
  const Duration = document.createElement("td");
  Duration.textContent = "Duration (mm:ss)";

  thead_tr.appendChild(Title);
  thead_tr.appendChild(Year);
  thead_tr.appendChild(Duration);

  songsByArtist.forEach((song) => {
    if (song.explicit === false) {
      // only display songs that are not explicit
      const tbody_tr = document.createElement("tr");
      tbody.appendChild(tbody_tr);

      const SongTitle = document.createElement("td");
      const youtubeURL = document.createElement("a");
      youtubeURL.href = song.url; // set the href attribute of the anchor to the song's URL
      youtubeURL.textContent = song.title;
      SongTitle.appendChild(youtubeURL); // append the anchor to the header

      const songYear = document.createElement("td");
      songYear.textContent = song.year;

      const songDuration = document.createElement("td");
      const songMinutes = Math.floor(song.duration / 60); // round down the minutes to the nearest whole number
      const songSeconds = song.duration % 60;
      songDuration.textContent = songMinutes + ":" + songSeconds;

      tbody_tr.appendChild(SongTitle);
      tbody_tr.appendChild(songYear);
      tbody_tr.appendChild(songDuration);

      tbody_tr.addEventListener("click", () => {
        // Add a click handler to your <tr> that will console.log() the song whenever the user clicks it
        console.log(song);
      });
    }
  });
}
function main() {
  console.log("page is loaded");
  generateArtistButtons(artists);
}
window.addEventListener("load", main); // Make sure you don’t do anything to the DOM until it’s fully loaded.
