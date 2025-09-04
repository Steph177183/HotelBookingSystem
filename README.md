HOTEL BOOKING SYSTEM
  A simple **C++ Hotel Booking System** that allows users to view hotel information, check available rooms, book a room, cancel a booking, 
  and view booking details. The system also handles error checking and saves records using file handling.

FEATURES:
1. View Hotel Information  
   - Displays hotel details such as address, email, and contact number.  
   - Shows 5 room types: Single Room, Double Room, Twin Room, Suite Room, and Deluxe Room.  
   - Includes check-in/check-out schedule and hotel amenities.
     
<img width="622" height="578" alt="hotel_info" src="https://github.com/user-attachments/assets/7a3c7efa-046b-4024-b5b3-79b95830a1b9" />


2. View Available Rooms 
   - Displays all reserved and available rooms per room type.
     
   <img width="400" height="283" alt="view_available_room" src="https://github.com/user-attachments/assets/50b2ab86-b9bc-48af-a153-f0b8f7de5eaf" />

3.  Book a Room  
     - Requires users to fill in booking details:  
     - Number of adults  
     - Number of kids  
     - Guest name  
     - Contact number  
     - Email  
     - Check-in date  
     - Number of nights  
     - Payment amount  
   - If booking is successful, a room number will be assigned.  
   
<img width="624" height="842" alt="bookRoom" src="https://github.com/user-attachments/assets/72970154-01e7-4ac5-9913-cd10164122d7" />


4. Cancel Booking
   - Users can cancel their booking and receive a refund.  
   - The room status will be updated to available.  

<img width="479" height="682" alt="cancelBooking" src="https://github.com/user-attachments/assets/dba42493-43b2-4276-88fc-ee6ecd915f43" />


5. View Booking Details
   - Display all the records.
<img width="1159" height="371" alt="viewBookingDetails" src="https://github.com/user-attachments/assets/6e72b5a7-7807-438b-a369-e2e041c214ba" />

6. Exit - End of program

ERROR HANDLING
Book a Room
  - Users must select a valid room type.  
  - All required form fields must be completed.  
  - If the room type does not match the number of adults and children entered, the program notifies the user.  
  - If payment is less than the required total, the program shows:  
    ```
    Invalid amount
    ```  
    and requires the correct payment.  
  - If any required fields are left blank, the booking is unsuccessful.
    
Cancel Booking
If the user attempts to cancel a room that has not been reserved, the program displays:  
    ```
    No room found to be cancelled

FILE HANDLING
- `bookings.txt` → Stores booking details.  
- `receipts.txt` → Stores payment information.  
- `cancellations.txt` → Stores cancelled booking records.
