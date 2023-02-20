 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct MusicFestival
{
    //5 properties:
    //    1) number of sold tickets (int)
    int soldTickets = 10000;
    //    2) number of artists (int)
    int numberOfArtists = 12;
    //    3) duration in days for the festival (int)
    int numberOfFestivalDays = 3;
    //    4) concert average duration (float)
    float averageConcertsDuration = 8.5f;
    //    5) water cost (double)
    double waterCost = 4.5;
    //3 things it can do:
    //    1) check the ticket type
    void checkTicketType();
    //    2) announce next artist
    void announceNextArtist(std::string currentArtist); // this parameters is used to check inside an inner list of artists
    //    3) reserve a parking spot
    int reserveParkingSpot(float payment);
    // the payment is needed to calculate the duration for the parking spot. The function returns this duration in minutes.
};

/*
Thing 2) Digital Audio Workstation
5 properties:
    1) volume value (float)
    2) number of tracks (int)
    3) panning value (double)
    4) type of track (std::string)
    5) cost for the software (double)
3 things it can do:
    1) add a new track
    2) increase volume of tracks
    3) solos a given track
*/
struct DigitalAudioWorkstation
{
    //5 properties:
    //    1) volume value (float)
    float volumeValue = 3.5f;
    //    2) number of tracks (int)
    int numberOfTracks = 1;
    //    3) panning value (double)
    double panValue = 0.0;
    //    4) type of track (std::string)
    std::string trackType = "midi";
    //    5) cost for the software (double)
    double softwareCost = 299.99;

    struct TrackSlot
    {
        bool isTrackPaused = true;
        std::string actualTimelinePoint = "00h:00m:00s";
        double gainValue = 1.0;
        double skipTimeValue = 0.5;
        bool isIsolated = false;

        void setLoopRange(std::string startTime = "00h::01m::34s", std::string endTime = "00h::01m::40s"); // set the range for the loop
        void recordTrack(std::string startTime = "00h::00m::00s"); //record a track from a give start time value.
        double changeGain(double actualGainValue, double addingValue = 0.5); // change the actualGainValue by adding an addingValue. It returns the updated gain. 
    };
    //3 things it can do:
    //    1) add a new track
    void addNewTrack(int trackType, TrackSlot trackSlot); // trackType could range from 0 to whatever number to select the type of track (audio, midi, ecc..). You give to the function a new trackSlot with all its characteristics.
    //    2) increase volume of tracks
    float increaseTracksVolume(int newVolumeValue); // returns the updated volumeValue
    //    3) solos a given track
    bool soloTrack(int trackNumber, TrackSlot trackSlot); // uses the track number as parameter to isolate it and the trackSlot to set the isIsolated value to true/false. It returns true/false if it has been isolated
};

/*
Thing 3) Train station
5 properties:
    1) number of rails (int)
    2) number of trains per day (int)
    3) travelers rate (double)
    4) number of intercity trains (int)
    5) number of national trains (int)
3 things it can do:
    1) check trains' arrivals
    2) announce delays
    3) control travelers access
*/
struct TrainStation
{
    //5 properties:
    //    1) number of rails (int)
    int numberOfRails = 20;
    //    2) number of trains per day (int)
    int trainsPerDay = 200; 
    //    3) travelers rate (double)
    double travelersRate = 80.2;
    //    4) number of intercity trains (int)
    int numberOfIntercityTrains = 10;
    //    5) number of national trains (int)
    int numberOfNationalTrains = 10;

    struct Train
    {
        int numberOfWagons = 12;
        int numberOfSeats = 120;
        int trainId = 123;
        bool hasArrived = false;
        float fuelPercentage = 100.0f;

