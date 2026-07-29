import React from 'react'
import { Link, graphql } from 'gatsby'
import Layout from '../layout/layout'
import NoteList from '../components/note-list'
import Pager from '../components/pager'

export default function Sitemap({ pageContext, data }) {
  return (
    <Layout title="Sitemap" type="page">
      <div className="column is-three-fifths">
        <div style={{
            padding: '2rem 0',
            borderBottom: '1px solid var(--border)',
            marginBottom: '2rem',
            animation: 'fadeInUp 0.5s ease-out'
        }}>
            <h1 style={{ marginBottom: '0.5rem', fontWeight: 800 }}>
                <span role="img" aria-label="map">🗺️</span> All Notes
            </h1>
            <p className="lead" style={{ color: 'var(--text-sub)' }}>
                A complete overview of everything in this digital garden.
            </p>
        </div>

        <div style={{ animation: 'fadeInUp 0.6s ease-out' }}>
            <NoteList notes={data.notes.edges} />
        </div>

        <div style={{ animation: 'fadeInUp 0.7s ease-out' }}>
            <Pager context={pageContext} />
        </div>
      </div>
    </Layout>
  )
}

export const query = graphql`
  query($skip: Int!, $limit: Int!) {
    notes: allMdx(
      skip: $skip
      limit: $limit
      filter: { fields: { visibility: { eq: "public" } } }
      sort: { fields: fields___date, order: DESC }
    ) {
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
