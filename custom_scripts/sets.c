	void StartSetsPlayer(PlayerBase player)
	{
		
		EntityAI itemCreated = NULL;
		EntityAI itemCreated1 = NULL;
		EntityAI inItem_spawn = NULL;
		ItemBase itemCasted = NULL;

		int use_set_id;
		string arrayPlayersAdmins_case_1[2]={"ArtH3sbCJAksPQZgAh8NrMdvWHsA9ZFJegHvK_0VJgY=", "bbbbbbbbbbbbbbbbbbbbbb"};
		
		for (int i=0; i<2; i++)
			{
					if (player.GetIdentity().GetId()==arrayPlayersAdmins_case_1[i])
					{
						use_set_id = 1;
					}
			}

		switch( use_set_id ) //Админ сет
			{
				//CASE 1
				case 1: //Set with number 1 (Сет с номером 1)
				{
					RemoveAllItems(player); 
					itemCreated = player.GetInventory().CreateInInventory("AssaultBag_Black"); 
						if (itemCreated)
							{
							//	SetRandomHealthItem(itemCreated);// Выдаем рюкзаку рандомное качество
								itemCreated1 = itemCreated.GetInventory().CreateInInventory("Honey");// Добавляем в инвентарь созданного рюкзака яблоко и записываем в переменную itemCreated1
								if (itemCreated1) 
								{
									SetRandomHealthItem(itemCreated1);// Выдаем предмету рандомное качество
								}
								itemCreated1 = NULL;
								itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");
								if (itemCreated1)
								{
									itemCasted = ItemBase.Cast(itemCreated1);// Выполняем преобразование в другой класс для работы с нужной нам функцией, поскольку в классе EntityAI нет нужной нам функции SetQuantity, а в подклассе ItemBase она есть. Предмет при этом так и остается один и тот же!
									itemCasted.SetQuantity(4);// Определяем количество для созданных бинтов как 4 штуки
									SetRandomHealthItem(itemCreated1); // Выдаем бинтам рандомное качество, функция работает с классом EntityAI
								}
								itemCreated1 = NULL;
								itemCreated1 = itemCreated.GetInventory().CreateInInventory("MilitaryBeret_ChDKZ");
							}
					// переменную itemCreated не обнуляем далее, поскольку мы ее не используем в проверке ниже.
					itemCreated = player.GetInventory().CreateInInventory("ShortJeans_Black");// Выдаем игроку штаны
					itemCreated = player.GetInventory().CreateInInventory("TShirt_Black");// Выдаем игроку куртку
					itemCreated = player.GetInventory().CreateInInventory("JungleBoots_Olive");// Выдаем игроку обувь
					//itemCasted = ItemBase.Cast(itemCreated);// Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
					itemCreated = player.GetInventory().CreateInInventory("SurgicalMask");
					itemCreated = player.GetInventory().CreateInInventory("Mich2001Helmet");
					if (itemCreated)
						{
							inItem_spawn = itemCreated.GetInventory().CreateAttachment( "NVGoggles" );
							inItem_spawn.GetInventory().CreateAttachment( "Battery9V" );
							inItem_spawn = NULL;
						}
					
					
					itemCreated = player.GetInventory().CreateInInventory("MilitaryBelt");
					if (itemCreated)
						{
							inItem_spawn = itemCreated.GetInventory().CreateAttachment( "Canteen" );
							itemCasted = ItemBase.Cast(inItem_spawn);
							itemCasted.SetQuantity(999);
							
							inItem_spawn = NULL;
							itemCreated.GetInventory().CreateAttachment( "PlateCarrierHolster" );
							inItem_spawn = itemCreated.GetInventory().CreateAttachment( "NylonKnifeSheath" );
							inItem_spawn.GetInventory().CreateAttachment( "CombatKnife" );
							
						}
					itemCreated = NULL;
					itemCreated = player.GetInventory().CreateInInventory("PlateCarrierVest_Black");// Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
					if (itemCreated)
						{
							itemCreated.GetInventory().CreateAttachment( "PlateCarrierPouches_Black" );
						}
					itemCreated = player.GetInventory().CreateInInventory("SodaCan_Cola")
					itemCreated = player.GetInventory().CreateInInventory("SodaCan_Pipsi")
					itemCreated = player.GetInventory().CreateInInventory("TacticalBaconCan")
					itemCreated = player.GetInventory().CreateInInventory("PeachesCan")
					itemCreated = player.GetInventory().CreateInInventory("SpaghettiCan")
					itemCreated = player.GetInventory().CreateInInventory("CharcoalTablets")
					itemCreated = player.GetInventory().CreateInInventory("PainkillerTablets")
					itemCreated = player.GetInventory().CreateInInventory("TetracyclineAntibiotics")
					itemCreated = player.GetInventory().CreateInInventory("MilitaryBeret_ChDK2")
					itemCreated = player.GetInventory().CreateInInventory("TacticalGloves_Black");
					itemCreated = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
					itemCreated = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
					itemCreated = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
					
										
					
					itemCreated = player.GetInventory().CreateInInventory("Ammo_556x45");
					if (itemCreated)
						{	
							itemCasted = ItemBase.Cast(itemCreated);
							itemCasted.SetQuantity(20);
						}
					itemCreated=NULL;
					
					itemCreated = player.GetInventory().CreateInInventory("Ammo_556x45");
					if (itemCreated)
						{	
							itemCasted = ItemBase.Cast(itemCreated);
							itemCasted.SetQuantity(20);
						}
						
					itemCreated = player.GetInventory().CreateInInventory("Ammo_556x45");
					if (itemCreated)
						{	
							itemCasted = ItemBase.Cast(itemCreated);
							itemCasted.SetQuantity(20);
						}
					itemCreated=NULL;
					
					itemCreated = player.GetInventory().CreateInInventory("Ammo_556x45");
					if (itemCreated)
						{	
							itemCasted = ItemBase.Cast(itemCreated);
							itemCasted.SetQuantity(20);
						}
					itemCreated = NULL;// Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
					
					
					itemCreated = player.GetHumanInventory().CreateInHands("Aug");// Выдаем игроку AKM в руки
					if (itemCreated) // Проверяем, создался ли АКМ
					{
						itemCreated.GetInventory().CreateAttachment( "ACOGOptic" ); //
						itemCreated.GetInventory().CreateAttachment( "M4_Suppressor" ); 
						inItem_spawn = itemCreated.GetInventory().CreateAttachment( "UniversalLight" );
						inItem_spawn.GetInventory().CreateAttachment( "Battery9V" );
						inItem_spawn = NULL;
					}
					break;
					
				}//END OF CASE 1
				
					case 2: //Set with number 2 (Сет с номером 2)
			{
					break;
			}
		}
	}

	void SetRandomHealthItem(EntityAI itemCreated) // Функция генерирует и применяет для предмета рандомное значение здоровья!
	{
		if ( itemCreated )
		{
			private int rndHlt = Math.RandomInt(55,6);
			itemCreated.SetHealth("","",rndHlt);
		}
		
	}
	
	void RemoveAllItems (PlayerBase player) 
	{
		private array<EntityAI> ItemListPlayer = new array<EntityAI>;
		private array<EntityAI> ItemsForDelete = new array<EntityAI>;
		private EntityAI itemInHands_player = player.GetHumanInventory().GetEntityInHands();
		if (itemInHands_player != NULL)
		{
			if (player.CanDropEntity(itemInHands_player) && player.GetHumanInventory().CanRemoveEntityInHands())
			{
			//	Print("ItemForDelete: " + itemInHands_player.ToString());
				ItemsForDelete.Insert(itemInHands_player);
			}
		}
		ItemListPlayer = GetItemListinobject(player,NULL,true);		
		if (ItemListPlayer.Count() > 0)
		{			
			foreach(EntityAI ItemPlayer: ItemListPlayer)
			{
				private array<EntityAI> ItemInItemInInventory = GetItemListinobject(NULL,ItemPlayer,false);
				private CargoBase cargo = ItemPlayer.GetInventory().GetCargo();		
				if(cargo) 
				{
					if (cargo.GetItemCount() > 0)
					{
						for (int f = 0; f < cargo.GetItemCount(); f++)
						{
							if(cargo.GetItem(f))
							{						
								ItemsForDelete.Insert(cargo.GetItem(f));
							}
						}														
					}
				}									
				if (ItemInItemInInventory.Count() > 0)
				{
					foreach(EntityAI items_temp: ItemInItemInInventory)
					{
						if(items_temp)
						{						
							ItemsForDelete.Insert(items_temp);
						}
					}		
				}
				if(ItemPlayer)
				{	
					ItemsForDelete.Insert(ItemPlayer);
				}
			}										
		} 
		if (ItemsForDelete.Count() > 0)
		{
			foreach(EntityAI item_temp: ItemsForDelete)
			{
				if(item_temp)
				{														
					GetGame().ObjectDelete(item_temp);													
				}												
			}
		}
	}
	
	array<EntityAI> GetItemListinobject(PlayerBase player,EntityAI item, bool check_player)
	{
		array<EntityAI> EntityAI_list_items = new array<EntityAI>; EntityAI_list_items.Clear();
		int	attIdx = 0; int attCount = 0; EntityAI		item_in_object;
		if ((player) && (check_player))
		{
			attCount	=	player.GetInventory().AttachmentCount(); 
			for (attIdx	=	0; attIdx < attCount; attIdx++)
			{
				item_in_object	=	player.GetInventory().GetAttachmentFromIndex(attIdx);
				if ( item_in_object.IsItemBase() )
				{
					EntityAI_list_items.Insert(item_in_object);
				}
			}
		}
		if ((item) && !check_player)
		{
			attCount	=	item.GetInventory().AttachmentCount();
			for (attIdx	=	0; attIdx < attCount; attIdx++)
			{
				item_in_object	=	item.GetInventory().GetAttachmentFromIndex(attIdx);
				if ( item_in_object.IsItemBase() )
				{
					EntityAI_list_items.Insert(item_in_object);
				}
			}
		}
		return EntityAI_list_items;		
	}