/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#include "AI/ScriptDevAI/PreCompiledHeader.h"
#include "Spells/Spell.h"
#include <cstring>
enum
{
    SPELL_DOMINION_SOUL1     = 10202,
    NPC_EMBERSTRIFE1         = 10321
};

bool GossipHello_ItemUse_Item_teleport(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    player->ADD_GOSSIP_ITEM( 3, " 世界主城传送 " , 1, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 3, " 初级副本传送 " , 1, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 3, " 中级副本传送 " , 1, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 3, " 团队副本传送 " , 1, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 3, " 野外BOSS传送 " , 1, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 3, " 世界风景传送1 " , 1, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 3, " 世界风景传送2 " , 1, GOSSIP_ACTION_INFO_DEF + 7);
    player->SEND_GOSSIP_MENU(99990,_Item->GetObjectGuid());
    
    player->SendEquipError(EQUIP_ERR_NONE, _Item, NULL);

    if (const SpellEntry* pSpellInfo = GetSpellStore()->LookupEntry<SpellEntry>(SPELL_DOMINION_SOUL1))
    {  
        Spell::SendCastResult(player, pSpellInfo, SPELL_FAILED_TARGET_AURASTATE);
    }
    return true;
}

void SendDefaultMenu_ItemUse_Item_teleport(Player *player, Item *_Item, uint32 action, SpellCastTargets const& targets)
{
    switch(action) {
        // 主城
        case GOSSIP_ACTION_INFO_DEF + 1 :
            
            player->ADD_GOSSIP_ITEM( 0, " [联盟] 暴风城 " , 2, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [联盟] 铁炉堡 " , 2, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [联盟] 达纳苏斯 " , 2, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [部落] 奥格瑞玛 " , 2, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [部落] 雷霆崖 " , 2, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [部落] 幽暗城 " , 2, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [中立] 棘齿城 " , 2, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [中立] 藏宝海湾 " , 2, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99987,_Item->GetObjectGuid());
            break;
        // 初级副本
        case GOSSIP_ACTION_INFO_DEF + 2 :
            
            player->ADD_GOSSIP_ITEM( 0, " [14] 怒焰裂谷 " , 4, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [19] 死亡矿井 " , 4, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [22] 哀嚎洞穴 " , 4, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [24] 影牙城堡 " , 4, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [26] 黑暗深渊 " , 4, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [27] 暴风城监狱 " , 4, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [31] 剃刀沼泽 " , 4, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [33] 诺莫瑞根 " , 4, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, " [40] 血色修道院 " , 4, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, " [42] 剃刀高地 " , 4, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, " [45] 奥达曼 " , 4, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99986,_Item->GetObjectGuid());
            break;

        // 中级副本
        case GOSSIP_ACTION_INFO_DEF + 3 :
            
            player->ADD_GOSSIP_ITEM( 0, " [46] 祖尔法拉克 " , 5, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [49] 玛拉顿 " , 5, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [53] 失落的神庙 " , 5, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [57] 黑石深渊 " , 5, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [60] 通灵学院 " , 5, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [60] 厄运之槌 (北区) " , 5, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [60] 厄运之槌 (东区) " , 5, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [60] 厄运之槌 (西区) " , 5, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, " [60] 斯坦索姆 " , 5, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, " [60] 黑石塔下 " , 5, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99993,_Item->GetObjectGuid());
            break;

        // 高级副本
        case GOSSIP_ACTION_INFO_DEF + 4 :
                
            player->ADD_GOSSIP_ITEM( 0, " [团] 溶火之心 " , 6, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [团] 黑石塔上 " , 6, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [团] 祖尔格拉布 " , 6, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [团] 黑翼之巢 " , 6, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [团] 安其拉 " , 6, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [团] 安其拉废墟 " , 6, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [团] 奥妮克希亚的巢穴 " , 6, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [团] 纳克萨玛斯 " , 6, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, " [团] 冰龙巢穴 " , 6, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99); 
            player->SEND_GOSSIP_MENU(99994,_Item->GetObjectGuid());
            break;

       // 野外BOSS传送
        case GOSSIP_ACTION_INFO_DEF + 5 :
            
            player->ADD_GOSSIP_ITEM( 0, " [野外]暮色森林 " , 9, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [野外]辛特兰 " , 9, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [野外]灰谷 " , 9, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [野外]艾萨拉 " , 9, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [野外]菲拉斯 " , 9, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [野外]诅咒之地 " , 9, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99988,_Item->GetObjectGuid()); 
            break;
        // 風景傳送
        case GOSSIP_ACTION_INFO_DEF + 6 :
            player->ADD_GOSSIP_ITEM( 0, " 海加尔山 " , 11, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " 翡翠圣地 " , 11, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " 时光之穴 " , 11, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " 黑暗之门 " , 11, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " 双塔山 " , 11, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " 梦境之树 " , 11, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " GM之岛" , 11, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " 海加尔山-暴雪路障 " , 11, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99989,_Item->GetObjectGuid()); 
            break;
        case GOSSIP_ACTION_INFO_DEF + 7 :
            player->ADD_GOSSIP_ITEM( 0, " 天涯海滩 " , 12, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " 安戈洛环形山 " , 12, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " 比吉尔的飞艇残骸 " , 12, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " 石堡瀑布" , 12, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " 地铁海底" , 12, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " 工程之岛" , 12, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99997,_Item->GetObjectGuid());
        break;
    }
}

bool GossipSelect_ItemUse_Item_teleport(Player *player, Item *_Item, uint32 sender, uint32 action, SpellCastTargets const& targets)
{
    switch(sender) {
        // 主选单
        case 1 :
            SendDefaultMenu_ItemUse_Item_teleport(player, _Item, action,targets);
            break;
        // 各大主城
        case 2 :
            switch(action) {
                // 暴风城
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(0,-9065,434,94,0);
                    break;
                // 铁炉堡
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(0,-5032,-819,495,0);
                    break;
                // 达纳苏斯
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,9961,2055,1329,0);
                    break;
                // 奥格瑞玛
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(1,1317,-4383,27,0);
                    break;
                // 雷霆崖
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(1,-1391,140,23,0);
                    break;
                // 幽暗城
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(0,1909,235,53,0);
                    break;
                // 棘齿城 */
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(1,-977,-3788,6,0);
                    break;
                // 藏宝海湾
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(0,-14302,518,9,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 4:
            switch(action) {
                // [14] 怒焰裂谷 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(389,2.024650f,-10.021000f,-16.187500f,0);
                    break;
                // [19] 死亡矿井
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(36,-16.4f,-383.07f,61.78f,0);
                    break;
                // [22] 哀嚎洞穴
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(43,-161.841995f,133.266998f,-73.866203f,0);
                    break;
                // [24] 影牙城堡
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(33,-228.19f,2110.56f,76.89f,0);
                    break;
                // [26] 黑暗深渊
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(48,-150.367004f,102.995003f,-40.555801f,0);
                    break;
                // [27] 暴风城监狱
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(34,48.29f,0.45f,-16.14f,0);
                    break;
                // [31] 剃刀沼泽
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(47,1943,1544,82,0);
                    break;
                // [33] 诺莫瑞根
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(90,-332.562988f,-3.445f,-152.845993f,0);
                    break;
                // [40] 血色修道院
                case GOSSIP_ACTION_INFO_DEF + 9 :
                    player->TeleportTo(189,855.903992f,1321.939941f,18.673000f,0);
                    break;
                // [42] 剃刀高地
                case GOSSIP_ACTION_INFO_DEF + 10 :
                    player->TeleportTo(129,2593.209961f,1109.459961f,51.093300f,0);
                    break;
                // [45] 奥达曼
                case GOSSIP_ACTION_INFO_DEF + 11 :
                    player->TeleportTo(70,-227.529007f,45.009800f,-46.019600f,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        // 中级副本
        case 5:
            switch(action) {
                // [46] 祖尔法拉克 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(209,1213,841,8.9f,0);
                    break;
                // [49] 玛拉顿
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(349,1012.700012f,-459.317993f,-43.547100f,0);
                    break;
                // [53] 失落的神庙
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(109,-313.369995f,99.955399f,-131.848999f,0);
                    break;
                // [57] 黑石深渊
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(230,456.928986f,34.927700f,-69.388100f,0);
                    break;
                // [60] 通灵学院
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(289,199,126,135,0);
                    break;
                // [60] 厄运之槌 (北区)
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(429,255.164001f,-17.024200f,-2.560600f,0);
                    break;
                // [60] 厄运之槌 (东区)
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(429,46.24f,-155.53f,-2.71349f,0);
                    break;
                // [60] 厄运之槌 (西区)
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(429,32.722599f,159.417007f,-3.470170f,0);
                    break;
                // [60] 斯坦索姆
                case GOSSIP_ACTION_INFO_DEF + 9 :
                    player->TeleportTo(329,3392,-3379,143,0);
                    break;
                // [60] 黑石塔下
                case GOSSIP_ACTION_INFO_DEF + 10 :
                    player->TeleportTo(229,78.19f,-227.63f,49.72f,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;

        // 高级副本
        case 6:
            switch(action) {
                // [团] 溶火之心 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(409,1089.601685f,-470.190247f,-106.413055f,0);
                    break;
                // [团] 黑石塔上
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(229,78.339836f,-227.793518f,49.7103f,0);
                    break;
                // [团] 祖尔格拉布
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(309,-11916f,-1251.469971f,92.32f,0);
                    break;
                // [团] 黑翼之巢
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(469,-7674.470215f,-1108.380005f,396.649994f,0);
                    break;
                // [团] 安其拉
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(531,-8212.002930f,2034.474854f,129.141342f,0);
                    break;
                // [团] 安其拉废墟
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(509,-8443.475586f,1518.648560f,31.906958f,0);
                    break;
                // [团] 奥妮克希亚的巢穴
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(249,30.010290f,-58.840508f,-5.325367f,0);
                    break;
                //[团] 纳克萨玛斯 
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(533,3005.87f,-3435.01f,293.882f,0);
                    break;
                // [团] 冰龙巢穴
                case GOSSIP_ACTION_INFO_DEF + 9 :
                    player->TeleportTo(533,3700.35f,-5185.92f,143.957f,4.403038f,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        // 野外BOSS坐标
        case 9:
            switch(action) {
                // 暮色森林 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(0,-10526.168945f,-434.996796f,50.894821f,0);
                    break;
                // 辛特兰
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(0,759.605713f,-3893.341309f,116.475304f,0);
                    break;
                // 灰谷
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,3120.289307f,-3439.444336f,139.566345f,1);
                    break;
                //  艾萨拉
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(1,2622.219971f,-5977.930176f,100.562897f,1);
                    break;
                // 菲拉斯
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(1,-2741.290039f,2009.481323f,31.877323f,1);
                    break;
                // 诅咒之地
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(0,-12234.000000f,-2474.000000f,-3.000000f,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 11 :
            switch(action) {
                //海加爾山 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(1,4603.946777f,-3879.250977f,944.183472f,1);
                    break;
                //翡翠聖地 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(1,3968.264648f,-1290.036011f,240.326889f,5.927989f);
                    break;
                //時光之穴 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,-8173.930176f,-4737.463867f,33.777351f,4.772119f);
                    break;
                //黑暗之門 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(0,-11849.031250f,-3201.170654f,-28.885090f,3.280838f);
                    break;
                //雙塔山 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(1,-3331.353271f,2225.728271f,30.987701f,6.267522f);
                    break;
                //夢境之樹 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(1,-2914.756104f,1902.199341f,34.741035f,5.690404f);
                    break;
                //GM之島 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(1, 16222.1f,16252.1f,12.5872f,1);
                    break;
                //暴雪建設公司路障 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(1,5478.060059f,-3730.850098f,1593.439941f,5.610376f);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 12 :
            switch(action) {
                //天涯海灘 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(1,-9851.617188f,-3608.474121f,8.939731f,2.513388f);
                    break;
                //安戈洛環形山 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(1,-8562.096680f,-2106.056641f,8.852538f,0.090425f);
                    break;
                //比吉爾的飛艇殘骸 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,-4014.003418f,-3768.186523f,42.123295f,5.220697f);
                    break;
                //石堡瀑布 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(0,-9481.493164f,-3326.915283f,8.864347f,0.846896f);
                    break;
                //地鐵海底
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(369, -9.96166f,1238.17f,-126.102f,0);
                    break;
                //工程師之島
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(451, 16299.464844f, 16272.843750f, 69.443901f,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 15:
            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
            break;
    }
    return true;
}

void AddSC_Item_teleport()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="Item_teleport";
    newscript->pItemUse = &GossipHello_ItemUse_Item_teleport;
    newscript->pGossipSelect_Item = &GossipSelect_ItemUse_Item_teleport;
    newscript->RegisterSelf();
}

 
