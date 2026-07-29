import React from 'react'
import { Link } from 'gatsby'
import { Helmet } from 'react-helmet'
import { startCase, camelCase } from 'lodash'
import siteConfig from '../../gatsby-config'
import Search from '../components/search'
import {
  DefaultMenuStructure,
  MenuItemPage,
  MenuItemText,
  MenuItemNote,
  MenuItemTag,
  MenuItemExternalLink,
} from '../utils/menu-structure'

import DarkMode from '../components/dark-mode'

export default function Header({ title, type, description }) {
  const menu = DefaultMenuStructure('header')
  const pageTitle =
    (siteConfig.siteMetadata.title || 'muhibarshad') +
    (title ? ` : ${title}` : '')

  const handleHamburgerMenuClick = e => {
    const target_id = e.currentTarget.getAttribute('data-target')
    const target = document.getElementById(target_id)

    // Toggle the "is-active" class on both the "navbar-burger" and the "navbar-menu"
    e.currentTarget.classList.toggle('is-active')
    target.classList.toggle('is-active')
  }

  return (
    <>
      <Helmet>
        <meta content="width=device-width, initial-scale=1" name="viewport" />
        <meta content={siteConfig.siteMetadata.title} property="og:site_name" />
        <link rel="preconnect" href="https://fonts.googleapis.com" />
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
        <link
          href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700;800;900&family=JetBrains+Mono:wght@400;500;600&display=swap"
          rel="stylesheet"
        />
        <meta content={title ? title : pageTitle} property="og:title" />
        {description ? (
          <meta content={description} property="og:description" />
        ) : null}

        {type === 'note' ? (
          <meta content="article" property="og:type"></meta>
        ) : (
          <meta content="website" property="og:type"></meta>
        )}

        <title>{pageTitle}</title>

        <link
          rel="icon"
          href="/img/favicon.svg"
          type="image/svg+xml"
          sizes="16x16"
        />
      </Helmet>

      <nav
        className="navbar is-transparent"
        role="navigation"
        aria-label="main navigation"
      >
        <div className="navbar-brand">
          <Link className="navbar-item" to="/">
            <img
              src="/img/falcon-1.png"
              style={{ maxHeight: '42px', width: 'auto', borderRadius: '8px' }}
              alt="Logo"
            />
            <h4>{siteConfig.siteMetadata.title || 'muhibarshad'}</h4>
          </Link>
          <div className="navbar-item navbar-dark-mode__mobile is-hidden-tablet">
            <DarkMode />
          </div>
          <button
            className="navbar-burger button-link"
            aria-label="menu"
            aria-expanded="false"
            data-target="navbar-main"
            onClick={handleHamburgerMenuClick}
          >
            <span aria-hidden="true"></span>
            <span aria-hidden="true"></span>
            <span aria-hidden="true"></span>
          </button>
        </div>

        <div className="navbar-menu" id="navbar-main">
          <div className="navbar-start">
            {menu.map((item, index) => {
              return item.menu ? (
                <span key={index} className="navbar-item dropdown">
                  <Link
                    to={`/${item.item}`}
                    id={`dropdown-${item.item}`}
                    className="dropdown-toggle"
                    data-toggle="dropdown"
                    aria-haspopup="true"
                    aria-expanded="false"
                  >
                    {item.title ? item.title : startCase(camelCase(item.item))}
                  </Link>
                  <div
                    className="dropdown-menu"
                    aria-labelledby={`dropdown-${item.item}`}
                  >
                    {item.menu.map((subItem, subIndex) => {
                      return (
                        <MenuItem
                          className="navbar-item"
                          item={subItem}
                          key={subIndex}
                        />
                      )
                    })}
                  </div>
                </span>
              ) : (
                <MenuItem className="navbar-item" item={item} key={index} />
              )
            })}
          </div>
          <div className="navbar-end is-hidden-mobile">
            <div className="navbar-item">
              <Search size="small" showExcerpt={false} />
            </div>
            <div className="navbar-item">
              <DarkMode />
            </div>
          </div>
        </div>
      </nav>
    </>
  )
}

function MenuItem({ item, className }) {
  let itm
  if (item.type === 'page')
    itm = <MenuItemPage item={item} className={className} />
  else if (item.type === 'tag')
    itm = <MenuItemTag item={item} className={className} />
  else if (item.type === 'note')
    itm = <MenuItemNote item={item} className={className} />
  else if (item.type === 'link')
    itm = <MenuItemExternalLink item={item} className={className} />
  else if (item.type === 'text')
    itm = <MenuItemText item={item} className={className} />

  return itm
}
