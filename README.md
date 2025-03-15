# 🎉 Auction System

---

## 🌟 Project Overview

The **Auction System** is a robust and user-friendly C++ application designed to streamline online auctions. It empowers users to manage auction items, place bids, handle member profiles, and provide ratings and reviews. With an intuitive interface, the system supports seamless interactions for guests, registered members, and administrators alike.

### ✨ Key Features
- **🔑 User Authentication**: Secure login, signup, and role-based access control (Admin, Guest, Member).
- **🛍️ Item Management**: Effortlessly add, update, and remove auction items.
- **💸 Bidding System**: Place bids on available items with real-time updates.
- **⭐ Ratings and Reviews**: Members can rate and review items to ensure transparency.
- **📂 File Management**: Persist data using CSV files for items, members, and reviews.

---

## 👨‍💻 Developer

This project was meticulously crafted by:

- **Nguyen Minh Khai** - **s3995223**

---

## 🚀 How to Run

Follow the steps below to set up and run the Auction System on your local machine:

1. **Clone the Repository**  
   Download the project files by cloning the GitHub repository:  
   ```bash
   git clone https://github.com/khainguyen04/Aunction-System.git
   cd auction-system

2. **Compile the Project**  
    g++ -std=c++11 main.cpp \
    application/*.cpp \
    controllers/*.cpp \
    models/*.cpp \
    utils/*.cpp \
    views/*.cpp \
    -o main

3. **Run the Executable**  
    ./main
