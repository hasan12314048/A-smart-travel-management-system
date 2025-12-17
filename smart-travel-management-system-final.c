#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[50], nid[20], phone[20], email[50], address[100];
char spouse[50], family[100], username[20], password[20];
int age;

void pause() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void clearScreen() {
    system("cls");
}

void signup() {
    FILE *fp = fopen("user.txt", "w");
    if (fp == NULL) {
        printf("❌ Could not open file.\n");
        return;
    }

    clearScreen();
    printf("📝 Sign Up (Create Your Travel Account)\n\n");

    printf("Name: "); gets(name);
    printf("Age: "); scanf("%d", &age); getchar();
    printf("NID: "); gets(nid);
    printf("Phone: "); gets(phone);
    printf("Email: "); gets(email);
    printf("Address: "); gets(address);
    printf("Spouse: "); gets(spouse);
    printf("Family: "); gets(family);
    printf("Username: "); gets(username);
    printf("Password: "); gets(password);

    fprintf(fp, "%s\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
            name, age, nid, phone, email, address, spouse, family, username, password);

    fclose(fp);

    printf("\n✅ Sign-up successful!\n");
    pause();
}

int login() {
    FILE *fp = fopen("user.txt", "r");
    if (fp == NULL) {
        printf("❌ No account found. Please sign up first.\n");
        return 0;
    }

    char u[20], p[20];
    char savedName[50], savedNID[20], savedPhone[20], savedEmail[50], savedAddress[100];
    char savedSpouse[50], savedFamily[100], savedUsername[20], savedPassword[20];
    int savedAge;

    fscanf(fp, "%[^\n]\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",
           savedName, &savedAge, savedNID, savedPhone, savedEmail, savedAddress,
           savedSpouse, savedFamily, savedUsername, savedPassword);

    fclose(fp);

    clearScreen();
    printf("🔐 Login\n");
    printf("Username: "); gets(u);
    printf("Password: "); gets(p);

    if (strcmp(u, savedUsername) == 0 && strcmp(p, savedPassword) == 0) {
        strcpy(name, savedName);
        age = savedAge;
        strcpy(nid, savedNID);
        strcpy(phone, savedPhone);
        strcpy(email, savedEmail);
        strcpy(address, savedAddress);
        strcpy(spouse, savedSpouse);
        strcpy(family, savedFamily);
        strcpy(username, savedUsername);
        strcpy(password, savedPassword);
        return 1;
    }

    return 0;
}

