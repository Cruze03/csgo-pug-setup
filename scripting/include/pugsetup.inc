// Different ways teams can be selected.
enum TeamType {
    TeamType_Manual,
    TeamType_Random,
    TeamType_Captains
};

// Different ways the map can be selected.
enum MapType {
    MapType_Current,
    MapType_Vote,
    MapType_Veto
};

// Called when a setup menu is finished.
forward OnSetup(int client, TeamType teamType, MapType mapType, int playersPerTeam);

// Called when the going-live process begins.
forward OnGoingLive();

// Called when the match is over.
forward OnMatchOver(bool hasDemo, char demoFileName[]);

// Returns whether a client is ready.
// This is only valid when the game is setup AND not live.
native bool IsReady(int client);

// Returns if the game settings have been setup.
native bool IsSetup();

// Returns the team type being used.
// Only valid if IsSetup is true.
native TeamType GetTeamType();

// Returns the map type being used.
// Only valid if IsSetup is true.
native MapType GetMapType();

// Returns if there is currently a match setup.
native bool IsMatchLive();

// Returns the pug leader, or -1 if not set.
native int GetLeader();

// Returns captain 1, or -1 if not set.
native int GetCaptain1();

// Returns captain 2, or -1 if not set.
native int GetCaptain2();

// Prints a plugin-formatted message to a client.
native void PugSetupMessage(int client, const char format[], any:...);

// Prints a plugin-formatted message to all clients.
native void PugSetupMessageToAll(const char format[], any:...);

// Returns the maximum number of players in the pug.
// Only valid if the game has already been setup.
native int GetPugMaxPlayers();