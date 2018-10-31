const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.resolve(__dirname, 'build/');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './src/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    publicPath: './',
    filename: 'Index.js',
  },
  // plugins: [
  //   new HtmlWebpackPlugin({
  //     template: 'src/index.html',
  //     inject: 'body',
  //   }),
  // ],
  module: {
    rules: [
      {
        test: /\.css$/,
        use: ['style-loader', 'css-loader'],
      },
    ],
  },
  watch: true,
  watchOptions: {
    ignored: /node_modules/,
  },
  devServer: {
    hot: true,
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true,
  },
};
