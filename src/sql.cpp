#include <mysql/mysql.h>
#include <iostream>


int main(){
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "127.0.0.1";
    const char *user = "root";
    const char *password = "book_Keeping2024";
    const char *database = "book_inventory";
    const char *table = "books";


    conn = mysql_init(NULL);
    if(conn == NULL){
        std::cerr << "mysql_init() failed\n";
        return EXIT_FAILURE;
    }
    // Connect to SQL
    if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)){
        std::cerr << "mysql_real_connect() failed\n";
        return EXIT_FAILURE;
    }

    // Send SQL query
    if(mysql_query(conn, "SELECT * FROM books")){
        std::cerr << "SELECT * FROM test_table failed. "
                  << mysql_error(conn) << "\n";

        return EXIT_FAILURE; 
    }

    res = mysql_store_result(conn);

    if(res == NULL){
        std::cerr << "mysql_store_result() failed. "
                  << mysql_error(conn) << "\n";
        return EXIT_FAILURE;
    }

    int num_fields = mysql_num_fields(res);

    while((row = mysql_fetch_row(res))){
        for(int i = 0; i < num_fields; i++){
            // std::cout << "row: " << row[i] << std::endl;
            std::cout << (row[i] ? row[i] : "NULL") << " ";

        }
        std::cout << std::endl;
    }

    //Close connection
    mysql_free_result(res);
    mysql_close(conn);

    return EXIT_SUCCESS;

}