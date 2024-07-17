# BookShop-Inventory-Management


## Table of contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [API References](#api-references)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)


## Introduction
Descript what your project does, its purpose, andn the problems it aims to solve.
An inventory system for a bookshop management system using OOP while learning other frameworks/softwares.


## Features
Feature 1:

Feature 2:

Feature 3:

## Requirements
- C++ compiler(e.g. g++, std=17)
- CMake
- MySQL server
- MySQL Connector/C++
- Any other dependencies

## Installation
Instructions on how to install and set up the project
### On Ubuntu

### Window/WSL

## Usage
How to run and use the program



## Configuration
```
{
  "database": {
    "host": "127.0.0.1",
    "port": 3306,
    "user": "yourusername",
    "password": "yourpassword",
    "dbname": "yourdatabase"
  }
}
```

## API References
Detail the REST API endpoints
ex: 
- GET/api/hello
    - Description: Returns a greeting message
    - Response: '{ "message": "Hello, World!" }'

## Database Setup
Instructions on setting up the MySQL database
```
    # Log into MySQL
    mysql -u root -p

    # Create a new database
    CREATE DATABASE yourdatabase;

    # Create a new user and grant privileges
    CREATE USER 'yourusername'@'localhost' IDENTIFIED BY 'yourpassword';
    GRANT ALL PRIVILEGES ON yourdatabase.* TO 'yourusername'@'localhost';

    # Use the new database
    USE yourdatabase;

    # Create tables
    CREATE TABLE your_table (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL
    );
```
## Contributing
Guidlines for contributing to this project
1. Fork
2. Create new branch
3. Commit
4. Push to branch
5. Open a pull request

## License
This project is licensed under the MIT License - see the [LICENSE] file for details.

## Contact
Email: ntt.tram.tran@gmail.com

GitHub: NttTram

