import React from 'react'
import { graphql, Link } from 'gatsby'
import Layout from '../layout/layout'
import kebabCase from 'lodash/kebabCase'
import '../styles/tag-list.css'

export default function TagList({ data }) {
  let tagList = data.allMdx.group
  tagList.sort((a, b) => {
    return b.totalCount - a.totalCount
  })

  return (
    <Layout title="All Tags" type="tag">
      <div className="column is-three-fifths">
        <div style={{
            padding: '2rem 0',
            borderBottom: '1px solid var(--border)',
            marginBottom: '2rem',
            animation: 'fadeInUp 0.5s ease-out'
        }}>
            <h1 style={{ marginBottom: '0.5rem', fontWeight: 800 }}>
                <span role="img" aria-label="tags">🏷️</span> Topics & Tags
            </h1>
            <p className="lead" style={{ color: 'var(--text-sub)' }}>
                Explore notes organized by categories and interests.
            </p>
        </div>

        <ul style={{
            display: 'flex',
            flexWrap: 'wrap',
            gap: '8px',
            padding: 0,
            animation: 'fadeInUp 0.6s ease-out'
        }}>
          {tagList.map((tag, index) => (
            <li key={tag.fieldValue} className="tag-name" style={{
                animationDelay: `${index * 0.05}s`,
                animationFillMode: 'both'
            }}>
              <Link to={`/tags/${kebabCase(tag.fieldValue)}/`}>
                #{tag.fieldValue} <span className="badge">{tag.totalCount}</span>
              </Link>
            </li>
          ))}
        </ul>
      </div>
    </Layout>
  )
}

export const query = graphql`
  query {
    allMdx(limit: 2000) {
      group(field: frontmatter___tags) {
        fieldValue
        totalCount
      }
    }
  }
`
