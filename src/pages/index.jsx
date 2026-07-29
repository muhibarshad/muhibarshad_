import React, { useMemo } from 'react'
import { graphql, useStaticQuery, Link, navigate } from 'gatsby'
import { MDXRenderer } from 'gatsby-plugin-mdx'
import Graph from 'react-graph-vis'
import Layout from '../layout/layout'
import siteConfig from '../../gatsby-config'
import NoteList from '../components/note-list'
import Search from '../components/search'
import '../styles/index.css'
import '../styles/graph.css'
import { DefaultMenuStructure, MenuRoot } from '../utils/menu-structure'
const _ = require('lodash')

function findReferences(content) {
  if (!content) return []
  const linkRegex = /\[\[([^\]\|]+)(\|.+)?\]\]/g
  const links = [...content.matchAll(linkRegex)]
  const matchedNotes = links.map(lnk => lnk[1])
  return _.uniqWith(matchedNotes, (a, b) => a.toLowerCase() === b.toLowerCase())
}

function getPreExistingTitle(title, allNoteTitles) {
  const key = Object.keys(allNoteTitles).find(k => k.toLowerCase() === title.toLowerCase())
  return key || title
}

export default function Home() {
  const data = useStaticQuery(graphql`
    query HomeQuery {
      homeNote: mdx(frontmatter: {slug: {eq: "home"}}) {
        body
        fields { title date }
        frontmatter { tags }
      }
      notes: allMdx(
        filter: { fields: { visibility: { eq: "public" } } }
        sort: { fields: fields___date, order: DESC }
      ) {
        edges {
          node {
            excerpt
            rawBody
            fields { slug title date }
            frontmatter { tags }
          }
        }
      }
    }
  `)

  // Extract recent 5 notes
  const recentNotes = data.notes.edges.slice(0, 5)

  // Memoize graph generation to prevent re-renders
  const { graph, graphOptions, events } = useMemo(() => {
    let refersTo = {}
    let allNoteTitles = {}
    
    // Map existing titles for case-insensitive lookup
    data.notes.edges.forEach(({ node }) => {
      allNoteTitles[node.fields.title] = node
    })

    // Build references
    data.notes.edges.forEach(({ node }) => {
      const title = node.fields.title
      const outgoingLinks = findReferences(node.rawBody)
      refersTo[title] = outgoingLinks.map(outTitle => getPreExistingTitle(outTitle, allNoteTitles))
    })

    const g = {
      nodes: Object.keys(refersTo).map((title) => ({ id: title, label: title })),
      edges: []
    }

    Object.keys(refersTo).forEach(noteTitle => {
      const refNoteTitles = refersTo[noteTitle]
      refNoteTitles.forEach(refNoteTitle => {
        if (allNoteTitles[refNoteTitle]) {
          g.edges.push({ from: noteTitle, to: refNoteTitle })
        }
      })
    })

    const options = {
      nodes: {
        shape: "dot",
        size: 8,
        font: { color: "#888" },
        color: {
          border: "#aaa",
          background: "#aaa",
          highlight: { border: "#666", background: "#888" }
        }
      },
      edges: {
        color: { border: "#ddd" },
        arrows: "middle",
      },
      height: "400px"
    }

    const evts = {
      select: function(event) {
        const { nodes } = event
        if (!nodes || nodes.length === 0) return
        const nodeId = nodes[0].toLowerCase()
        const targetNode = data.notes.edges.find(obj => obj.node.fields.title.toLowerCase() === nodeId)
        if (targetNode) {
          navigate(targetNode.node.fields.slug)
        }
      }
    }

    return { graph: g, graphOptions: options, events: evts }
  }, [data.notes.edges])

  let tagList = DefaultMenuStructure('tag-list')
  tagList.push({
    type:'page',
    item:'tags',
    title: 'All Tags',
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
        
        {/* Intro */}
        <div style={{ padding: '2rem 0 1rem 0' }}>
          <h1 style={{ marginBottom: '1rem' }}>
            {siteConfig.siteMetadata.title}
          </h1>
          <p className="lead" style={{ maxWidth: '600px' }}>
            {siteConfig.siteMetadata.description}
          </p>
        </div>

        {/* Search */}
        <div className="block mt-4">
          <Search size="medium" showExcerpt={true} />
        </div>

        {/* Tags */}
        <div className="block tag-list mt-4">
          <h3 style={{ marginBottom: '1rem', borderBottom: '1px solid var(--border)', paddingBottom: '0.5rem' }}>
            Topics
          </h3>
          <MenuRoot menu={tagList} />
        </div>

        {/* Recent Notes */}
        <div className="block mt-4">
          <h3 style={{ marginBottom: '1rem', borderBottom: '1px solid var(--border)', paddingBottom: '0.5rem' }}>
            Recent Notes
          </h3>
          <NoteList notes={recentNotes} />
        </div>

        <div style={{ marginTop: '2rem', marginBottom: '3rem' }}>
          <Link to="/sitemap" style={{ fontWeight: 600 }}>
            View All Notes →
          </Link>
        </div>

        {/* Global Knowledge Map */}
        <div className="block mt-4">
          <h3 style={{ marginBottom: '1rem', borderBottom: '1px solid var(--border)', paddingBottom: '0.5rem' }}>
            Knowledge Map
          </h3>
          <div id="graph-container" style={{ borderRadius: '8px', overflow: 'hidden' }}>
            <Graph graph={graph} options={graphOptions} events={events} />
          </div>
        </div>

      </div>
    </Layout>
  )
}
