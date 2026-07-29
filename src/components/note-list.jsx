import React from 'react'
import { Link, navigate } from 'gatsby'
import '../styles/note.css'
const moment = require('moment')

export default function NoteList({ notes }) {
  return (
    <div className="block note-cards note-list">
      {notes.map((data, index) => (
        <div
          className="note-area box-feed"
          key={index}
          role="button"
          tabIndex={index}
          onClick={() => {
            navigate(data.node.fields.slug)
          }}
          onKeyDown={event => {
            if (event.keycode === 13) navigate(data.node.fields.slug)
          }}
          style={{
            animationDelay: `${index * 0.08}s`,
            animationFillMode: 'both',
          }}
        >
          <h4 className="note-title">
            <Link to={`${data.node.fields.slug}`}>
              {data.node.fields.title}
            </Link>
          </h4>
          <p className="note-excerpt">
            {data.node.fields.excerpt
              ? data.node.fields.excerpt
              : data.node.excerpt}
          </p>

          <div style={{
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'space-between',
            flexWrap: 'wrap',
            gap: '8px',
            marginTop: '10px',
          }}>
            {data.node.frontmatter.tags?.length ? (
              <div className="note-tag-list" style={{
                display: 'flex',
                flexWrap: 'wrap',
                gap: '4px',
              }}>
                {data.node.frontmatter && data.node.frontmatter.tags
                  ? data.node.frontmatter.tags.map((tag, tagIndex) => (
                      <Link 
                        key={tagIndex} 
                        to={`/tags/${tag}`}
                        style={{
                          background: 'var(--tag-bg)',
                          color: 'var(--tag-text)',
                          padding: '2px 10px',
                          borderRadius: '9999px',
                          fontSize: '0.75rem',
                          fontWeight: 500,
                          textDecoration: 'none',
                          border: '1px solid var(--tag-border)',
                          transition: 'all 0.2s ease',
                        }}
                        onClick={(e) => e.stopPropagation()}
                      >
                        #{tag}
                      </Link>
                    ))
                  : null}
              </div>
            ) : null}

            <span className="note-date" style={{
              fontSize: '0.78rem',
              color: 'var(--text-muted, #999)',
              whiteSpace: 'nowrap',
            }}>
              {moment(new Date(data.node.fields.date)).fromNow()}
            </span>
          </div>
        </div>
      ))}
    </div>
  )
}
