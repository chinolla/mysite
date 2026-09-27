(function () {
  var nodes = Array.prototype.slice.call(
    document.querySelectorAll("[data-include]")
  );

  if (!nodes.length) {
    if (window.initProfileTabs) window.initProfileTabs();
    if (window.initCarousels) window.initCarousels();
    if (window.initLightbox) window.initLightbox();
    return;
  }

  Promise.all(
    nodes.map(function (el) {
      var url = el.getAttribute("data-include");
      return fetch(url).then(function (res) {
        if (!res.ok) {
          throw new Error("Failed to load " + url + " (" + res.status + ")");
        }
        return res.text().then(function (html) {
          // Parse as a document so Live Server wrappers/scripts cannot break outerHTML.
          var doc = new DOMParser().parseFromString(html, "text/html");
          doc.querySelectorAll("script").forEach(function (script) {
            script.remove();
          });
          var frag = document.createDocumentFragment();
          while (doc.body.firstChild) {
            frag.appendChild(doc.body.firstChild);
          }
          el.replaceWith(frag);
        });
      });
    })
  )
    .then(function () {
      if (window.initProfileTabs) window.initProfileTabs();
      if (window.initCarousels) window.initCarousels();
      if (window.initLightbox) window.initLightbox();
    })
    .catch(function (err) {
      console.error(err);
      document.body.insertAdjacentHTML(
        "afterbegin",
        '<p style="margin:1rem;font-family:sans-serif;">Could not load page sections. Open this site with Live Server (not a raw file:// URL).</p>'
      );
    });
})();
