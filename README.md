# City Tourism Ranking System

A console-based C program that manages tourism information for cities. The program reads city data from a text file, displays rankings, searches for city information, updates tourist numbers, sorts cities by yearly visitors, generates country-specific reports, and removes cities from the ranking.

## Features

- View the content of the input data file
- Load city tourism data into an array of structures
- Search for a city and display its ranking
- Display detailed information about a specific city
- Update the yearly number of tourists for a city
- Sort cities by number of yearly tourists in descending order
- Generate a text file containing the most visited cities in a selected country
- Remove a city from the ranking list
- Menu-based console interface

## Technologies Used

- C programming language
- File handling
- Arrays and structures
- String manipulation
- Sorting algorithm
- Console input/output

## Project Structure

```text
city-tourism-ranking-c/
├── tourism_ranking.c
├── data.txt
└── README.md
```

## Required Data File

The program expects a file named `data.txt` in the same folder as the C file.

Each city should be stored using this format:

```text
City Name
Country Name
Number of Yearly Tourists
Most Visited Place
Separator Line
```

Example:

```text
Paris
France
19000000
Eiffel Tower
--------------------
```

## How to Compile

Use `gcc` to compile the program:

```bash
gcc tourism_ranking.c -o tourism_ranking
```

## How to Run

After compiling, run the executable:

```bash
./tourism_ranking
```

On Windows, you can run:

```bash
tourism_ranking.exe
```

## Menu Options

When the program starts, it displays a menu with the following options:

1. View file content
2. Load file data
3. Get the ranking of a city
4. Get information about a city
5. Update the number of yearly tourists of a city
6. Find the most visited cities in a country
7. Remove a city from the ranking
8. Quit

## How It Works

The program stores each city inside a `city_info` structure. This structure contains the city name, country name, yearly number of tourists, most visited place, and a separator line from the file.

After loading the file data, the user can search for a city, update its tourist count, sort the cities again based on yearly visitors, or generate a country-specific output file. The sorting is done in descending order so that cities with the highest number of tourists appear first.

## Main Functions

- `display()` displays the content of the data file and counts the number of cities.
- `load_file_data()` loads city data from `data.txt` into an array.
- `city_ranking()` returns the ranking position of a city.
- `get_city_info()` searches for a city and returns its index.
- `updateTourist_N()` updates the yearly tourist number of a city.
- `sort()` sorts cities by yearly tourists in descending order.
- `country_info()` creates a country-specific text file.
- `remove_city()` removes a city from the array by shifting the remaining elements.

## Notes

- The program must load the data before using search, update, or remove options.
- The `data.txt` file must follow the expected 5-line format for each city.
- The generated country file will be named using the country name, for example `France.txt`.
- The project is intended as a basic data structures and file handling project in C.

## Possible Improvements

- Save updated rankings back into `data.txt` after modifying or removing a city
- Improve input validation
- Make city and country search case-insensitive
- Update the city count correctly after removing a city
- Add dynamic memory allocation instead of using a fixed-size array
- Improve the formatting of generated country files

## Author

Created by Yassine Benomar and Adnane Bakkou.