        void leaveStation(float fuelPercentage, bool setAutoPilot = false); // Function to indicate that the train has to leave the station. It accepts fuelPercentage parameter to check that it can actually leave and if it need to turn the Autopilot on. 
        double computeMilesTraveledPerDay(std::string day); // return the mailes traveled in a given day
        void openTheDoors(float velocity = 100.0f); // open the doors given a certain velocity (hopefully 0).     
        
    };
    //3 things it can do:
    //    1) check trains' arrivals
    void checkTrainsArrivals(Train train);
    //    2) announce delays
    void announceDelays(int trainId, int delayMinutesAmount, Train train); // parameters to select the train and its delay in minutes
    //    3) control travelers access
    bool controlTravelersAccess(int ticketId); // based on ticketId, return true if the traveler payed it so that can access the trainStation 
};

/*
Thing 4) Notebook
5 properties:
    1) ram size (int)
    2) graphic card size (int)
    3) number of CPU cores (int)
    4) model name (std::string)
    5) number of USB ports (int)
3 things it can do:
    1) run newest videogames
    2) connect to the internet
    3) auto update
*/
struct Notebook
{
    //5 properties:
    //    1) ram size (int)
    int ramSize = 4096;
    //    2) graphic card size (int)
    int graphicCardSize = 2048;
    //    3) number of CPU cores (int)
    int numberOfCpuCores = 4;
    //    4) model name (std::string)
    std::string modelName = "Lenovo ThinkPad";
    //    5) number of USB ports (int)
    int numberOfUsbPorts = 3;
    //3 things it can do:
    //    1) run newest videogames
    void runNewestVideogames(bool minimumRequirementsChecked); // run the videogame upon minimumRequirementsChecked value
    //    2) connect to internet
    bool connectToInternet(std::string networkName, std::string password); // return true if the password for the given network name is correct
    //    3) auto update
    void autoUpdate();
};

/*
Thing 5) HandleBar
5 properties:
    1) material (std::string)
    2) number of breaks (int)
    3) speed indicator in Km/h (int)
    4) fuel indicator in percentage (int)
    5) hour indicator (std::string)
3 things it can do:
    1) accelerate
    2) decelerate
    3) steer
*/
struct HandleBar
{
    //5 properties:
    //    1) material (std::string)
    std::string material = "plastic";
    //    2) number of breaks (int)
    int numberOfBreaks = 2;
    //    3) speed indicator in Km/h (int)
    int speedIndication = 0;
    //    4) fuel indicator in percentage (int)
    int fuelPercentage = 50;
    //    5) hour indicator (std::string)
    std::string hourIndication = "00:00:00";
    //3 things it can do:
    //    1) accelerate
    int accelerate(int accelerationAmount); // return an updated speedIndication value given an acceleration amount as parameter
    //    2) decelerate
    int decelerate(int decelerationAmount); // return an updated speedIndication value given decelerationAmount as parameter
    //    3) steer
    void steer(std::string direction); // steer based on direction that could be for example right or left
};

/*
Thing 6) Wheel
5 properties:
    1) material (std::string)
    2) wheel rim type (std::string)
    3) maximum pressure in bar (float)
    4) colour (std::string)
    5) percentage of wear (float)
3 things it can do:
    1) loose pressure
    2) bounce
    3) spin
*/
struct Wheel
{
    //5 properties:
    //    1) material (std::string)
    std::string material = "rubber";
    //    2) wheel rim type (std::string)
    std::string rimType = "aluminum";
    //    3) maximum pressure in bar (float)
    float maxBarPressure = 6.2f;
    //    4) colour (std::string)
    std::string colour = "black";
    //    5) percentage of wear (float)
    float wearPercentage = 0.0f;
    //3 things it can do:
    //    1) loose pressure
    void loosePressure(float pressureAmount); // loose pressure of a given pressure amount
    //    2) bounce
    void bounce();
    //    3) spin
    void spin(int revolutionsPerMinute); // set the revolution per minute to make the wheel spinning
};

