#include "mongo.hpp"

int main()
{
    // Crea una instancia de la clase 'mongocxx::instance'. Esta instancia se debe crear antes de realizar cualquier
    // operación con la base de datos MongoDB.
    mongocxx::instance instance{};

    try
    {
        // Crea una conexión a la base de datos MongoDB. Cambia la URI para que coincida con tu configuración.
        mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};

        // Accede a la base de datos "test" y la colección "mycollection".
        mongocxx::database db = client["test"];
        mongocxx::collection coll = db["mycollection"];

        // Ahora puedes realizar operaciones con la colección, como insertar documentos, buscar, etc.
        // Por ejemplo, aquí se inserta un documento en la colección.
        coll.insert_one(document{} << "name"
                                   << "John"
                                   << "age" << 30 << finalize);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
