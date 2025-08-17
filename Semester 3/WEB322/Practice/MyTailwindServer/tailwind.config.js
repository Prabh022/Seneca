/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [],
  theme: {
    extend: {},
  },
  plugins: [],
}
module.exports = {
  content: [`./views/**/*.html`], // all .html files
  // ...
};
module.exports = {
  // ...
  plugins: [require('@tailwindcss/typography'), require('daisyui')],
};

