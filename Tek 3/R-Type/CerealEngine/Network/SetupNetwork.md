## Setup Network

### Install dependencies

```bash
sudo apt-get install sqlite3
sudo apt-get install libsqlite3-dev
sudo apt install libasio-dev
```

### Compile and start the server
- Compile
```bash
make all / re
./rtype_server <TCP_PORT> <UDP_PORT>
```

- Example
```bash
./rtype_server 50000 50001
```

### Compile and start the client

- Compile
```bash
make re
```
- Run
```bash
./n-ty.pe
```


### Manage Database
- Export Database as SQL Dump
```bash
sqlite3 database.db .dump > output.sql
```
- Export Database as CSV
```sqlite
sqlite3 -header -csv database.db "SELECT * FROM RTYPE;" > output.csv
```