/*
Thing 7) Seat
5 properties:
    1) material (std::string)
    2) shape (std::string)
    3) number (int)
    4) colour (std::string)
    5) percentage of cushioning (float)
3 things it can do:
    1) absorb vibrations
    2) it can warm the seating
    3) comfort driver
*/
struct Seat
{
    //5 properties:
    //    1) material (std::string)
    std::string material = "leather";
    //    2) shape (std::string)
    std::string shape = "rounded";
    //    3) number (int)
    int numberOfSeats = 1;
    //    4) colour (std::string)
    std::string colour = "black";
    //    5) percentage of cushioning (float)
    float cushioningPercentage = 90.0f;
    //3 things it can do:
    //    1) absorb vibrations
    void absorbVibrations();
    //    2) it can warm the seating
    bool isWarmingTheSeating(); // return true if the seat is warming the seating
    //    3) comfort driver   
    void comfortDriver();
};

/*
Thing 8) Light
5 properties:
    1) wattage (float)
    2) brightness percentage (double)
    3) colour (std::string)
    4) light anglulation in degrees (int)
    5) type of light (std::string)
3 things it can do:
    1) illuminate street
    2) alert people
    3) indicate change of direction
*/
struct Light
{
    //5 properties:
    //    1) wattage (float)
    float wattage = 60.0f;
    //    2) brightness percentage (double)
    double brightnessPercentage = 80.5;
    //    3) colour (std::string)
    std::string colour = "white";
    //    4) light anglulation in degrees (int)
    int degreesAngulation = 90;
    //    5) type of light (std::string)
    std::string type = "halogen";
    //3 things it can do:
    //    1) illuminate street
    double illuminateStreet(double brightnessAmount); // Based upon the brightness amount, it returns the updated brightness percentage
    //    2) alert people
    void alertPeople();
    //    3) indicate change of direction
    std::string indicateChangeOfDirection(int direction); // direction could be 1 or 2 to indicate left or right. It returns the direction as a string.
};

/*
Thing 9) Case
5 properties:
    1) shape (std::string)
    2) colour (std::string)
    3) material (std::string)
    4) maximum load in Kg (float)
    5) volume (float)
3 things it can do:
    1) carry objects
    2) support passenger
    3) reflect lights
*/
struct Case
{
    //5 properties:
    //    1) shape (std::string)
    std::string shape = "squared";
    //    2) colour (std::string)
    std::string colour = "red";
    //    3) material (std::string)
    std::string material = "plastic";
    //    4) maximum load in Kg (float)
    float maximumKgLoad = 2.8f;
    //    5) volume in litres (float)
    float volumeInLitres = 46.2f;
    //3 things it can do:
    //    1) carry objects
    void carryObjects(std::string objectName); // the case internally stores the object passed as a string parameter
    //    2) support passenger
    void supportPassenger();
    //    3) reflect lights
    void reflectLights();
};

/*
Thing 10) Scooter
5 properties:
    1) HandleBar
    2) Wheel
    3) Seat
    4) Light
    5) Case
3 things it can do:
    1) accelerate
    2) decelerate
    3) steer
*/
struct Scooter
{
    //5 properties:
    //    1) HandleBar
    //a member variabledeclaration of an instance of UDT 5
    HandleBar handleBar;
    //    2) Wheel
    //a member variabledeclaration of an instance of UDT 6
    Wheel wheel;
    //    3) Seat
    //a member variabledeclaration of an instance of UDT 7
    Seat seat;
    //    4) Light
    //a member variabledeclaration of an instance of UDT 8
    Light light;
    //    5) Case
    //a member variabledeclaration of an instance of UDT 9
    Case scooterCase; //cannot use "case" as object name
    //3 things it can do:
    //    1) accelerate
    int accelerate(int accelerationAmount); // returns the updated speed based on the accelerationAmount parameter
    //    2) decelerate
    int decelerate(int decelerationAmount); // returns the updated speed based on the decelerationAmount parameter
    //    3) steer
    void steer(std::string direction); // steer based on direction that could be for example right or left
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
