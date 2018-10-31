import React from 'react';
import { render } from 'react-dom';
import 'react-hot-loader';
import './components/App/App.bs';

import 'bulma/css/bulma.css';
import './base.styl';

const renderApp = () => {
  const App = require('./components/App/App.bs').default;
  render(<App />, document.getElementById('root'));
};

renderApp();

if (module.hot) {
  module.hot.accept(renderApp);
}
