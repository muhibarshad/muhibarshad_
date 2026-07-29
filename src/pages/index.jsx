import React from 'react'
import { graphql, useStaticQuery, Link } from 'gatsby'
import { MDXRenderer } from 'gatsby-plugin-mdx'
import Layout from '../layout/layout'
import siteConfig from '../../gatsby-config'
import NoteList from '../components/note-list'
import Search from '../components/search'
import '../styles/index.css'
import { DefaultMenuStructure, MenuRoot } from '../utils/menu-structure'

export default function Home() {
  const data = useStaticQuery(graphql`
    query HomeQuery {
      homeNote: mdx(frontmatter: {slug: {eq: "home"}}) {
        body
        fields {
          title
          date
        }
        frontmatter {
          tags
        }
      }
      notes: allMdx(
        filter: { fields: { visibility: { eq: "public" } } }
        limit: 5
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
  `)

  let tagList = DefaultMenuStructure('tag-list')
  tagList.push({
    type:'page',
    item:'tags',
    title: 'All Tags →',
    liClassName: 'pill'
  })

  return data.homeNote ? (
    <Layout title={data.homeNote.fields.title} type="home">
      <div className="column is-half">
        <div className="note-area">
          <h1 className="note-title">{data.homeNote.fields.title}</h1>
          <div className="note-content">
            <MDXRenderer>{ data.homeNote.body }</MDXRenderer>
          </div>
        </div>
      </div>
    </Layout>
  ) : (
    <Layout title="Home" type="home">
      <div className="column is-half">
        {/* Hero Section */}
        <div style={{
          padding: '2.5rem 0 1.5rem 0',
          animation: 'fadeInUp 0.6s ease-out',
        }}>
          <div style={{
            display: 'inline-flex',
            alignItems: 'center',
            gap: '8px',
            background: 'var(--tag-bg)',
            border: '1px solid var(--tag-border)',
            borderRadius: '9999px',
            padding: '6px 16px',
            marginBottom: '16px',
            fontSize: '0.85rem',
            color: 'var(--tag-text)',
            fontWeight: 500,
          }}>
            <span role="img" aria-label="sparkles">✨</span>
            Digital Garden
          </div>
          
          <h1 style={{
            fontSize: 'clamp(2rem, 5vw, 3rem)',
            fontWeight: 800,
            letterSpacing: '-0.04em',
            lineHeight: 1.1,
            marginBottom: '1rem',
            background: 'var(--accent-gradient)',
            WebkitBackgroundClip: 'text',
            WebkitTextFillColor: 'transparent',
            backgroundClip: 'text',
          }}>
            {siteConfig.siteMetadata.title}
          </h1>
          
          <p className="lead" style={{
            fontSize: '1.1rem',
            lineHeight: 1.7,
            color: 'var(--text-sub)',
            maxWidth: '580px',
            marginBottom: '1.5rem',
          }}>
            {siteConfig.siteMetadata.description}
          </p>
        </div>

        {/* Tags */}
        <div className="block tag-list" style={{
          animation: 'fadeInUp 0.7s ease-out',
        }}>
          <MenuRoot menu={tagList} />
        </div>

        {/* Search */}
        <div className="block" style={{
          animation: 'fadeInUp 0.8s ease-out',
        }}>
          <Search size="medium" showExcerpt={true} />
        </div>

        {/* Recent Notes */}
        <div className="block" style={{
          animation: 'fadeInUp 0.9s ease-out',
          marginTop: '2rem',
        }}>
          <h3 style={{
            fontSize: '1.1rem',
            fontWeight: 700,
            color: 'var(--text-main)',
            marginBottom: '1rem',
            display: 'flex',
            alignItems: 'center',
            gap: '8px',
          }}>
            <span role="img" aria-label="notebook">📝</span>
            Recent Notes
          </h3>
          <NoteList notes={data.notes.edges} />
        </div>

        <div style={{
          marginTop: '1.5rem',
          animation: 'fadeInUp 1s ease-out',
        }}>
          <Link 
            to="/sitemap"
            style={{
              display: 'inline-flex',
              alignItems: 'center',
              gap: '6px',
              padding: '10px 20px',
              background: 'var(--accent-gradient)',
              color: '#fff',
              borderRadius: '10px',
              fontWeight: 600,
              fontSize: '0.9rem',
              textDecoration: 'none',
              transition: 'all 0.25s cubic-bezier(0.4, 0, 0.2, 1)',
              boxShadow: '0 4px 12px rgba(99,102,241,0.25)',
            }}
            onMouseEnter={(e) => {
              e.currentTarget.style.transform = 'translateY(-2px)'
              e.currentTarget.style.boxShadow = '0 8px 24px rgba(99,102,241,0.35)'
            }}
            onMouseLeave={(e) => {
              e.currentTarget.style.transform = 'translateY(0)'
              e.currentTarget.style.boxShadow = '0 4px 12px rgba(99,102,241,0.25)'
            }}
          >
            Browse All Notes
            <span>→</span>
          </Link>
        </div>
      </div>
    </Layout>
  )
}