void showAccount() {
    clearScreen();
    printf("👤 Account Information\n");
    printf("----------------------\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("NID: %s\n", nid);
    printf("Phone: %s\n", phone);
    printf("Email: %s\n", email);
    printf("Address: %s\n", address);
    printf("Spouse: %s\n", spouse);
    printf("Family: %s\n", family);
    printf("Username: %s\n", username);
    pause();
}

void airTravel() {
    int from,to,numtravelers,triptype,airline,classs,numcity=8;
    char fromcity[20],tocity[20],departdate[20],returndate[20];
    char *city[]= {"Barishal","Chittagong","Dhaka","Khulna","Mymensingh","Rajshahi","Rangpur","Sylhet"};

    clearScreen();
    printf("-----AIR TRAVEL-----\n\n\n");

    do {
        printf("Choose Departure City :\n");
        for(int i=1; i<=numcity; i++) {
            printf("%d. %s\n",i,city[i-1]);
        }
        printf("Enter Your Choice (1-8):");
        scanf("%d",&from);

        if( from<1 || from>8 ) {
            printf("\nInvalid choice.Please try again.\n");
        }
    } while( from<1 || from>8 );
    sprintf(fromcity,"%s",city[from-1]);

    do {
        printf("\nChoose Destination City :\n");
        for(int i=1; i<=numcity; i++) {
            if(i!=from) {
                printf("%d. %s\n",i,city[i-1]);
            }
        }
        printf("Enter Your Choice (1-8):");
        scanf("%d",&to);

        if( to<1 || to>8 || to==from ) {
            printf("\nInvalid choice.Please try again.\n");
        }
    } while( to<1 || to>8 || to==from );
    sprintf(tocity,"%s",city[to-1]);

    printf("\nOne-way Trip or Both-way\n");
    printf("1. One-way\n2. Both-way\n");
    do {
        printf("\nEnter your choice :");
        scanf("%d",&triptype);
        if(triptype<1 || triptype>2) {
            printf("\nInvalid choice.Please try again.\n");
        }
    } while(triptype<1 || triptype>2);

    printf("\nEnter Departure Date (dd-mm-yyyy):");
    getchar();
    gets(departdate);

    if(triptype==2) {
        printf("\nEnter Return Date (dd-mm-yyyy):");
        gets(returndate);
    }

    do {
        printf("\nAvailable Airlines:\n");
        printf("1. Biman Bangladesh Airlines (8:00 AM)\n");
        printf("2. US-Bangla Airlines (12:30 PM)\n");
        printf("3. Novoair (5:45 PM)\n");
        printf("Enter your choice :");
        scanf("%d",&airline);
        if(airline<1 || airline>3) {
            printf("\nInvalid choice.Please try again.\n");
        }
    } while(airline<1 || airline>3);

    do {
        printf("\nAvailable Classes:\n");
        printf("1. Economy (Price:5000tk)\n");
        printf("2. Business (Price:7500tk)\n");
        printf("3. First Class (Price:10000tk)\n");
        printf("Enter your choice :");
        scanf("%d",&classs);
        if(classs<1 || classs>3) {
            printf("Invalid choice.Please try again.\n");
        }
    } while(classs<1 || classs>3);

    printf("\nEnter the number of travelers :");
    scanf("%d",&numtravelers);

    printf("\n--------------------------------------------\n");
    printf("              **TRAVEL TICKET**");
    printf("\n--------------------------------------------\n");
    printf("Travelers :%d\n",numtravelers);
    printf("Departure Date: %s\n", departdate);

    if(triptype==1) {
        printf("Route: %s -> %s\n",fromcity,tocity);
    }
    if(triptype==2) {
        printf("Return Date :%s\n",returndate);
        printf("Route : %s -> %s -> %s\n",fromcity,tocity,fromcity);
    }

    printf("Airline :");
    if(airline==1) {
        printf("Biman Bangladesh Airlines\n");
    }
    else if(airline==2) {
        printf("US-Bangla Airlines\n");
    }
    else if(airline==3) {
        printf("Novoair\n");
    }
    else printf("ERROR\n");

    printf("Class :");
    if(classs==1) {
        printf("Economy");
    }
    else if(classs==2) {
        printf("Business");
    }
    else if(classs==3) {
        printf("First Class");
    }
    else printf("ERROR");

    printf("\n--------------------------------------------\n");
    printf("      **Thank you for your booking!**");
    printf("\n--------------------------------------------\n");
    pause();
}

typedef struct {
    int id;
    char name[50];
    char from[30];
    char to[30];
    char departure[10];
    char arrival[10];
    int seats;
    float price;
} Train;

typedef struct {
    int train_id;
    int tickets;
    float total;
} Booking;

Train trains[] = {
    {1, "Subarna Express", "Dhaka", "Chittagong", "08:00", "13:00", 50, 550.0},
    {2, "Mohanagar Provati", "Dhaka", "Chittagong", "06:30", "12:00", 50, 450.0},
    {3, "Ekota Express", "Dhaka", "Dinajpur", "10:00", "18:30", 50, 600.0},
    {4, "Tista Express", "Dhaka", "Rangpur", "09:00", "16:00", 50, 500.0},
    {5, "Chitra Express", "Dhaka", "Khulna", "07:30", "13:30", 50, 400.0}
};

int train_count = 5;

void display_trains() {
    printf("\nAvailable Trains:\n");
    printf("-----------------------------------------------------------------\n");
    printf("ID  Train Name           From      To          Departure  Arrival  Seats  Price\n");
    printf("-----------------------------------------------------------------\n");

    for(int i = 0; i < train_count; i++) {
        printf("%-3d %-20s %-9s %-11s %-9s   %-7s  %-5d  %.2f Tk\n",
               trains[i].id, trains[i].name, trains[i].from, trains[i].to,
               trains[i].departure, trains[i].arrival, trains[i].seats, trains[i].price);
    }
}

void display_ticket(Booking booking) {
    int train_index = -1;

    for(int i = 0; i < train_count; i++) {
        if(trains[i].id == booking.train_id) {
            train_index = i;
            break;
        }
    }

    printf("\n=== TICKET SUMMARY ===\n");
    printf("Train: %s (%d)\n", trains[train_index].name, trains[train_index].id);
    printf("Route: %s to %s\n", trains[train_index].from, trains[train_index].to);
    printf("Departure: %s, Arrival: %s\n", trains[train_index].departure, trains[train_index].arrival);
    printf("Tickets: %d\n", booking.tickets);
    printf("Price per ticket: %.2f Tk\n", trains[train_index].price);
    printf("Total Amount: %.2f Tk\n", booking.total);
    printf("\nThank you for your booking!\n");
    printf("=================================\n");
}

void book_train_ticket() {
    Booking booking;
    int train_found = 0;
    int train_index = -1;

    display_trains();

    printf("\nEnter Train ID to book: ");
    scanf("%d", &booking.train_id);

    for(int i = 0; i < train_count; i++) {
        if(trains[i].id == booking.train_id) {
            train_found = 1;
            train_index = i;
            break;
        }
    }

    if(!train_found) {
        printf("\nSorry, no train found with ID %d\n", booking.train_id);
        pause();
        return;
    }

    printf("\nEnter number of tickets: ");
    scanf("%d", &booking.tickets);

    if(booking.tickets <= 0) {
        printf("\nPlease enter a valid number of tickets.\n");
        pause();
        return;
    }

    if(booking.tickets > trains[train_index].seats) {
        printf("\nSorry, only %d seats available on this train.\n", trains[train_index].seats);
        pause();
        return;
    }

    booking.total = booking.tickets * trains[train_index].price;
    trains[train_index].seats -= booking.tickets;

    printf("\n=== Booking Successful ===\n");
    display_ticket(booking);
    pause();
}

void trainTravel() {
    int choice;

    clearScreen();
    printf("\n\n=== Welcome to Railway Ticket System ===\n\n");

    do {
        printf("\nMain Menu:\n");
        printf("1. View Available Trains\n");
        printf("2. Book a Ticket\n");
        printf("3. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_trains();
                pause();
                break;
            case 2:
                book_train_ticket();
                break;
            case 3:
                return;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pause();
        }
    } while(choice != 3);
}

void fromList() {
    printf("\n========= FROM LOCATIONS =========\n");
    printf("1. Dhaka\n");
    printf("2. Chattagram\n");
    printf("3. Sylhet\n");
    printf("4. Rangpur\n");
    printf("5. Mymensingh\n");
    printf("6. Khulna\n");
    printf("7. Barishal\n");
    printf("8. Rajshahi\n");
}

void toList() {
    printf("\n========= TO LOCATIONS =========\n");
    printf("1. Dhaka\n");
    printf("2. Chattagram\n");
    printf("3. Sylhet\n");
    printf("4. Rangpur\n");
    printf("5. Mymensingh\n");
    printf("6. Khulna\n");
    printf("7. Barishal\n");
    printf("8. Rajshahi\n");
}

void busList() {
    printf("\n========= BUS SERVICES =========\n");
    printf("1. Green Line\n");
    printf("2. Hanif\n");
    printf("3. Shyamoli\n");
    printf("4. Shohag\n");
    printf("5. Ena\n");
    printf("6. London Express\n");
    printf("7. Saudia Travels\n");
}

void dateList() {
    printf("\n========= AVAILABLE DATES =========\n");
    printf("1. 15-12-2023\n");
    printf("2. 16-12-2023\n");
    printf("3. 17-12-2023\n");
    printf("4. 18-12-2023\n");
    printf("5. 19-12-2023\n");
}

void timeList() {
    printf("\n========= AVAILABLE TIMES =========\n");
    printf("1. 08:00AM\n");
    printf("2. 10:30AM\n");
    printf("3. 01:00PM\n");
    printf("4. 04:30PM\n");
    printf("5. 08:00PM\n");
    printf("6. 11:30PM\n");
}

void priceList(int busChoice) {
    printf("\n========= TICKET PRICES =========\n");

    switch(busChoice) {
        case 1:
            printf("1. AC Business Class: 1500 BDT\n");
            printf("2. AC Standard: 1200 BDT\n");
            printf("3. Non-AC: 800 BDT\n");
            break;
        case 2:
            printf("1. AC Business Class: 1300 BDT\n");
            printf("2. AC Standard: 1000 BDT\n");
            printf("3. Non-AC: 700 BDT\n");
            break;
        case 3:
            printf("1. AC Business Class: 1400 BDT\n");
            printf("2. AC Standard: 1100 BDT\n");
            printf("3. Non-AC: 750 BDT\n");
            break;
        case 4:
            printf("1. AC Business Class: 1600 BDT\n");
            printf("2. AC Standard: 1300 BDT\n");
            printf("3. Non-AC: 850 BDT\n");
            break;
        case 5:
            printf("1. AC Business Class: 1200 BDT\n");
            printf("2. AC Standard: 900 BDT\n");
            printf("3. Non-AC: 600 BDT\n");
            break;
        case 6:
            printf("1. AC Business Class: 1800 BDT\n");
            printf("2. AC Standard: 1500 BDT\n");
            printf("3. Non-AC: 950 BDT\n");
            break;
        case 7:
            printf("1. AC Business Class: 1700 BDT\n");
            printf("2. AC Standard: 1400 BDT\n");
            printf("3. Non-AC: 900 BDT\n");
            break;
        default:
            printf("No price information available.\n");
    }
}

void busTravel() {
    int from, to, bus, date, time, priceOption;
    char selectedDate[15], selectedTime[10], selectedPrice[50];
    int price;

    clearScreen();
    printf("========================================\n");
    printf("       WELCOME TO BUS TICKET SYSTEM     \n");
    printf("========================================\n");

    fromList();
    printf("Select FROM location (1-8): ");
    scanf("%d", &from);

    toList();
    printf("Select TO location (1-8): ");
    scanf("%d", &to);

    busList();
    printf("Select BUS service (1-7): ");
    scanf("%d", &bus);

    dateList();
    printf("Select JOURNEY DATE (1-5): ");
    scanf("%d", &date);

    switch(date) {
        case 1: strcpy(selectedDate, "15-12-2023"); break;
        case 2: strcpy(selectedDate, "16-12-2023"); break;
        case 3: strcpy(selectedDate, "17-12-2023"); break;
        case 4: strcpy(selectedDate, "18-12-2023"); break;
        case 5: strcpy(selectedDate, "19-12-2023"); break;
        default: strcpy(selectedDate, "Invalid Date");
    }

    timeList();
    printf("Select JOURNEY TIME (1-6): ");
    scanf("%d", &time);

    switch(time) {
        case 1: strcpy(selectedTime, "08:00AM"); break;
        case 2: strcpy(selectedTime, "10:30AM"); break;
        case 3: strcpy(selectedTime, "01:00PM"); break;
        case 4: strcpy(selectedTime, "04:30PM"); break;
        case 5: strcpy(selectedTime, "08:00PM"); break;
        case 6: strcpy(selectedTime, "11:30PM"); break;
        default: strcpy(selectedTime, "Invalid Time");
    }

    priceList(bus);
    printf("Select PRICE OPTION (1-3): ");
    scanf("%d", &priceOption);

    switch(bus) {
        case 1:
            if(priceOption == 1) {
                price = 1500;
                strcpy(selectedPrice, "AC Business Class: 1500 BDT");
            }
            else if(priceOption == 2) {
                price = 1200;
                strcpy(selectedPrice, "AC Standard: 1200 BDT");
            }
            else {
                price = 800;
                strcpy(selectedPrice, "Non-AC: 800 BDT");
            }
            break;
        case 2:
            if(priceOption == 1) {
                price = 1300;
                strcpy(selectedPrice, "AC Business Class: 1300 BDT");
            }
            else if(priceOption == 2) {
                price = 1000;
                strcpy(selectedPrice, "AC Standard: 1000 BDT");
            }
            else {
                price = 700;
                strcpy(selectedPrice, "Non-AC: 700 BDT");
            }
            break;
        case 3:
            if(priceOption == 1) {
                price = 1400;
                strcpy(selectedPrice, "AC Business Class: 1400 BDT");
            }
            else if(priceOption == 2) {
                price = 1100;
                strcpy(selectedPrice, "AC Standard: 1100 BDT");
            }
            else {
                price = 750;
                strcpy(selectedPrice, "Non-AC: 750 BDT");
            }
            break;
        case 4:
            if(priceOption == 1) {
                price = 1600;
                strcpy(selectedPrice, "AC Business Class: 1600 BDT");
            }
            else if(priceOption == 2) {
                price = 1300;
                strcpy(selectedPrice, "AC Standard: 1300 BDT");
            }
            else {
                price = 850;
                strcpy(selectedPrice, "Non-AC: 850 BDT");
            }
            break;
        case 5:
            if(priceOption == 1) {
                price = 1200;
                strcpy(selectedPrice, "AC Business Class: 1200 BDT");
            }
            else if(priceOption == 2) {
                price = 900;
                strcpy(selectedPrice, "AC Standard: 900 BDT");
            }
            else {
                price = 600;
                strcpy(selectedPrice, "Non-AC: 600 BDT");
            }
            break;
        case 6:
            if(priceOption == 1) {
                price = 1800;
                strcpy(selectedPrice, "AC Business Class: 1800 BDT");
            }
            else if(priceOption == 2) {
                price = 1500;
                strcpy(selectedPrice, "AC Standard: 1500 BDT");
            }
            else {
                price = 950;
                strcpy(selectedPrice, "Non-AC: 950 BDT");
            }
            break;
        case 7:
            if(priceOption == 1) {
                price = 1700;
                strcpy(selectedPrice, "AC Business Class: 1700 BDT");
            }
            else if(priceOption == 2) {
                price = 1400;
                strcpy(selectedPrice, "AC Standard: 1400 BDT");
            }
            else {
                price = 900;
                strcpy(selectedPrice, "Non-AC: 900 BDT");
            }
            break;
        default:
            price = 0;
            strcpy(selectedPrice, "Invalid Price Option");
    }

    printf("\n========================================\n");
    printf("           YOUR TICKET DETAILS          \n");
    printf("========================================\n");

    printf("From           : ");
    switch(from) {
        case 1: printf("Dhaka\n"); break;
        case 2: printf("Chattagram\n"); break;
        case 3: printf("Sylhet\n"); break;
        case 4: printf("Rangpur\n"); break;
        case 5: printf("Mymensingh\n"); break;
        case 6: printf("Khulna\n"); break;
        case 7: printf("Barishal\n"); break;
        case 8: printf("Rajshahi\n"); break;
        default: printf("Invalid Location\n");
    }

    printf("To             : ");
    switch(to) {
        case 1: printf("Dhaka\n"); break;
        case 2: printf("Chattagram\n"); break;
        case 3: printf("Sylhet\n"); break;
        case 4: printf("Rangpur\n"); break;
        case 5: printf("Mymensingh\n"); break;
        case 6: printf("Khulna\n"); break;
        case 7: printf("Barishal\n"); break;
        case 8: printf("Rajshahi\n"); break;
        default: printf("Invalid Location\n");
    }

    printf("Bus Service    : ");
    switch(bus) {
        case 1: printf("Green Line\n"); break;
        case 2: printf("Hanif\n"); break;
        case 3: printf("Shyamoli\n"); break;
        case 4: printf("Shohag\n"); break;
        case 5: printf("Ena\n"); break;
        case 6: printf("London Express\n"); break;
        case 7: printf("Saudia Travels\n"); break;
        default: printf("Invalid Bus\n");
    }

    printf("Journey Date   : %s\n", selectedDate);
    printf("Journey Time   : %s\n", selectedTime);
    printf("Ticket Price   : %s\n", selectedPrice);

    printf("========================================\n");
    printf("         THANK YOU & SAFE JOURNEY       \n");
    printf("========================================\n");
    pause();
}

typedef struct {
    char vehicle_type[20];
    float fare_per_km;
    int available;
} VehicleOption;

char* dhaka_locations[] = {
    "Mirpur", "Dhanmondi", "Gulshan", "Motijheel", "Uttara",
    "Mohammadpur", "Tejgaon", "Ramna", "Bashundhara", "Savar",
    "Palashi", "Aftabnagar", "Kuratoli", "Cantonment", "New Market",
    "Baily Road", "Mohakhali", "Mirpur", "Dhanmondi", "Shahbag"
};

char* colleges[] = {
    "Adamjee Cantonment College",
    "Dhaka College",
    "RAJUK Uttara Model College",
    "Viqarunnisa Noon School & College",
    "Holy Cross College",
    "Government Science College",
    "Dhaka City College",
    "Notre Dame College",
    "St. Joseph Higher Secondary School",
    "Dhaka Residential Model College"
};

char* universities[] = {
    "University of Dhaka",
    "Bangladesh University of Engineering and Technology",
    "Jahangirnagar University",
    "North South University",
    "BRAC University",
    "East West University",
    "American International University-Bangladesh",
    "Daffodil International University",
    "Ahsanullah University of Science and Technology",
    "Bangladesh University of Professionals"
};

VehicleOption vehicle_options[] = {
    {"Bus", 2.5, 1},
    {"Mini Bus", 3.0, 1},
    {"Car", 8.0, 1},
    {"Bike", 5.0, 1}
};

char* time_slots[] = {
    "6:00 AM", "8:00 AM", "10:00 AM", "12:00 PM",
    "2:00 PM", "4:00 PM", "6:00 PM", "8:00 PM"
};

int getValidChoice(int max) {
    int choice;
    while(1) {
        printf("Enter your choice (1-%d): ", max);
        scanf("%d", &choice);
        if(choice >= 1 && choice <= max) {
            return choice;
        }
        printf("Invalid choice. Please try again.\n");
    }
}

float calculateFare(const char* vehicle_type, float distance) {
    for(int i = 0; i < 4; i++) {
        if(strcmp(vehicle_type, vehicle_options[i].vehicle_type) == 0) {
            return distance * vehicle_options[i].fare_per_km;
        }
    }
    return 0;
}

float getDistance(const char* from, const char* to) {
    if(strcmp(from, "Mirpur") == 0 && strcmp(to, "Campus Area") == 0) return 12.5;
    if(strcmp(from, "Dhanmondi") == 0 && strcmp(to, "Campus Area") == 0) return 5.0;
    if(strcmp(from, "Gulshan") == 0 && strcmp(to, "Campus Area") == 0) return 8.0;
    if(strcmp(from, "Uttara") == 0 && strcmp(to, "Campus Area") == 0) return 15.0;
    return 10.0;
}

void displayTicket(const char* from, const char* to, const char* institution,
                  const char* vehicle, const char* time, float fare) {
    printf("\n\n\t\t=== TRANSPORT TICKET ===\n");
    printf("\t\t========================\n\n");
    printf("From: %s\n", from);
    printf("To: %s (%s)\n", to, institution);
    printf("Vehicle Type: %s\n", vehicle);
    printf("Departure Time: %s\n", time);
    printf("\nTotal Fare: %.2f BDT\n", fare);
    printf("\nThank you for using Dhaka Student Transport System!\n");
    printf("Please show this ticket to your driver.\n\n");
    pause();
}

void studentTransport() {
    int choice, subChoice, vehicleChoice, timeChoice;
    char from_location[50], to_location[50];
    char selected_institution[100], selected_vehicle[20], selected_time[20];
    float distance, fare;

    clearScreen();
    printf("\n\n\t\tWelcome to Dhaka Student Transport System\n");
    printf("\t\t---------------------------------------\n\n");

    printf("Step 1: Select your current location\n");
    for(int i = 0; i < 20; i++) {
        printf("%d. %s\n", i+1, dhaka_locations[i]);
    }
    choice = getValidChoice(20);
    strcpy(from_location, dhaka_locations[choice-1]);

    printf("\nStep 2: Select your destination type\n");
    printf("1. College\n");
    printf("2. University\n");
    choice = getValidChoice(2);

    if(choice == 1) {
        printf("\nSelect your college:\n");
        for(int i = 0; i < 10; i++) {
            printf("%d. %s\n", i+1, colleges[i]);
        }
        subChoice = getValidChoice(10);
        strcpy(selected_institution, colleges[subChoice-1]);
    }
    else {
        printf("\nSelect your university:\n");
        for(int i = 0; i < 10; i++) {
            printf("%d. %s\n", i+1, universities[i]);
        }
        subChoice = getValidChoice(10);
        strcpy(selected_institution, universities[subChoice-1]);
    }

    strcpy(to_location, "Campus Area");

    printf("\nJourney Details:\n");
    printf("From: %s\n", from_location);
    printf("To: %s (%s)\n", to_location, selected_institution);

    printf("\nStep 4: Select your preferred vehicle\n");
    for(int i = 0; i < 4; i++) {
        printf("%d. %s (%.2f BDT per km)\n", i+1,
               vehicle_options[i].vehicle_type,
               vehicle_options[i].fare_per_km);
    }
    vehicleChoice = getValidChoice(4);
    strcpy(selected_vehicle, vehicle_options[vehicleChoice-1].vehicle_type);

    printf("\nStep 5: Select your preferred time\n");
    for(int i = 0; i < 8; i++) {
        printf("%d. %s\n", i+1, time_slots[i]);
    }
    timeChoice = getValidChoice(8);
    strcpy(selected_time, time_slots[timeChoice-1]);

    distance = getDistance(from_location, to_location);
    fare = calculateFare(selected_vehicle, distance);

    displayTicket(from_location, to_location, selected_institution,
                 selected_vehicle, selected_time, fare);
}

void menu() {
    int choice;
    while (1) {
        clearScreen();
        printf("🌍 Travel Options Menu\n");
        printf("-----------------------\n");
        printf("1. ✈️  By Air\n");
        printf("2. 🚌 By Bus\n");
        printf("3. 🚆 By Train\n");
        printf("4. 🎓 Student Transport System\n");
        printf("5. 👤 My Account Info\n");
        printf("6. 🔓 Logout\n");
        printf("Select: ");
        scanf("%d", &choice); getchar();

        switch (choice) {
            case 1: airTravel(); break;
            case 2: busTravel(); break;
            case 3: trainTravel(); break;
            case 4: studentTransport(); break;
            case 5: showAccount(); break;
            case 6:
                printf("\nLogging out...\n");
                pause();
                return;
            default:
                printf("❌ Invalid choice.\n");
                pause();
        }
    }
}

int main() {
    int choice;
    while (1) {
        clearScreen();
        printf("🚇 Smart Travel Management System\n");
        printf("----------------------------------\n");
        printf("1. 📝 Sign Up\n");
        printf("2. 🔐 Login\n");
        printf("3. ❌ Exit\n");
        printf("Choose: ");
        scanf("%d", &choice); getchar();

        switch (choice) {
            case 1: signup(); break;
            case 2:
                if (login()) {
                    printf("\n✅ Login successful!\n");
                    pause();
                    menu();
                } else {
                    printf("❌ Login failed. Try again.\n");
                    pause();
                }
                break;
            case 3:
                printf("\n👋 Goodbye!\n");
                exit(0);
            default:
                printf("❌ Invalid choice.\n");
                pause();
        }
    }
    return 0;
}
