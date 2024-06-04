# Image Node.js
FROM node:14

# Répertoire de travail
WORKDIR /app

# Copie du package.json et du package-lock.json pour installer les dépendances
COPY package*.json ./

# Installation les dépendances
RUN npm install

# Copie le reste des fichiers de l'application
COPY . .

# Port du serveur
EXPOSE 8080

# Commande pour démarrer l'application Node.js
CMD ["node", "app.js"]