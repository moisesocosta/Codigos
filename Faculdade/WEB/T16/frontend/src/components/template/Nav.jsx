import './Nav.css'
import React from 'react'

export default props => 
    <aside className="menu-area">
        <nav className="menu">
            <a href="#/">
                <i className="fa fa-home"/>Inicio
            </a>
            <a href="#/users">
            <i className="fa fa-users"/>Usuarios
            </a>
        </nav>
    </aside>