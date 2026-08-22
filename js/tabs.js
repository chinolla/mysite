window.initProfileTabs = function initProfileTabs() {
  var tablist = document.querySelector(".tabs");
  if (!tablist || tablist.dataset.ready === "true") return;
  tablist.dataset.ready = "true";

  var buttons = Array.prototype.slice.call(
    tablist.querySelectorAll(".tabs__btn")
  );
  var panels = Array.prototype.slice.call(
    document.querySelectorAll(".tab-panel")
  );

  function activate(id) {
    buttons.forEach(function (btn) {
      var on = btn.getAttribute("data-tab") === id;
      btn.classList.toggle("is-active", on);
      btn.setAttribute("aria-selected", on ? "true" : "false");
    });
    panels.forEach(function (panel) {
      var on = panel.getAttribute("data-panel") === id;
      if (on) {
        panel.removeAttribute("hidden");
      } else {
        panel.setAttribute("hidden", "");
      }
    });
  }

  buttons.forEach(function (btn) {
    btn.addEventListener("click", function () {
      activate(btn.getAttribute("data-tab"));
    });
  });
};
