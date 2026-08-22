<main class="content-panel">
  <nav class="tabs" aria-label="Profile sections">
    <button class="tabs__btn is-active" type="button" data-tab="work" aria-selected="true">
      Work
    </button>
    <button class="tabs__btn" type="button" data-tab="archive" aria-selected="false">
      Archive
    </button>
    <button class="tabs__btn" type="button" data-tab="about" aria-selected="false">
      About me
    </button>
  </nav>

  <section class="tab-panel" id="panel-work" data-panel="work">
    <ul class="feed">
      <li>
        <article class="post" id="work-cipher">
          <img
            class="post__avatar"
            src="media/employers/seva.png"
            alt=""
            width="80"
            height="80"
          >
          <div class="post__body">
            <div class="post__meta">
              <span class="post__name">CIPHER</span>
              <span class="post__dot" aria-hidden="true">·</span>
              <span class="post__context">SEVA Innovations</span>
            </div>
            <p class="post__what">Local-LLM platform for military intelligence interrogation: live transcription, translation, and report generation.</p>
            <ul class="post__did">
              <li>Designed and built the entire system, concept to production</li>
              <li>Led business development and customer outreach</li>
              <li>Ran user assessments with the 501st MIB in Korea and 66th MIB in Germany</li>
            </ul>
            <blockquote class="post__result">Fielded in international training exercises including Arirang Sentinel 26 and STERN DAGGER 26</blockquote>
            <ul class="post__tags" aria-label="Focus">
              <li>Lead Engineer</li>
              <li>Business Development</li>
              <li>Field Engineering</li>
            </ul>
          </div>
        </article>
      </li>
      <li>
        <article class="post" id="work-tactilink">
          <img
            class="post__avatar"
            src="media/employers/seva.png"
            alt=""
            width="80"
            height="80"
          >
          <div class="post__body">
            <div class="post__meta">
              <span class="post__name">Tactilink</span>
              <span class="post__dot" aria-hidden="true">·</span>
              <span class="post__context">SEVA Innovations</span>
            </div>
            <p class="post__what">Chat and file transfer over SINCGARS and HF, the DoW's most widespread radios.</p>
            <ul class="post__did">
              <li>Built core messaging: 1:1 direct, broadcast, and chat rooms</li>
              <li>Ran field demos and user assessments with radio operators</li>
              <li>Led business development and customer outreach</li>
            </ul>
            <blockquote class="post__result">Acquired by the Department of War as GOTS software</blockquote>
            <ul class="post__tags" aria-label="Focus">
              <li>Software Engineer</li>
              <li>Field Engineering</li>
              <li>Business Development</li>
            </ul>
          </div>
        </article>
      </li>
    </ul>
  </section>

  <section class="tab-panel" id="panel-archive" data-panel="archive" hidden>
    <p class="feed-empty">Nothing in the archive yet.</p>
  </section>

  <section class="tab-panel" id="panel-about" data-panel="about" hidden>
    <div class="about">
      <div class="about__bio">
        <p>
          I’m a software engineer who’s pivoting into hardware. I started
          my career at Dell Technologies, but I wasn’t interested in
          building internal tools, so I moved to a small defense tech
          company where I could play a bigger role. Since then, I’ve
          expanded into full system design and ownership, business
          development, and working with the U.S. government.
        </p>
        <p>
          Outside of that, I’m an Intelligence Officer in the Army Reserve.
          I’m interested in startups, and I like to backpack.
        </p>
      </div>

      <h2 class="about__heading">Work history</h2>
      <ul class="employers">
        <li>
          <article class="employer">
            <div class="employer__top">
              <!-- Logo: media/employers/army.png -->
              <div class="employer__logo employer__logo--placeholder" aria-hidden="true">A</div>
              <span class="employer__status employer__status--current">Current</span>
            </div>
            <h3 class="employer__org">US Army Reserve</h3>
            <p class="employer__role">Intelligence Officer</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <div class="employer__top">
              <!-- Logo: media/employers/module8.png -->
              <div class="employer__logo employer__logo--placeholder" aria-hidden="true">M</div>
              <span class="employer__status employer__status--current">Current</span>
            </div>
            <h3 class="employer__org">Module 8 Dynamics</h3>
            <p class="employer__role">Founding Engineer</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <div class="employer__top">
              <!-- Logo: media/employers/dell.png -->
              <div class="employer__logo employer__logo--placeholder" aria-hidden="true">D</div>
              <span class="employer__status employer__status--previous">Previous</span>
            </div>
            <h3 class="employer__org">Dell</h3>
            <p class="employer__role">Software Engineer II</p>
            <p class="employer__note">Software Engineer I</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <div class="employer__top">
              <img
                class="employer__logo"
                src="media/employers/seva.png"
                alt=""
                width="48"
                height="48"
              >
              <span class="employer__status employer__status--previous">Previous</span>
            </div>
            <h3 class="employer__org">SEVA Innovations</h3>
            <p class="employer__role">Founding Engineer</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <div class="employer__top">
              <!-- Logo: media/employers/aws.png -->
              <div class="employer__logo employer__logo--placeholder" aria-hidden="true">A</div>
              <span class="employer__status employer__status--previous">Previous</span>
            </div>
            <h3 class="employer__org">Amazon Web Services</h3>
            <p class="employer__role">Solution Architect Intern</p>
          </article>
        </li>
      </ul>
    </div>
  </section>
</main>
