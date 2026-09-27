<main class="content-panel">
  <nav class="tabs" aria-label="Profile sections">
    <button class="tabs__btn is-active" type="button" data-tab="work" aria-selected="true">
      Work
    </button>
    <button class="tabs__btn" type="button" data-tab="about" aria-selected="false">
      About me
    </button>
  </nav>

  <section class="tab-panel" id="panel-work" data-panel="work">
    <ul class="feed">
      <li>
        <article class="post" id="work-drone-detector">
          <div class="post__body">
            <div class="post__meta">
              <span class="post__name">Drone Detector</span>
              <span class="post__dot" aria-hidden="true">·</span>
              <span class="post__context">Personal project</span>
            </div>
            <p class="post__tldr">
              <span class="post__tldr-label">TL;DR</span>
              A small edge-AI system that spots drones on camera, tracks them
              in real time, and physically points at them with a pan-tilt mount.
              It runs entirely on a Jetson Orin Nano.
            </p>
            <div class="post__content">
              <p>
                I'm building a small counter-drone sensing demo on an NVIDIA
                Jetson Orin Nano. The goal is a system that can see a drone,
                keep track of it as it moves, and physically cue onto it, all
                on a device about the size of a paperback.
              </p>
              <p>
                At its core, a camera feeds a YOLO object-detection model
                optimized with TensorRT so it runs in real time on the Jetson.
                ByteTrack sits on top of the detector and keeps a consistent ID
                on each target from frame to frame. That way the system follows
                one drone instead of re-detecting it from scratch every frame.
              </p>
              <p>
                The tracker's output drives a pan-tilt mount through a PCA9685
                servo controller, which closes the loop. As the target moves,
                the mount turns to keep it centered, and an LED cues whatever
                the system is locked onto. Everything runs offline on the
                device, with no cloud and no network required.
              </p>
              <p>
                Alongside the build, I'm putting together a test harness to
                measure how well it actually works across different conditions:
                accuracy (precision, recall, mAP), frame rate, and how the
                tracker holds up when targets are small, fast, or partly blocked.
              </p>
              <p>
                This one comes straight out of my day job. CIPHER taught me how
                much work it takes to get AI running reliably on hardware in the
                field, and counter-UAS is one of the most pressing problems the
                Army has right now. I wanted to understand the detect, track, and
                cue chain firsthand by building it.
              </p>
            </div>
            <ul class="post__tags" aria-label="Focus">
              <li>edge ai</li>
              <li>computer vision</li>
              <li>in progress</li>
            </ul>
          </div>
        </article>
      </li>
      <li>
        <article class="post" id="work-cipher">
          <div class="post__body">
            <div class="post__meta">
              <span class="post__name">CIPHER</span>
              <span class="post__dot" aria-hidden="true">·</span>
              <span class="post__context">SEVA Innovations</span>
            </div>
            <p class="post__tldr">
              <span class="post__tldr-label">TL;DR</span>
              Offline local-LLM platform for Army MI interrogation ops:
              live transcription, translation, and report tooling. Built
              end to end and fielded with units in Korea and Germany.
            </p>
            <div class="post__content">
              <p>
                CIPHER is the Central Intelligence Platform for HUMINT Evaluation
                and Reporting, a platform I built for SEVA Innovations. It was
                purpose-built for U.S. Army Military Intelligence units,
                specifically for interrogation operations. The system runs fully
                offline for network-denied and austere environments, or anywhere
                outside connections are not allowed, like a SCIF.
              </p>
              <p>
                At its core, units can connect wired or wireless devices to record
                video and audio during interrogations. That can mean phones they
                already have, like ATAK phones, or basic CCTV security cameras
                that run and connect over PoE.
              </p>
              <p>
                Interrogations can be live-monitored from other devices on the
                same network, with local LLMs providing live transcription and
                translation from the video and audio stream. That matters because
                evaluators and spectators do not always speak the target language.
              </p>
              <p>
                Once the video and audio artifacts are stored, users can run
                additional models against them. Models are swappable on the
                device, and cover report generation, translations, summaries, or
                freeform prompts against the transcript.
              </p>
              <p>
                This was an extremely fun project to build and support. I got to
                help support the 501st MIB in Korea during Arirang Sentinel 26,
                and the 66th MIB in Germany for Stern Dagger 26.
              </p>
              <p>
                I learned a whole lot, and got to build something I not only
                found interesting, but that directly benefits the organization
                I am part of, the 338th MI BN.
              </p>
              <div class="carousel" data-carousel aria-label="Photos from Korea supporting CIPHER">
                <div class="carousel__scroller" tabindex="0">
                  <ul class="carousel__track">
                    <li class="carousel__slide">
                      <img
                        src="media/work/cipher-korea-1.jpg"
                        alt="Field setup with laptops and a network switch during CIPHER support in Korea"
                        width="1200"
                        height="900"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                    <li class="carousel__slide">
                      <img
                        src="media/work/cipher-korea-2.jpg"
                        alt="Temporary ADET workstation with laptop and monitor by the window"
                        width="900"
                        height="1200"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                    <li class="carousel__slide">
                      <img
                        src="media/work/cipher-korea-3.jpg"
                        alt="N Seoul Tower and Namsan Mountain from the city"
                        width="900"
                        height="1200"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                    <li class="carousel__slide">
                      <img
                        src="media/work/cipher-korea-4.jpg"
                        alt="With a U.S. Army contact during CIPHER support in Korea"
                        width="900"
                        height="1200"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                  </ul>
                </div>
                <button class="carousel__btn carousel__btn--prev" type="button" aria-label="Previous photos">
                  <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
                    <path fill="currentColor" d="M15.41 7.41 14 6l-6 6 6 6 1.41-1.41L10.83 12z"/>
                  </svg>
                </button>
                <button class="carousel__btn carousel__btn--next" type="button" aria-label="Next photos">
                  <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
                    <path fill="currentColor" d="M10 6 8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"/>
                  </svg>
                </button>
              </div>
            </div>
            <ul class="post__tags" aria-label="Focus">
              <li>lead engineer</li>
              <li>business development</li>
              <li>field engineering</li>
            </ul>
          </div>
        </article>
      </li>
      <li>
        <article class="post" id="work-tactilink">
          <div class="post__body">
            <div class="post__meta">
              <span class="post__name">Tactilink</span>
              <span class="post__dot" aria-hidden="true">·</span>
              <span class="post__context">SEVA Innovations</span>
            </div>
            <p class="post__tldr">
              <span class="post__tldr-label">TL;DR</span>
              Chat and file transfer over SINCGARS and HF radios. Built core
              messaging, ran field demos with operators, and helped take it
              to DoW GOTS acquisition.
            </p>
            <div class="post__content">
              <p>
                Tactilink is software I worked on at SEVA Innovations for chat
                and file transfer over SINCGARS and HF, the Department of War's
                most widespread radios. The goal was straightforward: let users
                move messages and files across radio links that were never
                designed for modern data traffic.
              </p>
              <p>
                I built out the core messaging layer, including 1:1 direct
                messages, broadcast, and chat rooms, then spent time in the field
                running demos and user assessments with radio operators. That
                feedback loop mattered. Operator workflows and radio constraints
                shaped how the product actually got used.
              </p>
              <p>
                Alongside the engineering work, I led business development and
                customer outreach. The result of that effort: Tactilink was
                acquired by the Department of War as government off-the-shelf
                (GOTS) software.
              </p>
              <div class="carousel" data-carousel aria-label="Photos from Tactilink field work">
                <div class="carousel__scroller" tabindex="0">
                  <ul class="carousel__track">
                    <li class="carousel__slide">
                      <img
                        src="media/work/tactilink-1.jpg"
                        alt="Close-up of a tactical radio keypad and display used with Tactilink"
                        width="1200"
                        height="1600"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                    <li class="carousel__slide">
                      <img
                        src="media/work/tactilink-2.jpg"
                        alt="SINCGARS radio stack mounted in a military vehicle during field use"
                        width="1200"
                        height="1600"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                  </ul>
                </div>
                <button class="carousel__btn carousel__btn--prev" type="button" aria-label="Previous photos">
                  <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
                    <path fill="currentColor" d="M15.41 7.41 14 6l-6 6 6 6 1.41-1.41L10.83 12z"/>
                  </svg>
                </button>
                <button class="carousel__btn carousel__btn--next" type="button" aria-label="Next photos">
                  <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
                    <path fill="currentColor" d="M10 6 8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"/>
                  </svg>
                </button>
              </div>
            </div>
            <ul class="post__tags" aria-label="Focus">
              <li>software engineer</li>
              <li>field engineering</li>
              <li>business development</li>
            </ul>
          </div>
        </article>
      </li>
      <li>
        <article class="post" id="work-statis">
          <div class="post__body">
            <div class="post__meta">
              <span class="post__name">Statis: Social Fitness App</span>
              <span class="post__dot" aria-hidden="true">·</span>
              <span class="post__context">Personal project</span>
            </div>
            <p class="post__tldr">
              <span class="post__tldr-label">TL;DR</span>
              Social fitness app I published in 2025. Workout and meal tracking
              with friends, weekly leaderboards, and an XP/rank system that
              rewarded consistency over PRs.
            </p>
            <div class="post__content">
              <p>
                Statis was a mobile app I published in 2025. It started as a side
                project so I had a decent way to track workouts and nutrition.
                I hated MyFitnessPal, and I wanted something that actually fit
                how I trained.
              </p>
              <p>
                It turned into a social app where you could share tracked
                workouts and meals with friends, a bit like Strava, but for the
                full logging loop instead of just activities. The idea was to
                make consistency visible and competitive without turning fitness
                into a highlight reel of max lifts.
              </p>
              <p>
                Rewards were based on showing up, not on how much weight someone
                moved. Users earned XP for logging meals and workouts, climbed
                ranks in a system similar to games like Valorant (Bronze through
                Diamond), and competed on weekly leaderboards both globally and
                among friends.
              </p>
              <p>
                It was a fun project, and it put a fun spin on social fitness
                apps. It died after I realized building it was the easy part,
                and I knew nothing about marketing.
              </p>
              <div class="carousel" data-carousel aria-label="Statis app screenshots">
                <div class="carousel__scroller" tabindex="0">
                  <ul class="carousel__track">
                    <li class="carousel__slide">
                      <img
                        src="media/work/statis-profile.jpg"
                        alt="Statis profile screen showing workouts, totals, and performance trends"
                        width="1170"
                        height="2532"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                    <li class="carousel__slide">
                      <img
                        src="media/work/statis-appstore.jpg"
                        alt="Statis App Store listing showing the social fitness app and XP rewards"
                        width="1170"
                        height="2532"
                        loading="lazy"
                        draggable="false"
                      >
                    </li>
                  </ul>
                </div>
                <button class="carousel__btn carousel__btn--prev" type="button" aria-label="Previous photos">
                  <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
                    <path fill="currentColor" d="M15.41 7.41 14 6l-6 6 6 6 1.41-1.41L10.83 12z"/>
                  </svg>
                </button>
                <button class="carousel__btn carousel__btn--next" type="button" aria-label="Next photos">
                  <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
                    <path fill="currentColor" d="M10 6 8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"/>
                  </svg>
                </button>
              </div>
            </div>
            <ul class="post__tags" aria-label="Focus">
              <li>mobile</li>
              <li>product</li>
              <li>solo founder</li>
            </ul>
          </div>
        </article>
      </li>
    </ul>
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
            <span class="employer__status employer__status--current">Current</span>
            <h3 class="employer__role">Intelligence Officer</h3>
            <p class="employer__org">US Army Reserve</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <span class="employer__status employer__status--current">Current</span>
            <h3 class="employer__role">Founding Engineer</h3>
            <p class="employer__org">Module 8 Dynamics</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <span class="employer__status employer__status--previous">Previous</span>
            <h3 class="employer__role">Founding Engineer</h3>
            <p class="employer__org">SEVA Innovations</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <span class="employer__status employer__status--previous">Previous</span>
            <h3 class="employer__role">Software Engineer II</h3>
            <p class="employer__org">Dell</p>
          </article>
        </li>
        <li>
          <article class="employer">
            <span class="employer__status employer__status--previous">Previous</span>
            <h3 class="employer__role">Solution Architect Intern</h3>
            <p class="employer__org">Amazon Web Services</p>
          </article>
        </li>
      </ul>

      <h2 class="about__heading">Interests</h2>
      <div class="about__bio">
        <p>I like to workout, run, travel, and pokemon</p>
      </div>
      <div class="carousel" data-carousel aria-label="Photos from working out, running, and travel">
        <div class="carousel__scroller" tabindex="0">
          <ul class="carousel__track">
            <li class="carousel__slide">
              <img
                src="media/interests/workout.jpg"
                alt="Flexing after a workout"
                width="900"
                height="1200"
                loading="lazy"
                draggable="false"
              >
            </li>
            <li class="carousel__slide">
              <img
                src="media/interests/run.jpg"
                alt="At a race with friends in the mountains"
                width="900"
                height="1200"
                loading="lazy"
                draggable="false"
              >
            </li>
            <li class="carousel__slide">
              <img
                src="media/interests/travel.jpg"
                alt="Traveling near Mount Fuji with a Charmander plush"
                width="900"
                height="1200"
                loading="lazy"
                draggable="false"
              >
            </li>
          </ul>
        </div>
        <button class="carousel__btn carousel__btn--prev" type="button" aria-label="Previous photos">
          <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
            <path fill="currentColor" d="M15.41 7.41 14 6l-6 6 6 6 1.41-1.41L10.83 12z"/>
          </svg>
        </button>
        <button class="carousel__btn carousel__btn--next" type="button" aria-label="Next photos">
          <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
            <path fill="currentColor" d="M10 6 8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"/>
          </svg>
        </button>
      </div>
    </div>
  </section>

  <footer class="site-footer">
    <p>Last updated September 2026</p>
  </footer>
</main>
