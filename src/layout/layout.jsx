import React from 'react'
import Header from './header'

export default function Layout({ children, title, type }) {
  return (
    <>
      <Header title={title} type={type} />
      <section className="section">
        <div className="columns is-centered">{children}</div>
      </section>
      <footer style={{
        borderTop: '1px solid var(--border)',
        padding: '2rem 0',
        marginTop: '3rem',
        textAlign: 'center',
      }}>
        <div style={{
          maxWidth: '800px',
          margin: '0 auto',
          padding: '0 1.5rem',
        }}>
          <div style={{
            display: 'flex',
            justifyContent: 'center',
            alignItems: 'center',
            gap: '6px',
            fontSize: '0.85rem',
            color: 'var(--text-muted, var(--text-sub))',
            fontFamily: "'Inter', 'IBM Plex Sans', sans-serif",
          }}>
            <span>Built with</span>
            <span role="img" aria-label="heart" style={{ fontSize: '1rem' }}>💜</span>
            <span>by</span>
            <a 
              href="https://github.com/muhibarshad" 
              target="_blank" 
              rel="noopener noreferrer"
              style={{
                fontWeight: 600,
                background: 'var(--accent-gradient, linear-gradient(135deg, #6366F1, #EC4899))',
                WebkitBackgroundClip: 'text',
                WebkitTextFillColor: 'transparent',
                backgroundClip: 'text',
              }}
            >
              Muhib Arshad
            </a>
          </div>
          <p style={{
            fontSize: '0.75rem',
            color: 'var(--text-muted, var(--text-sub))',
            marginTop: '8px',
            opacity: 0.6,
          }}>
            Digital Garden • Knowledge Base
          </p>
        </div>
      </footer>
    </>
  )
}
