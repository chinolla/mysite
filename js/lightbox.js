window.initLightbox = function initLightbox() {
  if (document.documentElement.dataset.lightboxReady === "true") return;
  document.documentElement.dataset.lightboxReady = "true";

  var overlay = document.createElement("div");
  overlay.className = "lightbox";
  overlay.hidden = true;
  overlay.setAttribute("role", "dialog");
  overlay.setAttribute("aria-modal", "true");
  overlay.setAttribute("aria-label", "Photo viewer");
  overlay.innerHTML =
    '<button class="lightbox__close" type="button" aria-label="Close">' +
    '<svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">' +
    '<path fill="currentColor" d="M18.3 5.71 12 12.01 5.7 5.7 4.29 7.11 10.59 13.4 4.29 19.7 5.7 21.11 12 14.82l6.3 6.29 1.41-1.41-6.29-6.3 6.29-6.29z"/>' +
    "</svg></button>" +
    '<button class="lightbox__nav lightbox__nav--prev" type="button" aria-label="Previous photo">' +
    '<svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">' +
    '<path fill="currentColor" d="M15.41 7.41 14 6l-6 6 6 6 1.41-1.41L10.83 12z"/>' +
    "</svg></button>" +
    '<figure class="lightbox__figure">' +
    '<img class="lightbox__img" alt="">' +
    "</figure>" +
    '<button class="lightbox__nav lightbox__nav--next" type="button" aria-label="Next photo">' +
    '<svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">' +
    '<path fill="currentColor" d="M10 6 8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"/>' +
    "</svg></button>" +
    '<p class="lightbox__count" aria-live="polite"></p>';

  document.body.appendChild(overlay);

  var imgEl = overlay.querySelector(".lightbox__img");
  var countEl = overlay.querySelector(".lightbox__count");
  var closeBtn = overlay.querySelector(".lightbox__close");
  var prevBtn = overlay.querySelector(".lightbox__nav--prev");
  var nextBtn = overlay.querySelector(".lightbox__nav--next");

  var items = [];
  var index = 0;
  var lastFocus = null;

  function render() {
    var item = items[index];
    if (!item) return;
    imgEl.src = item.src;
    imgEl.alt = item.alt || "";
    countEl.textContent = items.length > 1 ? index + 1 + " / " + items.length : "";
    prevBtn.hidden = items.length < 2;
    nextBtn.hidden = items.length < 2;
  }

  function open(gallery, startIndex) {
    items = gallery;
    index = startIndex;
    lastFocus = document.activeElement;
    render();
    overlay.hidden = false;
    document.body.classList.add("lightbox-open");
    closeBtn.focus();
  }

  function close() {
    overlay.hidden = true;
    document.body.classList.remove("lightbox-open");
    imgEl.removeAttribute("src");
    items = [];
    if (lastFocus && lastFocus.focus) lastFocus.focus();
  }

  function step(delta) {
    if (items.length < 2) return;
    index = (index + delta + items.length) % items.length;
    render();
  }

  closeBtn.addEventListener("click", close);
  prevBtn.addEventListener("click", function () {
    step(-1);
  });
  nextBtn.addEventListener("click", function () {
    step(1);
  });

  overlay.addEventListener("click", function (event) {
    if (event.target === overlay || event.target.classList.contains("lightbox__figure")) {
      close();
    }
  });

  document.addEventListener("keydown", function (event) {
    if (overlay.hidden) return;
    if (event.key === "Escape") {
      event.preventDefault();
      close();
    } else if (event.key === "ArrowLeft") {
      event.preventDefault();
      step(-1);
    } else if (event.key === "ArrowRight") {
      event.preventDefault();
      step(1);
    }
  });

  function galleryFrom(img) {
    var carousel = img.closest("[data-carousel]");
    if (carousel) {
      return Array.prototype.map.call(
        carousel.querySelectorAll(".carousel__slide img"),
        function (node) {
          return { src: node.currentSrc || node.src, alt: node.alt || "" };
        }
      );
    }
    var media = img.closest(".post__media");
    if (media) {
      return Array.prototype.map.call(media.querySelectorAll("img"), function (node) {
        return { src: node.currentSrc || node.src, alt: node.alt || "" };
      });
    }
    return [{ src: img.currentSrc || img.src, alt: img.alt || "" }];
  }

  function bindImage(img) {
    if (img.dataset.lightboxBound === "true") return;
    img.dataset.lightboxBound = "true";
    img.classList.add("is-zoomable");
    img.setAttribute("role", "button");
    img.setAttribute("tabindex", "0");
    img.setAttribute("aria-label", (img.alt ? img.alt + ". " : "") + "View larger");

    var startX = 0;
    var startY = 0;
    var moved = false;

    img.addEventListener("pointerdown", function (event) {
      startX = event.clientX;
      startY = event.clientY;
      moved = false;
    });

    img.addEventListener("pointermove", function (event) {
      if (Math.abs(event.clientX - startX) > 8 || Math.abs(event.clientY - startY) > 8) {
        moved = true;
      }
    });

    img.addEventListener("click", function (event) {
      if (moved) return;
      event.preventDefault();
      event.stopPropagation();
      var gallery = galleryFrom(img);
      var start = gallery.findIndex(function (item) {
        return item.src === (img.currentSrc || img.src);
      });
      open(gallery, Math.max(0, start));
    });

    img.addEventListener("keydown", function (event) {
      if (event.key === "Enter" || event.key === " ") {
        event.preventDefault();
        img.click();
      }
    });
  }

  Array.prototype.forEach.call(
    document.querySelectorAll(".carousel__slide img, .post__media img"),
    bindImage
  );
};
