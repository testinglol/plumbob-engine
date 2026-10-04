
byte FUN_0047db81(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = FUN_0047dce6(param_1,s_route_entry_flags_006c508c,param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_0047dce6(param_1,s_exclusive_placement_flags_006c5070,param_2);
    if (cVar1 == '\0') {
      cVar1 = FUN_0047dce6(param_1,s_wall_placement_flags_006c5058,param_2);
      if (cVar1 == '\0') {
        cVar1 = FUN_0047dce6(param_1,s_placement_flags_006c5048,param_2);
        if (cVar1 == '\0') {
          cVar1 = FUN_0047dce6(param_1,s_movement_flags_006c5038,param_2);
          if (cVar1 == '\0') {
            cVar1 = FUN_0047dce6(param_1,s_function_sort_flags_006c5024,param_2);
            if (cVar1 == '\0') {
              cVar1 = FUN_0047dce6(param_1,s_room_sort_flags_006c5014,param_2);
              if (cVar1 == '\0') {
                cVar1 = FUN_0047dce6(param_1,s_censorship_flags_006c5000,param_2);
                if (cVar1 == '\0') {
                  cVar1 = FUN_0047dce6(param_1,s_wall_adjacency_flags_006c4fe8,param_2);
                  if (cVar1 == '\0') {
                    cVar1 = FUN_0047dce6(param_1,s_flag_field_2_006c4fd8,param_2);
                    if (cVar1 == '\0') {
                      cVar1 = FUN_0047dce6(param_1,s_Render_Display_Flags_006c4fc0,param_2);
                      if (cVar1 == '\0') {
                        cVar1 = FUN_0047dce6(param_1,s_flags_006c4f28,param_2);
                        if (cVar1 == '\0') {
                          cVar1 = FUN_0047dce6(param_1,s_Game_Edition_006c4fb0,param_2);
                          bVar2 = -(cVar1 != '\0') & 0xfc;
                        }
                        else {
                          bVar2 = 0x8e;
                        }
                      }
                      else {
                        bVar2 = 0xd1;
                      }
                    }
                    else {
                      bVar2 = 0xd6;
                    }
                  }
                  else {
                    bVar2 = 0xd0;
                  }
                }
                else {
                  bVar2 = 0xb2;
                }
              }
              else {
                bVar2 = 0xcd;
              }
            }
            else {
              bVar2 = 0xce;
            }
          }
          else {
            bVar2 = 0xcb;
          }
        }
        else {
          bVar2 = 0xca;
        }
      }
      else {
        bVar2 = 0xe5;
      }
    }
    else {
      bVar2 = 0xfb;
    }
  }
  else {
    bVar2 = 0;
  }
  return bVar2;
}

