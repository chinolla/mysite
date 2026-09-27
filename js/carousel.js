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
    var multi = slides.length > 2;

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
      var fit = Math.floor((available + gap) / (maxW + gap));
      if (fit >= 2) {
        return maxW;
      }
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
      var canScroll = maxScroll > 2;
      var atStart = scroller.scrollLeft <= 2;
      var atEnd = !canScroll || scroller.scrollLeft >= maxScroll - 2;

      // Only show arrows when there are more than 2 photos and overflow
      if (prevBtn) {
        var showPrev = multi && canScroll && !atStart;
        prevBtn.hidden = !showPrev;
        prevBtn.disabled = !showPrev;
      }
      if (nextBtn) {
        var showNext = multi && canScroll && !atEnd;
        nextBtn.hidden = !showNext;
        nextBtn.disabled = !showNext;
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
