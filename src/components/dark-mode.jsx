import React from 'react'
import { ThemeToggler } from 'gatsby-plugin-dark-mode'

class DarkMode extends React.Component {
  render() {
    return (
      <ThemeToggler>
        {({ theme, toggleTheme }) => (
          <label className="theme-switcher" style={{
            display: 'inline-flex',
            alignItems: 'center',
            justifyContent: 'center',
            cursor: 'pointer',
            width: '40px',
            height: '40px',
            borderRadius: '10px',
            background: 'var(--bg-sub)',
            border: '1px solid var(--border)',
            transition: 'all 0.25s cubic-bezier(0.4, 0, 0.2, 1)',
          }}
          onMouseEnter={(e) => {
            e.currentTarget.style.borderColor = 'var(--accent-primary)'
            e.currentTarget.style.transform = 'scale(1.05)'
            e.currentTarget.style.boxShadow = '0 0 12px rgba(99,102,241,0.15)'
          }}
          onMouseLeave={(e) => {
            e.currentTarget.style.borderColor = 'var(--border)'
            e.currentTarget.style.transform = 'scale(1)'
            e.currentTarget.style.boxShadow = 'none'
          }}
          >
            <input
              type="checkbox"
              onChange={e => {
                toggleTheme(e.target.checked ? 'dark' : 'light')
              }}
              checked={theme === 'dark'}
              hidden
            />
            {theme === 'dark' ? (
              <span role="img" aria-label="moon" style={{ fontSize: '18px', lineHeight: 1 }}>
                🌙
              </span>
            ) : (
              <span role="img" aria-label="sun" style={{ fontSize: '18px', lineHeight: 1 }}>
                ☀️
              </span>
            )}
          </label>
        )}
      </ThemeToggler>
    )
  }
}

export default DarkMode
