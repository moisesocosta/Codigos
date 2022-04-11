const movie = {
    title: "Harry Potter",
    url: "http://caminho.com/imagem",
};

// HTML
const figure = document.createElement("figcaption"); // <figure>
const img = document.createElement("img"); // <img>
const title = document.createElement("figcaption") // <figcaption>
const listBanners = document.querySelector(".list-banners")

figure.classList.add("wrapper-banner"); //<figure class="wrapper-banner">

img.src = "img/banner.png"; // <img src="img/banner.png">
img.alt = "Banner of the movie"; // <img src="img/banner.png" alt="Banner of the movie">
img.classList.add("main-banner"); // <img class="main-banner" src="img/banner.png" alt="Banner of the movie">

title.textContent = "Nome do filme"; // <figcaption>Nome do filme</figcaption>
title.classList.add("main-caption"); // <figcaption class"main-caption">Nome do filme</figcaption>

/*
<figure class="wrapper-banner">
    <img class="main-banner" src="img/banner.png" alt="Banner of the movie">
</figure>
*/
figure.insertAdjacentElement("beforeend", img);

/*
<figure class="wrapper-banner">
    <img class="main-banner" src="img/banner.png" alt="Banner of the movie">
    <figcaption class"main-caption">Nome do filme</figcaption>
</figure>
*/
figure.insertAdjacentElement("beforeend", title);

listBanners.insertAdjacentElement("beforeend", figure);