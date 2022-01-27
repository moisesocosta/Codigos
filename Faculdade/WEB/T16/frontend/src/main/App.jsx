import Logo from '../components/template/Logo'
import Nav from '../components/template/Nav'
import Home from '../components/template/Main'
import Footer from '../components/template/Footer'
import 'bootstrap/dist/css/bootstrap.min.css'
import 'font-awesome/css/font-awesome.min.css'
import './App.css'

export default props =>
    <div className="app">
        <Logo />
        <Nav />
        <Home />
        <Footer />
    </div>