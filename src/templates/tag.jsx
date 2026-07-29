import React from 'react'
import { graphql, Link } from 'gatsby'
import Layout from '../layout/layout'
import NoteList from '../components/note-list'
import Pager from '../components/pager'

export default function Tag({ pageContext, data }) {
  const { tag } = pageContext
  const { edges, totalCount } = data.allMdx
  const heading = `${totalCount} note${totalCount === 1 ? '' : 's'}`

  return (
    <Layout title={`#${tag}`} type="tag">
      <div className="column is-three-fifths">
        <div style={{
            padding: '2rem 0',
            borderBottom: '1px solid var(--border)',
            marginBottom: '2rem',
            animation: 'fadeInUp 0.5s ease-out'
        }}>
            <div style={{
                display: 'inline-block',
                background: 'var(--tag-bg)',
                color: 'var(--tag-text)',
                padding: '4px 12px',
                borderRadius: '9999px',
                fontSize: '0.85rem',
                fontWeight: 600,
                marginBottom: '1rem',
                border: '1px solid var(--tag-border)'
            }}>
                Tag Collection
            </div>
            <h1 style={{ marginBottom: '0.5rem', fontWeight: 800 }}>
                #{tag}
            </h1>
            <p className="lead" style={{ color: 'var(--text-sub)' }}>
                {heading} tagged with <strong style={{ color: 'var(--accent-primary)' }}>{tag}</strong>
            </p>
        </div>

        <div style={{ animation: 'fadeInUp 0.6s ease-out' }}>
            <NoteList notes={edges} />
        </div>

        <div style={{ animation: 'fadeInUp 0.7s ease-out' }}>
            <Pager context={pageContext} />
        </div>

        <div style={{ marginTop: '2rem', textAlign: 'center', animation: 'fadeInUp 0.8s ease-out' }}>
          <Link 
            to="/tags"
            style={{
              display: 'inline-flex',
              alignItems: 'center',
              gap: '6px',
              padding: '10px 20px',
              background: 'var(--bg-card)',
              border: '1px solid var(--border)',
              color: 'var(--text-main)',
              borderRadius: '10px',
              fontWeight: 500,
              fontSize: '0.9rem',
              textDecoration: 'none',
              transition: 'all 0.25s ease',
            }}
            onMouseEnter={(e) => {
              e.currentTarget.style.borderColor = 'var(--accent-primary)'
              e.currentTarget.style.transform = 'translateY(-2px)'
              e.currentTarget.style.boxShadow = 'var(--shadow-sm)'
            }}
            onMouseLeave={(e) => {
              e.currentTarget.style.borderColor = 'var(--border)'
              e.currentTarget.style.transform = 'translateY(0)'
              e.currentTarget.style.boxShadow = 'none'
            }}
          >
            ← View All Tags
          </Link>
        </div>
      </div>
    </Layout>
  )
}

export const query = graphql`
  query($tag: String, $skip: Int!, $limit: Int!) {
    allMdx(
      skip: $skip
      limit: $limit
      sort: { fields: fields___date, order: DESC }
      filter: {
        frontmatter: { tags: { in: [$tag] } }
        fields: { visibility: { eq: "public" } }
      }
    ) {
      totalCount
      edges {
        node {
          excerpt
          fields {
            slug
            title
            date
          }
          frontmatter {
            tags
          }
        }
      }
    }
  }
`
