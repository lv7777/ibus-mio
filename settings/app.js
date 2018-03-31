const electron = require('electron')
// const app = electron.app
console.log('eslint test')
const BrowserWindow = electron.BrowserWindow

const path = require('path')
const url = require('url')

electron.app.on('ready', () => {
  var win = new BrowserWindow({ width: 500,
    height: 500,
    resizable: true,
    // dirty hack for electron jquery not loaded
    webPreferences: {
      nodeIntegration: false
    }
  })
  // console.log(electron.shell)
  win.loadURL(url.format({
    pathname: path.join(__dirname, 'index.html'),
    protocol: 'file:',
    slashes: true
  }))
})
