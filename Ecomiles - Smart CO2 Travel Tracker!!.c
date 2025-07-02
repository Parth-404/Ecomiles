#include <stdio.h>
#include <string.h>

int main() {
    char transport[15], fuel_type[15];
    int passengers;
    float kms, co2_per_km, total_co2, co2_per_person;
    float fuel_cost_per_km = 7.0;
    float total_cost;
    int trees_needed;

    float emissions[] = {
        0.021,
        0.120,
        0.150,
        0.050,
        0.060,
        0.045,
        0.250
    };

    printf("========================================================\n");
    printf("         🌿 Welcome to EcoMiles: Smart CO2 Travel Tracker 🌍\n");
    printf("========================================================\n");
    printf("This tool helps you calculate how much carbon dioxide (CO2)\n");
    printf("your travel emits based on your selected mode of transport.\n");
    printf("It also gives fuel cost estimates and environmental tips!\n\n");

    printf("Choose your mode of transportation (bike / car / bus / train / plane): ");
    scanf("%s", transport);

    if (strcmp(transport, "car") == 0) {
        printf("What type of car do you use? (Petrol / Diesel / Electric): ");
        scanf("%s", fuel_type);
    }

    printf("Enter total number of people travelling (including you): ");
    scanf("%d", &passengers);

    printf("Enter distance you plan to travel (in kilometers): ");
    scanf("%f", &kms);

    if (passengers <= 0 || kms <= 0) {
        printf("\n⚠️  Error: Number of passengers and distance must be greater than zero.\n");
        return 1;
    }

    if (strcmp(transport, "bike") == 0) {
        co2_per_km = emissions[0];
    } else if (strcmp(transport, "car") == 0) {
        if (strcmp(fuel_type, "Petrol") == 0) {
            co2_per_km = emissions[1];
        } else if (strcmp(fuel_type, "Diesel") == 0) {
            co2_per_km = emissions[2];
        } else if (strcmp(fuel_type, "Electric") == 0) {
            co2_per_km = emissions[3];
        } else {
            printf("\n❌ Invalid fuel type. Please enter Petrol, Diesel, or Electric.\n");
            return 1;
        }
    } else if (strcmp(transport, "bus") == 0) {
        co2_per_km = emissions[4];
    } else if (strcmp(transport, "train") == 0) {
        co2_per_km = emissions[5];
    } else if (strcmp(transport, "plane") == 0) {
        co2_per_km = emissions[6];
    } else {
        printf("\n❌ Invalid transport mode. Please choose from bike, car, bus, train, or plane.\n");
        return 1;
    }

    total_co2 = co2_per_km * kms;
    co2_per_person = total_co2 / passengers;
    total_cost = (strcmp(transport, "car") == 0) ? (fuel_cost_per_km * kms) : 0.0;
    trees_needed = (int)(total_co2 / 21);

    printf("\n=================== 📊 Journey Summary ===================\n");
    printf("Transportation Mode     : %s\n", transport);
    if (strcmp(transport, "car") == 0) {
        printf("Fuel Type               : %s\n", fuel_type);
    }
    printf("Distance Travelled      : %.2f km\n", kms);
    printf("Total Travellers        : %d\n", passengers);
    printf("Total CO2 Emitted       : %.2f kg\n", total_co2);
    printf("CO2 Emission per Person : %.2f kg\n", co2_per_person);
    if (strcmp(transport, "car") == 0) {
        printf("Estimated Fuel Cost     : ₹%.2f\n", total_cost);
    } else {
        printf("Fuel Cost               : Not Applicable\n");
    }
    printf("🌳 Trees Needed to Offset : %d tree(s)\n", trees_needed);
    printf("==========================================================\n");

    printf("\n💡 Eco-Friendly Suggestions:\n");
    if (strcmp(transport, "car") == 0) {
        printf("- Consider carpooling to share emissions.\n");
        printf("- If possible, switch to an electric vehicle.\n");
    } else if (strcmp(transport, "plane") == 0) {
        printf("- Use non-stop flights to reduce emissions.\n");
        printf("- For shorter trips, trains are much more eco-friendly.\n");
    } else if (strcmp(transport, "bus") == 0) {
        printf("- Buses are a good low-emission choice for group travel.\n");
    } else if (strcmp(transport, "train") == 0) {
        printf("- Trains are one of the cleanest modes of long-distance travel.\n");
    } else if (strcmp(transport, "bike") == 0) {
        printf("- Biking is an excellent zero-emission travel method. Keep it up!\n");
    }

    printf("- Try walking or biking for short distances.\n");
    printf("- Offset your carbon footprint by planting trees 🌱.\n");

    printf("\n🌐 Quick Environmental Facts:\n");
    printf("- A single plane trip emits 3x more CO2 per km than a train.\n");
    printf("- 70%%+ of urban travel emissions come from cars.\n");
    printf("- Walking and cycling can reduce emissions by up to 90%%.\n");

    printf("\n✅ Thank you for using EcoMiles! Together, let's travel greener. 💚\n");
    return 0;
}
