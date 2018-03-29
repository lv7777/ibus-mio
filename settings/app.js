const electron = require('electron')
// const app = electron.app
console.log('eslint test')
const BrowserWindow = electron.BrowserWindow

electron.app.on('ready', () => {
    var a = new BrowserWindow({ width:500, height:500, resizable: true,
        // dirty hack for electron jquery not loaded
        webPreferences: {
            nodeIntegration: false
        }
    })
    console.log(electron.shell)
    a.loadURL('file://' + __dirname + '/index.html')
})
