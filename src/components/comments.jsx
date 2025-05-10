import React, { useEffect, useRef } from 'react'
import style from '../styles/common/comment.css'

const Comments = ({ title }) => {
  const commentRef = useRef(null)

  useEffect(() => {
    if (!commentRef.current || commentRef.current.hasChildNodes()) return

    const script = document.createElement('script')
    script.src = 'https://giscus.app/client.js'
    script.async = true
    script.crossOrigin = 'anonymous'
    script.setAttribute('data-repo', 'muhibarshad/muhibarshad_')
    script.setAttribute('data-repo-id', 'R_kgDOOnxEzQ')
    script.setAttribute('data-category-id', 'DIC_kwDOOnxEzc4Cp_zw')
    script.setAttribute('data-mapping', 'title')
    script.setAttribute('data-term', title)
    script.setAttribute('data-strict', '0')
    script.setAttribute('data-reactions-enabled', '1')
    script.setAttribute('data-emit-metadata', '0')
    script.setAttribute('data-input-position', 'bottom')
    script.setAttribute('data-theme', 'noborder_gray')
    script.setAttribute('data-lang', 'en')
    script.setAttribute('data-loading', 'lazy')

    commentRef.current.appendChild(script)
  }, [title])

  return <div ref={commentRef} className="giscus-comments" />
}

export default Comments
