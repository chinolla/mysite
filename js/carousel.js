window.initCarousels = function initCarousels() {
  var carousels = Array.prototype.slice.call(
    document.querySelectorAll("[data-carousel]")
  );

  carousels.forEach(function (root) {
    if (root.dataset.ready === "true") return;
    root.dataset.ready = "true";

    var scroller = root.querySelector(".carousel__scroller");
    var track = root.querySelector(".carousel__track");
    var slides = Array.prototype.slice.call(
      root.querySelectorAll(".carousel__slide")
    );
    var prevBtn = root.querySelector(".carousel__btn--prev");
    var nextBtn = root.querySelector(".carousel__btn--next");

    if (!scroller || !track || !slides.length) return;

    var gap = 2;

    function maxSlideWidth() {
      var raw = getComputedStyle(root).getPropertyValue("--carousel-slide-max").trim();
      if (!raw) return Infinity;
      var probe = document.createElement("div");
      probe.style.cssText = "position:absolute;visibility:hidden;width:" + raw;
      document.body.appendChild(probe);
      var px = probe.getBoundingClientRect().width;
      document.body.removeChild(probe);
      return px || Infinity;
    }

    function slideWidth() {
      var available = scroller.clientWidth;
      var maxW = maxSlideWidth();
      // How many max-sized slides fit in the visible area?
      var fit = Math.floor((available + gap) / (maxW + gap));
      if (fit >= 2) {
        // Show as many as fit at the capped photo size
        return maxW;
      }
      // Narrow screens: always show two by shrinking slightly
      return Math.max(0, (available - gap) / 2);
    }

    function layout() {
      var width = slideWidth();
      slides.forEach(function (slide) {
        slide.style.flex = "0 0 " + width + "px";
        slide.style.width = width + "px";
      });
      updateButtons();
    }

    function updateButtons() {
      var maxScroll = scroller.scrollWidth - scroller.clientWidth;
      var atStart = scroller.scrollLeft <= 2;
      var atEnd = maxScroll <= 2 || scroller.scrollLeft >= maxScroll - 2;
      if (prevBtn) {
        prevBtn.hidden = atStart;
        prevBtn.disabled = atStart;
      }
      if (nextBtn) {
        nextBtn.hidden = atEnd;
        nextBtn.disabled = atEnd;
      }
    }

    function scrollBySlides(count) {
      scroller.scrollBy({
        left: (slideWidth() + gap) * count,
        behavior: "smooth"
      });
    }

    if (prevBtn) {
      prevBtn.addEventListener("click", function () {
        scrollBySlides(-1);
      });
    }
    if (nextBtn) {
      nextBtn.addEventListener("click", function () {
        scrollBySlides(1);
      });
    }

    scroller.addEventListener("scroll", updateButtons, { passive: true });
    window.addEventListener("resize", layout);

    if (window.ResizeObserver) {
      new ResizeObserver(layout).observe(scroller);
    }

    layout();
  });
};
