class StartSetsPlayersConfig
{    
    void StartSetsPlayer(PlayerBase player,int use_set_id)
    {
        EntityAI itemCreated = NULL;
        EntityAI itemCreated1 = NULL;
        ItemBase itemCasted = NULL;
        
        switch( use_set_id ) //Раздаем лут (можно использовать значения от 1 и выше, только не 0 и не -1)
        {
            case 1: //Set with number 1 (Сет с номером 1)
            {
                My_Custom_Spawn_Parameters.RemoveAllItems(player); // Чтобы удалить с персонажа уже имеющиеся стандартные стартовые шмотки раскомментировать строку
                itemCreated = player.GetInventory().CreateInInventory("CoyoteBag_Green");     // Выдаем рюкзак и записываем в переменную itemCreated
                if (itemCreated)                                                            // Проверяем, создался ли рюкзак. Если он создался, переменная itemCreated будет не пуста и проверка пройдет
                {
                    SetRandomHealthItem(itemCreated);                                                // Выдаем рюкзаку рандомное качество
                    itemCreated1 = itemCreated.GetInventory().CreateInInventory("Apple");            // Добавляем в инвентарь созданного рюкзака яблоко и записываем в переменную itemCreated1
                    if (itemCreated1)                                                                // Проверяем, создалось ли яблоко в рюкзаке, яблоко у нас с переменной itemCreated1
                    {
                        SetRandomHealthItem(itemCreated1);                                                // Выдаем яблоку рандомное качество
                    }
                    itemCreated1 = NULL;                                                            // Обнуляем значение переменной после работы с ней, чтобы следующая проверка прошла корректно
                    itemCreated1 = itemCreated.GetInventory().CreateInInventory("Rag");                // Выдаем игроку бинты в рюкзак и записываем в переменную itemCreated1
                    if (itemCreated1)                                                                // Проверяем, создались ли бинты в рюкзаке, они у нас с переменной itemCreated1
                    {
                        itemCasted = ItemBase.Cast(itemCreated1);                                        // Выполняем преобразование в другой класс для работы с нужной нам функцией, поскольку в классе EntityAI нет нужной нам функции SetQuantity, а в подклассе ItemBase она есть. Предмет при этом так и остается один и тот же!
                        itemCasted.SetQuantity(4);                                                        // Определяем количество для созданных бинтов как 4 штуки
                        SetRandomHealthItem(itemCreated);                                                // Выдаем бинтам рандомное качество, функция работает с классом EntityAI (см. в конфе файла)
                    }
                }
                // переменную itemCreated не обнуляем далее, поскольку мы ее не используем в проверке ниже.
                itemCreated = player.GetInventory().CreateInInventory("TTSKOPants");        // Выдаем игроку штаны
                itemCreated = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");    // Выдаем игроку куртку
                itemCreated = player.GetInventory().CreateInInventory("CombatBoots_Black");    // Выдаем игроку обувь
                //itemCasted = ItemBase.Cast(itemCreated);                                        // Строка не нужна, закоментирована. используется для изменения класса EntityAI в ItemBase (чтобы нужные операции были доступны)
                itemCreated = player.GetInventory().CreateInInventory("CombatKnife");        // Выдаем игроку ножик в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("FNX45");                // Выдаем игроку FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");    // Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");    // Выдаем игроку магазины к FNX в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");        // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
                itemCreated = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");        // Выдаем игроку магазины к AKM в любой свободный слот в инвентаре
                itemCreated = NULL;                                                            // Обнуляем значение переменной после работы с ней, нужно если мы будем использовать ее далее
                itemCreated = player.GetHumanInventory().CreateInHands("akm");                // Выдаем игроку AKM в руки
                if (itemCreated)                                                            // Проверяем, создался ли АКМ
                {
                    itemCreated.GetInventory().CreateAttachment( "PSO11Optic" );                 // Выдаем игроку на AKM оптику ПСО 11 и крепим
                    itemCreated.GetInventory().CreateAttachment( "AK_WoodBttstck" );             // Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
                    itemCreated.GetInventory().CreateAttachment( "AK_WoodHndgrd" );                // Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
                    itemCreated.GetInventory().CreateAttachment( "AK_Suppressor" );                // Выдаем игроку на AKM цевье, приклад и глушитель, и крепим
                }                    
                break;
            }
            case 2: //Set with number 2  (Сет с номером 2)
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
};