#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\EditorFiles\objects_crasno.c"
#include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\custom_scripts\sets.c"
//ref StartSetsPlayersConfig StartSetsPlayers = new StartSetsPlayersConfig();
void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
	SpawnTEST();
	
}

class CustomMission: MissionServer
{
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		string arrayPlayersAdmins[2]={"ArtH3sbCJAksPQZgAh8NrMdvWHsA9ZFJegHvK_0VJgY=", "bbbbbbbbbbbbbbbbbbbbbb"};
		
//		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(GetGame().AdminLog, "Character "  + characterName + " spawn");
		
		
		for (int i=0; i<2; i++)
			{
				if (identity.GetId()==arrayPlayersAdmins[i])
				{
					characterName="SurvivorF_Keiko";
				}
			}
		
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(GetGame().AdminLog, "Player '" + identity.GetName() + "' (id=" + identity.GetId() + ") player info");
//		Error("Player info | uid " + identity.GetId() + " | name " + identity.GetName()) //дропает функцию 
		
		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;
		//PlayerBase my_test_player;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 2 );

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt( 0, 4 );
			itemEnt = itemClothing.GetInventory().CreateInInventory( chemlightArray[rndIndex] );
			SetRandomHealth( itemEnt );

			rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "Apple" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "Pear" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "Plum" );

			SetRandomHealth( itemEnt );
		}
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
		

		//my_test_player=player;
		//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(GetGame().AdminLog, "Player "  + my_test_player.GetIdentity().GetId() + " player info"); // ломает аддон Community tools
		
		StartSetsPlayer(player);
	}
	
	
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}