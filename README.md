# Personal site

Twitter-style personal site. Plain HTML/CSS. Use **Live Server** so
partials load.

## Structure

```
index.html
partials/
  profile.inc       banner, avatar, name, bio, links
  content.inc       tabs + work/about
css/
  base.css
  profile.css
  content.css
js/
  includes.js
  tabs.js
media/
  profile/
    avatar.jpg
    banner.png      (or .gif)
  work/             optional post media
```

## Tabs

- **Work** — project posts
- **About me** — bio

## Notes

Banner and avatar scale together via shared CSS variables. Replace
`media/profile/banner.png` with a PNG or GIF anytime.
