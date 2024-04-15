/* global use, db */
// MongoDB Playground
// Use Ctrl+Space inside a snippet or a string literal to trigger completions.

const database = 'prueba';
const collectionName = 'users';

// Create a new database.
use(database);

const collection = db.getCollection(collectionName);

// Insert a new document.

const users = [
    { username: 'user1', email: 'user1@gmail.com', age: 20 },
    { username: 'user2', email: 'user2@gmail.com', age: 25 },
    { username: 'user3', email: 'user3@gmail.com', age: 30 },
];

collection.insertMany(users);

// Find all documents in the collection.
const result = collection.find();