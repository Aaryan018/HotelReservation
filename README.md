# HotelReservation

A C++ hotel reservation system that reads customer data from a file and assigns rooms based on bed requirements. The hotel has 100 single-bed rooms, 50 double-bed rooms, and 30 triple-bed rooms (180 rooms total). The system uses a custom templated singly-linked list (`SLL`) to manage room allocations.

## Features

- **Smart room allocation** — Assigns the best combination of rooms to minimize wasted beds. If a customer needs more beds than the largest room provides, multiple rooms are assigned.
- **Date-aware booking** — Tracks check-in and check-out dates, automatically freeing rooms when customers check out.
- **Month-aware calendar** — Correctly handles months with 28, 30, and 31 days.
- **Custom data structures** — Implements a generic singly-linked list (`SLL`) with iterator support, used to manage rooms per bed count.
- **Batch processing** — Reads customer requests from `Customers.txt` and processes them sequentially.

## Tech Stack

- **Language:** C++ (C++14)
- **Build System:** Make
- **Data Structures:** Templated singly-linked list with iterators

## Project Structure

```
HotelReservation/
├── Booking.cpp       # Main program: reads Customers.txt, books rooms
├── Customer.h/cpp    # Customer class: ID, check-in/out dates, bed requirements
├── Room.h/cpp        # Room class: customer assignment, bed count
├── SLL.h             # Generic singly-linked list with Iterator (template)
├── Customers.txt     # Input: date, customer ID, beds requested, duration
├── Makefile          # Build configuration
└── README.md
```

## How to Run

### Build

```bash
make
```

This compiles `Booking.cpp`, `Room.cpp`, and `Customer.cpp` into an executable called `test`.

### Run

```bash
./test
```

The program reads customer data from `Customers.txt` and outputs the number of customers successfully serviced.

### Clean

```bash
make remove   # Linux/macOS
make clean    # Windows
```

## Input Format (`Customers.txt`)

Each line represents one customer:
```
<day>/<month>/<year>, <customerID>, <bedsRequired>, <durationInDays>
```

Example:
```
1/1/2018, 843A62A1MR, 3, 7
```

## Hotel Capacity

| Room Type | Beds | Quantity |
|-----------|------|----------|
| Type 1    | 1    | 100      |
| Type 2    | 2    | 50       |
| Type 3    | 3    | 30       |

Total bed capacity: 290 beds across 180 rooms.

## Author

**Aaryan Gupta**
