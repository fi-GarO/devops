FROM node:12-alpine
WORKDIR /app
COPY package.json yarn.lock ./
RUN yarn install --production
COPY . .
CMD ["node", "src/index.js"]

FROM grafana/grafana
EXPOSE 3000
ADD grafana.ini /etc/grafana