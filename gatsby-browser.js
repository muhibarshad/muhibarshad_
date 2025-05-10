// export const onClientEntry = () => {
//   window.onload = () => {  // Very undependable. Fires before anything is rendered.
//     console.log('onClientEntry');
//   }
// }

// gatsby-browser.js

import './src/styles/common/bulma.css'
import './src/styles/common/style.css'
import './src/styles/common/custom.css'
import './src/styles/common/util.css'

if (process.env.NODE_ENV === 'production') {
  const { inject } = require('@vercel/analytics')
  inject()
}
